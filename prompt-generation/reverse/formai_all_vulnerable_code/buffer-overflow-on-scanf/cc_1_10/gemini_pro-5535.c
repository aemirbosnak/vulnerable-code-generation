//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_DIGITS 100

// Function to convert a hexadecimal number to an integer
int hex_to_int(const char *hex) {
    int len = strlen(hex);
    int base = 1;
    int value = 0;
    for (int i = len - 1; i >= 0; i--) {
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else {
            // Invalid hexadecimal digit
            return -1;
        }
        value += digit * base;
        base *= 16;
    }
    return value;
}

// Function to convert an integer to a hexadecimal number
char *int_to_hex(int num) {
    char *hex = malloc(MAX_HEX_DIGITS + 1);
    int i = 0;
    while (num > 0) {
        int digit = num % 16;
        if (digit < 10) {
            hex[i++] = '0' + digit;
        } else {
            hex[i++] = 'A' + digit - 10;
        }
        num /= 16;
    }
    hex[i] = '\0';
    return hex;
}

int main() {
    // Get the hexadecimal number from the user
    char hex[MAX_HEX_DIGITS + 1];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert the hexadecimal number to an integer
    int num = hex_to_int(hex);
    if (num == -1) {
        printf("Invalid hexadecimal number\n");
        return 1;
    }

    // Convert the integer to a hexadecimal number
    char *hex_result = int_to_hex(num);

    // Print the result
    printf("The hexadecimal number is: %s\n", hex_result);

    // Free the allocated memory
    free(hex_result);

    return 0;
}