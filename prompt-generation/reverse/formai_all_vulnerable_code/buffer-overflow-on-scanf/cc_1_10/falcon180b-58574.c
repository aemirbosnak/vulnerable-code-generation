//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hexToDec(char hex[]);
void decToHex(int dec, char hex[]);

int main() {
    char hex[100];
    int dec;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    dec = hexToDec(hex);
    printf("\nThe decimal equivalent is: %d\n", dec);
    printf("The hexadecimal equivalent is: ");
    decToHex(dec, hex);
    printf("\n");
    return 0;
}

int hexToDec(char hex[]) {
    int i, j, dec = 0, len;
    len = strlen(hex);
    for (i = 0; i < len; i++) {
        if (isdigit(hex[i])) {
            dec = dec * 16 + hex[i] - '0';
        } else if (isupper(hex[i])) {
            dec = dec * 16 + hex[i] - 'A' + 10;
        } else if (islower(hex[i])) {
            dec = dec * 16 + hex[i] - 'a' + 10;
        } else {
            printf("\nInvalid hexadecimal number\n");
            exit(0);
        }
    }
    return dec;
}

void decToHex(int dec, char hex[]) {
    int i, j;
    for (i = 0; dec!= 0; i++) {
        j = dec % 16;
        if (j < 10) {
            hex[i] = j + '0';
        } else {
            hex[i] = j + 'A' - 10;
        }
        dec = dec / 16;
    }
    for (i = 0; i < strlen(hex); i++) {
        printf("%c", hex[i]);
    }
}