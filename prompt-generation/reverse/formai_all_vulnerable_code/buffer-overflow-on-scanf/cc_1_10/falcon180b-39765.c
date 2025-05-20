//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 32
#define MAX_HEX_DIGITS 8

void convert_hex_to_decimal(char hex[], int decimal[]);
void convert_decimal_to_hex(int decimal[], char hex[]);

int main() {

    char hex[MAX_HEX_LENGTH];
    int decimal[MAX_HEX_DIGITS];
    int hex_digits, decimal_digits;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_digits = strlen(hex);

    if (hex_digits > MAX_HEX_DIGITS) {
        printf("Error: Hexadecimal number is too long.\n");
        exit(1);
    }

    convert_hex_to_decimal(hex, decimal);

    decimal_digits = sprintf(NULL, "%d", decimal[0]);

    printf("Hexadecimal number: ");
    for (int i = 0; i < hex_digits; i++) {
        printf("%c", hex[i]);
    }

    printf("\nDecimal number: ");

    if (decimal_digits == 1) {
        printf("%d", decimal[0]);
    } else {
        printf("%d", decimal[0]);
        for (int i = 1; i < decimal_digits; i++) {
            printf("%09d", decimal[i]);
        }
    }

    printf("\n");

    return 0;
}

void convert_hex_to_decimal(char hex[], int decimal[]) {

    int hex_digits = strlen(hex);
    int decimal_digits = 0;

    for (int i = 0; i < hex_digits; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal[decimal_digits++] = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal[decimal_digits++] = hex[i] - 'A' + 10;
        } else {
            printf("Error: Invalid hexadecimal character.\n");
            exit(1);
        }
    }
}

void convert_decimal_to_hex(int decimal[], char hex[]) {

    int decimal_digits = 0;

    while (decimal[decimal_digits] == 0) {
        decimal_digits++;
    }

    for (int i = 0; i < decimal_digits; i++) {
        int remainder = decimal[i] % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder + 'A' - 10;
        }
    }
}