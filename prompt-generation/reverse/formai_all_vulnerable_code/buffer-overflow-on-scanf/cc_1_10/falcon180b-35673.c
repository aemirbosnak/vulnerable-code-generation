//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print binary representation of a number
void binary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    printf("%d", n % 2);
    binary(n / 2);
}

int main() {
    int n, m, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);

    // Bitwise AND operation
    printf("\nBitwise AND: ");
    result = n & m;
    binary(result);
    printf("\n");

    // Bitwise OR operation
    printf("Bitwise OR: ");
    result = n | m;
    binary(result);
    printf("\n");

    // Bitwise XOR operation
    printf("Bitwise XOR: ");
    result = n ^ m;
    binary(result);
    printf("\n");

    // Left shift operation
    printf("Left shift: ");
    for (int i = 0; i < 8; i++) {
        result = n << i;
        printf("%d ", result);
    }
    printf("\n");

    // Right shift operation
    printf("Right shift: ");
    for (int i = 0; i < 8; i++) {
        result = n >> i;
        printf("%d ", result);
    }
    printf("\n");

    // Bitwise NOT operation
    printf("Bitwise NOT: ");
    result = ~n;
    binary(result);
    printf("\n");

    // Bitwise complement operation
    printf("Bitwise complement: ");
    result = ~(n | m);
    binary(result);
    printf("\n");

    return 0;
}