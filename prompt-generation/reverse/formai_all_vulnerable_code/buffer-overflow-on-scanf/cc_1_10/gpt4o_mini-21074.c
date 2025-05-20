//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary for unsigned integers
void convertToBinary(unsigned int num, char *binary) {
    for (int i = 31; i >= 0; i--) {
        binary[i] = (num % 2) + '0'; // Store character '0' or '1'
        num /= 2; // Divide by 2 for next bit
    }
    binary[32] = '\0'; // Null-terminate the string
}

// Function to convert decimal to binary for signed integers
void convertToSignedBinary(int num, char *binary) {
    if (num < 0) {
        num = ~(-num) + 1; // Two's complement for negative numbers
    }
    convertToBinary((unsigned int) num, binary);
}

// Function to prompt for user input and validate
int getUserInput(int *num) {
    printf("Enter a decimal number (-2147483648 to 2147483647): ");
    char input[16];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char *endptr;
        long value = strtol(input, &endptr, 10);
        if (endptr == input || *endptr != '\n' || value < -2147483648 || value > 2147483647) {
            printf("Invalid input. Please enter a valid decimal integer.\n");
            return 0;
        }
        *num = (int)value;
        return 1;
    }
    return 0;
}

// Main functionality
int main() {
    int num;
    char binary[33]; // For 32 bits plus null terminator

    // Get user input with validation
    while (!getUserInput(&num)) {
        // Loop until valid input is provided
    }

    // Display the result
    printf("Decimal: %d\n", num);
    
    // Choice between signed and unsigned representation
    printf("Choose representation:\n1. Unsigned\n2. Signed\n");
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            convertToBinary((unsigned int)num, binary);
            printf("Binary (unsigned): %s\n", binary);
            break;
        case 2:
            convertToSignedBinary(num, binary);
            printf("Binary (signed): %s\n", binary);
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 1; // Exit with error code
    }

    return 0; // Successfully completed the program
}