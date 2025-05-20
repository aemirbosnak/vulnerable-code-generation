//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char binary[33];
    int decimal;
} binary_decimal;

void itob(int dec, binary_decimal *bd) {
    int i, rem;
    for (i = 0; dec != 0; ++i) {
        rem = dec % 2;
        dec /= 2;
        bd->binary[i] = rem + '0';
    }
    bd->binary[32] = '\0';
    if (bd->binary[0] == '0') puts("Leading zeros are ignored.\n");
}

int main(void) {
    binary_decimal bin_dec;
    char binary_str[33];
    int len;

    printf("Welcome to the Binary Decimal Converter!\n");
    printf("This program will convert binary numbers entered by you into decimal.\n");
    printf("Enter your binary number (max 32 digits): ");

    fgets(binary_str, sizeof(binary_str), stdin);

    // Remove newline character and whitespaces
    len = strlen(binary_str);
    binary_str[len - 1] = '\0';
    for (int i = 0; i < len; ++i)
        if (isspace(binary_str[i])) binary_str[i] = '\0';

    strcpy(bin_dec.binary, binary_str);

    itob(binary_to_decimal(bin_dec.binary), &bin_dec);

    printf("The decimal equivalent of %s is %d.\n", bin_dec.binary, bin_dec.decimal);

    return 0;
}

int binary_to_decimal(char binary[33]) {
    int decimal = 0;
    int power = 0;

    for (int i = 31; i >= 0; --i) {
        decimal += (binary[i] - '0') * pow(2, power);
        ++power;
    }

    return decimal;
}