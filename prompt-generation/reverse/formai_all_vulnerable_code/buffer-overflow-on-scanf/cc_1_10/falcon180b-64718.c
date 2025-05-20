//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 200

// Function to check if a character is a valid hexadecimal digit
int is_valid_hex_digit(char c) {
    if (isdigit(c)) {
        return 1;
    } else if (c >= 'a' && c <= 'f') {
        return 1;
    } else if (c >= 'A' && c <= 'F') {
        return 1;
    }
    return 0;
}

// Function to convert a hexadecimal string to a decimal integer
int hex_to_dec(char* hex_str, int* dec_num) {
    int len = strlen(hex_str);
    int i = 0;
    int j = 0;
    int value = 0;
    while (i < len) {
        if (is_valid_hex_digit(hex_str[i])) {
            value += (hex_str[i] - '0' + 9 * (hex_str[i] >= 'A'));
            i++;
        } else {
            return 0;
        }
    }
    *dec_num = value;
    return 1;
}

// Function to convert a decimal integer to a hexadecimal string
void dec_to_hex(int dec_num, char* hex_str) {
    int len = 0;
    int i = 0;
    while (dec_num > 0) {
        hex_str[len++] = (dec_num % 16 < 10? '0' + dec_num % 16 : 'A' + dec_num % 16 - 10);
        dec_num /= 16;
    }
    hex_str[len] = '\0';
    for (i = 0; i < len / 2; i++) {
        char temp = hex_str[i];
        hex_str[i] = hex_str[len - i - 1];
        hex_str[len - i - 1] = temp;
    }
}

int main() {
    char hex_str[MAX_INPUT_SIZE];
    int dec_num;
    int i;
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_str);
    if (hex_to_dec(hex_str, &dec_num)) {
        printf("The decimal equivalent is: ");
        dec_to_hex(dec_num, hex_str);
        printf("%s\n", hex_str);
    } else {
        printf("Invalid hexadecimal string.\n");
    }
    return 0;
}