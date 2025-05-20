//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex_to_dec(char *hex) {
    int dec = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        char ch = tolower(hex[i]);
        if (ch >= '0' && ch <= '9') {
            dec = dec * 16 + (ch - '0');
        } else if (ch >= 'a' && ch <= 'f') {
            dec = dec * 16 + (ch - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", ch);
            exit(1);
        }
    }
    printf("Decimal value: %d\n", dec);
}

void dec_to_hex(int dec) {
    char hex[10];
    int len = 0;
    while (dec > 0) {
        int rem = dec % 16;
        if (rem < 10) {
            hex[len++] = rem + '0';
        } else {
            hex[len++] = rem + 'a' - 10;
        }
        dec /= 16;
    }
    printf("Hexadecimal value: %s\n", hex);
}

int main() {
    char input[100];
    printf("Cyberpunk Hexadecimal Converter\n");
    while (1) {
        printf("Enter a hexadecimal number or type 'exit' to quit: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        hex_to_dec(input);
    }
    return 0;
}