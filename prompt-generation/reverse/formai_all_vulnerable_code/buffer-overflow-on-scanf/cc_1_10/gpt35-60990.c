//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Function prototypes
int recursiveAnd(int a, int b);
int recursiveOr(int a, int b);
int recursiveXor(int a, int b);
int recursiveShiftRight(int num, int shift);
int recursiveShiftLeft(int num, int shift);
int recursiveComplement(int num);

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("\nAND Operation: %d\n", recursiveAnd(a, b));
    printf("OR Operation: %d\n", recursiveOr(a, b));
    printf("XOR Operation: %d\n", recursiveXor(a, b));
    
    int shift;
    printf("\nEnter a number to shift right: ");
    scanf("%d", &shift);
    printf("Shift Right Operation: %d\n", recursiveShiftRight(a, shift));
    
    printf("\nEnter a number to shift left: ");
    scanf("%d", &shift);
    printf("Shift Left Operation: %d\n", recursiveShiftLeft(a, shift));
    
    printf("\nComplement Operation: %d\n", recursiveComplement(a));
    return 0;
}

// Recursive AND operation
int recursiveAnd(int a, int b) {
    if(a == 0 || b == 0) {
        return 0;
    }
    else if(a == 1 && b == 1) {
        return 1;
    }
    else {
        return recursiveAnd(a & b, 1 << 1); // Shift bits left and recursively AND
    }
}

// Recursive OR operation
int recursiveOr(int a, int b) {
    if(a == 1 || b == 1) {
        return 1;
    }
    else if(a == 0 && b == 0) {
        return 0;
    }
    else {
        return recursiveOr(a | b, 1 << 1); // Shift bits left and recursively OR
    }
}

// Recursive XOR operation
int recursiveXor(int a, int b) {
    if(a == b) {
        return 0;
    }
    else {
        return recursiveXor(a ^ b, 1 << 1); // Shift bits left and recursively XOR
    }
}

// Recursive right shift
int recursiveShiftRight(int num, int shift) {
    if(shift == 0) {
        return num;
    }
    else {
        return recursiveShiftRight(num >> 1, shift - 1); // Shift bits right and recursively shift
    }
}

// Recursive left shift
int recursiveShiftLeft(int num, int shift) {
    if(shift == 0) {
        return num;
    }
    else {
        return recursiveShiftLeft(num << 1, shift - 1); // Shift bits left and recursively shift
    }
}

// Recursive complement
int recursiveComplement(int num) {
    int mask = ~(0); // All ones
    if(num == 0) {
        return mask; // Return 111...111
    }
    else {
        return recursiveComplement(num >> 1) & mask << 1 | !(num & 1); // Complement bits and recursively complement
    }
}