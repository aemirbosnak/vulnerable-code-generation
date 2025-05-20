//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MAX_NUM_OF_BITS 32

void binary_to_decimal(int binary[], int length, int decimal[]);
void decimal_to_binary(int decimal, int binary[], int length);
void print_binary(int binary[], int length);

int main() {
    int binary[MAX_LENGTH], decimal, length;
    char input[MAX_LENGTH];
    int choice;

    do {
        printf("Enter a binary number (up to %d bits): ", MAX_NUM_OF_BITS);
        scanf("%s", input);
        length = strlen(input);
        if (length > MAX_NUM_OF_BITS) {
            printf("Error: Binary number too long.\n");
            continue;
        }
        for (int i = 0; i < length; i++) {
            if (input[i]!= '0' && input[i]!= '1') {
                printf("Error: Invalid binary number.\n");
                continue;
            }
        }
        for (int i = 0; i < length; i++) {
            binary[i] = input[i] - '0';
        }
        decimal = 0;
        for (int i = length - 1; i >= 0; i--) {
            decimal += binary[i] * pow(2, length - 1 - i);
        }
        printf("Decimal equivalent: %d\n", decimal);
        printf("Enter 1 to convert decimal to binary, 0 to exit: ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}

void binary_to_decimal(int binary[], int length, int decimal[]) {
    int i, j, remainder;
    int quotient = 0;

    for (i = length - 1; i >= 0; i--) {
        remainder = binary[i] % 10;
        quotient += remainder * pow(2, length - 1 - i);
    }
    decimal[0] = quotient;
}

void decimal_to_binary(int decimal, int binary[], int length) {
    int i, remainder;

    for (i = 0; i < length; i++) {
        remainder = decimal % 2;
        binary[i] = remainder;
        decimal /= 2;
    }
}

void print_binary(int binary[], int length) {
    int i;

    for (i = 0; i < length; i++) {
        printf("%d", binary[i]);
    }
}