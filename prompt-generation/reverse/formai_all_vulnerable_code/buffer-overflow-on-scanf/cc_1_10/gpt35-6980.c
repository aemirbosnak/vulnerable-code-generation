//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>

void printMenu() {
    printf("==============================================\n");
    printf("                  HEX CONVERTER                \n");
    printf("==============================================\n");
    printf("\n");
    printf("Please choose an option:\n");
    printf("1. Convert from decimal to hexadecimal\n");
    printf("2. Convert from hexadecimal to decimal\n");
    printf("3. Exit program\n");
    printf("\n");
}

int decimalToHex(int decimal) {
    if (decimal == 0) {
        return 0;
    } else {
        int hexNumber = decimalToHex(decimal / 16);
        int remainder = decimal % 16;
        if (remainder < 10) {
            printf("%d", remainder);
        } else {
            printf("%c", 'A' + (remainder - 10));
        }
        return hexNumber;
    }
}

int hexToDecimal(char hex[]) {
    int decimal = 0;
    int base = 1;
    int length = strlen(hex);
    int i;

    for (i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
    }

    return decimal;
}

int main() {
    int option;

    do {
        printMenu();

        scanf("%d", &option);

        switch(option) {
            case 1: {
                int decimalNumber;
                printf("Please enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("The hexadecimal equivalent is: ");
                decimalToHex(decimalNumber);
                printf("\n\n");
                break;
            }
            case 2: {
                char hexNumber[100];
                printf("Please enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("The decimal equivalent is: %d\n\n", hexToDecimal(hexNumber));
                break;
            }
            case 3: {
                printf("Exiting program... Thank you!\n");
                break;
            }
            default: {
                printf("Invalid option! Please try again.\n\n");
                break;
            }
        }
    } while (option != 3);

    return 0;
}