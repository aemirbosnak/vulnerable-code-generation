//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_STRING_LENGTH 100

// Define the hexadecimal digits.
char hex_digits[] = "0123456789ABCDEF";

// Define the function to convert a hexadecimal string to an integer.
int hex_to_int(char *hex_string) {
    int value = 0;
    int i;
    int length = strlen(hex_string);

    // Iterate over the hexadecimal string.
    for (i = 0; i < length; i++) {
        // Get the index of the current character in the hexadecimal digits array.
        int index = strchr(hex_digits, hex_string[i]) - hex_digits;

        // Shift the value left by 4 bits.
        value = value << 4;

        // Add the value of the current character to the total value.
        value = value + index;
    }

    // Return the total value.
    return value;
}

// Define the function to convert an integer to a hexadecimal string.
char *int_to_hex(int value) {
    char *hex_string = malloc(MAX_STRING_LENGTH);
    int i = 0;

    // Iterate until the value is 0.
    while (value > 0) {
        // Get the remainder of the value when divided by 16.
        int remainder = value % 16;

        // Convert the remainder to a hexadecimal digit.
        hex_string[i] = hex_digits[remainder];

        // Increment the index.
        i++;

        // Divide the value by 16.
        value = value / 16;
    }

    // Reverse the hexadecimal string.
    for (i = 0; i < strlen(hex_string) / 2; i++) {
        char temp = hex_string[i];
        hex_string[i] = hex_string[strlen(hex_string) - i - 1];
        hex_string[strlen(hex_string) - i - 1] = temp;
    }

    // Return the hexadecimal string.
    return hex_string;
}

// Define the main function.
int main() {
    // Get the input string from the user.
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a hexadecimal string: ");
    scanf("%s", input_string);

    // Convert the hexadecimal string to an integer.
    int value = hex_to_int(input_string);

    // Convert the integer to a hexadecimal string.
    char *hex_string = int_to_hex(value);

    // Print the hexadecimal string.
    printf("The hexadecimal string is: %s\n", hex_string);

    // Free the memory allocated for the hexadecimal string.
    free(hex_string);

    return 0;
}