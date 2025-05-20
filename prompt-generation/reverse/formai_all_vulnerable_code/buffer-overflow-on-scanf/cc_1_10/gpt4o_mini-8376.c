//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimal_to_binary(int n) {
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }
    
    int binary[32];
    int idx = 0;

    while (n > 0) {
        binary[idx] = n % 2;
        n = n / 2;
        idx++;
    }

    // Print binary from reverse order
    printf("Binary: ");
    for (int i = idx - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int binary_to_decimal(const char *binary_str) {
    int decimal = 0;
    int base = 1;

    // Start from the last character of the string
    for (int i = strlen(binary_str) - 1; i >= 0; i--) {
        if (binary_str[i] == '1') {
            decimal += base;
        } else if (binary_str[i] != '0') {
            printf("Invalid binary number.\n");
            return -1;
        }
        base *= 2;
    }
    return decimal;
}

void display_menu() {
    printf("Binary Converter\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
}

int main() {
    while (1) {
        display_menu();
        
        int choice;
        printf("Select an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimal_to_binary(decimal);
                break;
            }
            case 2: {
                char binary_str[33]; // Max 32 bits + 1 for null terminator
                printf("Enter a binary number: ");
                scanf("%s", binary_str);
                int decimal_value = binary_to_decimal(binary_str);
                if (decimal_value != -1) {
                    printf("Decimal: %d\n", decimal_value);
                }
                break;
            }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select 1, 2 or 3.\n");
        }
    }
    return 0;
}