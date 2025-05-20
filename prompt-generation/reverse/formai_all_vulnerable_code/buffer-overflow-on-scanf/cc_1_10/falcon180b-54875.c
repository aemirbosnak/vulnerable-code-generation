//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 4096

void hex_to_decimal(char *hex, char *decimal) {
    int i = 0, j = 0, decimal_value = 0;
    while (hex[i]) {
        if (isxdigit(hex[i])) {
            if (isdigit(hex[i])) {
                decimal_value += hex[i] - '0';
            } else {
                decimal_value += hex[i] - 'A' + 10;
            }
        }
        i++;
    }
    sprintf(decimal, "%d", decimal_value);
}

void decimal_to_hex(char *decimal, char *hex) {
    char buffer[MAX_HEX_LENGTH];
    int i = 0, j = 0;
    sprintf(buffer, "%d", atoi(decimal));
    while (buffer[i]) {
        if (isdigit(buffer[i])) {
            hex[j] = buffer[i] + '0';
        } else {
            hex[j] = buffer[i] + 'A' - 10;
        }
        i++;
        j++;
    }
    hex[j] = '\0';
}

int main() {
    char hex[MAX_HEX_LENGTH], decimal[MAX_HEX_LENGTH];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hex_to_decimal(hex, decimal);
    printf("Decimal: %s\n", decimal);
    printf("Enter a decimal number: ");
    scanf("%s", decimal);
    decimal_to_hex(decimal, hex);
    printf("Hexadecimal: %s\n", hex);
    return 0;
}