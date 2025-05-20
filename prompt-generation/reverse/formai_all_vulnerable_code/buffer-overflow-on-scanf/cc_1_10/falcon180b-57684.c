//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>

// Function to count the number of bits set in a given integer
int count_bits(unsigned int n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n-1);
    }
    return count;
}

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    // Count the number of bits set in the given number
    int bits_set = count_bits(num);
    printf("Number of bits set in %u: %d\n", num, bits_set);

    // Check if the given number is a power of 2
    if (num & (num-1) == 0) {
        printf("%u is a power of 2.\n", num);
    } else {
        printf("%u is not a power of 2.\n", num);
    }

    // Swap the values of two variables without using a third variable
    unsigned int a = 10, b = 20;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After swapping: a = %u, b = %u\n", a, b);

    // Set, clear, and toggle specific bits in a given integer
    unsigned int bit_manip = 0b10101010;
    printf("Original value: %u\n", bit_manip);

    // Set the 5th bit
    bit_manip |= (1 << 4);
    printf("After setting the 5th bit: %u\n", bit_manip);

    // Clear the 3rd bit
    bit_manip &= ~(1 << 2);
    printf("After clearing the 3rd bit: %u\n", bit_manip);

    // Toggle the 7th bit
    bit_manip ^= (1 << 6);
    printf("After toggling the 7th bit: %u\n", bit_manip);

    return 0;
}