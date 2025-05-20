//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int hexadecimal_to_decimal(char *hex) {
    int decimal = 0;
    int i = 0;
    while (hex[i]!= '\0') {
        if (isdigit(hex[i])) {
            decimal = decimal * 16 + hex[i] - '0';
        } else {
            switch (hex[i]) {
                case 'A':
                    decimal = decimal * 16 + 10;
                    break;
                case 'B':
                    decimal = decimal * 16 + 11;
                    break;
                case 'C':
                    decimal = decimal * 16 + 12;
                    break;
                case 'D':
                    decimal = decimal * 16 + 13;
                    break;
                case 'E':
                    decimal = decimal * 16 + 14;
                    break;
                case 'F':
                    decimal = decimal * 16 + 15;
                    break;
            }
        }
        i++;
    }
    return decimal;
}

int decimal_to_hexadecimal(int decimal, char *hex) {
    int i = 0;
    while (decimal > 0) {
        int digit = decimal % 16;
        if (digit < 10) {
            hex[i] = digit + '0';
        } else {
            hex[i] = digit + 'A' - 10;
        }
        i++;
        decimal /= 16;
    }
    hex[i] = '\0';
    return i;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hexadecimal_number>\n", argv[0]);
        return 1;
    }

    char hex[MAX_LENGTH];
    strcpy(hex, argv[1]);

    int decimal = hexadecimal_to_decimal(hex);
    char hex_decimal[MAX_LENGTH];
    int hex_decimal_length = decimal_to_hexadecimal(decimal, hex_decimal);

    printf("Decimal value of %s is %d\n", hex, decimal);
    printf("Hexadecimal value of %d is %s\n", decimal, hex_decimal);

    return 0;
}