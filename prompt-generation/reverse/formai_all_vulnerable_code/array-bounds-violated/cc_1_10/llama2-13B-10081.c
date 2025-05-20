//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold the binary number
struct binary_number {
    int digits[32];
    int length;
};

// Function to convert a decimal number to binary
struct binary_number decimal_to_binary(int dec) {
    struct binary_number bin;
    int i, j;

    // Initialize the binary number struct
    bin.length = 0;
    for (i = 0; i < 32; i++) {
        bin.digits[i] = 0;
    }

    // Convert the decimal number to binary
    while (dec != 0) {
        // Find the highest set bit
        for (j = 0; j < 32; j++) {
            if (dec & (1 << j)) {
                bin.digits[j] = 1;
                break;
            }
        }

        // Shift the binary number to the left
        for (; j < 32; j++) {
            bin.digits[j] = bin.digits[j - 1];
        }

        // Decrement the decimal number
        dec = dec >> 1;

        // Increment the length of the binary number
        bin.length++;
    }

    return bin;
}

// Function to print the binary number
void print_binary(struct binary_number bin) {
    int i;

    // Print the binary number
    for (i = 0; i < bin.length; i++) {
        printf("%d", bin.digits[i]);
    }

    printf("\n");
}

int main() {
    int dec = 123;
    struct binary_number bin = decimal_to_binary(dec);
    print_binary(bin);

    return 0;
}