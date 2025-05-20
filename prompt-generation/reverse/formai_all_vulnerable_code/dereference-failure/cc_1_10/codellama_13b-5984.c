//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
/*
 * A unique C Hexadecimal Converter example program in a Sherlock Holmes style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char *hex) {
    int dec = 0, i, len = strlen(hex);
    for (i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0') * (1 << (4 * (len - 1 - i)));
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 'A' + 10) * (1 << (4 * (len - 1 - i)));
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 'a' + 10) * (1 << (4 * (len - 1 - i)));
        }
    }
    return dec;
}

// Function to convert decimal to hexadecimal
char *dec_to_hex(int dec) {
    char *hex = (char *)malloc(9 * sizeof(char));
    int i = 8;
    while (dec > 0) {
        int rem = dec % 16;
        if (rem < 10) {
            hex[i] = rem + '0';
        } else {
            hex[i] = rem - 10 + 'A';
        }
        dec /= 16;
        i--;
    }
    hex[i] = '\0';
    return hex;
}

int main() {
    char hex[100];
    int dec;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    dec = hex_to_dec(hex);
    printf("Hexadecimal number %s is equal to decimal number %d.\n", hex, dec);
    dec = 255;
    printf("Decimal number %d is equal to hexadecimal number %s.\n", dec, dec_to_hex(dec));
    return 0;
}