//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_DIGITS 32
#define MAX_DECIMAL_DIGITS 10

void print_binary(const char *binary, int length);
void print_decimal(const char *decimal, int length);

int main() {
    char binary[MAX_BINARY_DIGITS];
    char decimal[MAX_DECIMAL_DIGITS];
    int length;

    printf("Binary to Decimal Converter\n");
    printf("Enter a binary number (up to 32 bits): ");
    scanf("%s", binary);
    length = strlen(binary);

    if (length > MAX_BINARY_DIGITS) {
        printf("Error: Binary number is too long.\n");
        return 1;
    }

    int decimal_num = 0;
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal_num += pow(2, length - 1 - i);
        }
    }

    sprintf(decimal, "%d", decimal_num);
    print_binary(binary, length);
    print_decimal(decimal, strlen(decimal));

    return 0;
}

void print_binary(const char *binary, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", binary[i]);
    }
    printf("\n");
}

void print_decimal(const char *decimal, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", decimal[i]);
    }
    printf("\n");
}