//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
/*
 * A Medieval Hexadecimal Converter Program
 *
 * This program converts a given number from decimal to hexadecimal
 * and back again.
 *
 * Usage:
 * 1. Enter a decimal number to convert to hexadecimal
 * 2. Press Enter
 * 3. The program will print the hexadecimal representation of the number
 * 4. Enter a hexadecimal number to convert to decimal
 * 5. Press Enter
 * 6. The program will print the decimal representation of the number
 */

#include <stdio.h>
#include <stdlib.h>

// Function to convert a hexadecimal string to a decimal number
int hex_to_dec(char *hex) {
    int dec = 0;
    int i = 0;
    while (hex[i]) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0') * (1 << (4 * i));
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 'A' + 10) * (1 << (4 * i));
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 'a' + 10) * (1 << (4 * i));
        } else {
            return -1;
        }
        i++;
    }
    return dec;
}

// Function to convert a decimal number to a hexadecimal string
char *dec_to_hex(int dec) {
    int i = 0;
    char *hex = malloc(9 * sizeof(char));
    while (dec > 0) {
        if (dec % 16 < 10) {
            hex[i] = dec % 16 + '0';
        } else {
            hex[i] = dec % 16 + 'A' - 10;
        }
        dec /= 16;
        i++;
    }
    hex[i] = '\0';
    return hex;
}

int main() {
    int dec;
    char hex[9];
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &dec);
    printf("Hexadecimal representation: %s\n", dec_to_hex(dec));
    printf("Enter a hexadecimal number to convert to decimal: ");
    scanf("%s", hex);
    printf("Decimal representation: %d\n", hex_to_dec(hex));
    return 0;
}