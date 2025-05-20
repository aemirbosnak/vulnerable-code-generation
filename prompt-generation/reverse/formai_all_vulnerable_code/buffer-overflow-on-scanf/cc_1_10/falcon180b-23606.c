//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

long long int binary_to_decimal(char* binary) {
    long long int decimal = 0;
    int i, j;

    for (i = strlen(binary) - 1, j = 0; i >= 0; i--, j++) {
        if (binary[i] == '1') {
            decimal += pow(2, j);
        }
    }

    return decimal;
}

char* decimal_to_binary(long long int decimal) {
    char* binary = malloc(33 * sizeof(char));
    int i, j;

    for (i = 0; decimal > 0; i++) {
        binary[i] = '0';
        j = 0;

        while (decimal % 2 == 0 && j < 8) {
            binary[i] = '1' + binary[i];
            decimal /= 2;
            j++;
        }
    }

    binary[i] = '\0';

    return binary;
}

int main() {
    char* binary = malloc(33 * sizeof(char));
    long long int decimal;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    decimal = binary_to_decimal(binary);
    printf("Decimal equivalent: %lld\n", decimal);

    printf("Enter a decimal number: ");
    scanf("%lld", &decimal);

    printf("Binary equivalent: %s\n", decimal_to_binary(decimal));

    free(binary);

    return 0;
}