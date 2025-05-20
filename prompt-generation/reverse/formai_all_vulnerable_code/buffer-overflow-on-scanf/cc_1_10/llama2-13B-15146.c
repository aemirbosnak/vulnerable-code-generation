//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 1024

// Structure to hold the binary data
typedef struct {
    char data[MAX_INPUT_LENGTH];
    size_t len;
} binary_data_t;

// Function to convert decimal to binary
void decimal_to_binary(int dec, binary_data_t *binary) {
    size_t i = 0;
    while (dec != 0) {
        binary->data[i++] = dec % 2 == 0 ? '0' : '1';
        dec /= 2;
    }
    binary->len = i;
}

// Function to convert binary to decimal
int binary_to_decimal(const char *binary) {
    int dec = 0;
    size_t i = 0;
    while (binary[i] != '\0') {
        dec *= 2;
        if (binary[i] == '1') {
            dec += 1;
        }
        i++;
    }
    return dec;
}

int main() {
    // Example usage of the binary converter
    int dec = 42;
    binary_data_t binary;
    decimal_to_binary(dec, &binary);
    printf("Binary representation of %d: %s\n", dec, binary.data);

    // Convert binary back to decimal
    int new_dec = binary_to_decimal(binary.data);
    printf("Decimal representation of %s: %d\n", binary.data, new_dec);

    // Get user input and convert it to binary
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    binary.data[0] = '\0';
    decimal_to_binary(dec, &binary);
    printf("Binary representation of %d: %s\n", dec, binary.data);

    // Convert binary back to decimal and print the result
    new_dec = binary_to_decimal(binary.data);
    printf("Decimal representation of %s: %d\n", binary.data, new_dec);

    return 0;
}