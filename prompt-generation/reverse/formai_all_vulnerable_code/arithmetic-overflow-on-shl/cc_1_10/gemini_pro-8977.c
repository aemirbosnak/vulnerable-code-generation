//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int a, b, c;

    // Get input from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Perform bitwise operations
    c = a & b;  // Bitwise AND
    printf("Bitwise AND: %d\n", c);

    c = a | b;  // Bitwise OR
    printf("Bitwise OR: %d\n", c);

    c = a ^ b;  // Bitwise XOR
    printf("Bitwise XOR: %d\n", c);

    c = ~a;  // Bitwise NOT
    printf("Bitwise NOT: %d\n", c);

    c = a << 2;  // Bitwise left shift
    printf("Bitwise left shift: %d\n", c);

    c = a >> 2;  // Bitwise right shift
    printf("Bitwise right shift: %d\n", c);

    // Perform bitwise operations on bit fields
    struct {
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
    } bits;

    bits.bit1 = 1;
    bits.bit2 = 0;
    bits.bit3 = 1;

    printf("Bit field: %d%d%d\n", bits.bit1, bits.bit2, bits.bit3);

    // Perform bitwise operations on arrays
    int arr[5] = {1, 2, 3, 4, 5};
    int i;

    for (i = 0; i < 5; i++) {
        arr[i] &= 1;  // Set the least significant bit of each element to 1
    }

    for (i = 0; i < 5; i++) {
        printf("Array element %d: %d\n", i, arr[i]);
    }

    return 0;
}