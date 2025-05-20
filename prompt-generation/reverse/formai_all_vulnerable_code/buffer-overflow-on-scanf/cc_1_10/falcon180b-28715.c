//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char hex[100], bin[100], dec[100];
    int i, j, k, l, len, num;
    char c;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    len = strlen(hex);

    // check if input is valid hexadecimal
    for (i = 0; i < len; i++) {
        c = hex[i];
        if (!isxdigit(c)) {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            return 0;
        }
    }

    // convert hexadecimal to binary
    for (i = 0, j = 0; i < len; i++) {
        c = hex[i];
        if (isdigit(c)) {
            num = c - '0';
        } else {
            num = toupper(c) - 'A' + 10;
        }
        bin[j++] = num + '0';
    }
    bin[j] = '\0';

    // convert binary to decimal
    for (i = 0, j = 0; i < strlen(bin); i++) {
        c = bin[i];
        if (isdigit(c)) {
            num = c - '0';
        } else {
            num = toupper(c) - 'A' + 10;
        }
        dec[j++] = num + '0';
    }
    dec[j] = '\0';

    // print results
    printf("\nHexadecimal: %s\n", hex);
    printf("Binary:     %s\n", bin);
    printf("Decimal:   %s\n", dec);

    return 0;
}