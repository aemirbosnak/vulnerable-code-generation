//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM_LENGTH 33
#define MAX_BIN_LENGTH (MAX_NUM_LENGTH * 8)

int is_valid_binary(char *binary) {
    for (int i = 0; i < strlen(binary); i++) {
        if (!isdigit(binary[i]) && binary[i]!= '0' && binary[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

int is_valid_decimal(char *decimal) {
    for (int i = 0; i < strlen(decimal); i++) {
        if (!isdigit(decimal[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input_decimal[MAX_NUM_LENGTH];
    char input_binary[MAX_BIN_LENGTH];
    char *decimal_ptr = input_decimal;
    char *binary_ptr = input_binary;

    printf("Enter a decimal number: ");
    scanf("%s", input_decimal);

    if (!is_valid_decimal(input_decimal)) {
        printf("Invalid decimal input\n");
        return 1;
    }

    int decimal = atoi(input_decimal);
    int binary_length = 0;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binary_ptr[binary_length++] = remainder + '0';
        decimal /= 2;
    }

    binary_ptr[binary_length] = '\0';
    printf("Binary representation: %s\n", input_binary);

    return 0;
}