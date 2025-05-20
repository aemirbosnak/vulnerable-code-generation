//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise AND operation on two integers
int bitwise_and(int a, int b) {
    return (a & b);
}

// Function to perform bitwise OR operation on two integers
int bitwise_or(int a, int b) {
    return (a | b);
}

// Function to perform bitwise XOR operation on two integers
int bitwise_xor(int a, int b) {
    return (a ^ b);
}

// Function to perform bitwise NOT operation on an integer
int bitwise_not(int a) {
    return (~a);
}

// Function to perform bitwise left shift operation on an integer
int bitwise_left_shift(int a, int b) {
    return (a << b);
}

// Function to perform bitwise right shift operation on an integer
int bitwise_right_shift(int a, int b) {
    return (a >> b);
}

int main() {
    int a, b, c;

    // Prompt user to enter two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Perform bitwise AND operation on two integers
    c = bitwise_and(a, b);
    printf("Bitwise AND operation: %d\n", c);

    // Perform bitwise OR operation on two integers
    c = bitwise_or(a, b);
    printf("Bitwise OR operation: %d\n", c);

    // Perform bitwise XOR operation on two integers
    c = bitwise_xor(a, b);
    printf("Bitwise XOR operation: %d\n", c);

    // Perform bitwise NOT operation on an integer
    c = bitwise_not(a);
    printf("Bitwise NOT operation: %d\n", c);

    // Perform bitwise left shift operation on an integer
    c = bitwise_left_shift(a, 2);
    printf("Bitwise left shift operation: %d\n", c);

    // Perform bitwise right shift operation on an integer
    c = bitwise_right_shift(a, 2);
    printf("Bitwise right shift operation: %d\n", c);

    return 0;
}