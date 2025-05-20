//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toBinary(int n, char *binary) {
    for (int i = 0; i < 32; i++) {
        binary[31 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binary[32] = '\0';  // Null-terminate the binary string
}

void printBinary(char *binary) {
    printf("Binary representation: %s\n", binary);
}

void displayMenu() {
    printf("\n--- Welcome to the Visionary Binary Converter ---\n");
    printf("1. Convert a decimal number to binary\n");
    printf("2. Exit\n");
    printf("Please choose an option (1 or 2): ");
}

int main() {
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        
        if (choice == 2) {
            printf("Thank you for using the Visionary Binary Converter. Goodbye!\n");
            break;
        } else if (choice != 1) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        printf("Enter a decimal number: ");
        int number;
        scanf("%d", &number);

        if (number < 0) {
            printf("Only non-negative integers are allowed.\n");
            continue;
        }

        char binary[33];  // 32 bits + 1 for null terminator
        toBinary(number, binary);
        
        printBinary(binary);
    }

    return 0;
}