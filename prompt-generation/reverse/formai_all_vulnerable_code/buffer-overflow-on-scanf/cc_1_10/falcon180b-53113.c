//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_STR_LEN 1000

void hex_to_decimal(char *hex_str, int *decimal_num) {
    int len = strlen(hex_str);
    int i = 0;
    int decimal_val = 0;

    *decimal_num = 0;

    while (i < len) {
        if (isdigit(hex_str[i])) {
            decimal_val = decimal_val * 16 + (hex_str[i] - '0');
        } else if (isupper(hex_str[i])) {
            decimal_val = decimal_val * 16 + (hex_str[i] - 'A' + 10);
        } else if (islower(hex_str[i])) {
            decimal_val = decimal_val * 16 + (hex_str[i] - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", hex_str[i]);
            exit(1);
        }

        if (decimal_val > 0xFFFFFFFF) {
            printf("Decimal value too large: %d\n", decimal_val);
            exit(1);
        }

        i++;
    }

    *decimal_num = decimal_val;
}

void decimal_to_hex(int decimal_num, char *hex_str) {
    char buffer[MAX_HEX_STR_LEN];
    int len = 0;

    sprintf(buffer, "%X", decimal_num);
    strcpy(hex_str, buffer);
}

int main() {
    char hex_str[MAX_HEX_STR_LEN];
    int decimal_num;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    hex_to_decimal(hex_str, &decimal_num);

    printf("Decimal value: %d\n", decimal_num);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    decimal_to_hex(decimal_num, hex_str);

    printf("Hexadecimal value: %s\n", hex_str);

    return 0;
}