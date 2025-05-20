//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include <stdio.h>
#include <string.h>

#define MAX_HEX_SIZE 32

void hex_to_dec(char hex[], int hex_len, int *dec_val) {
    int i;
    int j;
    int base;
    int dec_result = 0;

    for (i = hex_len - 1, j = 0; i >= 0; i--, j++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec_result += (hex[i] - '0') * pow(16, j);
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec_result += (hex[i] - 'A' + 10) * pow(16, j);
        } else {
            printf("Invalid hexadecimal character '%c'!\n", hex[i]);
            exit(1);
        }
    }

    *dec_val = dec_result;
}

void dec_to_hex(int dec_val, char hex[], int *hex_len) {
    char hex_digits[] = "0123456789ABCDEF";
    int i;
    int j;

    for (i = 0, j = 0; dec_val > 0; i++) {
        if (dec_val % 16 == 0) {
            hex[i] = '0';
        } else {
            hex[i] = hex_digits[dec_val % 16];
        }
        dec_val /= 16;
    }

    for (; i < MAX_HEX_SIZE - 1; i++) {
        hex[i] = '0';
    }

    hex[i] = '\0';
    *hex_len = i;
}

int main() {
    char hex[MAX_HEX_SIZE];
    int hex_len;
    int dec_val;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_len = strlen(hex);

    if (hex_len == 0 || hex_len > MAX_HEX_SIZE) {
        printf("Invalid hexadecimal number!\n");
        exit(1);
    }

    hex_to_dec(hex, hex_len, &dec_val);
    printf("Decimal value: %d\n", dec_val);

    dec_to_hex(dec_val, hex, &hex_len);
    printf("Hexadecimal value: %s\n", hex);

    return 0;
}