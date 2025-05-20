//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

// Function to count the number of set bits in an integer
int count_bits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    int num, i, j, k;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Count the number of set bits in the given integer
    int bit_count = count_bits(num);

    // Print the binary representation of the integer
    printf("Binary representation of %d: ", num);
    for (i = 0; i < 32; i++) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    // Print the number of set bits
    printf("Number of set bits: %d\n", bit_count);

    // Perform bitwise operations on the integer
    num = num << 2; // Shift left by 2 bits
    printf("Shifted left by 2 bits: %d\n", num);

    num = num >> 3; // Shift right by 3 bits
    printf("Shifted right by 3 bits: %d\n", num);

    num = num & 0x7; // Bitwise AND with 7 (binary 0111)
    printf("Bitwise AND with 7: %d\n", num);

    num = num | 0x8; // Bitwise OR with 8 (binary 1000)
    printf("Bitwise OR with 8: %d\n", num);

    num = num ^ 0x5; // Bitwise XOR with 5 (binary 0101)
    printf("Bitwise XOR with 5: %d\n", num);

    return 0;
}