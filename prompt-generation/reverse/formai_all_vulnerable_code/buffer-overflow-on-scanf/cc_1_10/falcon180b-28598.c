//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_HEX_LENGTH 100

typedef struct {
    char hex[MAX_HEX_LENGTH];
    int decimal;
} hex_decimal;

void hex_to_decimal(char *hex, int *decimal) {
    int i = 0, j = strlen(hex) - 1;
    int power = 0;
    *decimal = 0;

    while (i <= j) {
        if (isdigit(hex[i])) {
            *decimal += (hex[i] - '0') * pow(16, power);
        } else if (isalpha(hex[i])) {
            if (isupper(hex[i])) {
                *decimal += (hex[i] - 'A') + 10;
            } else {
                *decimal += (hex[i] - 'a') + 10;
            }
        } else {
            printf("Invalid hexadecimal character '%c'\n", hex[i]);
            exit(1);
        }
        i++;
        power++;
    }
}

void decimal_to_hex(int decimal, char *hex) {
    int i = 0, j = 0;
    while (decimal > 0) {
        int digit = decimal % 16;
        if (digit < 10) {
            hex[j++] = digit + '0';
        } else {
            hex[j++] = digit + 'A' - 10;
        }
        decimal /= 16;
    }
    hex[j] = '\0';
    for (i = 0; i < j / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[j - i - 1];
        hex[j - i - 1] = temp;
        i++;
        j--;
    }
}

int main() {
    char hex[MAX_HEX_LENGTH];
    int decimal;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_to_decimal(hex, &decimal);
    printf("Decimal equivalent: %d\n", decimal);

    decimal_to_hex(decimal, hex);
    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}