//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hexadecimal_number> <decimal_number>\n", argv[0]);
        return 1;
    }

    char *hex = argv[1];
    char *decimal = argv[2];

    if (!isxdigit(hex[0])) {
        printf("Invalid hexadecimal number %s\n", hex);
        return 1;
    }

    int hex_len = strlen(hex);
    int decimal_len = strlen(decimal);

    if (hex_len > 8 || decimal_len > 32) {
        printf("Number too large\n");
        return 1;
    }

    unsigned long long hex_num = 0;
    unsigned long long decimal_num = 0;

    for (int i = 0; i < hex_len; i++) {
        char c = tolower(hex[i]);
        if (c >= '0' && c <= '9') {
            hex_num = hex_num * 16 + (c - '0');
        } else if (c >= 'a' && c <= 'f') {
            hex_num = hex_num * 16 + (c - 'a' + 10);
        } else {
            printf("Invalid hexadecimal number %s\n", hex);
            return 1;
        }
    }

    for (int i = 0; i < decimal_len; i++) {
        char c = tolower(decimal[i]);
        if (c >= '0' && c <= '9') {
            decimal_num = decimal_num * 16 + (c - '0');
        } else {
            printf("Invalid decimal number %s\n", decimal);
            return 1;
        }
    }

    printf("Hexadecimal: %llx\n", hex_num);
    printf("Decimal: %llu\n", decimal_num);

    return 0;
}