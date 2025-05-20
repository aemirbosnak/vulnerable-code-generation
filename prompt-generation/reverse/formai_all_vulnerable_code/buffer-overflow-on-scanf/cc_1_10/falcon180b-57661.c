//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DIGITS 32

typedef struct {
    int num_digits;
    char *digits;
} binary_t;

binary_t *binary_create(int num_digits) {
    binary_t *binary = (binary_t *)malloc(sizeof(binary_t));
    binary->num_digits = num_digits;
    binary->digits = (char *)malloc(MAX_NUM_DIGITS * sizeof(char));
    memset(binary->digits, '0', num_digits);
    binary->digits[num_digits] = '\0';
    return binary;
}

void binary_destroy(binary_t *binary) {
    free(binary->digits);
    free(binary);
}

void binary_print(binary_t *binary) {
    printf("%s\n", binary->digits);
}

int main() {
    int num_digits;
    int decimal_num;
    char input_str[MAX_NUM_DIGITS];
    binary_t *binary;

    printf("Enter the number of digits for the binary number: ");
    scanf("%d", &num_digits);

    printf("Enter the decimal number: ");
    scanf("%s", input_str);

    decimal_num = atoi(input_str);
    binary = binary_create(num_digits);

    int quotient = decimal_num;
    int remainder;
    int i = 0;

    while (quotient > 0) {
        remainder = quotient % 2;
        binary->digits[i] = remainder + '0';
        i++;
        quotient /= 2;
    }

    binary_print(binary);
    binary_destroy(binary);

    return 0;
}