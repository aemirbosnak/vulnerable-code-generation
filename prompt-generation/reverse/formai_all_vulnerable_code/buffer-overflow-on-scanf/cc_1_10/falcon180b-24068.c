//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hex_to_dec(char hex[]) {
    int decimal = 0;
    int i = 0;
    while (hex[i]!= '\0') {
        if (isdigit(hex[i])) {
            decimal = decimal * 16 + hex[i] - '0';
        } else if (isupper(hex[i])) {
            decimal = decimal * 16 + hex[i] - 'A' + 10;
        } else if (islower(hex[i])) {
            decimal = decimal * 16 + hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character.\n");
            exit(1);
        }
        i++;
    }
    return decimal;
}

void dec_to_hex(int dec, char hex[]) {
    sprintf(hex, "%X", dec);
}

int main() {
    char input[100];
    char output[100];
    int decimal;
    int i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid hexadecimal character.\n");
            exit(1);
        }
    }

    decimal = hex_to_dec(input);
    dec_to_hex(decimal, output);

    printf("Decimal equivalent: %s\n", output);

    return 0;
}