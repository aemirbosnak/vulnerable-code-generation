#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int hexToDec(char *hex) {
    int dec = 0;
    while (*hex) {
        if (isdigit(*hex))
            dec = dec * 16 + (*hex - '0');
        else if (isxdigit(*hex)) {
            char c = tolower(*hex);
            dec = dec * 16 + (c >= 'a' ? c - 'a' + 10 : c - '0');
        } else {
            fprintf(stderr, "Invalid character in hexadecimal input.\n");
            exit(1);
        }
        hex++;
    }
    return dec;
}

char* decToHex(int dec) {
    static char buffer[33];
    int i = 0;
    do {
        int remainder = dec % 16;
        buffer[i++] = (remainder < 10) ? (remainder + '0') : ((remainder - 10) + 'A');
        dec /= 16;
    } while (dec > 0);
    buffer[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
    return buffer;
}

int main() {
    char input[100];
    printf("Enter a hexadecimal number: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    int dec = hexToDec(input);
    printf("Decimal equivalent: %d\n", dec);

    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    getchar(); // Consume newline

    char *hex = decToHex(dec);
    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}
