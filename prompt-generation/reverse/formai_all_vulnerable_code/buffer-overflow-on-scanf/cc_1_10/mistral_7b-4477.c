//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8
#define NUM_BYTES 4

void print_binary(unsigned int num) {
    int i, byte, bit;
    for (i = NUM_BYTES; i > 0; i--) {
        byte = num >> (8 * (NUM_BYTES - i));
        printf("Byte %d: ", NUM_BYTES - i);
        for (bit = 7; bit >= 0; bit--) {
            printf("%d", (byte >> bit) & 1);
        }
        printf("\n");
    }
}

int main() {
    unsigned int num, mask, result;

    while (1) {
        printf("Enter an integer (0 to quit): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        printf("\nBitwise operations for number %d:\n", num);

        // AND
        mask = 0xFFFFFFFF;
        mask &= num;
        printf("AND: %x\n", mask);

        // OR
        mask = 0xFFFFFFFF;
        mask |= num;
        printf("OR : %x\n", mask);

        // XOR
        mask = 0xFFFFFFFF;
        mask ^= num;
        printf("XOR: %x\n", mask);

        // NOT
        mask = ~num;
        printf("NOT: %x\n", mask);

        // Left shift
        printf("Enter the number of positions to shift: ");
        int shift;
        scanf("%d", &shift);
        mask = num << shift;
        printf("Left shift by %d: %x\n", shift, mask);

        print_binary(num);
        printf("\n");
    }

    return 0;
}