//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_DIGITS "0123456789abcdef"
#define HEX_DIGIT_COUNT 16

void hex_to_decimal(char* hex_str, int* decimal_num) {
    int hex_num = 0, i = 0;
    while (hex_str[i]) {
        int digit = hex_str[i] - '0';
        if (digit < 0 || digit > 9) {
            digit = hex_str[i] - 'a' + 10;
        }
        hex_num = (hex_num << 4) | digit;
        i++;
    }
    *decimal_num = hex_num;
}

void decimal_to_hex(int decimal_num, char* hex_str) {
    char hex_digits[HEX_DIGIT_COUNT + 1] = {0};
    int i = 0, j = 0;
    while (decimal_num > 0) {
        int digit = decimal_num % 16;
        if (digit < 10) {
            hex_digits[i++] = digit + '0';
        } else {
            hex_digits[i++] = digit + 'a' - 10;
        }
        decimal_num /= 16;
    }
    for (int k = i - 1; k >= 0; k--) {
        hex_str[j++] = hex_digits[k];
    }
    hex_str[j] = '\0';
}

int main() {
    char hex_str[HEX_DIGIT_COUNT + 1] = {0};
    int decimal_num = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    hex_to_decimal(hex_str, &decimal_num);
    printf("Decimal representation: %d\n", decimal_num);

    decimal_to_hex(decimal_num, hex_str);
    printf("Hexadecimal representation: %s\n", hex_str);

    return 0;
}