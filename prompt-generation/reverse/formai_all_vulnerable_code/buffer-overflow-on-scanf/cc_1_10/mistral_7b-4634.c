//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

void hex_to_decimal(char hex[MAX_LENGTH], int *decimal) {
    int i, j, hex_value;
    char hex_char;
    *decimal = 0;

    for (i = 0; i < strlen(hex) && i < MAX_LENGTH; i++) {
        hex_char = toupper(hex[i]);

        if ((hex_char < '0' || hex_char > '9') &&
            (hex_char < 'A' || hex_char > 'F') &&
            (hex_char < 'A' + 0x0A && i != 0)) {
            printf("Error: Invalid hexadecimal character '%c' detected.\n", hex_char);
            return;
        }

        if (i == 0) {
            hex_value = hex_char - '0';
        } else {
            hex_value = (hex_char - '0') * 16;
            if (i < strlen(hex) - 1) {
                hex_value += hex[++i] < '0' ? (hex[i++] - 'A' + 0x0A) : (hex[i++] - '0');
                i--;
            }
        }

        *decimal += hex_value;
    }
}

int main() {
    char hex[MAX_LENGTH];
    int decimal;

    printf("Enter a hexadecimal number (maximum length: %d): ", MAX_LENGTH);
    scanf("%s", hex);

    if (strlen(hex) > MAX_LENGTH) {
        printf("Error: Hexadecimal number too long.\n");
        return 1;
    }

    hex_to_decimal(hex, &decimal);

    if (decimal >= 0) {
        printf("The decimal equivalent of %s is: %d\n", hex, decimal);
    } else {
        printf("Error: Negative decimal number obtained.\n");
    }

    return 0;
}