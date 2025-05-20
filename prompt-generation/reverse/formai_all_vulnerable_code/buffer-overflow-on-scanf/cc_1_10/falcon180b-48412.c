//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_STRING_LENGTH 100

void hex_to_decimal(char* hex_str, int* decimal_num) {
    int len = strlen(hex_str);
    if (len == 0) {
        *decimal_num = 0;
        return;
    }
    int power = 0;
    int decimal_value = 0;
    for (int i = len - 1; i >= 0; i--) {
        char c = hex_str[i];
        if (c >= '0' && c <= '9') {
            decimal_value += (c - '0') * (int)pow(16, power);
        } else if (c >= 'A' && c <= 'F') {
            decimal_value += (c - 'A' + 10) * (int)pow(16, power);
        } else if (c >= 'a' && c <= 'f') {
            decimal_value += (c - 'a' + 10) * (int)pow(16, power);
        } else {
            printf("Invalid hexadecimal character: %c\n", c);
            exit(1);
        }
        power++;
    }
    *decimal_num = decimal_value;
}

void decimal_to_hex(int decimal_num, char* hex_str) {
    int len = strlen(hex_str);
    if (len == 0) {
        hex_str[0] = '\0';
        return;
    }
    int power = 0;
    while (decimal_num!= 0) {
        int remainder = decimal_num % 16;
        if (remainder < 10) {
            hex_str[len - 1] = '0' + remainder;
        } else {
            hex_str[len - 1] = 'A' + remainder - 10;
        }
        decimal_num /= 16;
        len++;
    }
    hex_str[len - 1] = '\0';
}

int main() {
    char hex_str[MAX_HEX_STRING_LENGTH];
    int decimal_num;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);
    hex_to_decimal(hex_str, &decimal_num);
    printf("Decimal equivalent: %d\n", decimal_num);
    char dec_str[33];
    sprintf(dec_str, "%d", decimal_num);
    decimal_to_hex(decimal_num, hex_str);
    printf("Hexadecimal equivalent: %s\n", hex_str);
    return 0;
}