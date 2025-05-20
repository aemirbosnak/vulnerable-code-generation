//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure to represent a binary number
typedef struct binary_t {
    int digits[32];
    int len;
} binary_t;

// Function to convert a decimal number to binary
binary_t decimal_to_binary(int dec) {
    binary_t bin;
    int i, j;

    // Initialize the binary array with zeros
    for (i = 0; i < 32; i++) {
        bin.digits[i] = 0;
    }

    // Loop until the decimal number is reduced to 0
    while (dec > 0) {
        // Divide the decimal number by 2
        dec /= 2;

        // Find the position of the remainder in the binary array
        for (j = 0; j < 32; j++) {
            if (dec >= (1 << (31 - j))) {
                bin.digits[j] = 1;
                dec -= (1 << (31 - j));
                break;
            }
        }

        // If the remainder is 0, the loop is done
        if (dec == 0) {
            break;
        }
    }

    // Set the length of the binary array
    bin.len = j;

    return bin;
}

// Function to convert a binary number to decimal
int binary_to_decimal(binary_t bin) {
    int dec = 0;
    int i;

    // Loop until the binary array is reduced to 0
    for (i = 0; i < bin.len; i++) {
        dec += (bin.digits[i] << (31 - i));
    }

    return dec;
}

int main() {
    // Convert 123 to binary
    binary_t bin = decimal_to_binary(123);
    printf("123 in binary: %s\n", bin.digits);

    // Convert binary to decimal
    int dec = binary_to_decimal(bin);
    printf("123 in decimal: %d\n", dec);

    return 0;
}