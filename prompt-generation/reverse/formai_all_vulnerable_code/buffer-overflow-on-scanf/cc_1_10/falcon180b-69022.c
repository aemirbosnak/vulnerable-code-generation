//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

char *binary_to_decimal(char *binary) {
    int decimal = 0;
    int power = 1;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }

    char *decimal_string = malloc(MAX_LENGTH);
    sprintf(decimal_string, "%d", decimal);

    return decimal_string;
}

char *decimal_to_binary(int decimal) {
    char *binary = malloc(MAX_LENGTH);
    int power = 1;
    int remainder;

    while (decimal > 0) {
        remainder = decimal % 2;
        strcat(binary, (remainder == 0)? "0" : "1");
        decimal /= 2;
        power *= 10;
    }

    return binary;
}

int main() {
    char binary[MAX_LENGTH];
    char decimal[MAX_LENGTH];

    printf("Enter a binary number: ");
    scanf("%s", binary);

    char *decimal_result = binary_to_decimal(binary);
    printf("Decimal representation: %s\n", decimal_result);

    char *binary_result = decimal_to_binary(atoi(decimal_result));
    printf("Binary representation: %s\n", binary_result);

    free(decimal_result);
    free(binary_result);

    return 0;
}