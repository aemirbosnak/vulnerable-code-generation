//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary and print steps
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0 in binary is 0\n");
        return;
    }

    int binary[32]; // Array to store binary number
    int index = 0;  // Counter for binary array
    
    printf("Converting %d to binary:\n", decimal);
    
    // Process of conversion
    while (decimal > 0) {
        binary[index] = decimal % 2; // Get the remainder
        printf("Step %d: %d %% 2 = %d, Store: %d\n", index + 1, decimal, binary[index], binary[index]);
        decimal = decimal / 2; // Update the decimal number
        index++;
    }

    printf("Binary in reverse order (since we have built it backwards): ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to read integer input from the user
int readInput() {
    int num;
    printf("Enter a decimal number to convert to binary: ");
    
    while (1) {
        if (scanf("%d", &num) == 1 && num >= 0) {
            break;
        } else {
            printf("Invalid input. Please enter a non-negative integer: ");
            while (getchar() != '\n'); // Clear invalid input
        }
    }
    
    return num;
}

// Main function
int main() {
    printf("Welcome to the Decimal to Binary Converter!\n");
    
    int decimal = readInput(); // Get user input
    decimalToBinary(decimal);   // Convert and display the binary
    
    printf("Thank you for using the converter!\n");
    return 0;
}