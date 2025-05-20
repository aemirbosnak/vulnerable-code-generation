//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_DIGITS 16

int main(int argc, char *argv[]) {
    char input_string[MAX_LENGTH];
    int input_length, i, decimal_value, binary_value, j;
    char binary_string[MAX_DIGITS];

    printf("Enter a decimal number: ");
    fgets(input_string, MAX_LENGTH, stdin);
    input_length = strlen(input_string);

    /* Remove leading/trailing whitespaces */
    for (i = 0; i < input_length; i++) {
        if (isspace(input_string[i])) {
            input_string[i] = '\0';
            input_length--;
        }
    }

    /* Convert decimal to binary */
    decimal_value = atoi(input_string);
    binary_value = 0;
    j = 0;

    while (decimal_value > 0) {
        binary_string[j++] = (decimal_value % 2) + '0';
        decimal_value /= 2;
    }

    /* Reverse the binary string */
    for (i = 0; i < j / 2; i++) {
        char temp = binary_string[i];
        binary_string[i] = binary_string[j - i - 1];
        binary_string[j - i - 1] = temp;
    }

    /* Add leading zeros to the binary string */
    for (i = 0; i < MAX_DIGITS - j; i++) {
        binary_string[i] = '0';
    }
    binary_string[MAX_DIGITS - 1] = '\0';

    printf("Binary representation: %s\n", binary_string);

    return 0;
}