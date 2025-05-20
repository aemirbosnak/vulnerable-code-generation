//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TRIALS 100000
#define NUM_BITS 32

void generate_random_integer(int *integer) {
    srand(time(NULL));
    *integer = rand() % ((1 << NUM_BITS) - 1);
}

void print_integer_in_binary(int integer) {
    char binary_string[NUM_BITS + 1];
    binary_string[NUM_BITS] = '\0';
    int i;
    for (i = NUM_BITS - 1; i >= 0; i--) {
        binary_string[i] = (integer & (1 << i))? '1' : '0';
    }
    printf("%s\n", binary_string);
}

int main() {
    int integer1, integer2, result;
    int i;

    for (i = 0; i < NUM_TRIALS; i++) {
        generate_random_integer(&integer1);
        generate_random_integer(&integer2);

        printf("Integer 1: ");
        print_integer_in_binary(integer1);
        printf("Integer 2: ");
        print_integer_in_binary(integer2);

        result = integer1 & integer2;
        printf("Bitwise AND: ");
        print_integer_in_binary(result);

        result = integer1 | integer2;
        printf("Bitwise OR: ");
        print_integer_in_binary(result);

        result = integer1 ^ integer2;
        printf("Bitwise XOR: ");
        print_integer_in_binary(result);

        result = integer1 << 2;
        printf("Bitwise left shift by 2: ");
        print_integer_in_binary(result);

        result = integer1 >> 2;
        printf("Bitwise right shift by 2: ");
        print_integer_in_binary(result);

        result = ~integer1;
        printf("Bitwise NOT: ");
        print_integer_in_binary(result);

        printf("\n");
    }

    return 0;
}