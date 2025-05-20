#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int hexToDec(char *hex) {
    int dec = 0;
    while (*hex != '\0') {
        if (isdigit(*hex))
            dec = dec * 16 + (*hex - '0');
        else if (isxdigit(*hex))
            dec = dec * 16 + (tolower(*hex) - 'a' + 10);
        hex++;
    }
    return dec;
}

char* decToHex(int dec) {
    static char hex[100];
    int i = 0;
    do {
        int remainder = dec % 16;
        if (remainder < 10)
            hex[i++] = remainder + '0';
        else
            hex[i++] = remainder - 10 + 'A';
        dec /= 16;
    } while (dec > 0);
    hex[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
    return hex;
}

int main() {
    int choice;
    char hex[100];
    int dec;

    while (1) {
        printf("Menu:\n");
        printf("1. Convert Hexadecimal to Decimal\n");
        printf("2. Convert Decimal to Hexadecimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                dec = hexToDec(hex);
                printf("Decimal equivalent: %d\n", dec);
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &dec);
                printf("Hexadecimal equivalent: %s\n", decToHex(dec));
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
