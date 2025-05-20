//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void decimalToBinary(int n);
char* binaryToDecimal(const char* binary);

// Main function
int main() {
    int choice, number;
    char binary[33];  // To hold binary string (32 bits + null terminator)
    
    printf("Welcome to the Binary Converter Program!\n");
    printf("Choose an operation:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");

    // Loop for user operation
    while (1) {
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a positive integer to convert to binary: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("Please enter a non-negative integer.\n");
                } else {
                    printf("Binary representation of %d is: ", number);
                    decimalToBinary(number);
                    printf("\n");
                }
                break;
                
            case 2:
                printf("Enter a binary number (up to 32 bits): ");
                scanf("%s", binary);
                // Validate input binary string
                if (strspn(binary, "01") != strlen(binary)) {
                    printf("Invalid binary number. Please use only 0s and 1s.\n");
                } else {
                    char* decimalValue = binaryToDecimal(binary);
                    printf("Decimal representation of %s is: %s\n", binary, decimalValue);
                    free(decimalValue);  // Clean up allocated memory for decimal string
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid selection. Please choose 1, 2, or 3.\n");
                break;
        }
    }
    return 0;
}

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    
    int binary[32];  // To hold binary digits
    int index = 0;

    while (n > 0) {
        binary[index] = n % 2;  // Store remainder
        n = n / 2;               // Update n
        index++;
    }

    // Print binary digits in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

// Function to convert binary string to decimal
char* binaryToDecimal(const char* binary) {
    unsigned long long decimalValue = 0;  // Use long long for larger binary numbers
    int length = strlen(binary);

    // Convert each character of binary string to decimal value
    for (int i = 0; i < length; i++) {
        if (binary[length - 1 - i] == '1') {
            decimalValue += (1ULL << i);  // Calculate power of 2
        }
    }

    // Allocate memory for decimal string representation
    char* decimalString = malloc(21);  // Enough to store up to 64-bit signed integer in string form
    if (!decimalString) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Convert decimal value to string
    snprintf(decimalString, 21, "%llu", decimalValue);
    return decimalString;
}