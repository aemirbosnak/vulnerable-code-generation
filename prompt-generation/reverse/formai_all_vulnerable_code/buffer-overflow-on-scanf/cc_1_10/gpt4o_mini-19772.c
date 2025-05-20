//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to display binary representation of an integer
void printBinary(int n) {
    if (n > 1) {
        printBinary(n >> 1);
    }
    printf("%d", n & 1);
}

// Function to perform various bitwise operations
void bitwiseOperations(int a, int b) {
    printf("\nBitwise Operations between %d and %d:\n", a, b);
    
    // AND operation
    int andResult = a & b;
    printf("AND: %d (", andResult);
    printBinary(andResult);
    printf(")\n");
    
    // OR operation
    int orResult = a | b;
    printf("OR: %d (", orResult);
    printBinary(orResult);
    printf(")\n");
    
    // XOR operation
    int xorResult = a ^ b;
    printf("XOR: %d (", xorResult);
    printBinary(xorResult);
    printf(")\n");
    
    // NOT operation
    printf("NOT (of %d): %d (", a, ~a);
    printBinary(~a);
    printf(")\n");
    
    // Left shift operation
    int leftShiftResult = a << 1;
    printf("Left Shift (of %d by 1): %d (", a, leftShiftResult);
    printBinary(leftShiftResult);
    printf(")\n");
    
    // Right shift operation
    int rightShiftResult = a >> 1;
    printf("Right Shift (of %d by 1): %d (", a, rightShiftResult);
    printBinary(rightShiftResult);
    printf(")\n");
}

int main() {
    int a, b;

    printf("Welcome to the Brave Bitwise Operations Program!\n");
    printf("Please enter two integers (a and b): ");
    if (scanf("%d %d", &a, &b) != 2) {
        fprintf(stderr, "Invalid input! Please provide two integers.\n");
        return 1;
    }

    // Display the original numbers
    printf("You entered:\n");
    printf("a: %d (", a);
    printBinary(a);
    printf(")\n");
    printf("b: %d (", b);
    printBinary(b);
    printf(")\n");

    // Perform bitwise operations
    bitwiseOperations(a, b);

    // Challenge with bitwise manipulation
    int challengeNum = a ^ b;
    printf("\nChallenge Time! We'll find the number of set bits in %d (", challengeNum);
    printBinary(challengeNum);
    printf(")\n");

    // Counting set bits using a while loop
    int count = 0;
    while (challengeNum) {
        count += challengeNum & 1; // Increment count if LSB is 1
        challengeNum >>= 1;        // Right shift to check the next bit
    }
    printf("The number of set bits: %d\n", count);

    // Additional demonstration of using bitwise operation to swap two numbers
    printf("\nNow, let's see how to swap two numbers using bitwise XOR.\n");
    printf("Before swapping: a = %d, b = %d\n", a, b);
    
    a = a ^ b; // Step 1
    b = a ^ b; // Step 2
    a = a ^ b; // Step 3

    printf("After swapping: a = %d, b = %d\n", a, b);
    
    // User can find out if an integer is even or odd using bitwise operation
    printf("\nChecking if the first number is even or odd...\n");
    if (b & 1) {
        printf("%d is Odd.\n", b);
    } else {
        printf("%d is Even.\n", b);
    }

    printf("\nThank you for participating in the Brave Bitwise Operations Program! Have a great day!\n");
    return 0;
}