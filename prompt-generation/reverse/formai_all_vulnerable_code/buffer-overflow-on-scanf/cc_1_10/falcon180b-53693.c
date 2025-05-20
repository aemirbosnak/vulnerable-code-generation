//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_HEX_LENGTH 100

void hex_to_decimal(char *hex, int *decimal) {
    int i, j, value = 0;
    char hex_value;
    for(i = 0; i < strlen(hex); i++) {
        hex_value = tolower(hex[i]);
        if(isdigit(hex_value)) {
            value += hex_value - '0';
        } else {
            if(hex_value >= 'a' && hex_value <= 'f') {
                value += hex_value - 'a' + 10;
            } else {
                printf("Invalid hexadecimal character: %c\n", hex_value);
                exit(1);
            }
        }
        value *= 16;
    }
    *decimal = value;
}

void decimal_to_hex(int decimal, char *hex) {
    int i, j;
    for(i = 0; i < MAX_HEX_LENGTH; i++) {
        if(decimal == 0) {
            hex[i] = '\0';
            break;
        }
        if(decimal % 16 < 10) {
            hex[i] = decimal % 16 + '0';
        } else {
            hex[i] = decimal % 16 + 'a' - 10;
        }
        decimal /= 16;
    }
}

int main() {
    char hex[MAX_HEX_LENGTH], dec[MAX_HEX_LENGTH];
    int decimal;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hex_to_decimal(hex, &decimal);
    printf("Decimal equivalent: %d\n", decimal);
    decimal_to_hex(decimal, dec);
    printf("Hexadecimal equivalent: %s\n", dec);
    return 0;
}