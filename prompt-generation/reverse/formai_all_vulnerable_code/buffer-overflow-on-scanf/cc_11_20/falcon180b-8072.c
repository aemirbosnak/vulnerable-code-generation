//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 256
#define HEX_DIGITS "0123456789ABCDEF"
#define BIN_DIGITS "01"
#define OCT_DIGITS "01234567"
#define DEC_DIGITS "0123456789"

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE * 3];
    char *endptr;
    int input_size;
    int output_size;
    int base;

    // Prompt the user for input
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove the newline character at the end of the input
    input_size = strlen(input) - 1;
    input[input_size] = '\0';

    // Check if the input is valid hexadecimal
    for (int i = 0; i < input_size; i++) {
        if (!isxdigit(input[i])) {
            printf("Error: Invalid hexadecimal input.\n");
            return 1;
        }
    }

    // Prompt the user for the output base
    printf("Enter the output base (2 for binary, 8 for octal, 10 for decimal): ");
    scanf("%d", &base);

    // Convert the hexadecimal input to the output base
    output_size = 0;
    for (int i = 0; i < input_size; i++) {
        char digit = input[i];
        if (digit >= '0' && digit <= '9') {
            output[output_size] = digit;
            output_size++;
        } else {
            output[output_size] = tolower(digit);
            output_size++;
        }
    }
    output[output_size] = '\0';

    // Convert the output to the desired base
    switch (base) {
        case 2:
            for (int i = 0; i < output_size; i++) {
                char digit = output[i];
                if (digit >= '0' && digit <= '9') {
                    sprintf(&output[i], "%c", digit - '0');
                } else {
                    sprintf(&output[i], "%c", digit - 'A' + 10);
                }
            }
            break;
        case 8:
            for (int i = 0; i < output_size; i++) {
                char digit = output[i];
                if (digit >= '0' && digit <= '7') {
                    sprintf(&output[i], "%c", digit - '0');
                } else {
                    sprintf(&output[i], "%c", digit - 'A' + 8);
                }
            }
            break;
        case 10:
            for (int i = 0; i < output_size; i++) {
                char digit = output[i];
                if (digit >= '0' && digit <= '9') {
                    sprintf(&output[i], "%c", digit);
                } else {
                    sprintf(&output[i], "%c", digit - 'A' + 10);
                }
            }
            break;
        default:
            printf("Error: Invalid output base.\n");
            return 1;
    }

    // Print the output
    printf("Hexadecimal: %s\n", input);
    printf("Base %d: %s\n", base, output);

    return 0;
}