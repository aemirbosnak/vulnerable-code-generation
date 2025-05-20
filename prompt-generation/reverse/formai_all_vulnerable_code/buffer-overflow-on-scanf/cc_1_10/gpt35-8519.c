//FormAI DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

// Function Prototypes
bool isValid(char c);
int hexToDec(char c);
int power(int base, int exponent);
int convertToRGB(int hexValue);

int main() {
    char hexCode[7];
    printf("Enter a 6 digit hexadecimal color code: ");
    scanf("%s", &hexCode);

    // Check if input is valid
    for(int i = 0; i < 6; i++) {
        if(!isValid(hexCode[i])) {
            printf("Invalid input!\n");
            return 0;
        }
    }
    
    int red = convertToRGB(hexToDec(hexCode[0])*16 + hexToDec(hexCode[1]));
    int green = convertToRGB(hexToDec(hexCode[2])*16 + hexToDec(hexCode[3]));
    int blue = convertToRGB(hexToDec(hexCode[4])*16 + hexToDec(hexCode[5]));
    
    printf("RGB Color Code: %d,%d,%d", red, green, blue);
    
    return 0;
}

// Function to check if input is a valid hexadecimal digit
bool isValid(char c) {
    if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
        return true;
    }
    return false;
}

// Function to convert hexadecimal digit to decimal value
int hexToDec(char c) {
    if(c >= '0' && c <= '9') {
        return c - '0';
    }
    else if(c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    else {
        return c - 'a' + 10;
    }
}

// Function to calculate power of a number
int power(int base, int exponent) {
    int result = 1;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to convert decimal value to RGB value
int convertToRGB(int hexValue) {
    int exponent = 0;
    int result = 0;
    while(hexValue > 0) {
        result += (hexValue % 2) * power(2, exponent);
        hexValue /= 2;
        exponent++;
    }
    return result;
}