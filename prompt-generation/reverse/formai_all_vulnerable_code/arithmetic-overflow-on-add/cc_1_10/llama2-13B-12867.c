//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define BINARY_DIGITS 8
#define MAX_INPUT_SIZE 1024

void binary_to_decimal(char *binary_str, int *decimal_value) {
    int i, j;
    long long int binary = 0;

    for (i = 0; binary_str[i] != '\0'; i++) {
        binary <<= 1;
        if (binary_str[i] == '1') {
            binary |= 1LL;
        }
    }

    *decimal_value = binary;
}

void decimal_to_binary(int decimal_value, char *binary_str) {
    int i, j;
    long long int binary = 0;

    do {
        binary <<= 1;
        binary |= (decimal_value % 2) ? 1LL : 0LL;
        decimal_value /= 2;
        if (binary_str[j] == '\0') {
            binary_str[j] = '1';
        }
        j++;
    } while (decimal_value > 0);

    binary_str[j] = '\0';
}

int main() {
    char binary_str[MAX_INPUT_SIZE];
    int decimal_value = 0;
    srand(time(NULL));

    printf("Enter a binary string (max %d characters): ", MAX_INPUT_SIZE);
    fgets(binary_str, MAX_INPUT_SIZE, stdin);

    binary_to_decimal(binary_str, &decimal_value);
    printf("Decimal value: %d\n", decimal_value);

    decimal_to_binary(decimal_value, binary_str);
    printf("Binary string: %s\n", binary_str);

    return 0;
}