//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
// C Hexadecimal Converter Example Program

#include <stdio.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDec(char *hex) {
    int dec = 0, i;
    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec = (dec * 16) + (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec = (dec * 16) + (hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec = (dec * 16) + (hex[i] - 'a' + 10);
        }
    }
    return dec;
}

// Function to convert decimal to hexadecimal
char *decToHex(int dec) {
    char *hex = (char *)malloc(10);
    int i = 0;
    while (dec > 0) {
        if (dec % 16 < 10) {
            hex[i++] = dec % 16 + '0';
        } else {
            hex[i++] = dec % 16 + 'A' - 10;
        }
        dec /= 16;
    }
    hex[i] = '\0';
    return hex;
}

// Main function
int main() {
    char hex[100];
    int dec;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    dec = hexToDec(hex);
    printf("Hexadecimal: %s\nDecimal: %d\n", hex, dec);
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    char *hex2 = decToHex(dec);
    printf("Hexadecimal: %s\n", hex2);
    free(hex2);
    return 0;
}