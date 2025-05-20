//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void hex_to_decimal(char *hex, int base, int *decimal) {
    int i = strlen(hex) - 1;
    int j = 0;
    int value = 0;
    while (i >= 0) {
        if (isdigit(hex[i])) {
            value += (hex[i] - '0') * base;
        } else if (isupper(hex[i])) {
            value += (hex[i] - 'A' + 10) * base;
        } else {
            value += (hex[i] - 'a' + 10) * base;
        }
        i--;
        base *= 16;
    }
    *decimal = value;
}

void decimal_to_hex(int decimal, char *hex, int base) {
    char temp[MAX_LENGTH];
    int i = 0;
    while (decimal > 0) {
        if (decimal % 16 < 10) {
            sprintf(temp, "%d", decimal % 16);
        } else {
            sprintf(temp, "%c", decimal % 16 + 'A' - 10);
        }
        strcat(hex, temp);
        decimal /= 16;
    }
}

int main() {
    char hex_str[MAX_LENGTH];
    int decimal;
    int base = 10;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);
    hex_to_decimal(hex_str, base, &decimal);
    printf("The decimal equivalent of %s is %d\n", hex_str, decimal);
    printf("Enter the base you want to convert to: ");
    scanf("%d", &base);
    decimal_to_hex(decimal, hex_str, base);
    printf("The %d-base equivalent of %d is %s\n", base, decimal, hex_str);
    return 0;
}