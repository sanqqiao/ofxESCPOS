// =============================================================================
//
// Copyright (c) 2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include <bitset>
#include "ofLog.h"
#include "ofx/IO/AbstractTypes.h"
#include "ofx/ESCPOS/BaseCodes.h"
#include "ofx/ESCPOS/BaseTypes.h"
#include "ofx/ESCPOS/BitImage.h"


namespace ofx {
namespace ESCPOS {
namespace Commands {

    
class DefaultPrinterStatus
{
public:
    DefaultPrinterStatus()
    {
    }


    virtual ~DefaultPrinterStatus()
    {
    }

    
private:
    int _modelId;
    int _typeId;

};


class DefaultPrinterStatusCommands:
    public virtual IO::AbstractByteSink,
    public virtual IO::AbstractBufferedByteSource
{
public:
    DefaultPrinterStatusCommands();
    virtual ~DefaultPrinterStatusCommands();

    virtual std::size_t getPrinterStatusRealTime();

    virtual std::size_t getOfflineStatus();
    virtual std::size_t getErrorStatus();
    virtual std::size_t getPaperStatus();

//    virtual uint8_t getPrinterModelId();
//
//    virtual const std::string& getFirmwareVersion();
//    virtual const std::string& getManufacturer();
//    virtual const std::string& getPrinterName();
//
//    virtual uint8_t getTypeId();
//
//    virtual bool multibyteCharactersSupported();
//    virtual bool autocutterInstalled();



    std::bitset<8> _typeId;
    std::string _firmwareVersion;
    std::string _manufacturer;
    std::string _printerName;
    std::string _serialNumber;
    std::string _additionalFonts;

};


} } } // namespace ofx::ESCPOS::Commands
