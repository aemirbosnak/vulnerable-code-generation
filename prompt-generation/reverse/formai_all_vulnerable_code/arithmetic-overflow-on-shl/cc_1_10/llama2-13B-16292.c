//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>

// Function to print the bits of an integer
void print_bits(int x) {
    int i;
    for (i = 0; i < 32; i++) {
        if (x & (1 << i)) {
            printf("%d", i);
        }
    }
    printf("\n");
}

int main() {
    int a, b, c;

    // Example 1: Bitwise AND
    a = 0x12345678;
    b = 0x89abcdef;
    c = a & b;
    print_bits(c);

    // Example 2: Bitwise OR
    a = 0x12345678;
    b = 0x89abcdef;
    c = a | b;
    print_bits(c);

    // Example 3: Bitwise XOR
    a = 0x12345678;
    b = 0x89abcdef;
    c = a ^ b;
    print_bits(c);

    // Example 4: Bitwise NOT
    a = 0x12345678;
    c = ~a;
    print_bits(c);

    // Example 5: Bit shift left
    a = 0x12345678;
    c = a << 4;
    print_bits(c);

    // Example 6: Bit shift right
    a = 0x12345678;
    c = a >> 4;
    print_bits(c);

    return 0;
}