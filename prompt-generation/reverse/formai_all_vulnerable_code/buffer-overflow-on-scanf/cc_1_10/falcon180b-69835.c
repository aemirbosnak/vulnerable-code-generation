//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a decimal number to hexadecimal
char *decimal_to_hex(int decimal) {
    char hex[100];
    int i, j = 0;
    char *result = malloc(100 * sizeof(char));

    if (decimal == 0) {
        strcpy(result, "0");
        return result;
    }

    sprintf(hex, "%x", decimal);

    for (i = strlen(hex) - 1; i >= 0; i--) {
        result[j++] = hex[i];
    }
    result[j] = '\0';

    return result;
}

// Function to convert a hexadecimal number to decimal
int hex_to_decimal(char *hex) {
    int decimal = 0, i = 0;

    while (hex[i]) {
        if (isdigit(hex[i])) {
            decimal = decimal * 16 + hex[i] - '0';
        } else if (isupper(hex[i])) {
            decimal = decimal * 16 + hex[i] - 'A' + 10;
        } else if (islower(hex[i])) {
            decimal = decimal * 16 + hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
        i++;
    }

    return decimal;
}

int main() {
    char input[100];
    char *result;
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    decimal = atoi(input);
    result = decimal_to_hex(decimal);

    printf("Hexadecimal representation: %s\n", result);

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    decimal = hex_to_decimal(input);

    printf("Decimal representation: %d\n", decimal);

    return 0;
}