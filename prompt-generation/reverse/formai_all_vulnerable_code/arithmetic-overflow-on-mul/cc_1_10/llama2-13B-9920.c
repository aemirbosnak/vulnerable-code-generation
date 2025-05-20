//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 1024

void binary_to_decimal(char *input, int *decimal) {
    int i, j, count = 0;
    char digit = 0;

    // Initialize output variable
    *decimal = 0;

    // Iterate over each character in the input string
    for (i = 0; i < strlen(input); i++) {
        // Check if the current character is a 1 or a 0
        if (input[i] == '1') {
            // If it is a 1, increment the count
            count++;
        } else if (input[i] == '0') {
            // If it is a 0, decrement the count
            count--;
        }

        // If the count is positive, add the corresponding digit to the output
        if (count > 0) {
            digit = '1' + (count - 1);
            *decimal = (*decimal * 2) + digit;
        }
    }
}

void decimal_to_binary(int decimal, char *output) {
    int i, j, count = 0;
    char digit = 0;

    // Initialize output variable
    *output = '\0';

    // Iterate over each digit of the decimal number
    for (i = 0; i < 32; i++) {
        // Check if the current digit is non-zero
        if (decimal & (1 << i)) {
            // If it is non-zero, add the corresponding digit to the output
            count++;
            digit = '1' + (count - 1);
            *output = digit;
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int decimal;
    char output[MAX_OUTPUT_LENGTH];

    // Get the input from the user
    printf("Enter a binary string (up to %d characters): ", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Convert the input to decimal
    binary_to_decimal(input, &decimal);

    // Convert the decimal to binary
    decimal_to_binary(decimal, output);

    // Print the binary output
    printf("The binary representation of %d is: %s\n", decimal, output);

    return 0;
}