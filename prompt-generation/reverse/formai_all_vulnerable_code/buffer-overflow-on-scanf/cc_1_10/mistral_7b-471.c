//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct Binary {
    int decimal;
    char binary[33];
} Binary;

void binToDec(char binary[], int base, int *decimal) {
    int i = 0, power = 0;
    long long num = 0;

    while (binary[i] != '\0') {
        if (binary[i] == '1') {
            num += pow(base, power);
        }
        power++;
        i++;
    }

    *decimal = (int)num;
}

void decToBin(int decimal, int base, char bin[]) {
    int i = 0, remainder;

    while (decimal > 0) {
        remainder = decimal % base;
        decimal /= base;

        bin[i++] = (remainder > 9) ? (remainder + 55) : (remainder + 48);
    }

    bin[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }
}

int main() {
    Binary converter;
    char binary[33];
    int base, decimal;

    printf("Enter the base (2, 8, 10 or 16): ");
    scanf("%d", &base);

    printf("Enter the binary number: ");
    scanf("%s", binary);

    binToDec(binary, base, &decimal);
    printf("Decimal: %d\n", decimal);

    decToBin(decimal, base, binary);
    printf("Binary: %s\n", binary);

    return 0;
}