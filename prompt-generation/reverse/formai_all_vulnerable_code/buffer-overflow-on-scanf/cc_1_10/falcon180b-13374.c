//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertBinary(char *binary, int length) {
    int decimal = 0;
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);
        }
    }
    printf("Decimal: %d\n", decimal);
}

void convertHex(char *hex, int length) {
    int decimal = 0;
    for (int i = 0; i < length; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        }
    }
    printf("Decimal: %d\n", decimal);
}

void convertOctal(char *octal, int length) {
    int decimal = 0;
    for (int i = 0; i < length; i++) {
        if (octal[i] >= '0' && octal[i] <= '7') {
            decimal += octal[i] - '0';
        } else {
            printf("Invalid octal number!\n");
            return;
        }
    }
    printf("Decimal: %d\n", decimal);
}

int main() {
    char binary[100], hex[100], octal[100];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    convertBinary(binary, strlen(binary));

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    convertHex(hex, strlen(hex));

    printf("Enter an octal number: ");
    scanf("%s", octal);
    convertOctal(octal, strlen(octal));

    return 0;
}