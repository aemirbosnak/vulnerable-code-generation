//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20

void toHexadecimal(int number, char *hexStr) {
    sprintf(hexStr, "%X", number);
}

int fromHexadecimal(const char *hexStr) {
    int number;
    sscanf(hexStr, "%X", &number);
    return number;
}

void displayMenu() {
    printf("\nHexadecimal Converter Menu:");
    printf("\n1. Convert Decimal to Hexadecimal");
    printf("\n2. Convert Hexadecimal to Decimal");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
}

void convertDecimalToHex() {
    int decimalNumber;
    char hexStr[MAX_LENGTH];

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    toHexadecimal(decimalNumber, hexStr);
    printf("Decimal: %d => Hexadecimal: %s\n", decimalNumber, hexStr);
}

void convertHexToDecimal() {
    char hexStr[MAX_LENGTH];
    int decimalNumber;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexStr);
    
    for (int i = 0; hexStr[i]; i++) {
        hexStr[i] = toupper(hexStr[i]); // Ensure the string is in upper case
    }

    decimalNumber = fromHexadecimal(hexStr);
    printf("Hexadecimal: %s => Decimal: %d\n", hexStr, decimalNumber);
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertDecimalToHex();
                break;
            case 2:
                convertHexToDecimal();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}