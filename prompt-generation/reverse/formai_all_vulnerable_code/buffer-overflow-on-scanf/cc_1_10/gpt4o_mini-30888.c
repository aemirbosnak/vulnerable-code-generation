//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void printBinary(int num) {
    int i;
    for (i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void performBitwiseOperations(int a, int b) {
    printf("Operands: \n");
    printf("A = %d, B = %d\n", a, b);
    printf("Binary Representation: \n");
    printf("A: ");
    printBinary(a);
    printf("B: ");
    printBinary(b);

    printf("\nBitwise Operations:\n");
    printf("A & B: %d\n", a & b);
    printf("Binary: ");
    printBinary(a & b);

    printf("A | B: %d\n", a | b);
    printf("Binary: ");
    printBinary(a | b);

    printf("A ^ B: %d\n", a ^ b);
    printf("Binary: ");
    printBinary(a ^ b);

    printf("~A: %d\n", ~a);
    printf("Binary: ");
    printBinary(~a);

    printf("~B: %d\n", ~b);
    printf("Binary: ");
    printBinary(~b);

    printf("A << 1: %d\n", a << 1);
    printf("Binary: ");
    printBinary(a << 1);

    printf("A >> 1: %d\n", a >> 1);
    printf("Binary: ");
    printBinary(a >> 1);

    printf("B << 1: %d\n", b << 1);
    printf("Binary: ");
    printBinary(b << 1);

    printf("B >> 1: %d\n", b >> 1);
    printf("Binary: ");
    printBinary(b >> 1);
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "Error reading input. Please enter valid integers.\n");
        return EXIT_FAILURE;
    }

    performBitwiseOperations(num1, num2);

    return EXIT_SUCCESS;
}