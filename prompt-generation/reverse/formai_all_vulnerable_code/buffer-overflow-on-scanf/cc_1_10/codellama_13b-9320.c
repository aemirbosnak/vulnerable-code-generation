//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
/*
 * C Hexadecimal Converter Example Program
 *
 * This program takes a hexadecimal number as input and converts it to its decimal equivalent.
 * It then prints the decimal equivalent to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char *hex_string) {
    int decimal = 0, i, len;

    // Get the length of the hexadecimal string
    len = strlen(hex_string);

    // Iterate over the characters of the hexadecimal string
    for (i = 0; i < len; i++) {
        // If the character is a digit, add its value to the decimal equivalent
        if (hex_string[i] >= '0' && hex_string[i] <= '9') {
            decimal += (hex_string[i] - '0') * (int)pow(16, len - i - 1);
        }
        // If the character is a letter, add its value to the decimal equivalent
        else if (hex_string[i] >= 'A' && hex_string[i] <= 'F') {
            decimal += (hex_string[i] - 'A' + 10) * (int)pow(16, len - i - 1);
        }
        else if (hex_string[i] >= 'a' && hex_string[i] <= 'f') {
            decimal += (hex_string[i] - 'a' + 10) * (int)pow(16, len - i - 1);
        }
    }

    return decimal;
}

int main() {
    char hex_string[100];
    int decimal;

    // Get the hexadecimal string from the user
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_string);

    // Convert the hexadecimal string to its decimal equivalent
    decimal = hex_to_dec(hex_string);

    // Print the decimal equivalent to the console
    printf("The decimal equivalent of %s is %d\n", hex_string, decimal);

    return 0;
}