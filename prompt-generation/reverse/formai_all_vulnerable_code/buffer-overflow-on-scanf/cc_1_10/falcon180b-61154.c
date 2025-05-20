//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent a bitwise operation
typedef struct {
    char *name;
    int (*func)(int a, int b);
} BitwiseOp;

// Function prototypes
int bitwise_and(int a, int b);
int bitwise_or(int a, int b);
int bitwise_xor(int a, int b);
int bitwise_not(int a);
int bitwise_left_shift(int a, int b);
int bitwise_right_shift(int a, int b);

// Define the bitwise operations
BitwiseOp bitwise_ops[] = {
    {"AND", bitwise_and},
    {"OR", bitwise_or},
    {"XOR", bitwise_xor},
    {"NOT", bitwise_not},
    {"<<", bitwise_left_shift},
    {">>", bitwise_right_shift}
};

// Function to perform bitwise AND
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT
int bitwise_not(int a) {
    return ~a;
}

// Function to perform bitwise left shift
int bitwise_left_shift(int a, int b) {
    return a << b;
}

// Function to perform bitwise right shift
int bitwise_right_shift(int a, int b) {
    return a >> b;
}

// Function to print the bitwise operations table
void print_bitwise_ops_table() {
    printf("Bitwise Operations:\n");
    printf("--------------------\n");
    for (int i = 0; i < sizeof(bitwise_ops) / sizeof(BitwiseOp); i++) {
        printf("%-10s %s\n", bitwise_ops[i].name, bitwise_ops[i].func(0, 0));
    }
}

// Function to prompt the user for input and perform the selected bitwise operation
int main() {
    printf("Bitwise Operations Example Program\n");
    printf("---------------------------------\n");
    print_bitwise_ops_table();

    int choice;
    printf("\nEnter the number of the bitwise operation you want to perform: ");
    scanf("%d", &choice);

    printf("\nEnter the first integer: ");
    int a = scanf("%d", &a);

    printf("\nEnter the second integer: ");
    int b = scanf("%d", &b);

    printf("\n%s %d %s %d = %d\n", bitwise_ops[choice].name, a, bitwise_ops[choice].name, b, bitwise_ops[choice].func(a, b));

    return 0;
}