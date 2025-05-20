//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void toHexadecimal(int value, char *hexStr) {
    int index = 0;
    const char *hexDigits = "0123456789ABCDEF";
    
    if (value == 0) {
        hexStr[index++] = '0';
    } else {
        while (value > 0) {
            hexStr[index++] = hexDigits[value % 16];
            value /= 16;
        }
    }
    hexStr[index] = '\0';
    
    // Reverse the string because we constructed it backwards
    for(int i = 0; i < index / 2; i++) {
        char temp = hexStr[i];
        hexStr[i] = hexStr[index - i - 1];
        hexStr[index - i - 1] = temp;
    }
}

void printMenu() {
    printf("=========================================\n");
    printf(" Welcome to the Curious Hexadecimal Converter!\n");
    printf("=========================================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("=========================================\n");
}

int decimalToHex() {
    int decimalValue;
    char hexString[20]; // Buffer to hold the hexadecimal string
    
    printf("Enter a decimal number to convert: ");
    scanf("%d", &decimalValue);
    
    toHexadecimal(decimalValue, hexString);
    printf("Hexadecimal representation: %s\n", hexString);
    
    return 0;
}

int hexadecimalToDecimal() {
    char hexString[20];
    int decimalValue;
    
    printf("Enter a hexadecimal number to convert: ");
    scanf("%s", hexString);
    
    decimalValue = (int)strtol(hexString, NULL, 16); // Convert hex to decimal
    printf("Decimal representation: %d\n", decimalValue);
    
    return 0;
}

int main() {
    int choice;
    
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                decimalToHex();
                break;
            case 2:
                hexadecimalToDecimal();
                break;
            case 3:
                printf("Thank you for using the Curious Hexadecimal Converter!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}