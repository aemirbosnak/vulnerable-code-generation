//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if input is a valid hexadecimal number
int is_hex(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert hexadecimal to decimal
int hex_to_dec(char* hex) {
    int decimal = 0;
    int power = 0;
    int i;

    for (i = strlen(hex) - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * pow(16, power);
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * pow(16, power);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * pow(16, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert decimal to hexadecimal
void dec_to_hex(int dec, char* hex) {
    char hex_digits[] = "0123456789ABCDEF";
    int i = 0;
    int j = 0;

    while (dec!= 0) {
        int remainder = dec % 16;
        if (remainder < 10) {
            hex[i++] = remainder + '0';
        } else {
            hex[i++] = remainder + 'A' - 10;
        }
        dec /= 16;
    }

    while (i < strlen(hex)) {
        hex[i++] = '0';
    }

    for (j = 0; j < strlen(hex); j++) {
        printf("%c", hex[j]);
    }
}

int main() {
    char hex[100];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    if (!is_hex(hex)) {
        printf("Invalid hexadecimal number\n");
        return 1;
    }

    dec = hex_to_dec(hex);

    printf("Decimal equivalent: %d\n", dec);

    printf("Hexadecimal equivalent: ");
    dec_to_hex(dec, hex);

    return 0;
}