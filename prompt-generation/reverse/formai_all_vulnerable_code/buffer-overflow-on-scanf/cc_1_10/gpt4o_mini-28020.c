//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }
    
    int binary[32], i = 0;
    
    while (n > 0) {
        binary[i] = n % 2; // Store remainder
        n = n / 2;         // Divide n by 2
        i++;
    }

    // Print binary representation in reverse order
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Function to validate if the input is a non-negative integer
int isNonNegativeInteger(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0; // Not a valid non-negative integer
        }
    }
    return 1; // Valid non-negative integer
}

// Main function
int main() {
    char input[100];
    int decimalNum;

    printf("Welcome to the Decimal to Binary Converter!\n");

    while(1) {
        printf("Please enter a non-negative decimal number (or type 'exit' to quit): ");
        scanf("%s", input); // Read user input

        // Check for exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Validate if the input is a non-negative integer
        if (!isNonNegativeInteger(input)) {
            printf("Invalid input. Please enter a valid non-negative integer.\n");
            continue;
        }

        // Convert string input to integer
        decimalNum = atoi(input);
        
        // Print the binary representation
        decimalToBinary(decimalNum);
    }

    return 0;
}