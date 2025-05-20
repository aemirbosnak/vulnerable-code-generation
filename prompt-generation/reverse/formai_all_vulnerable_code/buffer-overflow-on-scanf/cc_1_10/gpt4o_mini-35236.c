//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void decimal_to_binary(int decimal, char *binary) {
    for (int i = 0; i < MAX_BITS; i++) {
        binary[MAX_BITS - 1 - i] = (decimal & (1 << i)) ? '1' : '0';
    }
    binary[MAX_BITS] = '\0'; // Null-terminate the string
}

void binary_to_decimal(const char *binary, int *decimal) {
    *decimal = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        if (binary[MAX_BITS - 1 - i] == '1') {
            *decimal += (1 << i);
        }
    }
}

void display_conversion_menu() {
    printf("Choose a conversion option:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char binary[MAX_BITS + 1];
    int decimal;
    
    while (1) {
        display_conversion_menu();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimal_to_binary(decimal, binary);
                printf("Decimal: %d = Binary: %s\n\n", decimal, binary);
                break;

            case 2:
                printf("Enter a binary number (up to %d bits): ", MAX_BITS);
                scanf("%s", binary);
                binary_to_decimal(binary, &decimal);
                printf("Binary: %s = Decimal: %d\n\n", binary, decimal);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
    
    return 0;
}