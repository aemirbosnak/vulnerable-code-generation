//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to represent a binary number
struct binary {
    int bits[32];
    int length;
};

// Function to convert a decimal number to a binary string
struct binary decimal_to_binary(int decimal) {
    struct binary binary;
    int i;

    // Initialize the binary structure with zeros
    for (i = 0; i < 32; i++) {
        binary.bits[i] = 0;
    }

    // Loop until the decimal number is less than or equal to 2
    while (decimal > 0) {
        // Get the last bit of the decimal number
        binary.bits[i] = decimal % 2;

        // Increment the length of the binary string
        binary.length++;

        // Decrement the decimal number
        decimal /= 2;

        // Check if the decimal number is 0
        if (decimal == 0) {
            break;
        }
    }

    return binary;
}

// Function to convert a binary string to a decimal number
int binary_to_decimal(struct binary binary) {
    int decimal = 0;
    int i;

    // Loop until the length of the binary string is 0
    for (i = 0; i < binary.length; i++) {
        // Add the value of the ith bit to the decimal number
        decimal += (binary.bits[i] << (31 - i));
    }

    return decimal;
}

int main() {
    int decimal = 42;
    struct binary binary;

    // Convert the decimal number to a binary string
    binary = decimal_to_binary(decimal);

    // Print the binary string
    printf("Binary: %s\n", binary.bits);

    // Convert the binary string back to a decimal number
    decimal = binary_to_decimal(binary);

    // Print the decimal number
    printf("Decimal: %d\n", decimal);

    return 0;
}