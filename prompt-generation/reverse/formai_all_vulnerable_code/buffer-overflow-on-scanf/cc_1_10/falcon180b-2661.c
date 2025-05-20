//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINARY_LENGTH 32
#define MAX_NUM_LENGTH 10

void convert_binary_to_decimal(char *binary, int *decimal) {
    int i = 0;
    int j = 0;
    int power = 0;

    *decimal = 0;

    while (binary[i]!= '\0') {
        if (isdigit(binary[i])) {
            if (binary[i] == '1') {
                *decimal += pow(2, power);
            }

            power++;
        } else {
            printf("Invalid binary input!\n");
            exit(1);
        }

        i++;
    }
}

void convert_decimal_to_binary(int decimal, char *binary) {
    int i = 0;
    int j = 0;

    binary[i] = '\0';

    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary[j] = '0';
        } else {
            binary[j] = '1';
        }

        j++;
        decimal /= 2;
    }

    for (int k = j - 1; k >= 0; k--) {
        binary[i++] = binary[k];
    }
}

int main() {
    char binary[MAX_BINARY_LENGTH];
    int decimal;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    convert_binary_to_decimal(binary, &decimal);

    printf("The decimal equivalent of %s is %d.\n", binary, decimal);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    char result[MAX_BINARY_LENGTH];
    convert_decimal_to_binary(decimal, result);

    printf("The binary equivalent of %d is %s.\n", decimal, result);

    return 0;
}