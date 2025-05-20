//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int number, char *binary) {
    for (int i = 31; i >= 0; i--) {
        binary[i] = (number % 2) ? '1' : '0';
        number /= 2;
    }
    binary[32] = '\0'; // Null-terminate the string
}

void printMenu() {
    printf("=== Binary Converter ===\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("========================\n");
}

int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);
    
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    
    return decimal;
}

int main() {
    int choice, number;
    char binary[33]; // To store the binary representation (32 bits + null terminator)

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the invalid input
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%d", &number) != 1) {
                    printf("Invalid input. Please enter a valid decimal number.\n");
                    while (getchar() != '\n'); // Clear the invalid input
                    break;
                }
                convertToBinary(number, binary);
                printf("Binary representation of %d is: %s\n", number, binary);
                break;

            case 2:
                printf("Enter a binary number (up to 32 bits): ");
                char inputBinary[33];
                scanf("%s", inputBinary);
                if (strspn(inputBinary, "01") != strlen(inputBinary)) {
                    printf("Invalid binary input. Please enter a valid binary number.\n");
                    break;
                }
                int decimalValue = binaryToDecimal(inputBinary);
                printf("Decimal representation of %s is: %d\n", inputBinary, decimalValue);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}