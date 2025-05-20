//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define a function to generate a random number between 0 and n-1
int rand_int(int n) {
    return rand() % n;
}

// Define a function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Define a function to perform bitwise operations on two integers
void bitwise_operations(int a, int b) {
    // Perform bitwise AND operation
    int and_result = a & b;
    printf("Bitwise AND of %d and %d is %d\n", a, b, and_result);

    // Perform bitwise OR operation
    int or_result = a | b;
    printf("Bitwise OR of %d and %d is %d\n", a, b, or_result);

    // Perform bitwise XOR operation
    int xor_result = a ^ b;
    printf("Bitwise XOR of %d and %d is %d\n", a, b, xor_result);

    // Perform bitwise NOT operation
    int not_result = ~a;
    printf("Bitwise NOT of %d is %d\n", a, not_result);

    // Perform bitwise left shift operation
    int left_shift_result = a << 2;
    printf("Bitwise left shift of %d by 2 is %d\n", a, left_shift_result);

    // Perform bitwise right shift operation
    int right_shift_result = a >> 2;
    printf("Bitwise right shift of %d by 2 is %d\n", a, right_shift_result);
}

int main() {
    int a, b;

    // Take user input for two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Perform bitwise operations on the two integers
    bitwise_operations(a, b);

    return 0;
}