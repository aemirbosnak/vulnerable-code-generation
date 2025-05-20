//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <inttypes.h>

#define BINARY_LENGTH 32
#define MAX_NUMBER 1000000000

struct binary_number {
    unsigned int length;
    unsigned int value;
};

void convert_binary(struct binary_number *binary, int number) {
    int i, j;
    unsigned int temp;

    binary->length = 0;
    binary->value = 0;

    for (i = 0; i < log2(number); i++) {
        temp = number >> i;
        if (temp & 1) {
            binary->value |= (1 << (BINARY_LENGTH - 1 - i));
            binary->length++;
        }
    }
}

int main() {
    struct binary_number binary;
    int number;

    srand(time(NULL));
    number = (int)((float)rand() / RAND_MAX * MAX_NUMBER) + 1;

    convert_binary(&binary, number);

    printf("Original number: %d\n", number);
    printf("Binary representation: ");
    for (int i = 0; i < binary.length; i++) {
        printf("%c", binary.value & 1 ? '1' : '0');
        binary.value >>= 1;
    }
    printf("\n");

    return 0;
}