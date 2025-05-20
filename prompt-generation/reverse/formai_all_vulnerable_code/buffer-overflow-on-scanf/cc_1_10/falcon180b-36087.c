//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DIGITS 1000
#define MAX_NUM_LENGTH 4

int is_valid_binary(char *binary_str) {
    for (int i = 0; i < strlen(binary_str); i++) {
        if (binary_str[i]!= '0' && binary_str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

int get_binary_length(char *binary_str) {
    int length = 0;
    while (binary_str[length]!= '\0') {
        length++;
    }
    return length;
}

void convert_binary_to_decimal(char *binary_str, int *decimal_num) {
    int binary_length = get_binary_length(binary_str);
    int decimal_digits = 0;
    int i = 0;
    int j = 0;
    while (i < binary_length) {
        if (binary_str[i] == '1') {
            decimal_digits += pow(2, binary_length - i - 1);
        }
        i++;
    }
    *decimal_num = decimal_digits;
}

void main() {
    char binary_str[MAX_NUM_DIGITS];
    int decimal_num;
    printf("Enter a binary number: ");
    scanf("%s", binary_str);
    if (!is_valid_binary(binary_str)) {
        printf("Invalid binary number!\n");
        exit(1);
    }
    convert_binary_to_decimal(binary_str, &decimal_num);
    printf("Decimal representation: %d\n", decimal_num);
}