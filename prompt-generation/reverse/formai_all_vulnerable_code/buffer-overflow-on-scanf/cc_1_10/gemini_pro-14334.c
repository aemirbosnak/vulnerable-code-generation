//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Declare the binary converter function
int binary_converter(int decimal_number);

int main() {
    // Declare the decimal number
    int decimal_number;

    // Prompt the user to enter a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    // Convert the decimal number to binary
    int binary_number = binary_converter(decimal_number);

    // Print the binary number
    printf("The binary representation of %d is %d\n", decimal_number, binary_number);

    return 0;
}

// Define the binary converter function
int binary_converter(int decimal_number) {
    // Declare the binary number
    int binary_number = 0;
    int i = 1;

    // While the decimal number is greater than 0
    while (decimal_number > 0) {
        // If the decimal number is odd
        if (decimal_number % 2 == 1) {
            // Set the corresponding bit in the binary number
            binary_number |= i;
        }

        // Divide the decimal number by 2
        decimal_number /= 2;

        // Shift the binary number left by 1
        binary_number <<= 1;

        // Increment the value of i
        i <<= 1;
    }

    // Return the binary number
    return binary_number;
}