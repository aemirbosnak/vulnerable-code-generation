//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void toHexadecimal(int decimal, char *hexadecimal) {
    const char hexDigits[] = "0123456789ABCDEF";
    char buffer[20]; // Buffer to hold the hexadecimal characters
    int index = 0;
    
    if(decimal == 0) {
        hexadecimal[index++] = '0';
    } else {
        while(decimal != 0) {
            int remainder = decimal % 16;
            buffer[index++] = hexDigits[remainder];
            decimal /= 16;
        }
    }

    // Reverse the buffer into the hexadecimal string
    for(int j = 0; j < index; j++) {
        hexadecimal[j] = buffer[index - 1 - j];
    }
    hexadecimal[index] = '\0'; // Null-terminate the string
}

int main() {
    int decimalNumber;
    char hexadecimal[20]; // String to hold the hexadecimal representation

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Please enter a decimal number (non-negative): ");
    scanf("%d", &decimalNumber);

    if(decimalNumber < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Perform the conversion
    toHexadecimal(decimalNumber, hexadecimal);

    // Display the result
    printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexadecimal);
    
    // Additional functionality to convert multiple numbers
    char continueConversion;
    do {
        printf("Would you like to convert another number? (y/n): ");
        scanf(" %c", &continueConversion);
        
        if (continueConversion == 'y' || continueConversion == 'Y') {
            printf("Please enter a decimal number (non-negative): ");
            scanf("%d", &decimalNumber);
            
            if(decimalNumber < 0) {
                printf("Please enter a non-negative integer.\n");
            } else {
                toHexadecimal(decimalNumber, hexadecimal);
                printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexadecimal);
            }
        }
    } while (continueConversion == 'y' || continueConversion == 'Y');

    printf("Thank you for using the Hexadecimal Converter. Goodbye!\n");
    return 0;
}