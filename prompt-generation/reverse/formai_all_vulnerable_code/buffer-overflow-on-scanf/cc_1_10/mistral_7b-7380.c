//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BIT_SIZE (CHAR_BIT * sizeof(unsigned int))

void print_binary(unsigned int num) {
    int i;
    for (i = BIT_SIZE - 1; i >= 0; i--) {
        putchar((num >> i) & 1 ? '1' : '0');
    }
    putchar('\n');
}

int main(void) {
    unsigned int x, y, z;

    printf("Enter two numbers: ");
    scanf("%u %u", &x, &y);

    z = x & y;
    print_binary(x);
    printf(" AND ");
    print_binary(y);
    print_binary(z);
    printf(" = %u\n", z);

    z = x | y;
    print_binary(x);
    printf(" OR ");
    print_binary(y);
    print_binary(z);
    printf(" = %u\n", z);

    z = x ^ y;
    print_binary(x);
    printf(" XOR ");
    print_binary(y);
    print_binary(z);
    printf(" = %u\n", z);

    z = ~x;
    print_binary(x);
    printf(" NOT ");
    print_binary(z);
    printf(" = %u\n", z);

    z = x << 2;
    print_binary(x);
    printf(" LEFT SHIFT ");
    print_binary(1 << 2);
    print_binary(z);
    printf(" = %u\n", z);

    z = x >> 2;
    print_binary(x);
    printf(" RIGHT SHIFT ");
    print_binary(1 << 2);
    print_binary(z);
    printf(" = %u\n", z);

    return EXIT_SUCCESS;
}