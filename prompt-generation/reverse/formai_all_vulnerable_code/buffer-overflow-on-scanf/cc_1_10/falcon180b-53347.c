//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void convert_hex_to_decimal(char hex[], int decimal[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal[i] = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal[i] = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal[i] = hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
    }
}

void convert_decimal_to_hex(int decimal[], char hex[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        if (decimal[i] >= 0 && decimal[i] <= 9) {
            hex[i] = decimal[i] + '0';
        } else if (decimal[i] >= 10 && decimal[i] <= 15) {
            hex[i] = decimal[i] - 10 + 'A';
        } else {
            printf("Invalid decimal character: %d\n", decimal[i]);
            exit(1);
        }
    }
}

int main() {
    char hex[MAX_SIZE];
    int decimal[MAX_SIZE];
    int size = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    while (hex[size]!= '\0') {
        size++;
    }

    convert_hex_to_decimal(hex, decimal, size);

    printf("Decimal equivalent: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", decimal[i]);
    }

    printf("\n");

    return 0;
}