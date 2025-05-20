//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
// C Binary Converter Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_DIGITS 8

// Function to convert decimal to binary
void decimal_to_binary(int num) {
    int i, rem, binary_num = 0;

    // Iterate through all binary digits
    for (i = 0; i < BINARY_DIGITS; i++) {
        rem = num % 2;
        num = num / 2;
        binary_num = (binary_num * 10) + rem;
    }

    // Print the binary number
    printf("%d in binary is %d\n", num, binary_num);
}

// Function to convert binary to decimal
void binary_to_decimal(int binary_num) {
    int decimal_num = 0, i = 0;

    // Iterate through all binary digits
    while (binary_num != 0) {
        decimal_num += (binary_num % 10) * pow(2, i);
        binary_num /= 10;
        i++;
    }

    // Print the decimal number
    printf("%d in decimal is %d\n", binary_num, decimal_num);
}

int main() {
    int num, binary_num;

    // Get the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Convert the decimal number to binary
    decimal_to_binary(num);

    // Get the binary number from the user
    printf("Enter a binary number: ");
    scanf("%d", &binary_num);

    // Convert the binary number to decimal
    binary_to_decimal(binary_num);

    return 0;
}