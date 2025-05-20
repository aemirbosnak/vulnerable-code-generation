//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
    int len = strlen(hex);
    int base = 1;
    int val = 0;

    for (int i = len - 1; i >= 0; i--) {
        // Get the digit value
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else {
            return -1;  // Invalid hexadecimal digit
        }

        // Multiply the digit by the base and add it to the value
        val += digit * base;
        base *= 16;
    }

    return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int val) {
    // Allocate a buffer for the hexadecimal string
    char *hex = malloc(11);  // 10 digits + null terminator

    // Convert the integer to hexadecimal
    int i = 0;
    while (val > 0) {
        // Get the remainder
        int rem = val % 16;

        // Convert the remainder to a hexadecimal digit
        char digit;
        if (rem < 10) {
            digit = '0' + rem;
        } else {
            digit = 'a' + rem - 10;
        }

        // Add the digit to the hexadecimal string
        hex[i++] = digit;

        // Divide the integer by 16
        val /= 16;
    }

    // Reverse the hexadecimal string
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }

    // Add the null terminator
    hex[i] = '\0';

    return hex;
}

// Main function
int main() {
    // Get the hexadecimal string from the user
    char hex[101];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);

    // Convert the hexadecimal string to an integer
    int val = hex_to_int(hex);

    // Print the integer
    printf("The integer value of the hexadecimal string is: %d\n", val);

    // Convert the integer to a hexadecimal string
    char *hex_result = int_to_hex(val);

    // Print the hexadecimal string
    printf("The hexadecimal string of the integer is: %s\n", hex_result);

    // Free the allocated memory
    free(hex_result);

    return 0;
}