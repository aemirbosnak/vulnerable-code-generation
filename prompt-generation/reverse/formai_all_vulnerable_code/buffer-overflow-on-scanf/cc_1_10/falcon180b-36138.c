//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    char hex[MAX_SIZE];
    int decimal;
} Hexadecimal;

void initialize(Hexadecimal *hex) {
    hex->hex[0] = '\0';
    hex->decimal = 0;
}

int hex_to_decimal(char *hex) {
    int decimal = 0;
    int length = strlen(hex);
    for (int i = 0; i < length; i++) {
        char c = toupper(hex[i]);
        if (c >= '0' && c <= '9') {
            decimal = decimal * 16 + (c - '0');
        } else if (c >= 'A' && c <= 'F') {
            decimal = decimal * 16 + (c - 'A' + 10);
        } else {
            return -1;
        }
    }
    return decimal;
}

void decimal_to_hex(int decimal, char *hex) {
    sprintf(hex, "%X", decimal);
}

int main() {
    Hexadecimal hex;
    initialize(&hex);

    printf("Enter a decimal number: ");
    scanf("%d", &hex.decimal);

    sprintf(hex.hex, "%X", hex.decimal);

    printf("Decimal: %d\n", hex.decimal);
    printf("Hexadecimal: %s\n", hex.hex);

    return 0;
}