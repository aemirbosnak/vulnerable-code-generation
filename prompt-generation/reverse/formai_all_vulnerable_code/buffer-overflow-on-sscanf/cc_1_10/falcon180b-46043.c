//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    char input_string[MAX_LENGTH];
    char output_string[MAX_LENGTH];
    int input_length;
    int output_length;
    int i, j;
    int hex_value;
    int decimal_value;
    int binary_value;
    int octal_value;
    int color_type;

    // Prompt user for input string
    printf("Enter a color code (hex, decimal, binary, or octal): ");
    fgets(input_string, MAX_LENGTH, stdin);
    input_length = strlen(input_string);

    // Remove newline character from input string
    input_string[input_length - 1] = '\0';

    // Check if input string is hexadecimal
    if (strncmp(input_string, "0x", 2) == 0) {
        color_type = 1;
    } else if (strncmp(input_string, "0b", 2) == 0) {
        color_type = 2;
    } else if (strncmp(input_string, "0", 1) == 0) {
        color_type = 3;
    } else {
        color_type = 0;
    }

    // Convert input string to uppercase
    for (i = 0; i < input_length; i++) {
        input_string[i] = toupper(input_string[i]);
    }

    // Convert input string to decimal
    if (color_type == 0) {
        sscanf(input_string, "%d", &decimal_value);
        sprintf(output_string, "Decimal: %d", decimal_value);
    } else if (color_type == 1) {
        sscanf(input_string, "%x", &hex_value);
        sprintf(output_string, "Hexadecimal: %x", hex_value);
    } else if (color_type == 2) {
        sscanf(input_string, "%b", &binary_value);
        sprintf(output_string, "Binary: %b", binary_value);
    } else if (color_type == 3) {
        sscanf(input_string, "%o", &octal_value);
        sprintf(output_string, "Octal: %o", octal_value);
    }

    // Output result
    printf("%s\n", output_string);

    return 0;
}