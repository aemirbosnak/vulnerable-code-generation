//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DIGITS 32

typedef struct {
    int num_digits;
    char digits[MAX_NUM_DIGITS];
} binary_t;

binary_t *binary_create(int num_digits) {
    binary_t *binary = malloc(sizeof(binary_t));
    binary->num_digits = num_digits;
    memset(binary->digits, '0', MAX_NUM_DIGITS);
    return binary;
}

void binary_destroy(binary_t *binary) {
    free(binary);
}

void binary_set_digit(binary_t *binary, int index, char digit) {
    if (index >= 0 && index < binary->num_digits) {
        binary->digits[index] = digit;
    }
}

void binary_print(binary_t *binary) {
    for (int i = binary->num_digits - 1; i >= 0; i--) {
        printf("%c", binary->digits[i]);
    }
    printf("\n");
}

int main() {
    int num_digits, decimal_num;
    char binary_num[MAX_NUM_DIGITS];

    printf("Enter the number of binary digits: ");
    scanf("%d", &num_digits);

    binary_t *binary = binary_create(num_digits);

    printf("Enter the decimal number to convert to binary: ");
    scanf("%d", &decimal_num);

    char *binary_str = malloc(num_digits + 1);
    sprintf(binary_str, "%d", decimal_num);

    int binary_idx = 0;
    for (int i = strlen(binary_str) - 1; i >= 0; i--) {
        char digit = binary_str[i] - '0';
        binary_set_digit(binary, binary_idx++, digit);
    }

    binary_print(binary);

    binary_destroy(binary);
    free(binary_str);

    return 0;
}