//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toHexadecimal(int number, char *hexStr) {
    if (number == 0) {
        strcpy(hexStr, "0");
        return;
    }
    
    int index = 0;
    while (number != 0) {
        int remainder = number % 16;
        hexStr[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        number /= 16;
    }
    hexStr[index] = '\0';

    // Reverse the hex string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexStr[i];
        hexStr[i] = hexStr[index - 1 - i];
        hexStr[index - 1 - i] = temp;
    }
}

void fromHexadecimal(const char *hexStr, int *number) {
    *number = 0;
    int len = strlen(hexStr);
    
    for (int i = 0; i < len; i++) {
        char currentChar = toupper(hexStr[len - 1 - i]);
        int value;

        if (isdigit(currentChar)) {
            value = currentChar - '0';
        } else {
            value = currentChar - 'A' + 10;
        }
        
        *number += value * (1 << (i * 4));
    }
}

void displayMenu() {
    printf("\nHexadecimal Converter Menu:\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int option;
    do {
        displayMenu();
        if (scanf("%d", &option) != 1) {
            clearInputBuffer(); // clear invalid input
            printf("Invalid input! Please enter a number.\n");
            option = 0; // reset option to continue the loop
            continue;
        }
        clearInputBuffer();

        switch (option) {
            case 1: {
                int decimalNumber;
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                clearInputBuffer();

                char hexStr[20];
                toHexadecimal(decimalNumber, hexStr);
                printf("Hexadecimal: %s\n", hexStr);
                break;
            }
            case 2: {
                char hexStr[20];
                printf("Enter a hexadecimal string: ");
                fgets(hexStr, sizeof(hexStr), stdin);
                hexStr[strcspn(hexStr, "\n")] = 0; // Remove newline character

                int decimalNumber;
                fromHexadecimal(hexStr, &decimalNumber);
                printf("Decimal: %d\n", decimalNumber);
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}