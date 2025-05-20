//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIGITS 32

int is_valid_binary(char *binary_str) {
    int i;
    for (i = 0; binary_str[i]!= '\0'; i++) {
        if (!isdigit(binary_str[i])) {
            return 0;
        }
    }
    return 1;
}

int binary_to_decimal(char *binary_str) {
    int decimal = 0, i, j;
    for (i = strlen(binary_str) - 1, j = 0; i >= 0; i--, j++) {
        if (binary_str[i] == '1') {
            decimal += pow(2, j);
        }
    }
    return decimal;
}

void decimal_to_binary(int decimal) {
    char binary_str[MAX_DIGITS];
    int i = 0;
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binary_str[i++] = '1';
        } else {
            binary_str[i++] = '0';
        }
        decimal /= 2;
    }
    binary_str[i] = '\0';
    printf("%s\n", binary_str);
}

int main() {
    char input_str[MAX_DIGITS];
    printf("Enter a binary number: ");
    scanf("%s", input_str);

    if (!is_valid_binary(input_str)) {
        printf("Invalid binary number.\n");
        return 1;
    }

    int decimal = binary_to_decimal(input_str);
    printf("Decimal equivalent: %d\n", decimal);

    decimal_to_binary(decimal);

    return 0;
}