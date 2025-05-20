//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void hex_to_dec(char hex[], int len, char dec[]) {
    int i;
    int decimal = 0;
    for (i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal input\n");
            exit(1);
        }
    }
    sprintf(dec, "%d", decimal);
}

void dec_to_hex(int dec, char hex[]) {
    char *hex_digits = "0123456789ABCDEF";
    char hex_str[MAX_LEN];
    int i = 0;
    while (dec > 0) {
        hex[i++] = hex_digits[dec % 16];
        dec /= 16;
    }
    hex[i] = '\0';
    strcpy(hex_str, hex);
    strcpy(hex, hex_str);
}

int main() {
    char hex[MAX_LEN];
    char dec[MAX_LEN];
    int len;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    len = strlen(hex);
    if (len == 0) {
        printf("Invalid hexadecimal input\n");
        exit(1);
    }
    hex_to_dec(hex, len, dec);
    printf("Decimal equivalent: %s\n", dec);
    printf("Hexadecimal equivalent: ");
    dec_to_hex(atoi(dec), hex);
    printf("%s\n", hex);
    return 0;
}