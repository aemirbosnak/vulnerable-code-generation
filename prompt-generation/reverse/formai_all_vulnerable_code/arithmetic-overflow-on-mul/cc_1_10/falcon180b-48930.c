//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 100

void hex_to_decimal(char *hex, int *decimal) {
    int i = 0, j = 0, k = 0;
    while (hex[i]) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            *decimal = *decimal * 16 + (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            *decimal = *decimal * 16 + (hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            *decimal = *decimal * 16 + (hex[i] - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
        i++;
    }
}

void decimal_to_hex(int decimal, char *hex) {
    int i = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i++] = '0' + remainder;
        } else {
            hex[i++] = 'A' + remainder - 10;
        }
        decimal /= 16;
    }
    hex[i] = '\0';
}

int main() {
    char hex[MAX_HEX_LENGTH];
    int decimal;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_to_decimal(hex, &decimal);
    printf("Decimal representation: %d\n", decimal);

    decimal_to_hex(decimal, hex);
    printf("Hexadecimal representation: %s\n", hex);

    return 0;
}