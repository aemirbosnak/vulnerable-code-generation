//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n*** Hexadecimal Converter Menu ***\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

void convertDecimalToHexadecimal() {
    int decimalNumber;
    char hexadecimalNumber[20];

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Converting decimal to hexadecimal
    sprintf(hexadecimalNumber, "%X", decimalNumber);
    printf("Decimal Number: %d\n", decimalNumber);
    printf("Hexadecimal Equivalent: %s\n", hexadecimalNumber);
}

void convertHexadecimalToDecimal() {
    char hexadecimalNumber[20];
    int decimalNumber;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimalNumber);

    // Converting hexadecimal to decimal
    decimalNumber = (int) strtol(hexadecimalNumber, NULL, 16);
    printf("Hexadecimal Number: %s\n", hexadecimalNumber);
    printf("Decimal Equivalent: %d\n", decimalNumber);
}

int main() {
    int option;
    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                convertDecimalToHexadecimal();
                break;
            case 2:
                convertHexadecimalToDecimal();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}