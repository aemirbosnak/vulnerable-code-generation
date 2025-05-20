//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <string.h>

#define MAX_HEX_LEN 100

int main() {
    char hex[MAX_HEX_LEN];
    char dec[MAX_HEX_LEN];
    int len;
    int i;
    int j;
    int num;
    int hex_num;
    int dec_num;
    int is_hex = 0;
    int is_dec = 0;
    int is_negative = 0;
    int is_valid = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    len = strlen(hex);

    for (i = 0; i < len; i++) {
        if ((hex[i] >= '0' && hex[i] <= '9') ||
            (hex[i] >= 'A' && hex[i] <= 'F') ||
            (hex[i] >= 'a' && hex[i] <= 'f')) {
            if (is_hex == 0) {
                is_hex = 1;
            }
        } else if (hex[i] == '-') {
            is_negative = 1;
        } else {
            is_hex = 0;
        }
    }

    if (is_hex == 1) {
        hex_num = 0;
        for (i = 0; i < len; i++) {
            if (hex[i] >= '0' && hex[i] <= '9') {
                hex_num = hex_num * 16 + (hex[i] - '0');
            } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                hex_num = hex_num * 16 + (hex[i] - 'A' + 10);
            } else if (hex[i] >= 'a' && hex[i] <= 'f') {
                hex_num = hex_num * 16 + (hex[i] - 'a' + 10);
            }
        }
        if (is_negative == 1) {
            hex_num = -hex_num;
        }
        sprintf(dec, "%d", hex_num);
        printf("Decimal equivalent: %s\n", dec);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}