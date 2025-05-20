//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000000

void hex2dec(char* hex, int hex_len, char* dec) {
    int i, j, k, decimal = 0;
    for (i = hex_len - 1, j = 0; i >= 0; i--, j++) {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * pow(16, hex_len - 1 - i);
        } else {
            decimal += (hex[i] - 'A' + 10) * pow(16, hex_len - 1 - i);
        }
    }
    sprintf(dec, "%d", decimal);
}

void dec2hex(int dec, char* hex) {
    char hex_str[MAX_SIZE];
    sprintf(hex_str, "%X", dec);
    strcpy(hex, hex_str);
}

int main() {
    char hex[MAX_SIZE], dec[MAX_SIZE];
    FILE* fp;
    int hex_len, dec_len;

    printf("Enter the path to the input file: ");
    scanf("%s", hex);

    fp = fopen(hex, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    hex_len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    fread(hex, hex_len, 1, fp);
    fclose(fp);

    dec_len = strlen(hex);
    hex2dec(hex, dec_len, dec);

    printf("The hexadecimal string '%s' is equivalent to the decimal value '%s'.\n", hex, dec);

    return 0;
}