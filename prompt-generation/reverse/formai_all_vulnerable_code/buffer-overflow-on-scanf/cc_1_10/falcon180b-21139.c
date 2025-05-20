//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

// Function to count the number of set bits in an integer
int count_bits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n &= (n - 1);
    }
    return count;
}

int main() {
    unsigned int n, m;
    printf("Enter an integer: ");
    scanf("%u", &n);
    printf("Number of set bits: %d\n", count_bits(n));

    printf("Enter another integer: ");
    scanf("%u", &m);

    printf("n = %u (binary: %b)\n", n, n);
    printf("m = %u (binary: %b)\n", m, m);

    // Bitwise AND operation
    unsigned int result = n & m;
    printf("n & m = %u (binary: %b)\n", result, result);

    // Bitwise OR operation
    result = n | m;
    printf("n | m = %u (binary: %b)\n", result, result);

    // Bitwise XOR operation
    result = n ^ m;
    printf("n ^ m = %u (binary: %b)\n", result, result);

    // Bitwise NOT operation
    result = ~n;
    printf("~n = %u (binary: %b)\n", result, result);

    // Bitwise left shift operation
    result = n << 2;
    printf("n << 2 = %u (binary: %b)\n", result, result);

    // Bitwise right shift operation
    result = n >> 2;
    printf("n >> 2 = %u (binary: %b)\n", result, result);

    return 0;
}