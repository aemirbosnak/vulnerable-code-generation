//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BIT_SIZE 32

void print_binary(unsigned int num) {
    int i;
    for (i = BIT_SIZE; i > 0; i--) {
        printf("%d", (num >> (i - 1) & 1));
    }
    printf("\n");
}

int main() {
    unsigned int num, mask, shift, result;

    printf("Enter a 32-bit decimal number: ");
    if (scanf("%u", &num) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    printf("Enter bitmask (0's and 1's separated by spaces): ");
    if (scanf("%u", &mask) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    printf("Enter number of bits to shift: ");
    if (scanf("%u", &shift) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    printf("\nNumber before operations: ");
    print_binary(num);

    result = num & mask;
    printf("Bitwise AND: ");
    print_binary(result);

    result = num | mask;
    printf("Bitwise OR: ");
    print_binary(result);

    result = num ^ mask;
    printf("Bitwise XOR: ");
    print_binary(result);

    result = ~num;
    printf("Bitwise NOT: ");
    print_binary(result);

    result = num << shift;
    printf("Left shift by %d bits: ", shift);
    print_binary(result);

    result = num >> shift;
    printf("Right shift by %d bits: ", shift);
    print_binary(result);

    return 0;
}