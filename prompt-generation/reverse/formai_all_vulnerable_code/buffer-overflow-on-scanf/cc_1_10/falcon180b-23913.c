//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hex[9];
    int decimal;
} hex_decimal;

hex_decimal* create_hex_decimal(char* hex) {
    hex_decimal* hd = (hex_decimal*)malloc(sizeof(hex_decimal));
    strcpy(hd->hex, hex);
    hd->decimal = 0;
    return hd;
}

int get_decimal_from_hex(char* hex) {
    int decimal = 0;
    int length = strlen(hex);
    for (int i = 0; i < length; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal = decimal * 16 + hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal = decimal * 16 + hex[i] - 'A' + 10;
        } else {
            printf("Invalid hexadecimal character '%c'!\n", hex[i]);
            exit(1);
        }
    }
    return decimal;
}

void print_hex_decimal(hex_decimal* hd) {
    printf("Hexadecimal: %s\n", hd->hex);
    printf("Decimal: %d\n", hd->decimal);
}

int main() {
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_decimal* hd = create_hex_decimal(hex);
    hd->decimal = get_decimal_from_hex(hd->hex);

    print_hex_decimal(hd);

    free(hd);
    return 0;
}