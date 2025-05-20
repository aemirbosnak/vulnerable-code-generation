//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to hexadecimal
void decimalToHexadecimal(int decimal, char* hexadecimal) {
    int remainder;
    char hexadecimalChar;
    int index = 0;

    // Convert decimal to hexadecimal
    while (decimal!= 0) {
        remainder = decimal % 16;
        decimal = decimal / 16;
        hexadecimalChar = remainder + '0';
        hexadecimal[index] = hexadecimalChar;
        index++;
    }
    hexadecimal[index] = '\0'; // Add null terminator
}

// Function to convert a hexadecimal number to decimal
int hexadecimalToDecimal(char* hexadecimal) {
    int decimal = 0;
    int index = 0;

    // Convert hexadecimal to decimal
    while (hexadecimal[index]!= '\0') {
        decimal = decimal * 16 + hexadecimal[index] - '0';
        index++;
    }
    return decimal;
}

int main() {
    char decimal[10];
    char hexadecimal[10];
    int decimalInput;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalInput);
    strcpy(decimal, (char*)&decimalInput);

    printf("The hexadecimal equivalent is: ");
    decimalToHexadecimal(decimalInput, hexadecimal);
    printf("%s\n", hexadecimal);

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimal);
    int decimalOutput = hexadecimalToDecimal(hexadecimal);
    printf("The decimal equivalent is: %d\n", decimalOutput);

    return 0;
}