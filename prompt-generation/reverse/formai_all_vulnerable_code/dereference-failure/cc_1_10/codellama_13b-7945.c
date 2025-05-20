//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex_str) {
    int i, len, val = 0;

    // Get the length of the hexadecimal string
    len = strlen(hex_str);

    // Iterate over each character of the hexadecimal string
    for (i = 0; i < len; i++) {
        // Get the current character and convert it to its integer equivalent
        int c = hex_str[i];
        if (c >= '0' && c <= '9') {
            val = (val * 16) + (c - '0');
        } else if (c >= 'a' && c <= 'f') {
            val = (val * 16) + (c - 'a' + 10);
        } else if (c >= 'A' && c <= 'F') {
            val = (val * 16) + (c - 'A' + 10);
        }
    }

    return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int val) {
    char *hex_str = malloc(11 * sizeof(char));
    int i, len = 0;

    // Iterate over each digit of the integer
    for (i = 0; val != 0; i++) {
        // Get the current digit and convert it to its hexadecimal equivalent
        int c = val % 16;
        if (c < 10) {
            hex_str[i] = c + '0';
        } else {
            hex_str[i] = c - 10 + 'a';
        }

        // Update the length of the hexadecimal string
        len++;

        // Update the value of the integer
        val /= 16;
    }

    // Add a null terminator to the end of the hexadecimal string
    hex_str[len] = '\0';

    return hex_str;
}

int main() {
    char *hex_str = "ff";
    int val = hex_to_int(hex_str);
    printf("Hexadecimal value: %s\n", hex_str);
    printf("Integer value: %d\n", val);

    int new_val = 255;
    char *new_hex_str = int_to_hex(new_val);
    printf("Hexadecimal value: %s\n", new_hex_str);
    printf("Integer value: %d\n", new_val);

    return 0;
}