//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 300

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];
    int i, j, input_length, output_length;
    int decimal_value, hexadecimal_value;
    char hexadecimal_digit;
    
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input_length = strlen(input);
    
    // Remove leading and trailing whitespace
    input[input_length-1] = '\0';
    for (i = 0; i < input_length; i++) {
        if (isspace(input[i])) {
            input[i] = '\0';
        }
    }
    
    // Convert hexadecimal to decimal
    decimal_value = 0;
    for (i = input_length-1; i >= 0; i--) {
        if (isxdigit(input[i])) {
            hexadecimal_value = 0;
            if (isdigit(input[i])) {
                hexadecimal_value = input[i] - '0';
            } else {
                hexadecimal_value = input[i] - 'A' + 10;
            }
            decimal_value += hexadecimal_value * pow(16, input_length-1-i);
        } else {
            printf("Invalid hexadecimal number\n");
            return 1;
        }
    }
    
    // Convert decimal to hexadecimal
    output[output_length-1] = '\0';
    for (i = 0; i < MAX_OUTPUT_LENGTH-1; i++) {
        output[i] = '\0';
    }
    output_length = 0;
    while (decimal_value > 0) {
        hexadecimal_value = decimal_value % 16;
        if (hexadecimal_value < 10) {
            hexadecimal_digit = hexadecimal_value + '0';
        } else {
            hexadecimal_digit = hexadecimal_value + 'A' - 10;
        }
        output[output_length] = hexadecimal_digit;
        output_length++;
        decimal_value /= 16;
    }
    
    printf("Hexadecimal number: %s\n", output);
    
    return 0;
}