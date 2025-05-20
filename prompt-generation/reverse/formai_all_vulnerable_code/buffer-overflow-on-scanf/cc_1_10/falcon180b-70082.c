//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex_to_dec(char *hex, int *dec) {
    int len = strlen(hex);
    int i = 0;
    int j = 0;
    int value = 0;

    *dec = 0;

    while (i < len) {
        if (isxdigit(hex[i])) {
            if (isdigit(hex[i])) {
                value = hex[i] - '0';
            } else {
                value = toupper(hex[i]) - 'A' + 10;
            }
            *dec = (*dec * 16) + value;
        } else {
            printf("Invalid hexadecimal character found.\n");
            exit(1);
        }
        i++;
    }
}

void dec_to_hex(int dec, char *hex) {
    char buffer[32];
    int i = 0;

    sprintf(buffer, "%X", dec);

    for (i = strlen(buffer) - 1; i >= 0; i--) {
        hex[i] = buffer[i];
    }
    hex[i + 1] = '\0';
}

int main() {
    char input[32];
    char hex[33];
    int dec;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    hex_to_dec(input, &dec);

    printf("The hexadecimal equivalent is: ");
    dec_to_hex(dec, hex);
    printf("%s\n", hex);

    return 0;
}