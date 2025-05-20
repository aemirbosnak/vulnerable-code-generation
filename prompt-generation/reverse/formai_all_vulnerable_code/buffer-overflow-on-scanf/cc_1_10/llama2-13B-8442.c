//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define BINARY_LENGTH 32

bool is_negative(uint8_t num) {
    return num & 0x80;
}

uint8_t parse_binary(const char *str) {
    uint8_t num = 0;
    while (*str) {
        if (*str == '1') {
            num |= 0x01;
        } else if (*str == '0') {
            num |= 0x02;
        } else {
            break;
        }
        str++;
    }
    return num;
}

void print_binary(uint8_t num) {
    while (num != 0) {
        if (num & 0x01) {
            printf('1');
        } else {
            printf('0');
        }
        num >>= 1;
    }
}

int main() {
    char binary_str[BINARY_LENGTH];
    uint8_t num;

    // Convert decimal to binary
    printf("Enter a decimal number: ");
    scanf("%s", binary_str);
    num = parse_binary(binary_str);
    print_binary(num);

    // Convert binary to decimal
    printf("Enter a binary number: ");
    scanf("%s", binary_str);
    num = parse_binary(binary_str);
    printf("The decimal equivalent of %s is %d\n", binary_str, num);

    return 0;
}