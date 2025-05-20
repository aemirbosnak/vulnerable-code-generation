//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20

void validate_input(const char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i]) && (input[i] < 'a' || input[i] > 'f') && (input[i] < 'A' || input[i] > 'F')) {
            fprintf(stderr, "Error: Invalid character '%c' detected in input.\n", input[i]);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

int hex_to_dec(const char *hex) {
    int decimal_value = 0;
    int base = 1; // Base 16^0 

    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            decimal_value += (hex[i] - '0') * base;
        } else if (tolower(hex[i]) >= 'a' && tolower(hex[i]) <= 'f') {
            decimal_value += (tolower(hex[i]) - 'a' + 10) * base;
        }
        base *= 16; // Increment base to the next power of 16
    }
    return decimal_value;
}

void display_conversion(const char *hex, int decimal) {
    printf("The hexadecimal number %s converts to decimal: %d\n", hex, decimal);
}

void prompt_user() {
    printf("Hello, paranoid user! Please enter a hexadecimal number to convert (up to %d characters): ", MAX_LENGTH);
}

int main() {
    char hex_input[MAX_LENGTH + 1];

    // Obtain input from the user
    prompt_user();
    if (fgets(hex_input, sizeof(hex_input), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read input. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    // Remove newline character if present
    hex_input[strcspn(hex_input, "\n")] = 0;

    // Validate the hexadecimal input
    validate_input(hex_input);

    // Convert hex to decimal
    int decimal_value = hex_to_dec(hex_input);
    
    // Display the conversion result
    display_conversion(hex_input, decimal_value);

    return 0;
}