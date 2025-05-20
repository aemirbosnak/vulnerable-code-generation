//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000000 // maximum size of input string

int is_hexadecimal(char c) {
    if (isdigit(c)) {
        return 1;
    } else if (c >= 'A' && c <= 'F') {
        return 1;
    } else if (c >= 'a' && c <= 'f') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[MAX_SIZE];
    int i = 0;
    int hex_value = 0;
    int decimal_value = 0;
    int j = 0;
    int length = 0;
    char *output = (char*) malloc(MAX_SIZE * sizeof(char));

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_SIZE, stdin);
    length = strlen(input);

    // remove newline character
    input[length - 1] = '\0';

    // check if input is hexadecimal
    for (i = 0; i < length; i++) {
        if (!is_hexadecimal(input[i])) {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            exit(1);
        }
    }

    // convert hexadecimal to decimal
    for (i = 0; i < length; i++) {
        if (isdigit(input[i])) {
            decimal_value += input[i] - '0';
        } else {
            hex_value = input[i] - 'A' + 10;
            if (hex_value < 0 || hex_value > 15) {
                printf("Invalid input. Please enter a valid hexadecimal number.\n");
                exit(1);
            }
            decimal_value += hex_value;
        }
    }

    // convert decimal to hexadecimal
    while (decimal_value > 0) {
        j++;
        if (decimal_value % 16 < 10) {
            output[j - 1] = decimal_value % 16 + '0';
        } else {
            output[j - 1] = decimal_value % 16 + 'A' - 10;
        }
        decimal_value /= 16;
    }

    // print output
    printf("Hexadecimal: %s\n", input);
    printf("Decimal: %s\n", output);

    free(output);
    return 0;
}