//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define NUM_BITS 32
#define MAX_VALUE (1 << NUM_BITS) - 1

// Function to count the number of bits set in an integer
int count_bits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

// Function to reverse the bits in an integer
int reverse_bits(int num) {
    int reversed = 0;
    for (int i = 0; i < NUM_BITS; i++) {
        reversed |= (num & (1 << i)) << (NUM_BITS - 1 - i);
    }
    return reversed;
}

// Function to toggle the nth bit in an integer
int toggle_bit(int num, int n) {
    return num ^ (1 << n);
}

// Function to set the nth bit in an integer
int set_bit(int num, int n) {
    return num | (1 << n);
}

// Function to clear the nth bit in an integer
int clear_bit(int num, int n) {
    return num & ~(1 << n);
}

// Function to check if the nth bit is set in an integer
int check_bit(int num, int n) {
    return (num & (1 << n))!= 0;
}

int main() {
    int num = 0b11010101101100010011010101110000;
    int n = 7;

    printf("Number: %d\n", num);
    printf("Bit %d is set: %s\n", n, check_bit(num, n)? "true" : "false");
    num = toggle_bit(num, n);
    printf("Bit %d toggled: %d\n", n, num);
    num = set_bit(num, n);
    printf("Bit %d set: %d\n", n, num);
    num = clear_bit(num, n);
    printf("Bit %d cleared: %d\n", n, num);
    printf("Number of bits set: %d\n", count_bits(num));
    printf("Reversed bits: %d\n", reverse_bits(num));

    return 0;
}