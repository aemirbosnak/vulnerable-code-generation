//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH * 2)

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];
    int input_length;
    int output_length;
    bool is_valid_input = true;

    // Get input from user
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input_length = strlen(input);

    // Validate input
    for (int i = 0; i < input_length; i++) {
        if (!isxdigit(input[i])) {
            is_valid_input = false;
            break;
        }
    }

    if (!is_valid_input) {
        printf("Invalid input! Please enter a valid hexadecimal number.\n");
        return 1;
    }

    // Convert input to decimal
    int decimal = 0;
    for (int i = 0; i < input_length; i++) {
        if (isdigit(input[i])) {
            decimal = decimal * 16 + input[i] - '0';
        } else {
            decimal = decimal * 16 + toupper(input[i]) - 'A' + 10;
        }
    }

    // Convert decimal to binary
    char binary[MAX_OUTPUT_LENGTH];
    int binary_length = 0;
    while (decimal > 0) {
        binary[binary_length] = (decimal % 2) + '0';
        decimal /= 2;
        binary_length++;
    }

    // Reverse binary string
    for (int i = 0; i < binary_length / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[binary_length - i - 1];
        binary[binary_length - i - 1] = temp;
    }

    // Convert binary to hexadecimal
    for (int i = 0; i < binary_length; i += 4) {
        output[output_length++] = (i / 4 == 0? '0' : 'A') + (binary[i] - '0');
    }

    // Add leading zeros if necessary
    while (output_length < MAX_OUTPUT_LENGTH) {
        output[output_length++] = '0';
    }

    // Print result
    printf("Hexadecimal: %s\n", output);

    return 0;
}