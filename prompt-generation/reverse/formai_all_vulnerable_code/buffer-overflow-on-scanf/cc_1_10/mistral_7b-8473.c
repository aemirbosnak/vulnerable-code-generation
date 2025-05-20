//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_binary(int number) {
    if (number > 0) {
        print_binary(number >> 1);
        printf("%d", number & 1);
    }
}

void print_bitwise_xor(int x, int y) {
    if (x > y) {
        print_bitwise_xor(x - y, y);
    } else {
        printf(" x ^ y = ");
        print_binary(x ^ y);
        printf("\n");
    }
}

void print_bitwise_and(int x, int y) {
    if (x > y) {
        print_bitwise_and(x - y, y);
    } else {
        printf(" x & y = ");
        print_binary(x & y);
        printf("\n");
    }
}

void print_bitwise_or(int x, int y) {
    if (x > y) {
        print_bitwise_or(x - y, y);
    } else {
        printf(" x | y = ");
        print_binary(x | y);
        printf("\n");
    }
}

int main() {
    int num, x = 5, y = 3;

    printf("Enter a number to print its binary representation: ");
    scanf("%d", &num);

    printf("\nBinary representation of %d:\n", num);
    print_binary(num);
    printf("\n");

    printf("Bitwise AND of %d and %d:\n", x, y);
    print_bitwise_and(x, y);

    printf("Bitwise OR of %d and %d:\n", x, y);
    print_bitwise_or(x, y);

    printf("Bitwise XOR of %d and %d:\n", x, y);
    print_bitwise_xor(x, y);

    return 0;
}