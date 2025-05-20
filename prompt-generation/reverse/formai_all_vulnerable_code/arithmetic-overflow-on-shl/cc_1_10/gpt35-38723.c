//FormAI DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Bitwise AND
    int a = 15 & 9;
    printf("15 & 9 = %d\n", a);
    // Expected Output: 9

    // Bitwise OR
    int b = 15 | 9;
    printf("15 | 9 = %d\n", b);
    // Expected Output: 15

    // Bitwise XOR
    int c = 15 ^ 9;
    printf("15 ^ 9 = %d\n", c);
    // Expected Output: 6

    // Bitwise NOT
    int d = ~15;
    printf("~15 = %d\n", d);
    // Expected Output: -16

    // Bitwise LEFT SHIFT
    int e = 15 << 2;
    printf("15 << 2 = %d\n", e);
    // Expected Output: 60

    // Bitwise RIGHT SHIFT
    int f = 15 >> 2;
    printf("15 >> 2 = %d\n", f);
    // Expected Output: 3

    // Bitwise LEFT ROTATE
    int g = 15 << 2 | 15 >> (32 - 2);
    printf("15 << 2 | 15 >> (32 - 2) = ");
    printBinary(g);
    // Expected Output: 1111000000000000000000000000011

    // Bitwise RIGHT ROTATE
    int h = 15 >> 2 | 15 << (32 - 2);
    printf("15 >> 2 | 15 << (32 - 2) = ");
    printBinary(h);
    // Expected Output: 11000000000000000000000000000111

    return 0;
}