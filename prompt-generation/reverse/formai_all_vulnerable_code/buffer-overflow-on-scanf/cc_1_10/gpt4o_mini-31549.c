//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void decimalToBinary(int n, char *binary) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binary[i] = (n & 1) ? '1' : '0'; 
        n >>= 1; 
    }
    binary[MAX_BITS] = '\0';
}

void binaryToDecimal(const char *binary, int *decimal) {
    *decimal = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        if (binary[i] == '1') {
            *decimal += (1 << (MAX_BITS - 1 - i));
        }
    }
}

void displayConversionMenu() {
    printf("Welcome to the Binary Converter!\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

void binaryStringValidation(const char *binary) {
    while (*binary) {
        if (*binary != '0' && *binary != '1') {
            fprintf(stderr, "Error: Invalid binary string. Only '0' and '1' are allowed.\n");
            exit(EXIT_FAILURE);
        }
        binary++;
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char binary[MAX_BITS + 1];
    int decimal;
    int choice;

    do {
        displayConversionMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                clearInputBuffer();
                
                if (decimal < 0) {
                    fprintf(stderr, "Error: Negative numbers cannot be converted to binary.\n");
                    continue;
                }
                
                decimalToBinary(decimal, binary);
                printf("Decimal %d in binary is: %s\n", decimal, binary);
                break;

            case 2:
                printf("Enter a binary number: ");
                fgets(binary, MAX_BITS, stdin);
                
                // Remove newline character from the string, if present
                binary[strcspn(binary, "\n")] = 0;
                
                // Validate binary string
                binaryStringValidation(binary);
                binaryToDecimal(binary, &decimal);
                printf("Binary %s in decimal is: %d\n", binary, decimal);
                break;

            case 3:
                printf("Exiting the Binary Converter. Goodbye!\n");
                break;

            default:
                printf("Invalid input. Please select an option between 1 and 3.\n");
                break;
        }
        
        printf("\n");

    } while (choice != 3);

    return 0;
}