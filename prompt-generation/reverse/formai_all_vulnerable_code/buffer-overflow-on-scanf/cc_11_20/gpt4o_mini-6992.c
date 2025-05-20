//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to perform paranoid bitwise operations
void paranoidBitwiseOperations(int a, int b) {
    printf("Given numbers: a = %d, b = %d\n", a, b);
    
    // Paranoia level 1: Checking if we can safely perform operations on integers
    if (a < INT_MIN || a > INT_MAX || b < INT_MIN || b > INT_MAX) {
        printf("Paranoia Alert: One of the integers is out of bounds!\n");
        return;
    }

    // Bitwise AND
    int andResult = a & b;
    printf("Bitwise AND (a & b): %d\n", andResult);
    if (andResult < 0) {
        printf("Paranoia Alert: Result of AND might have negative implications!\n");
    }

    // Bitwise OR
    int orResult = a | b;
    printf("Bitwise OR (a | b): %d\n", orResult);
    
    // Paranoia level 2: Check if result of OR is suspiciously large
    if (orResult > (INT_MAX - 10)) {
        printf("Paranoia Alert: Result of OR is suspiciously high!\n");
    }

    // Bitwise XOR
    int xorResult = a ^ b;
    printf("Bitwise XOR (a ^ b): %d\n", xorResult);
    
    // Paranoia level 3: Check if the XOR result is identical to one of the operands
    if (xorResult == a || xorResult == b) {
        printf("Paranoia Alert: XOR result matches one of the operands! Potentially a problem!\n");
    }

    // Bitwise NOT
    int notA = ~a;
    int notB = ~b;
    printf("Bitwise NOT (~a): %d, (~b): %d\n", notA, notB);
    if (notA == a && notB == b) {
        printf("Paranoia Alert: Bitwise NOT operation did nothing! Check your inputs!\n");
    }

    // Left Shift
    int leftShiftA = a << 1;
    printf("Left Shift (a << 1): %d\n", leftShiftA);
    if (leftShiftA < 0) {
        printf("Paranoia Alert: Shifted left value appears negative! Watch out!\n");
    }

    // Right Shift
    int rightShiftA = a >> 1;
    printf("Right Shift (a >> 1): %d\n", rightShiftA);
    if (rightShiftA > a) {
        printf("Paranoia Alert: Right shift yields a value greater than original, something is off!\n");
    }

    // Cumulative paranoia checker
    printf("Cumulative threat assessment: \n");
    if (andResult < 0 || orResult > (INT_MAX - 10) || xorResult == a || xorResult == b || 
        notA == a || notB == b || leftShiftA < 0 || rightShiftA > a) {
        printf("Alert: Multiple paranoia levels triggered! Recommend resetting system!\n");
    } else {
        printf("All operations executed safely; no signs of paranoia!\n");
    }
}

int main() {
    int a, b;

    // Paranoia check for user input
    printf("Enter two integers for paranoid bitwise operations: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Paranoia Alert: Invalid input detected! Only integers are allowed!\n");
        return EXIT_FAILURE;
    }

    // Perform paranoid bitwise operations
    paranoidBitwiseOperations(a, b);

    return EXIT_SUCCESS;
}