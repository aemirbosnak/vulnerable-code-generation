//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to print the binary representation of a number
void print_binary(int n) {
    int i = 31;
    while (i >= 0) {
        if (n & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
        i--;
    }
}

// Function to perform bitwise OR operation on two numbers
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to perform bitwise AND operation on two numbers
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to perform bitwise XOR operation on two numbers
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise left shift operation on a number
int bitwise_left_shift(int n, int shift) {
    return n << shift;
}

// Function to perform bitwise right shift operation on a number
int bitwise_right_shift(int n, int shift) {
    return n >> shift;
}

// Function to perform bitwise NOT operation on a number
int bitwise_not(int n) {
    return ~n;
}

int main() {
    int a, b, c, d, e;
    int choice;
    char str[MAX_SIZE];

    // Prompt the user to enter two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Display the binary representation of the numbers
    printf("\nBinary representation of %d: ", a);
    print_binary(a);
    printf("\nBinary representation of %d: ", b);
    print_binary(b);

    // Prompt the user to choose a bitwise operation
    printf("\nChoose a bitwise operation:\n");
    printf("1. Bitwise OR\n");
    printf("2. Bitwise AND\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise left shift\n");
    printf("5. Bitwise right shift\n");
    printf("6. Bitwise NOT\n");
    scanf("%d", &choice);

    // Perform the chosen bitwise operation
    switch (choice) {
        case 1:
            c = bitwise_or(a, b);
            printf("\nResult of bitwise OR operation: %d", c);
            break;
        case 2:
            c = bitwise_and(a, b);
            printf("\nResult of bitwise AND operation: %d", c);
            break;
        case 3:
            c = bitwise_xor(a, b);
            printf("\nResult of bitwise XOR operation: %d", c);
            break;
        case 4:
            printf("\nEnter the number of positions to shift: ");
            scanf("%d", &d);
            c = bitwise_left_shift(a, d);
            printf("\nResult of bitwise left shift operation: %d", c);
            break;
        case 5:
            printf("\nEnter the number of positions to shift: ");
            scanf("%d", &d);
            c = bitwise_right_shift(a, d);
            printf("\nResult of bitwise right shift operation: %d", c);
            break;
        case 6:
            c = bitwise_not(a);
            printf("\nResult of bitwise NOT operation: %d", c);
            break;
        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}