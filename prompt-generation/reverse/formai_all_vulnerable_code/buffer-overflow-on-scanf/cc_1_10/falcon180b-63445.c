//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise AND operation
void bitwise_and(int a, int b) {
    printf("Bitwise AND of %d and %d is \n", a, b);
    printf("%d\n", a & b);
}

// Function to perform bitwise OR operation
void bitwise_or(int a, int b) {
    printf("Bitwise OR of %d and %d is \n", a, b);
    printf("%d\n", a | b);
}

// Function to perform bitwise XOR operation
void bitwise_xor(int a, int b) {
    printf("Bitwise XOR of %d and %d is \n", a, b);
    printf("%d\n", a ^ b);
}

// Function to perform bitwise NOT operation
void bitwise_not(int a) {
    printf("Bitwise NOT of %d is \n", a);
    printf("%d\n", ~a);
}

// Function to perform bitwise left shift operation
void bitwise_left_shift(int a, int b) {
    printf("Bitwise left shift of %d by %d is \n", a, b);
    printf("%d\n", a << b);
}

// Function to perform bitwise right shift operation
void bitwise_right_shift(int a, int b) {
    printf("Bitwise right shift of %d by %d is \n", a, b);
    printf("%d\n", a >> b);
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Bitwise AND operation
    bitwise_and(a, b);

    // Bitwise OR operation
    bitwise_or(a, b);

    // Bitwise XOR operation
    bitwise_xor(a, b);

    // Bitwise NOT operation
    bitwise_not(a);

    // Bitwise left shift operation
    bitwise_left_shift(a, b);

    // Bitwise right shift operation
    bitwise_right_shift(a, b);

    return 0;
}