//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 100
#define MAX_DEC_LENGTH 33

int hex_to_dec(char* hex);
char* dec_to_hex(int dec);

int main() {
    char hex[MAX_HEX_LENGTH];
    int dec;
    char choice;
    char* result;

    do {
        printf("Enter a hexadecimal number (up to %d characters):\n", MAX_HEX_LENGTH - 1);
        scanf("%s", hex);

        if (strlen(hex) == 0) {
            printf("Invalid input. Please enter a hexadecimal number.\n");
            continue;
        }

        dec = hex_to_dec(hex);
        result = dec_to_hex(dec);

        printf("Hexadecimal: %s\nDecimal: %s\n", hex, result);

        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

int hex_to_dec(char* hex) {
    int dec = 0;
    int i = 0;

    while (hex[i]!= '\0') {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec = dec * 16 + hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec = dec * 16 + hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec = dec * 16 + hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            return -1;
        }

        i++;
    }

    return dec;
}

char* dec_to_hex(int dec) {
    char* hex = malloc(MAX_HEX_LENGTH * sizeof(char));
    int i = 0;

    while (dec > 0) {
        if (dec % 16 < 10) {
            hex[i] = dec % 16 + '0';
        } else {
            hex[i] = dec % 16 + 'A' - 10;
        }

        i++;
        dec /= 16;
    }

    hex[i] = '\0';
    return hex;
}