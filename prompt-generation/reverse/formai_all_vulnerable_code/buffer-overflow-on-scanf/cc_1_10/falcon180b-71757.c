//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *binary_to_decimal(char *binary) {
    int decimal = 0, i = 0;

    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal += pow(2, strlen(binary) - i - 1);
        }
        i++;
    }

    char *decimal_str = malloc(12);
    sprintf(decimal_str, "%d", decimal);

    return decimal_str;
}

char *decimal_to_binary(int decimal) {
    char *binary = malloc(33);
    int i = 0, j = 0;

    while (decimal!= 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    while (i < 32) {
        binary[i++] = '0';
    }

    binary[i] = '\0';

    return binary;
}

int main() {
    char *binary_str, *decimal_str;

    printf("Enter a binary number: ");
    scanf("%s", binary_str);

    decimal_str = binary_to_decimal(binary_str);
    printf("Decimal equivalent: %s\n", decimal_str);

    free(decimal_str);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_str);

    binary_str = decimal_to_binary(decimal_str);
    printf("Binary equivalent: %s\n", binary_str);

    free(binary_str);

    return 0;
}