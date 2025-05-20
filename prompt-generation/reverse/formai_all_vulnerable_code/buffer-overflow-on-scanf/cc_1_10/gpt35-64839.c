//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int hexToDecimal(char hexVal) {
    if (hexVal >= '0' && hexVal <= '9')
        return hexVal - '0';
    else if (hexVal >= 'A' && hexVal <= 'F')
        return hexVal - 'A' + 10;
    else if (hexVal >= 'a' && hexVal <= 'f')
        return hexVal - 'a' + 10;
    else {
        printf("Invalid hex input");
        exit(0);
    }
}

void decimalToRGB(int decimal, int* red, int* green, int* blue) {
    *red = (decimal >> 16) & 0xFF;
    *green = (decimal >> 8) & 0xFF;
    *blue = decimal & 0xFF;
}

void decimalToHex(int decimal, char* hex) {
    char hexString[8];
    sprintf(hexString, "%X", decimal);
    *hex = hexString[0];
    *(hex+1) = hexString[1];
}

void hexToRGB(char* hex, int* red, int* green, int* blue) {
    int decimal = 0;
    decimal = hexToDecimal(*hex) * 16 + hexToDecimal(*(hex + 1));
    decimalToRGB(decimal, red, green, blue);
}

void rgbToDecimal(int red, int green, int blue, int* decimal) {
    *decimal = (red << 16) | (green << 8) | blue;
}

void rgbToHex(int red, int green, int blue, char* hex) {
    int decimal = 0;
    rgbToDecimal(red, green, blue, &decimal);
    decimalToHex(decimal, hex);
}

void convertToRGB(char format, char* input, int* red, int* green, int* blue) {
    if (format == 'r') {
        sscanf(input, "%d,%d,%d", red, green, blue);
    } else if (format == 'h') {
        hexToRGB(input, red, green, blue);
    } else {
        printf("Invalid format input");
        exit(0);
    }
}

void convertToHex(char format, char* input, char* hex) {
    int red, green, blue, decimal;
    if (format == 'r') {
        sscanf(input, "%d,%d,%d", &red, &green, &blue);
        rgbToHex(red, green, blue, hex);
    } else if (format == 'h') {
        sprintf(hex, "%s", input);
    } else {
        printf("Invalid format input");
        exit(0);
    }
}

void recursiveColorConversion(char formatFrom, char formatTo, char* input, char* output) {
    int red, green, blue, decimal;
    char hex[7];
    
    if (formatFrom == formatTo) {
        sprintf(output, "%s", input);
        return;
    }
    
    if (formatFrom == 'h' && formatTo == 'r') {
        convertToRGB('h', input, &red, &green, &blue);
        sprintf(output, "%d,%d,%d", red, green, blue);
        return;
    }
    
    if (formatFrom == 'r' && formatTo == 'h') {
        convertToHex('r', input, hex);
        sprintf(output, "#%s", hex);
        return;
    }
    
    if (formatFrom == 'h' && formatTo == 'h') {
        sprintf(output, "#%s", input);
        return;
    }
    
    convertToRGB(formatFrom, input, &red, &green, &blue);
    rgbToHex(red, green, blue, hex);
    recursiveColorConversion('h', formatTo, hex, output);
}

int main() {
    char formatFrom, formatTo, input[20], output[20];
    
    printf("Enter the format of the input (h for hex, r for RGB): ");
    scanf("%c", &formatFrom);
    getchar();
    
    printf("Enter the format of the output (h for hex, r for RGB): ");
    scanf("%c", &formatTo);
    getchar();
    
    printf("Enter the input color: ");
    scanf("%19s", input);
    
    recursiveColorConversion(formatFrom, formatTo, input, output);
    
    printf("%s in %c format is %s in %c format", input, formatFrom, output, formatTo);
    
    return 0;
}