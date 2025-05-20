//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define a macro to represent the bitwise XOR operation
#define XOR(a, b) (a ^ b)

// Function to perform bitwise XOR on two integers
int bitwise_xor(int a, int b) {
    return (a ^ b);
}

// Function to find the maximum of two integers using bitwise XOR
int maximum(int a, int b) {
    // Find the bitwise XOR of the two integers
    int result = XOR(a, b);

    // The maximum integer will have the highest bit set to 1
    // If the result has the highest bit set to 1, then it is the maximum
    if (result & (1 << 31)) {
        // If the result has the highest bit set to 1, then it is the maximum
        return a;
    } else {
        // Otherwise, the other integer is the maximum
        return b;
    }
}

// Function to find the minimum of two integers using bitwise XOR
int minimum(int a, int b) {
    // Find the bitwise XOR of the two integers
    int result = XOR(a, b);

    // The minimum integer will have the highest bit set to 0
    // If the result has the highest bit set to 0, then it is the minimum
    if (!(result & (1 << 31))) {
        // If the result has the highest bit set to 0, then it is the minimum
        return a;
    } else {
        // Otherwise, the other integer is the minimum
        return b;
    }
}

// Function to swap two integers using bitwise XOR
void swap(int *a, int *b) {
    // Find the bitwise XOR of the two integers
    int result = XOR(*a, *b);

    // Swap the values of the two integers
    *a = XOR(*a, result);
    *b = XOR(*b, result);
}

// Function to find the absolute value of an integer using bitwise XOR
int absolute(int a) {
    // Find the bitwise XOR of the integer with its negative value
    int result = XOR(a, -a);

    // The absolute value will have the sign bit set to 0
    // If the result has the sign bit set to 0, then it is the absolute value
    if (!(result & (1 << 31))) {
        // If the result has the sign bit set to 0, then it is the absolute value
        return result;
    } else {
        // Otherwise, the absolute value is the negative of the result
        return -result;
    }
}

// Function to find the inverse of an integer using bitwise XOR
int inverse(int a) {
    // Find the bitwise XOR of the integer with its negative value
    int result = XOR(a, -a);

    // The inverse will have the sign bit set to 1
    // If the result has the sign bit set to 1, then it is the inverse
    if (result & (1 << 31)) {
        // If the result has the sign bit set to 1, then it is the inverse
        return result;
    } else {
        // Otherwise, the inverse is the negative of the result
        return -result;
    }
}

// Function to find the square of an integer using bitwise XOR
int square(int a) {
    // Find the bitwise XOR of the integer with itself
    int result = XOR(a, a);

    // The square will have the sign bit set to 0
    // If the result has the sign bit set to 0, then it is the square
    if (!(result & (1 << 31))) {
        // If the result has the sign bit set to 0, then it is the square
        return result;
    } else {
        // Otherwise, the square is the negative of the result
        return -result;
    }
}

int main() {
    int a, b;

    // Get two integers from the user
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Perform bitwise XOR on the two integers
    printf("Bitwise XOR of %d and %d is %d\n", a, b, bitwise_xor(a, b));

    // Find the maximum of the two integers using bitwise XOR
    printf("Maximum of %d and %d is %d\n", a, b, maximum(a, b));

    // Find the minimum of the two integers using bitwise XOR
    printf("Minimum of %d and %d is %d\n", a, b, minimum(a, b));

    // Swap the values of the two integers using bitwise XOR
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);

    // Find the absolute value of an integer using bitwise XOR
    printf("Absolute value of %d is %d\n", a, absolute(a));

    // Find the inverse of an integer using bitwise XOR
    printf("Inverse of %d is %d\n", a, inverse(a));

    // Find the square of an integer using bitwise XOR
    printf("Square of %d is %d\n", a, square(a));

    return 0;
}