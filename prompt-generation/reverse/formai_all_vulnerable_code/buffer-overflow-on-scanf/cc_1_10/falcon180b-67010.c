//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HEX_LENGTH 32

bool is_hex(char c) {
    return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int hex_to_dec(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        return -1;
    }
}

void dec_to_hex(char *hex, int dec) {
    char temp[MAX_HEX_LENGTH];
    sprintf(temp, "%X", dec);
    strcpy(hex, temp);
}

int main() {
    char hex[MAX_HEX_LENGTH];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    if (strlen(hex) > MAX_HEX_LENGTH) {
        printf("Error: Hexadecimal number is too long.\n");
        return 1;
    }

    for (int i = 0; i < strlen(hex); i++) {
        if (!is_hex(hex[i])) {
            printf("Error: Invalid hexadecimal number.\n");
            return 1;
        }
    }

    dec = 0;
    for (int i = strlen(hex) - 1; i >= 0; i--) {
        dec += hex_to_dec(hex[i]) * pow(16, strlen(hex) - i - 1);
    }

    printf("Decimal equivalent: %d\n", dec);

    return 0;
}