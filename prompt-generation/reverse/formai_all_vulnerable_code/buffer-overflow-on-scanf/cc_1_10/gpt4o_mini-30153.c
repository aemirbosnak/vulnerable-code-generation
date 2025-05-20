//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal, char *binary) {
    int index = 0;
    if (decimal == 0) {
        binary[index++] = '0';
    } else {
        while (decimal > 0) {
            binary[index++] = (decimal % 2) ? '1' : '0';
            decimal /= 2;
        }
    }
    binary[index] = '\0';

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

int main() {
    int decimalNumber;
    char *binaryRepresentation;

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please enter a positive integer (or -1 to exit): ");
    
    while (1) {
        if (scanf("%d", &decimalNumber) != 1) {
            printf("Invalid input! Please enter a valid positive integer.\n");
            // Clean the input buffer
            while (getchar() != '\n');
            continue; // Ask for input again
        }

        if (decimalNumber == -1) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (decimalNumber < 0) {
            printf("Negative numbers are not allowed. Please enter a positive integer.\n");
            continue; // Ask for input again
        }

        // Allocate memory for binary representation
        binaryRepresentation = (char *)malloc(32 * sizeof(char)); // Enough for 32 bits
        if (binaryRepresentation == NULL) {
            printf("Memory allocation failed. Exiting the program.\n");
            return 1;
        }

        // Convert to binary
        decimalToBinary(decimalNumber, binaryRepresentation);
        printf("Decimal: %d -> Binary: %s\n", decimalNumber, binaryRepresentation);

        // Free allocated memory
        free(binaryRepresentation);

        // Prompt for next input
        printf("Please enter another positive integer (or -1 to exit): ");
    }

    return 0;
}