//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 100

int main() {
    char input[MAX_HEX_LENGTH];
    char hex_output[MAX_HEX_LENGTH * 2];
    int decimal_output = 0;
    int i = 0;
    int j = 0;
    int input_length = 0;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_HEX_LENGTH, stdin);

    // Remove newline character from input
    input_length = strlen(input);
    input[input_length - 1] = '\0';

    // Check if input is a valid hexadecimal number
    for (i = 0; i < input_length; i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid hexadecimal number\n");
            return 0;
        }
    }

    // Convert hexadecimal to decimal
    for (i = 0; i < input_length; i++) {
        if (isdigit(input[i])) {
            decimal_output += (input[i] - '0');
        } else {
            if (input[i] >= 'A' && input[i] <= 'F') {
                decimal_output += (input[i] - 'A' + 10);
            } else if (input[i] >= 'a' && input[i] <= 'f') {
                decimal_output += (input[i] - 'a' + 10);
            } else {
                printf("Invalid hexadecimal number\n");
                return 0;
            }
        }
    }

    // Convert decimal to hexadecimal
    sprintf(hex_output, "0x%X", decimal_output);

    // Print output
    printf("Hexadecimal number: %s\n", hex_output);

    return 0;
}