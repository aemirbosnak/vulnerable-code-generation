//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* convertToHexadecimal(unsigned int decimalNumber);

int main(void) {
    unsigned int decimalNumber;
    char* hexadecimalNumber;

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%u", &decimalNumber);

    hexadecimalNumber = convertToHexadecimal(decimalNumber);
    printf("%u in decimal is %s in hexadecimal.\n", decimalNumber, hexadecimalNumber);

    free(hexadecimalNumber);

    return 0;
}

char* convertToHexadecimal(unsigned int decimalNumber) {
    char hexDigits[] = "0123456789ABCDEF";
    unsigned int temp = decimalNumber;
    int hexSize = 2; // Starting size of hexadecimalNumber is "0x" + 1 digit
    char* hexadecimalNumber;

    // Calculate size of hexadecimalNumber
    while(temp > 0) {
        temp /= 16;
        hexSize++;
    }

    // Allocate memory for hexadecimalNumber
    hexadecimalNumber = (char*) malloc(hexSize * sizeof(char));
    if(hexadecimalNumber == NULL) {
        fprintf(stderr, "Error allocating memory.");
        exit(1);
    }

    // Fill in hexadecimalNumber
    strcpy(hexadecimalNumber, "0x");
    for(int i = hexSize - 2; i >= 2; i--) {
        hexadecimalNumber[i] = hexDigits[decimalNumber % 16];
        decimalNumber /= 16;
    }
    hexadecimalNumber[hexSize - 1] = '\0';

    return hexadecimalNumber;
}