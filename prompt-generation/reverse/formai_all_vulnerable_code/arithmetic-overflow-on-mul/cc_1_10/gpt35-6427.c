//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hex_digits[] = "0123456789abcdef";

void to_hex(int decimal, char hex[]) {
    int quotient = decimal / 16;
    int remainder = decimal % 16;
    if (quotient == 0) {
        hex[0] = hex_digits[remainder];
        hex[1] = '\0';
    } else {
        to_hex(quotient, hex);
        int len = strlen(hex);
        hex[len] = hex_digits[remainder];
        hex[len+1] = '\0';
    }
}

int from_hex(char hex[]) {
    int len = strlen(hex);
    int decimal = 0;
    int factor = 1;
    for (int i = len-1; i >= 0; i--) {
        char digit = hex[i];
        int value = 0;
        for (int j = 0; j < 16; j++) {
            if (digit == hex_digits[j]) {
                value = j;
                break;
            }
        }
        decimal += value * factor;
        factor *= 16;
    }
    return decimal;
}

int main() {
    char input[100];
    printf("Enter a decimal number (0 to 65535): ");
    fgets(input, 100, stdin);
    int decimal = atoi(input);
    if (decimal < 0 || decimal > 65535) {
        printf("Invalid input!\n");
        return 1;
    }

    char hex[5];
    to_hex(decimal, hex);
    printf("Hexadecimal equivalent: %s\n", hex);

    printf("Enter a hexadecimal number (up to 4 digits): ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    int dec = from_hex(input);
    printf("Decimal equivalent: %d\n", dec);

    return 0;
}