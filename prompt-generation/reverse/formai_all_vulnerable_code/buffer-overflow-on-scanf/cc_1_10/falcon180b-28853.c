//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 8

int is_hex(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    if (c >= 'A' && c <= 'F') {
        return 1;
    }
    if (c >= 'a' && c <= 'f') {
        return 1;
    }
    return 0;
}

int main() {
    char hex_str[MAX_HEX_LENGTH];
    int decimal_num;
    int i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    if (strlen(hex_str)!= MAX_HEX_LENGTH) {
        printf("Error: Invalid hexadecimal number\n");
        return 1;
    }

    for (i = 0; i < strlen(hex_str); i++) {
        if (!is_hex(hex_str[i])) {
            printf("Error: Invalid hexadecimal number\n");
            return 1;
        }
    }

    decimal_num = 0;
    for (i = strlen(hex_str) - 1; i >= 0; i--) {
        if (hex_str[i] >= '0' && hex_str[i] <= '9') {
            decimal_num += hex_str[i] - '0';
        }
        else if (hex_str[i] >= 'A' && hex_str[i] <= 'F') {
            decimal_num += hex_str[i] - 'A' + 10;
        }
        else if (hex_str[i] >= 'a' && hex_str[i] <= 'f') {
            decimal_num += hex_str[i] - 'a' + 10;
        }
        else {
            printf("Error: Invalid hexadecimal number\n");
            return 1;
        }
        decimal_num *= 16;
    }

    printf("Decimal equivalent: %d\n", decimal_num);

    return 0;
}