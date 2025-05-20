//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

// Function to convert a single digit binary number to its decimal equivalent
int binary_to_decimal(int binary) {
    return binary < 10 ? binary : 10 * binary_to_decimal(binary / 2);
}

// Function to convert a binary string to a decimal number
int binary_string_to_decimal(const char *binary_string) {
    int decimal = 0;
    int length = 0;
    int binary = 0;

    while (binary_string[length] != '\0') {
        length++;
    }

    if (length > MAX_LENGTH) {
        printf("Error: Binary string too long.\n");
        exit(EXIT_FAILURE);
    }

    // Reverse the binary string for easy conversion
    for (int i = 0; i < length; i++) {
        binary = binary * 10 + (binary_string[length - i - 1] - '0');
    }

    decimal = binary_to_decimal(binary);

    return decimal;
}

int main() {
    char binary_string[MAX_LENGTH];

    printf("Enter a binary number: ");
    fgets(binary_string, MAX_LENGTH, stdin);

    // Remove the newline character added by fgets
    binary_string[strcspn(binary_string, "\n")] = '\0';

    int decimal = binary_string_to_decimal(binary_string);

    if (decimal == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return EXIT_SUCCESS;
}