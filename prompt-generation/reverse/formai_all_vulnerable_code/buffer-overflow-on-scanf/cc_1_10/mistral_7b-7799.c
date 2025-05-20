//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex_to_bin(unsigned char c, char *bin) {
    int i;
    for (i = 0; i < 4; i++) {
        bin[i] = '0';
    }
    bin[4] = '\0';

    for (i = 0; i < 4; i++) {
        int bit = (c >> (3 - i)) & 1;
        bin[3 - i] = bit + '0';
    }
}

void print_bin(char *bin) {
    int i;
    for (i = 0; i < 5; i++) {
        if (i == 0 || i == 4) {
            printf("-");
        }
        printf("%c", bin[i]);
    }
}

void print_hex(unsigned char c) {
    char hex[3];

    hex[0] = (c >> 4) & 0xF;
    hex[1] = (c & 0xF);

    if (hex[0] > 9) {
        hex[0] += 'A' - '9';
    }
    if (hex[1] > 9) {
        hex[1] += 'A' - '9';
    }

    printf("%s ", hex);
}

int main() {
    char hex[11];
    char bin[5];
    int i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    if (strlen(hex) > 10) {
        printf("Invalid hexadecimal number!\n");
        return 1;
    }

    for (i = 0; i < strlen(hex); i++) {
        if (isdigit(hex[i])) {
            continue;
        }
        if (hex[i] > 'F' || hex[i] < 'A') {
            printf("Invalid hexadecimal number!\n");
            return 1;
        }
    }

    for (i = 0; i < strlen(hex) / 2; i++) {
        unsigned char c = strtoul(&hex[2 * i], NULL, 16);
        hex_to_bin(c, bin);
        print_bin(bin);
        printf(" %c\n", c);
    }

    printf("\n");

    return 0;
}