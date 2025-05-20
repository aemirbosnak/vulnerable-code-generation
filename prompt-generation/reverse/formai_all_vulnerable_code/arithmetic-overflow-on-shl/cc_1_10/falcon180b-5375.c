//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a bitwise representation of a number
void print_bits(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to perform bitwise operations on two numbers
void bitwise_ops(unsigned int num1, unsigned int num2) {
    printf("Bitwise operations:\n");
    printf("OR: ");
    printf("%u | %u = ", num1, num2);
    printf("%u\n", num1 | num2);

    printf("AND: ");
    printf("%u & %u = ", num1, num2);
    printf("%u\n", num1 & num2);

    printf("XOR: ");
    printf("%u ^ %u = ", num1, num2);
    printf("%u\n", num1 ^ num2);

    printf("Left Shift: ");
    printf("%u << %d = ", num1, rand_num(0, 10));
    printf("%u\n", num1 << rand_num(0, 10));

    printf("Right Shift: ");
    printf("%u >> %d = ", num1, rand_num(0, 10));
    printf("%u\n", num1 >> rand_num(0, 10));
}

// Main function
int main() {
    srand(time(NULL));

    int i;
    for (i = 0; i < 10; i++) {
        unsigned int num1 = rand() % 1000;
        unsigned int num2 = rand() % 1000;

        printf("Random numbers:\n");
        printf("num1: %u\n", num1);
        printf("num2: %u\n", num2);

        bitwise_ops(num1, num2);
        print_bits(num1);
        print_bits(num2);
        print_bits(num1 | num2);
        print_bits(num1 & num2);
        print_bits(num1 ^ num2);
        print_bits(num1 << rand_num(0, 10));
        print_bits(num1 >> rand_num(0, 10));
        printf("\n");
    }

    return 0;
}