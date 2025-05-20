//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal number to an integer
int hex_to_int(char *hex) {
    int i, len, decimal = 0;
    len = strlen(hex);

    // Iterate over the hexadecimal number from right to left
    for (i = 0; i < len; i++) {
        // Get the digit value of the current character
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else {
            // Invalid hexadecimal digit, return -1 to indicate error
            return -1;
        }

        // Multiply the digit by the corresponding power of 16 and add to the decimal value
        decimal += digit * (1 << (4 * (len - i - 1)));
    }

    return decimal;
}

// Function to convert an integer to a hexadecimal number
char *int_to_hex(int decimal) {
    char *hex;
    int i = 0, temp = decimal;

    // Count the number of hexadecimal digits required
    while (temp > 0) {
        i++;
        temp /= 16;
    }

    // Allocate memory for the hexadecimal number
    hex = (char *) malloc(i + 1);
    if (hex == NULL) {
        return NULL; // Error allocating memory
    }

    // Iterate over the hexadecimal number from right to left
    while (decimal > 0) {
        int digit = decimal % 16;

        // Convert the digit to a hexadecimal character
        if (digit >= 0 && digit <= 9) {
            hex[i - 1] = digit + '0';
        } else {
            hex[i - 1] = digit - 10 + 'A';
        }

        // Divide the decimal number by 16 to get the next digit
        decimal /= 16;
        i--;
    }
    hex[i] = '\0'; // Null-terminate the hexadecimal number

    return hex;
}

int main() {
    // Get the hexadecimal number from the user
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert the hexadecimal number to an integer
    int decimal = hex_to_int(hex);
    if (decimal == -1) {
        printf("Invalid hexadecimal number\n");
        return -1;
    }

    // Print the integer
    printf("Integer: %d\n", decimal);

    // Convert the integer back to a hexadecimal number
    char *hex_result = int_to_hex(decimal);
    if (hex_result == NULL) {
        printf("Error converting integer to hexadecimal\n");
        return -1;
    }

    // Print the hexadecimal number
    printf("Hexadecimal: %s\n", hex_result);

    // Free the allocated memory
    free(hex_result);

    return 0;
}