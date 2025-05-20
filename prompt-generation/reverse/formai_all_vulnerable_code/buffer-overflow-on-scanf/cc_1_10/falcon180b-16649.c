//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 100

char *binary_to_decimal(char *binary_num) {
    int decimal_num = 0;
    int base = 1;
    int num_length = strlen(binary_num);

    for (int i = num_length - 1; i >= 0; i--) {
        if (binary_num[i] == '1') {
            decimal_num += base;
        }
        base *= 2;
    }

    char *decimal_str = malloc(MAX_NUM_LENGTH * sizeof(char));
    sprintf(decimal_str, "%d", decimal_num);
    return decimal_str;
}

char *decimal_to_binary(int decimal_num) {
    int binary_num = 0;
    int base = 1;
    char *binary_str = malloc(MAX_NUM_LENGTH * sizeof(char));

    while (decimal_num!= 0) {
        binary_num += (decimal_num % 2) * base;
        decimal_num /= 2;
        base *= 10;
    }

    sprintf(binary_str, "%d", binary_num);
    return binary_str;
}

int main() {
    char *binary_num = "101010";
    char *decimal_num = binary_to_decimal(binary_num);
    printf("Decimal number: %s\n", decimal_num);

    free(decimal_num);

    int decimal_num_input;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num_input);

    char *binary_num_output = decimal_to_binary(decimal_num_input);
    printf("Binary number: %s\n", binary_num_output);

    free(binary_num_output);

    return 0;
}