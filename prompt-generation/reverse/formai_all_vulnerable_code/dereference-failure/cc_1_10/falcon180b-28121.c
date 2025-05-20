//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_SIZE 1000

int is_valid_binary(const char* binary) {
    int i;
    for (i = 0; i < strlen(binary); i++) {
        if (binary[i]!= '0' && binary[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

void reverse_string(char* str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void binary_to_decimal(const char* binary, char* decimal) {
    int i, j, decimal_val = 0;
    for (i = strlen(binary) - 1, j = 0; i >= 0; i--, j++) {
        if (binary[i] == '1') {
            decimal_val += pow(2, j);
        }
    }
    sprintf(decimal, "%d", decimal_val);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s binary_number decimal_number\n", argv[0]);
        return 1;
    }

    char binary[MAX_NUM_SIZE];
    strcpy(binary, argv[1]);

    reverse_string(binary);

    if (!is_valid_binary(binary)) {
        printf("Invalid binary number\n");
        return 1;
    }

    char decimal[MAX_NUM_SIZE];
    binary_to_decimal(binary, decimal);

    printf("Decimal representation of %s is %s\n", argv[1], decimal);

    return 0;
}