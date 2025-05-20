//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Function to convert a decimal number to binary
char* dec_to_bin(int dec) {
    char* bin = malloc(sizeof(char) * 33);
    int i = 31;
    while (dec > 0) {
        bin[i--] = (dec % 2) + '0';
        dec /= 2;
    }
    bin[32] = '\0';
    return bin;
}

// Function to convert a binary number to decimal
int bin_to_dec(char* bin) {
    int dec = 0;
    int len = strlen(bin);
    for (int i = 0; i < len; i++) {
        dec += (bin[i] - '0') * (1 << (len - i - 1));
    }
    return dec;
}

int main() {
    // Get the decimal number from the user
    int dec;
    printf("Enter a decimal number: ");
    scanf("%d", &dec);

    // Convert the decimal number to binary
    char* bin = dec_to_bin(dec);

    // Print the binary representation
    printf("Binary representation: %s\n", bin);

    // Convert the binary number back to decimal
    int dec2 = bin_to_dec(bin);

    // Print the converted decimal number
    printf("Decimal representation: %d\n", dec2);

    // Free the allocated memory
    free(bin);

    return 0;
}