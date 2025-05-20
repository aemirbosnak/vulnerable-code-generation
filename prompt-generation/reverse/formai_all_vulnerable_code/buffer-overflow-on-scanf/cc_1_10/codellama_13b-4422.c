//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: relaxed
/*
 * A unique C Binary Converter example program
 *
 * Written in a relaxed style
 *
 * Usage:
 * 1. Compile the program with the following command:
 *      gcc binary_converter.c -o binary_converter
 * 2. Run the program with the following command:
 *      ./binary_converter
 *
 * Inputs:
 * 1. The program takes an integer as input.
 * 2. The integer should be in the range of 0 to 255.
 *
 * Outputs:
 * 1. The program prints the binary representation of the input integer.
 * 2. The binary representation is printed in a relaxed style, where each digit is separated by a space.
 */

#include <stdio.h>

int main() {
    int number;
    int binary[8];

    printf("Enter an integer between 0 and 255: ");
    scanf("%d", &number);

    if (number < 0 || number > 255) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        binary[i] = number % 2;
        number /= 2;
    }

    printf("The binary representation of %d is: ", number);

    for (int i = 7; i >= 0; i--) {
        printf("%d", binary[i]);

        if (i > 0) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}