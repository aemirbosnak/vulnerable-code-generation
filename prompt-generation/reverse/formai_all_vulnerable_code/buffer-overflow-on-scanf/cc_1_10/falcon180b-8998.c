//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

struct node {
    char binary[MAX_SIZE];
    int decimal;
};

void build_binary(int decimal, char *binary, int length) {
    int i = length - 1;
    while (decimal > 0 && i >= 0) {
        binary[i] = '1';
        decimal--;
        i--;
    }
    while (i >= 0) {
        binary[i] = '0';
        i--;
    }
    binary[length] = '\0';
}

void convert_to_binary(int decimal, char *binary) {
    int length = 0;
    while (decimal > 0) {
        decimal /= 2;
        length++;
    }
    build_binary(decimal, binary, length);
}

void convert_to_decimal(char *binary, int *decimal) {
    int length = strlen(binary);
    int power = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            power += (length - i - 1);
        }
    }
    *decimal = power;
}

int main() {
    int decimal;
    char binary[MAX_SIZE];
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    convert_to_binary(decimal, binary);
    printf("Binary representation: %s\n", binary);

    int binary_decimal;
    convert_to_decimal(binary, &binary_decimal);
    printf("Decimal representation: %d\n", binary_decimal);

    return 0;
}