//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LEN 1000

void hex2dec(char* hex, int hex_len, char* dec) {
    int i, j, dec_val = 0;
    for(i = 0; i < hex_len; i++) {
        if(isdigit(hex[i])) {
            dec_val = dec_val * 16 + (hex[i] - '0');
        } else if(isupper(hex[i])) {
            dec_val = dec_val * 16 + (hex[i] - 'A' + 10);
        } else if(islower(hex[i])) {
            dec_val = dec_val * 16 + (hex[i] - 'a' + 10);
        } else {
            break;
        }
    }
    sprintf(dec, "%d", dec_val);
}

void dec2hex(int dec, char* hex) {
    char temp[MAX_HEX_LEN];
    int i = 0;
    while(dec > 0) {
        if(dec % 16 < 10) {
            temp[i++] = dec % 16 + '0';
        } else {
            temp[i++] = dec % 16 + 'A' - 10;
        }
        dec /= 16;
    }
    for(int j = 0; j < i; j++) {
        hex[j] = temp[i - j - 1];
    }
    hex[i] = '\0';
}

int main() {
    char hex[MAX_HEX_LEN], dec[MAX_HEX_LEN];
    int len;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    len = strlen(hex);

    hex2dec(hex, len, dec);
    printf("Decimal equivalent: %s\n", dec);

    dec2hex(atoi(dec), hex);
    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}