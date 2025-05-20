//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void reverse_string(char *str, int length) {
    char *start = str;
    char *end = str + length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void binary_to_decimal(char *binary_str) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary_str);
    for (int i = length - 1; i >= 0; i--) {
        if (binary_str[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    printf("Decimal value: %d\n", decimal);
}

void decimal_to_binary(int decimal) {
    char binary_str[MAX_LENGTH];
    int length = 0;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary_str[length] = remainder + '0';
        length++;
        decimal /= 2;
    }
    binary_str[length] = '\0';
    reverse_string(binary_str, length);
    printf("Binary value: %s\n", binary_str);
}

int main() {
    char input_str[MAX_LENGTH];
    printf("Enter a binary number: ");
    scanf("%s", input_str);
    decimal_to_binary(atoi(input_str));
    printf("Enter a decimal number: ");
    scanf("%s", input_str);
    binary_to_decimal(input_str);
    return 0;
}