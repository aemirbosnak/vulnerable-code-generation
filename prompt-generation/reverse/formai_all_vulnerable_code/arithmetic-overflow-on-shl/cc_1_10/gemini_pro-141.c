//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BIT(n) (1 << (n))

int main() {
    // Initialize an array of 32-bit integers.
    uint32_t arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Print the original array.
    printf("Original array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform bitwise operations on the array.
    for (int i = 0; i < 10; i++) {
        arr[i] |= BIT(i);  // Set the ith bit of each element.
        arr[i] &= ~BIT(i + 1);  // Clear the (i + 1)th bit of each element.
        arr[i] ^= BIT(i - 1);  // Toggle the (i - 1)th bit of each element.
    }

    // Print the modified array.
    printf("Modified array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform bitwise operations on individual bits.
    uint32_t a = 0xABCD1234;
    uint32_t b = 0x567890EF;

    // Check if the 16th bit of a is set.
    if (a & BIT(15)) {
        printf("The 16th bit of a is set.\n");
    } else {
        printf("The 16th bit of a is not set.\n");
    }

    // Set the 8th bit of b.
    b |= BIT(7);

    // Clear the 24th bit of a.
    a &= ~BIT(23);

    // Toggle the 31st bit of b.
    b ^= BIT(31);

    // Print the modified values of a and b.
    printf("a = 0x%08X\n", a);
    printf("b = 0x%08X\n", b);

    return 0;
}