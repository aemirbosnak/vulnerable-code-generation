//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printMenu() {
    printf("\nHexadecimal Converter\n");
    printf("=========================\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("=========================\n");
    printf("Select an option: ");
}

int decimalToHexadecimal(int decimal, char *hexadecimal) {
    int index = 0;

    if (decimal == 0) {
        strcpy(hexadecimal, "0");
        return 1;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0';
        } else {
            hexadecimal[index++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }
    hexadecimal[index] = '\0';

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }

    return index;
}

int hexadecimalToDecimal(char *hexadecimal) {
    int decimal = 0;
    int base = 1;
    int length = strlen(hexadecimal);

    for (int i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 'A' + 10) * base;
        } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            decimal += (hexadecimal[i] - 'a' + 10) * base;
        }
        base *= 16;
    }

    return decimal;
}

int main() {
    int choice;
    char hexadecimal[20];
    int decimal;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);

                if (decimal < 0) {
                    printf("Please enter a non-negative integer.\n");
                    break;
                }

                decimalToHexadecimal(decimal, hexadecimal);
                printf("Decimal: %d  =>  Hexadecimal: %s\n", decimal, hexadecimal);
                break;

            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexadecimal);

                // Remove potential whitespaces
                char *ptr = hexadecimal;
                while (*ptr) {
                    if (isspace(*ptr)) {
                        memmove(ptr, ptr + 1, strlen(ptr));
                    } else {
                        ptr++;
                    }
                }

                for (int i = 0; hexadecimal[i]; i++) {
                    hexadecimal[i] = toupper(hexadecimal[i]);
                }

                decimal = hexadecimalToDecimal(hexadecimal);
                printf("Hexadecimal: %s  =>  Decimal: %d\n", hexadecimal, decimal);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select an option from the menu.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}