//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LEN 32

void hex_to_bin(char *hex, unsigned char *bin, int *bin_len) {
    int i, j, hex_len = strlen(hex);
    unsigned char temp;

    *bin_len = (hex_len / 2) * 4;
    bin = (unsigned char *)malloc(*bin_len);

    for (i = 0, j = 0; i < hex_len; i += 2) {
        sscanf(hex + i, "%2hhx", &temp);
        for (int bit = 0; bit < 4; bit++) {
            bin[j++] = (temp >> (bit * 1)) & 0x01;
        }
    }
}

unsigned long long hex_to_decimal(unsigned char *bin, int bin_len) {
    unsigned long long decimal = 0;
    int i, power = 0;

    for (i = bin_len - 1; i >= 0; i--) {
        decimal += (bin[i] << power);
        power += 1;
    }

    return decimal;
}

int main(int argc, char **argv) {
    char hex[MAX_HEX_LEN];
    unsigned char bin[128];
    int bin_len;
    unsigned long long decimal;

    printf("Enter a Hexadecimal string: ");
    scanf("%s", hex);

    hex_to_bin(hex, bin, &bin_len);
    decimal = hex_to_decimal(bin, bin_len);

    printf("Decimal equivalent of Hexadecimal '%s' is: %llu\n", hex, decimal);

    free(bin);
    return 0;
}