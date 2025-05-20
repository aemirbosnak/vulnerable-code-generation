//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32
#define MAX_SIZE 8

void binary_to_decimal(int binary[], int decimal[], int size) {
    int power = 0, i;

    for (i = 0; i < size; i++) {
        if (binary[i] == 1) {
            decimal[i] = (int)pow(2, power);
            power++;
        } else {
            decimal[i] = 0;
        }
    }
}

void decimal_to_binary(int decimal[], int binary[], int size) {
    int remainder, i;

    for (i = size - 1; i >= 0; i--) {
        remainder = decimal[i] % 2;
        binary[i] = remainder;
        decimal[i] /= 2;
    }
}

int main(int argc, char *argv[]) {
    int decimal[MAX_SIZE], binary[MAX_BITS];
    int size, i, j;

    printf("Enter the size of the binary number: ");
    scanf("%d", &size);

    printf("Enter the binary number: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &binary[i]);
    }

    printf("Binary number: ");
    for (i = 0; i < size; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");

    decimal_to_binary(binary, decimal, size);

    printf("Decimal number: ");
    for (i = 0; i < size; i++) {
        printf("%d", decimal[i]);
    }
    printf("\n");

    return 0;
}