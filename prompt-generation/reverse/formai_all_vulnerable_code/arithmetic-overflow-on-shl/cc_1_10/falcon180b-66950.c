//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter a hexadecimal number (max %d characters): ", MAX_INPUT_SIZE - 1);
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove the newline character at the end of the input string
    input[strcspn(input, "\n")] = '\0';

    // Check if the input string is empty or contains only whitespace
    if (strspn(input, " \t\n\r\f\v") == strlen(input)) {
        printf("Empty input.\n");
        return 1;
    }

    // Convert the input string to uppercase
    for (int i = 0; input[i]!= '\0'; i++) {
        input[i] = toupper(input[i]);
    }

    // Validate the input string as a hexadecimal number
    int is_valid = 1;
    for (int i = 0; input[i]!= '\0'; i++) {
        if (!isxdigit(input[i])) {
            is_valid = 0;
            break;
        }
    }

    if (!is_valid) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert the hexadecimal number to decimal
    int decimal = 0;
    for (int i = strlen(input) - 1; i >= 0; i--) {
        char c = input[i];
        if (isdigit(c)) {
            decimal += c - '0';
        } else {
            decimal += c - 'A' + 10;
        }
        decimal <<= 4;
    }

    printf("Hexadecimal: %s\nDecimal: %d\n", input, decimal);

    return 0;
}