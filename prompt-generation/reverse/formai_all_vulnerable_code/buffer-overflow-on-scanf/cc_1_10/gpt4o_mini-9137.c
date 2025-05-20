//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void decimalToHexadecimal(int decimal);
void hexadecimalToDecimal(char hex[]);
void displayMenu();

int main() {
    int choice;
    char hexInput[20];

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                {
                    int decimal;
                    printf("Enter a decimal number: ");
                    scanf("%d", &decimal);
                    decimalToHexadecimal(decimal);
                    break;
                }
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexInput);
                hexadecimalToDecimal(hexInput);
                break;
            case 3:
                printf("Exiting the program. Have a good day!\n");
                break;
            default:
                printf("Invalid choice, please select again.\n");
        }
    } while (choice != 3);
    
    return 0;
}

void displayMenu() {
    printf("\n======= Hexadecimal Converter =======\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

void decimalToHexadecimal(int decimal) {
    if (decimal < 0) {
        printf("Negative numbers cannot be converted to hexadecimal.\n");
        return;
    }
    
    // Buffer for the resulting hexadecimal string
    char hex[20];
    int index = 0;

    // Convert decimal to hexadecimal
    if (decimal == 0) {
        printf("The hexadecimal representation is: 0\n");
        return;
    }

    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';  // Convert to character
        } else {
            hex[index++] = (remainder - 10) + 'A'; // Convert to character
        }
        decimal /= 16;
    }

    // Reverse the hex string
    hex[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }

    printf("The hexadecimal representation is: %s\n", hex);
}

void hexadecimalToDecimal(char hex[]) {
    int length = strlen(hex);
    int base = 1; // Base of hexadecimal number
    int decimal = 0;

    // Convert hexadecimal string to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        } else {
            printf("Invalid hexadecimal number.\n");
            return;
        }
        base *= 16;
    }

    printf("The decimal representation is: %d\n", decimal);
}