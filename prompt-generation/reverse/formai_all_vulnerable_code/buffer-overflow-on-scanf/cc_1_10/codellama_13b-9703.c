//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to convert hexadecimal to decimal
int hexToDec(char *hex) {
    int dec = 0, i;

    for (i = 0; hex[i] != '\0'; ++i) {
        if (hex[i] >= '0' && hex[i] <= '9')
            dec = (dec * 16) + (hex[i] - '0');
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            dec = (dec * 16) + (hex[i] - 'A' + 10);
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            dec = (dec * 16) + (hex[i] - 'a' + 10);
        else
            printf("Invalid hexadecimal input\n");
    }

    return dec;
}

// Function to convert decimal to hexadecimal
char *decToHex(int dec) {
    static char hex[100];
    int i = 0, rem;

    while (dec > 0) {
        rem = dec % 16;
        if (rem < 10)
            hex[i++] = rem + '0';
        else
            hex[i++] = rem - 10 + 'A';
        dec = dec / 16;
    }

    hex[i] = '\0';

    return hex;
}

int main() {
    char hex[100];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    dec = hexToDec(hex);
    printf("Decimal value: %d\n", dec);

    dec = 12345;
    printf("Hexadecimal value: %s\n", decToHex(dec));

    return 0;
}