//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToHexadecimal(int decimal, char* hexStr) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexStr[i++] = remainder + '0';
        } else {
            hexStr[i++] = (remainder - 10) + 'A';
        }
        decimal = decimal / 16;
    }
    hexStr[i] = '\0';
    
    // Reverse the string to get the correct hexadecimal format
    for (int j = 0; j < i / 2; j++) {
        char temp = hexStr[j];
        hexStr[j] = hexStr[i - j - 1];
        hexStr[i - j - 1] = temp;
    }
}

void hexToDecimal(char* hexStr, int* decimal) {
    int len = strlen(hexStr);
    *decimal = 0;
    for (int i = 0; i < len; i++) {
        char c = hexStr[i];
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            printf("Invalid hexadecimal input: %s\n", hexStr);
            return;
        }
        *decimal = (*decimal << 4) | value; // Multiply by 16
    }
}

void displayConversion(int decimal, char* hexStr) {
    printf("You've converted successfully!\n");
    printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %s\n", hexStr);
}

int main() {
    char choice;
    int decimalInput;
    char hexInput[20];
    char hexStr[20];

    printf("Welcome to the Decoding Universe!\n");
    printf("Would you like to convert Decimal to Hexadecimal (D) or Hexadecimal to Decimal (H)? ");
    scanf(" %c", &choice);

    if (choice == 'D' || choice == 'd') {
        printf("Surprise! Enter a decimal number to convert to hexadecimal: ");
        scanf("%d", &decimalInput);
        
        decimalToHexadecimal(decimalInput, hexStr);
        displayConversion(decimalInput, hexStr);

    } else if (choice == 'H' || choice == 'h') {
        printf("Wow! Enter a hexadecimal number to convert to decimal (use uppercase or lowercase): ");
        scanf("%s", hexInput);
        
        hexToDecimal(hexInput, &decimalInput);
        
        if (decimalInput) {
            printf("You just transformed that hex into a decimal!\n");
            printf("Hexadecimal: %s\n", hexInput);
            printf("Decimal: %d\n", decimalInput);
        }
    } else {
        printf("Oops! Your choice is quite unexpected... Please enter D or H next time!\n");
    }

    printf("Thank you for using the Hexadecimal Converter!\n");
    return 0;
}