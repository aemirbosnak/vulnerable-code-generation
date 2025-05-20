//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary_to_decimal(int binary[]) {
    int decimal = 0;
    int i = 0;
    int power = 0;

    for (i = 31; i >= 0; i--) {
        if (binary[i] == 1) {
            decimal += pow(2, power);
        }
        power++;
    }

    printf("Decimal: %d\n", decimal);
}

void binary_to_hexadecimal(int binary[]) {
    int decimal = 0;
    char hex[3];

    binary_to_decimal(binary);

    for (int i = 0; decimal > 0; i++) {
        decimal >>= 4;
        hex[i] = (decimal > 9) ? (decimal + 55) : (decimal + 48);
        decimal &= 0xF;
    }

    printf("Hexadecimal: ");
    for (int i = 2; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

void binary_to_octal(int binary[]) {
    int decimal = 0;
    char octal[3];
    int i = 0;

    binary_to_decimal(binary);

    while (decimal > 0) {
        octal[i++] = (decimal % 8) < 10 ? (decimal % 8) + 48 : (decimal % 8) + 55;
        decimal /= 8;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", octal[j]);
    }
    printf("\n");
}

int main() {
    int binary[33];
    int i = 0;

    printf("Enter a binary number: ");
    for (; i < 33; scanf("%d", &binary[i])) {
        if (binary[i] < 0 || binary[i] > 1) {
            printf("Invalid binary digit. Enter a 0 or 1.\n");
            break;
        }
        i++;
    }

    printf("\nBinary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    binary_to_decimal(binary);
    binary_to_hexadecimal(binary);
    binary_to_octal(binary);

    return 0;
}