//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a given character is a valid binary digit (0 or 1)
bool is_valid_binary_digit(char c) {
    return (c == '0' || c == '1');
}

// Function to convert binary string to decimal number
int binary_to_decimal(char* binary_string) {
    int decimal = 0;
    int power = 0;

    // Iterate through each character in the binary string
    for (int i = strlen(binary_string) - 1; i >= 0; i--) {
        if (!is_valid_binary_digit(binary_string[i])) {
            fprintf(stderr, "Error: Invalid binary string\n");
            exit(EXIT_FAILURE);
        }

        // Calculate the decimal value of the current digit based on its position
        decimal += (is_valid_binary_digit(binary_string[i]) ? pow(2, power) : 0);
        power++;
    }

    return decimal;
}

// Function to print the binary representation of a decimal number
void decimal_to_binary(int decimal) {
    int remainder;
    int power = 0;

    // Keep dividing the decimal number by 2 and print the remainder until the quotient is 0
    do {
        remainder = decimal % 2;
        decimal /= 2;
        printf("%d", remainder);
        power++;
    } while (decimal != 0);

    // Print the leading bit (1) and add a 'b' prefix for artistic touch
    printf("b%d", power + 1);
}

// Main function
int main() {
    char binary_string[100];
    int decimal;

    printf("Welcome to the Binary Ballerina!\n");
    printf("A graceful dance of numbers, where 0s and 1s waltz in harmony.\n");
    printf("Please enter a binary string: ");
    scanf("%s", binary_string);

    // Call the binary to decimal converter function
    decimal = binary_to_decimal(binary_string);

    // Print the decimal equivalent with artistic flair
    printf("\nThe enchanting binary string, %s, transforms into the decimal number:\n", binary_string);
    printf("%d\n", decimal);

    // Call the decimal to binary converter function for added effect
    printf("\nAnd now, a mesmerizing transformation unfolds...\n");
    printf("The elegant decimal number, %d, gracefully becomes the captivating binary number:\n", decimal);
    decimal_to_binary(decimal);
    printf("\n");

    return 0;
}