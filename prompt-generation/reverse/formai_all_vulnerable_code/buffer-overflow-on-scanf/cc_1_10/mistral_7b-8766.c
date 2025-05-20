//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

void print_binary(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int a, b, result;
    int *array;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("\nBitwise AND:\n");
    result = a & b;
    print_binary(result);
    printf("Decimal: %d\n", result);

    printf("\nBitwise OR:\n");
    result = a | b;
    print_binary(result);
    printf("Decimal: %d\n", result);

    printf("\nBitwise XOR:\n");
    result = a ^ b;
    print_binary(result);
    printf("Decimal: %d\n", result);

    printf("\nLeft Shift:\n");
    result = a << 2;
    print_binary(result);
    printf("Decimal: %d\n", result);

    printf("\nRight Shift:\n");
    result = a >> 2;
    print_binary(result);
    printf("Decimal: %d\n", result);

    printf("\nMemory Allocation:\n");
    array = (int*) malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        array[i] = (i + 1) << 3; // set each element to 8 times its index
    }

    printf("\nPrinting array:\n");
    for (int i = 0; i < SIZE; i++) {
        print_binary(array[i]);
        printf("Decimal: %d\n", array[i]);
    }

    free(array);

    return 0;
}