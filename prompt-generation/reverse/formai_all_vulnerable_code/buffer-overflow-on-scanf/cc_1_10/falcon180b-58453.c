//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 100

// Function to convert a hexadecimal string to an integer
long int hex_to_int(char *hex) {
    int i, j, len;
    long int decimal = 0;
    char hex_digits[] = "0123456789abcdef";

    len = strlen(hex);

    // Check if the string is a valid hexadecimal
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(hex_digits); j++) {
            if (hex[i] == hex_digits[j]) {
                break;
            }
        }
        if (j == strlen(hex_digits)) {
            printf("Invalid hexadecimal string!\n");
            exit(1);
        }
    }

    // Convert the hexadecimal string to an integer
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(hex_digits); j++) {
            if (hex[i] == hex_digits[j]) {
                decimal = (decimal << 4) | j;
                break;
            }
        }
    }

    return decimal;
}

// Function to convert an integer to a hexadecimal string
void int_to_hex(long int decimal, char *hex) {
    int i = 0, j;

    while (decimal > 0) {
        hex[i++] = "0123456789abcdef"[decimal & 0x0f];
        decimal >>= 4;
    }

    while (i < MAX_HEX_LENGTH) {
        hex[i++] = '0';
    }

    hex[MAX_HEX_LENGTH - 1] = '\0';

    for (j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    char hex[MAX_HEX_LENGTH];
    long int decimal;

    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);

    decimal = hex_to_int(hex);

    printf("The decimal equivalent is: ");
    int_to_hex(decimal, hex);

    return 0;
}