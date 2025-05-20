//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

int is_valid_hex_digit(char c) {
    return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int i, j;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Check if input is empty
    if (input[0] == '\0') {
        printf("Error: Input is empty.\n");
        return 1;
    }

    // Check if input contains only hexadecimal digits
    for (i = 0; i < strlen(input); i++) {
        if (!is_valid_hex_digit(input[i])) {
            printf("Error: Input contains invalid characters.\n");
            return 1;
        }
    }

    // Convert hexadecimal to decimal
    int decimal = 0;
    for (i = strlen(input) - 1, j = 0; i >= 0; i--, j++) {
        if (input[i] >= '0' && input[i] <= '9') {
            decimal += input[i] - '0';
        } else if (input[i] >= 'A' && input[i] <= 'F') {
            decimal += input[i] - 'A' + 10;
        } else if (input[i] >= 'a' && input[i] <= 'f') {
            decimal += input[i] - 'a' + 10;
        } else {
            printf("Error: Input contains invalid characters.\n");
            return 1;
        }
        decimal *= 16;
    }

    // Print result
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}