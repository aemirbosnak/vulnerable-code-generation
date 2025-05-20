//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu() {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
}

void convertDecimalToHexadecimal() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    // Using a buffer to hold the hexadecimal representation
    char hexBuffer[20];
    sprintf(hexBuffer, "%X", decimalNumber);

    printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexBuffer);
}

void convertHexadecimalToDecimal() {
    char hexString[20];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexString);
    
    // A bit of error handling for invalid input
    if (strspn(hexString, "0123456789ABCDEFabcdef") != strlen(hexString)) {
        printf("Invalid hexadecimal input. Please use only characters 0-9 and A-F.\n");
        return;
    }

    // Using strtol to convert hex to decimal
    long decimalValue = strtol(hexString, NULL, 16);
    printf("The decimal representation of %s is: %ld\n", hexString, decimalValue);
}

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertDecimalToHexadecimal();
                break;
            case 2:
                convertHexadecimalToDecimal();
                break;
            case 3:
                printf("Thanks for using the Hexadecimal Converter! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}