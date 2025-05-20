//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 32
#define MAX_CHAR_LENGTH 3

int main() {
    char input[MAX_HEX_LENGTH];
    char hex[MAX_HEX_LENGTH];
    char output[MAX_HEX_LENGTH];
    int len, i;
    int decimal = 0;
    int digit = 0;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_HEX_LENGTH, stdin);
    len = strlen(input);

    // remove white spaces and newline character
    for (i = 0; i < len; i++) {
        if (isspace(input[i]) || input[i] == '\n') {
            input[i] = '\0';
            len--;
        }
    }

    // check if input is a valid hexadecimal number
    for (i = 0; i < len; i++) {
        if (!isxdigit(input[i])) {
            printf("Error: Invalid hexadecimal number\n");
            return 1;
        }
    }

    // convert hexadecimal to decimal
    for (i = 0; i < len; i++) {
        if (isdigit(input[i])) {
            digit = input[i] - '0';
        } else {
            digit = toupper(input[i]) - 'A' + 10;
        }
        decimal = decimal * 16 + digit;
    }

    // convert decimal to hexadecimal
    sprintf(hex, "%X", decimal);

    // output result
    printf("Hexadecimal: %s\n", input);
    printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %s\n", hex);

    return 0;
}