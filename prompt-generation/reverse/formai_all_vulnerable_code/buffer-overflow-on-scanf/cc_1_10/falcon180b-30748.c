//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 100
#define BINARY_DIGITS "01"
#define HEX_DIGITS "0123456789ABCDEF"
#define OCTAL_DIGITS "01234567"
#define DECIMAL_DIGITS "0123456789"

void convert_binary_to_decimal(char* binary_buffer) {
    int decimal_value = 0;
    int i = 0;
    while (binary_buffer[i]!= '\0') {
        if (binary_buffer[i] == '1') {
            decimal_value += pow(2, strlen(binary_buffer) - 1 - i);
        }
        i++;
    }
    printf("Decimal value: %d\n", decimal_value);
}

void convert_decimal_to_binary(int decimal_value) {
    char binary_buffer[MAX_BUFFER_SIZE];
    int i = 0;
    while (decimal_value > 0) {
        int remainder = decimal_value % 2;
        binary_buffer[i] = remainder + '0';
        i++;
        decimal_value /= 2;
    }
    binary_buffer[i] = '\0';
    printf("Binary value: %s\n", binary_buffer);
}

void convert_binary_to_hexadecimal(char* binary_buffer) {
    char hexadecimal_buffer[MAX_BUFFER_SIZE];
    int i = 0;
    while (i < strlen(binary_buffer) / 4) {
        int j = 0;
        int hexadecimal_digit = 0;
        while (j < 4) {
            if (binary_buffer[i * 4 + j] == '1') {
                hexadecimal_digit += pow(2, 3 - j);
            }
            j++;
        }
        sprintf(&hexadecimal_buffer[i * 2], "%02X", hexadecimal_digit);
        i++;
    }
    hexadecimal_buffer[i * 2] = '\0';
    printf("Hexadecimal value: %s\n", hexadecimal_buffer);
}

void convert_binary_to_octal(char* binary_buffer) {
    char octal_buffer[MAX_BUFFER_SIZE];
    int i = 0;
    while (i < strlen(binary_buffer) / 3) {
        int j = 0;
        int octal_digit = 0;
        while (j < 3) {
            if (binary_buffer[i * 3 + j] == '1') {
                octal_digit += pow(2, 2 - j);
            }
            j++;
        }
        sprintf(&octal_buffer[i * 3], "%03o", octal_digit);
        i++;
    }
    octal_buffer[i * 3] = '\0';
    printf("Octal value: %s\n", octal_buffer);
}

int main() {
    char input_buffer[MAX_BUFFER_SIZE];
    printf("Enter a binary number: ");
    scanf("%s", input_buffer);

    convert_binary_to_decimal(input_buffer);
    convert_binary_to_hexadecimal(input_buffer);
    convert_binary_to_octal(input_buffer);

    return 0;
}