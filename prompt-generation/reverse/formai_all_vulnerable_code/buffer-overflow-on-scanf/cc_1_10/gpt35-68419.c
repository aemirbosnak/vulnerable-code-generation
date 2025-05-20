//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>

int hexToDecimal(char hexDigit) {
    if(hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    } else if(hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10;
    } else if(hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10;
    }
    return -1;
}

void hexToRgb(char* hexValue, int* red, int* green, int* blue) {
    *red = (hexToDecimal(hexValue[1]) + (hexToDecimal(hexValue[0]) * 16)) * 16;
    *green = (hexToDecimal(hexValue[3]) + (hexToDecimal(hexValue[2]) * 16)) * 16;
    *blue = (hexToDecimal(hexValue[5]) + (hexToDecimal(hexValue[4]) * 16)) * 16;
}

void rgbToHex(int red, int green, int blue, char* hexValue) {
    int currentByte = 0;
    for(int i = 0; i < 6; i++) {
        if(i < 2) {
            currentByte = red >> (8 * (1 - i));
        } else if(i < 4) {
            currentByte = green >> (8 * (3 - i));
        } else {
            currentByte = blue >> (8 * (5 - i));
        }
        int firstNibble = currentByte >> 4;
        int secondNibble = currentByte & 15;
        if(firstNibble < 10) {
            hexValue[i] = (char)(firstNibble + '0');
        } else {
            hexValue[i] = (char)(firstNibble + 'a' - 10);
        }
        if(secondNibble < 10) {
            hexValue[i + 1] = (char)(secondNibble + '0');
        } else {
            hexValue[i + 1] = (char)(secondNibble + 'a' - 10);
        }
        i++;
    }
}

int main() {
    char hexValue[7];
    printf("Enter a hexadecimal color code in the form RRGGBB: ");
    scanf("%s", hexValue);
    int red, green, blue;
    hexToRgb(hexValue, &red, &green, &blue);
    printf("The RGB values are: %d %d %d\n", red, green, blue);
    char newHexValue[7];
    rgbToHex(red, green, blue, newHexValue);
    printf("The converted hexadecimal color code is: %s\n", newHexValue);
    return 0;
}