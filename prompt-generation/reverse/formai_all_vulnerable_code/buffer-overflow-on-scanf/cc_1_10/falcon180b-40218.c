//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32

int is_valid_binary(char* binary_str);
int binary_to_decimal(char* binary_str, int* decimal_num);
char* decimal_to_binary(int decimal_num, char* binary_str);

int main() {
    char binary_str[MAX_NUM_LENGTH];
    int decimal_num;

    printf("Enter a binary number: ");
    scanf("%s", binary_str);

    if (!is_valid_binary(binary_str)) {
        printf("Invalid binary number!\n");
        return 1;
    }

    binary_to_decimal(binary_str, &decimal_num);
    printf("Decimal equivalent: %d\n", decimal_num);

    char binary_decimal_str[MAX_NUM_LENGTH];
    decimal_to_binary(decimal_num, binary_decimal_str);
    printf("Binary equivalent: %s\n", binary_decimal_str);

    return 0;
}

int is_valid_binary(char* binary_str) {
    int i;
    for (i = 0; i < strlen(binary_str); i++) {
        if (binary_str[i]!= '0' && binary_str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

int binary_to_decimal(char* binary_str, int* decimal_num) {
    int i, j, power;
    for (i = strlen(binary_str) - 1, j = 0, power = 0; i >= 0; i--, power++) {
        if (binary_str[i] == '1') {
            j += pow(2, power);
        }
    }
    *decimal_num = j;
    return 1;
}

char* decimal_to_binary(int decimal_num, char* binary_str) {
    int i, remainder;
    for (i = 0; i < MAX_NUM_LENGTH; i++) {
        remainder = decimal_num % 2;
        binary_str[i] = remainder + '0';
        decimal_num /= 2;
        if (decimal_num == 0) {
            break;
        }
    }
    binary_str[i] = '\0';
    return binary_str;
}