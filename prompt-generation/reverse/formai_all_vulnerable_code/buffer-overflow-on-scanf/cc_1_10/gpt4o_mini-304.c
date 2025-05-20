//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void toBinary(int n, char *binary);

int main() {
    int number;
    char binaryRepresentation[33]; // 32 bits + 1 for '\0'

    printf("Welcome to the C Binary Converter!\n");
    printf("Please enter a positive integer (or -1 to exit): ");

    while (1) {
        scanf("%d", &number);

        // Exit condition
        if (number == -1) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Validating the input
        if (number < 0) {
            printf("Please enter a positive integer only.\n");
            continue;
        }

        // Convert to binary
        toBinary(number, binaryRepresentation);
        
        // Display the result
        printf("The binary representation of %d is: %s\n", number, binaryRepresentation);
        printf("Please enter another positive integer (or -1 to exit): ");
    }

    return 0;
}

// Function to convert a number to its binary representation
void toBinary(int n, char *binary) {
    int index = 0;

    // Edge case for zero
    if (n == 0) {
        binary[index++] = '0';
        binary[index] = '\0';
        return;
    }

    // Reset the binary string
    binary[32] = '\0'; // Null-terminate the string
    while (n > 0) {
        binary[index++] = (n % 2) ? '1' : '0'; // Store '1' or '0'
        n /= 2; // Shift right by dividing by 2
    }

    // Since we filled the binary representation in reverse order, we need to reverse it
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }

    binary[index] = '\0'; // Null-terminate the final binary string
}