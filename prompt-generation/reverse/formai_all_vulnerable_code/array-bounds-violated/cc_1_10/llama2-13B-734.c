//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to represent a binary number
typedef struct {
    int digits[8]; // 8 bits to represent the binary number
    int len; // length of the binary number
} binary_t;

// Function to convert a decimal number to binary
binary_t dec2bin(int dec) {
    binary_t bin;
    int i = 0;

    // Initialize the binary array with 0s
    for (int j = 0; j < 8; j++) {
        bin.digits[j] = 0;
    }

    // Loop until the decimal number is 0
    while (dec > 0) {
        // Divide the decimal number by 2 to get the remainder
        int rem = dec % 2;

        // Add the remainder to the binary array
        bin.digits[i] = rem;

        // Increment the index and decrement the decimal number
        i++;
        dec /= 2;
    }

    // Set the length of the binary number
    bin.len = i;

    return bin;
}

// Function to convert a binary number to decimal
int bin2dec(binary_t bin) {
    int dec = 0;
    int i = 0;

    // Loop until the binary number is 0
    while (bin.len > 0) {
        // Add the value of the current digit to the decimal number
        dec += (bin.digits[i] * pow(2, 7 - i));

        // Increment the index and decrement the binary number length
        i++;
        bin.len--;
    }

    return dec;
}

int main() {
    // Test cases
    binary_t bin1 = dec2bin(123);
    binary_t bin2 = dec2bin(456);
    binary_t bin3 = dec2bin(10101010);

    // Convert binary numbers to decimal
    int dec1 = bin2dec(bin1);
    int dec2 = bin2dec(bin2);
    int dec3 = bin2dec(bin3);

    // Print the results
    printf("123 in binary is: %s\n", bin1.digits);
    printf("456 in binary is: %s\n", bin2.digits);
    printf("10101010 in binary is: %s\n", bin3.digits);
    printf("123 in decimal is: %d\n", dec1);
    printf("456 in decimal is: %d\n", dec2);
    printf("10101010 in decimal is: %d\n", dec3);

    return 0;
}