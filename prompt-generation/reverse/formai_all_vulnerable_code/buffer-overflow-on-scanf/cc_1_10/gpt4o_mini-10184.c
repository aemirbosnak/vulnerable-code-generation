//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // Array to hold binary digits
    int binary[32];
    int index = 0;

    // Converting decimal to binary by repeated division
    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Printing the binary representation in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to check if input is valid
int isValidInput(char* input) {
    for (int i = 0; input[i] != '\0'; i++) {
        // Check if all characters are digits
        if (input[i] < '0' || input[i] > '9') {
            return 0; // Invalid input
        }
    }
    return 1; // Valid input
}

int main() {
    char input[20];
    int keepRunning = 1;

    printf("Welcome to the Decimal to Binary Converter!\n");

    while (keepRunning) {
        printf("Please enter a non-negative decimal number (or 'exit' to quit): ");
        scanf("%s", input);

        // Check for exit command
        if (strcmp(input, "exit") == 0) {
            keepRunning = 0;
            printf("Exiting the converter. Goodbye!\n");
            continue;
        }

        // Validate the input
        if (isValidInput(input)) {
            int decimal = atoi(input);
            if (decimal < 0) {
                printf("Please enter a non-negative number.\n");
            } else {
                decimalToBinary(decimal);
            }
        } else {
            printf("Invalid input. Please enter a valid non-negative decimal number.\n");
        }
    }

    return 0;
}