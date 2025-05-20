//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 20

void toHex(int num, char *hexStr) {
    sprintf(hexStr, "%X", num);
}

int fromHex(const char *hexStr) {
    int num;
    sscanf(hexStr, "%X", &num);
    return num;
}

void displayMenu() {
    printf("Hexadecimal Converter\n");
    printf("---------------------\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("---------------------\n");
    printf("Select an option: ");
}

void decimalToHexadecimal() {
    char hexStr[MAX_NUM_LENGTH];
    int decimalNum;

    printf("Enter a decimal number: ");
    if (scanf("%d", &decimalNum) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return;
    }
    
    toHex(decimalNum, hexStr);
    printf("The hexadecimal representation of %d is: %s\n", decimalNum, hexStr);
}

void hexadecimalToDecimal() {
    char hexStr[MAX_NUM_LENGTH];

    printf("Enter a hexadecimal number: ");
    // Clear the newline from previous input
    while ((getchar()) != '\n');
    fgets(hexStr, MAX_NUM_LENGTH, stdin);
    hexStr[strcspn(hexStr, "\n")] = 0; // Remove newline character

    // Validate that the input is hexadecimal
    for (int i = 0; hexStr[i] != '\0'; i++) {
        if (!isxdigit(hexStr[i])) {
            printf("Invalid hexadecimal input. Please enter a valid hexadecimal number.\n");
            return;
        }
    }

    int decimalNum = fromHex(hexStr);
    printf("The decimal representation of %s is: %d\n", hexStr, decimalNum);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Please enter a number between 1 and 3.\n");
            while ((getchar()) != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                decimalToHexadecimal();
                break;
            case 2:
                hexadecimalToDecimal();
                break;
            case 3:
                printf("Exiting the Hexadecimal Converter. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
                break;
        }
    }

    return 0;
}