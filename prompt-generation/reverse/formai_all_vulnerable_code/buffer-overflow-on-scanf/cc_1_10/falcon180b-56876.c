//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* hex_to_decimal(char* hex) {
    int decimal = 0;
    int i = 0;
    int j = strlen(hex) - 1;
    while (i <= j) {
        if (isdigit(hex[i])) {
            decimal += hex[i] - '0';
        } else if (isalpha(hex[i])) {
            if (isupper(hex[i])) {
                decimal += hex[i] - 'A' + 10;
            } else {
                decimal += hex[i] - 'a' + 10;
            }
        }
        i++;
    }
    sprintf(hex, "%d", decimal);
    return hex;
}

char* decimal_to_hex(char* dec) {
    int i = 0;
    int j = strlen(dec) - 1;
    char hex[10];
    while (i <= j) {
        if (isdigit(dec[i])) {
            sprintf(hex, "%s%c", hex, dec[i]);
        } else if (isalpha(dec[i])) {
            if (isupper(dec[i])) {
                sprintf(hex, "%s%c", hex, dec[i] + 'A' - 10);
            } else {
                sprintf(hex, "%s%c", hex, dec[i] + 'a' - 10);
            }
        }
        i++;
    }
    strcpy(dec, hex);
    return dec;
}

int main() {
    char hex[100];
    char dec[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hex_to_decimal(hex);
    printf("The decimal equivalent is: %s\n", hex);
    printf("Enter a decimal number: ");
    scanf("%s", dec);
    decimal_to_hex(dec);
    printf("The hexadecimal equivalent is: %s\n", dec);
    return 0;
}