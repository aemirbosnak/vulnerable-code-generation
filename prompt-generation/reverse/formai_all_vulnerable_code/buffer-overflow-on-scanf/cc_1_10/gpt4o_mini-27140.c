//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void decimalToBinary(int n) {
    // Variable to hold the binary representation
    char binary[32];
    int index = 0;
    
    // Special case for zero
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (n > 0) {
        binary[index++] = (n % 2) + '0';  // Store the character
        n /= 2;  // Shift right
    }

    // Print the binary representation in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
    printf("\n");
}

int binaryToDecimal(const char* binary) {
    int decimal = 0;
    int base = 1;  // Initialize base value for binary
    int length = strlen(binary);

    // Read binary string from right to left
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;  // Add base value if the bit is 1
        }
        base *= 2;  // Move to the next base (2^i)
    }

    return decimal;
}

void displayMenu() {
    printf("\nBinary Converter\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice, decimalNumber;
    char binaryInput[33];  // Enough for 32 bits + null terminator
    int isRunning = 1;

    while (isRunning) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                decimalToBinary(decimalNumber);
                break;
            case 2:
                printf("Enter a binary number (up to 32 bits): ");
                scanf("%s", binaryInput);
                // Validate binary input
                if (strspn(binaryInput, "01") != strlen(binaryInput)) {
                    printf("Invalid binary number. Please enter a valid binary string.\n");
                } else {
                    int decimalResult = binaryToDecimal(binaryInput);
                    printf("Decimal: %d\n", decimalResult);
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                isRunning = 0;  // Exit the loop
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}