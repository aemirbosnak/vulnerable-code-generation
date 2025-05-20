//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM_SIZE 1000
#define BINARY_NUM_SIZE (MAX_NUM_SIZE * 8 + 1)

typedef struct {
    char binary[MAX_NUM_SIZE];
    int decimal;
} Number;

Number *create_number() {
    Number *number = malloc(sizeof(Number));
    number->binary[0] = '\0';
    number->decimal = 0;
    return number;
}

void delete_number(Number *number) {
    free(number);
}

void set_binary(Number *number, const char *binary) {
    strcpy(number->binary, binary);
    number->decimal = 0;
}

int get_decimal(Number *number) {
    if (number->decimal == 0) {
        int decimal = 0;
        int i = strlen(number->binary) - 1;
        while (i >= 0) {
            if (number->binary[i] == '1') {
                decimal += pow(2, strlen(number->binary) - i - 1);
            }
            i--;
        }
        number->decimal = decimal;
    }
    return number->decimal;
}

void print_binary(Number *number) {
    printf("Binary: %s\n", number->binary);
}

void print_decimal(Number *number) {
    printf("Decimal: %d\n", get_decimal(number));
}

int main() {
    Number *number = create_number();
    set_binary(number, "101010");
    print_binary(number);
    print_decimal(number);
    delete_number(number);
    return 0;
}