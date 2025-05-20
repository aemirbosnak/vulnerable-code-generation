//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32
#define MAX_NUM_LENGTH 9

void print_binary(unsigned int num, int num_bits) {
    char binary[MAX_NUM_LENGTH];
    int i;

    for (i = num_bits - 1; i >= 0; i--) {
        if (num & (1 << i)) {
            strcat(binary, "1");
        } else {
            strcat(binary, "0");
        }
    }

    printf("%s\n", binary);
}

int main() {
    unsigned int num;
    int num_bits;

    printf("Enter a decimal number: ");
    if (scanf("%u", &num)!= 1) {
        printf("Invalid input.\n");
        exit(1);
    }

    printf("Enter the number of bits: ");
    if (scanf("%d", &num_bits)!= 1) {
        printf("Invalid input.\n");
        exit(1);
    }

    if (num_bits > MAX_BITS) {
        printf("Number of bits too large.\n");
        exit(1);
    }

    if (num_bits < 1) {
        printf("Number of bits too small.\n");
        exit(1);
    }

    if (num > (1 << num_bits) - 1) {
        printf("Decimal number too large for given number of bits.\n");
        exit(1);
    }

    print_binary(num, num_bits);

    return 0;
}