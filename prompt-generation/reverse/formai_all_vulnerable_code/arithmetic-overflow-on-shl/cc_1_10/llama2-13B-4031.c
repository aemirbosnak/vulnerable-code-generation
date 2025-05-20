//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>

// Function to print the binary representation of a number
void print_binary(int n) {
    int i, j;
    for (i = 0, j = 1; i < 32; i++, j <<= 1) {
        if (n & j) {
            printf("%d", j);
        }
    }
    printf("\n");
}

// Function to reverse the bits of a number
int reverse_bits(int n) {
    int r = 0;
    for (int i = 0; i < 32; i++) {
        r <<= 1;
        r |= (n & (1 << i)) ? 1 : 0;
    }
    return r;
}

// Function to find the first set bit in a number
int first_set_bit(int n) {
    int i;
    for (i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            return i;
        }
    }
    return -1;
}

// Function to check if a number is a power of 2
int is_power_of_2(int n) {
    return (n & (n - 1)) == 0;
}

int main() {
    int n = 123456789;

    // Print the binary representation of n
    print_binary(n);

    // Reverse the bits of n
    int r = reverse_bits(n);
    print_binary(r);

    // Find the first set bit in n
    int first_bit = first_set_bit(n);
    printf("First set bit: %d\n", first_bit);

    // Check if n is a power of 2
    if (is_power_of_2(n)) {
        printf("n is a power of 2\n");
    } else {
        printf("n is not a power of 2\n");
    }

    return 0;
}