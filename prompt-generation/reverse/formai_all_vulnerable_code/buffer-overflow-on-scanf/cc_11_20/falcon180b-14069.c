//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HEX_LENGTH 8

int main(void) {
    char hex_string[MAX_HEX_LENGTH + 1] = {0};
    char decimal_string[100];
    int decimal_num, i, j;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_string);

    // Check if the input string is a valid hexadecimal number
    for (i = 0; i < strlen(hex_string); i++) {
        if (!isxdigit(hex_string[i])) {
            printf("Invalid hexadecimal number.\n");
            return 1;
        }
    }

    // Convert hexadecimal to decimal
    decimal_num = 0;
    for (i = strlen(hex_string) - 1, j = 0; i >= 0; i--, j++) {
        if (hex_string[i] >= '0' && hex_string[i] <= '9') {
            decimal_num += hex_string[i] - '0';
        } else if (hex_string[i] >= 'A' && hex_string[i] <= 'F') {
            decimal_num += hex_string[i] - 'A' + 10;
        } else if (hex_string[i] >= 'a' && hex_string[i] <= 'f') {
            decimal_num += hex_string[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal number.\n");
            return 1;
        }
        decimal_num *= 16;
    }

    // Convert decimal to hexadecimal
    sprintf(decimal_string, "%d", decimal_num);
    for (i = strlen(decimal_string) - 1, j = 0; i >= 0; i--, j++) {
        if (decimal_string[i] == '0') {
            sprintf(&decimal_string[i], "%c", '0');
        } else {
            sprintf(&decimal_string[i], "%c", 'A' + decimal_string[i] - 10);
        }
    }

    printf("Hexadecimal number: %s\n", hex_string);
    printf("Decimal number: %s\n", decimal_string);

    return 0;
}