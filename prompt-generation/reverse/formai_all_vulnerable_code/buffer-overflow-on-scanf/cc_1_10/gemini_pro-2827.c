//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a binary string to an integer
int binary_to_integer(char *binary_string) {
    int length = strlen(binary_string);
    int integer = 0;
    for (int i = 0; i < length; i++) {
        if (binary_string[i] == '1') {
            integer += (1 << (length - i - 1));
        }
    }
    return integer;
}

// Function to convert an integer to a binary string
char *integer_to_binary(int integer) {
    char *binary_string = malloc(33);
    int index = 0;
    while (integer > 0) {
        if (integer % 2 == 0) {
            binary_string[index] = '0';
        } else {
            binary_string[index] = '1';
        }
        integer /= 2;
        index++;
    }
    binary_string[index] = '\0';
    return binary_string;
}

// Main function
int main() {
    // Get the binary string from the user
    char binary_string[33];
    printf("Enter a binary string: ");
    scanf("%s", binary_string);

    // Convert the binary string to an integer
    int integer = binary_to_integer(binary_string);

    // Print the integer
    printf("The integer equivalent of %s is %d\n", binary_string, integer);

    // Convert the integer to a binary string
    char *new_binary_string = integer_to_binary(integer);

    // Print the binary string
    printf("The binary equivalent of %d is %s\n", integer, new_binary_string);

    // Free the allocated memory
    free(new_binary_string);

    return 0;
}