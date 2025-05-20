//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

/* Function to print bits of a number */
void print_bits(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i))
            printf("1");
        else
            printf("0");
    }
}

/* Function to perform bitwise operations */
int main() {
    unsigned int num1 = 0b10101010;
    unsigned int num2 = 0b11110000;
    unsigned int result;

    /* Bitwise AND */
    result = num1 & num2;
    printf("Bitwise AND: ");
    print_bits(result);

    /* Bitwise OR */
    result = num1 | num2;
    printf("\nBitwise OR: ");
    print_bits(result);

    /* Bitwise XOR */
    result = num1 ^ num2;
    printf("\nBitwise XOR: ");
    print_bits(result);

    /* Bitwise NOT */
    result = ~num1;
    printf("\nBitwise NOT: ");
    print_bits(result);

    /* Left Shift */
    result = num1 << 2;
    printf("\nLeft Shift by 2: ");
    print_bits(result);

    /* Right Shift */
    result = num1 >> 2;
    printf("\nRight Shift by 2: ");
    print_bits(result);

    return 0;
}