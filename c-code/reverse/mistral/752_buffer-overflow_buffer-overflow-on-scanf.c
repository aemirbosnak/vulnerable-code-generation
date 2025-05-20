#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToDec(char *hex) {
    int dec = 0, i = 0, power = 1;
    while (hex[i] != '\0') {
        if (hex[i] >= '0' && hex[i] <= '9')
            dec += (hex[i] - '0') * power;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            dec += (hex[i] - 'A' + 10) * power;
        else
            break;
        power *= 16;
        i++;
    }
    printf("Decimal: %d\n", dec);
}

void decToHex(int dec) {
    char hex[10];
    int rem, i = 0;
    while (dec > 0) {
        rem = dec % 16;
        if (rem < 10)
            hex[i++] = rem + '0';
        else
            hex[i++] = rem + 'A' - 10;
        dec /= 16;
    }
    hex[i] = '\0';
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");
}

int main() {
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hexToDec(hex);
    printf("Enter a decimal number: ");
    int dec;
    scanf("%d", &dec);
    decToHex(dec);
    return 0;
}
