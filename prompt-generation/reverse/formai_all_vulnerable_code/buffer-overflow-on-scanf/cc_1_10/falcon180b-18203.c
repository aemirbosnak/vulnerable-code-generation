//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void binary_to_decimal(char* binary, int size) {
    int decimal = 0;
    int power = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    printf("Decimal: %d\n", decimal);
}

void decimal_to_binary(int decimal, char* binary, int size) {
    int power = 0;
    while (decimal > 0) {
        binary[size - 1 - power] = (decimal % 2) + '0';
        decimal /= 2;
        power++;
    }
    printf("Binary: %s\n", binary);
}

int main() {
    char binary[MAX_SIZE];
    char decimal[MAX_SIZE];
    int choice, size;

    printf("Enter 1 for Binary to Decimal conversion or 2 for Decimal to Binary conversion: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter a binary number: ");
        scanf("%s", binary);
        size = strlen(binary);
        binary_to_decimal(binary, size);
    } else if (choice == 2) {
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        size = sprintf(binary, "%d", decimal);
        decimal_to_binary(decimal, binary, size);
    }

    return 0;
}