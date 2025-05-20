//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

void toHexadecimal(int num, char* hexStr) {
    if (num == 0) {
        strcpy(hexStr, "0");
        return;
    }

    int index = 0;
    while (num != 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            hexStr[index++] = remainder + '0';
        } else {
            hexStr[index++] = (remainder - 10) + 'A';
        }
        num = num / 16;
    }
    hexStr[index] = '\0';

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexStr[i];
        hexStr[i] = hexStr[index - i - 1];
        hexStr[index - i - 1] = temp;
    }
}

void printMenu() {
    printf("Hexadecimal Converter\n");
    printf("=====================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int hexToDecimal(const char* hexStr) {
    int decimalValue = 0;
    int base = 1;
    int length = strlen(hexStr);

    for (int i = length - 1; i >= 0; i--) {
        char ch = hexStr[i];
        int digit;

        if (ch >= '0' && ch <= '9') {
            digit = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            digit = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            digit = ch - 'a' + 10;
        } else {
            printf("Invalid hex character: %c\n", ch);
            return -1;
        }
        
        decimalValue += digit * base;
        base *= 16;
    }
    
    return decimalValue;
}

int main() {
    int option;
    char hexStr[MAX_INPUT];
    char convertedHex[MAX_INPUT];
    int decimalNumber;

    while (1) {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                toHexadecimal(decimalNumber, convertedHex);
                printf("Decimal: %d -> Hexadecimal: %s\n", decimalNumber, convertedHex);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexStr);
                decimalNumber = hexToDecimal(hexStr);
                if (decimalNumber != -1) {
                    printf("Hexadecimal: %s -> Decimal: %d\n", hexStr, decimalNumber);
                }
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please choose again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}