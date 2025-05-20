//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_DIGITS 32
#define MAX_DECIMAL_DIGITS 10

void convert_binary_to_decimal(char* binary, int* decimal) {
    int len = strlen(binary);
    int i = 0;
    int j = 0;
    int power = 0;
    while (i < len) {
        if (binary[i] == '1') {
            int num = 0;
            while (i < len && binary[i] == '1') {
                num++;
                i++;
            }
            int value = (int)pow(2, num) - 1;
            *decimal += value;
        } else {
            i++;
        }
    }
}

void convert_decimal_to_binary(int decimal, char* binary) {
    int len = 0;
    int i = 0;
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binary[i] = '1';
            i++;
        } else {
            binary[i] = '0';
            i++;
        }
        decimal /= 2;
        len++;
    }
    binary[i] = '\0';
}

int main() {
    char binary[MAX_BINARY_DIGITS];
    int decimal;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    convert_binary_to_decimal(binary, &decimal);

    printf("Decimal equivalent: %d\n", decimal);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    convert_decimal_to_binary(decimal, binary);

    printf("Binary equivalent: %s\n", binary);

    return 0;
}