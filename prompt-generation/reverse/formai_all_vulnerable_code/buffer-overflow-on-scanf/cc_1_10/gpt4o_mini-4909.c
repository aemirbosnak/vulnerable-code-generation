//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

// Function to perform bitwise AND operation
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR operation
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR operation
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
int bitwise_not(int a) {
    return ~a;
}

// Function to perform left shift operation
int left_shift(int a, int shift) {
    return a << shift;
}

// Function to perform right shift operation
int right_shift(int a, int shift) {
    return a >> shift;
}

// Function to display the binary representation of an integer
void display_binary(int num) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int num1, num2;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("\nBitwise Operations on %d and %d:\n", num1, num2);
    
    printf("Binary Representation:\n");
    printf("Num1: ");
    display_binary(num1);
    printf("Num2: ");
    display_binary(num2);
    
    // Performing bitwise AND
    int and_result = bitwise_and(num1, num2);
    printf("\nBitwise AND (num1 & num2): %d\n", and_result);
    printf("Binary Result: ");
    display_binary(and_result);
    
    // Performing bitwise OR
    int or_result = bitwise_or(num1, num2);
    printf("\nBitwise OR (num1 | num2): %d\n", or_result);
    printf("Binary Result: ");
    display_binary(or_result);
    
    // Performing bitwise XOR
    int xor_result = bitwise_xor(num1, num2);
    printf("\nBitwise XOR (num1 ^ num2): %d\n", xor_result);
    printf("Binary Result: ");
    display_binary(xor_result);
    
    // Performing bitwise NOT on num1 and num2
    int not_num1 = bitwise_not(num1);
    int not_num2 = bitwise_not(num2);
    printf("\nBitwise NOT (~num1): %d\n", not_num1);
    printf("Binary Result: ");
    display_binary(not_num1);
    
    printf("\nBitwise NOT (~num2): %d\n", not_num2);
    printf("Binary Result: ");
    display_binary(not_num2);
    
    // Performing left shift on num1
    int left_shift_result = left_shift(num1, 2);
    printf("\nLeft Shift (num1 << 2): %d\n", left_shift_result);
    printf("Binary Result: ");
    display_binary(left_shift_result);
    
    // Performing right shift on num1
    int right_shift_result = right_shift(num1, 2);
    printf("\nRight Shift (num1 >> 2): %d\n", right_shift_result);
    printf("Binary Result: ");
    display_binary(right_shift_result);
    
    // Performing left shift on num2
    left_shift_result = left_shift(num2, 2);
    printf("\nLeft Shift (num2 << 2): %d\n", left_shift_result);
    printf("Binary Result: ");
    display_binary(left_shift_result);
    
    // Performing right shift on num2
    right_shift_result = right_shift(num2, 2);
    printf("\nRight Shift (num2 >> 2): %d\n", right_shift_result);
    printf("Binary Result: ");
    display_binary(right_shift_result);
    
    printf("\nThank you for using the bitwise operations program!\n");
    return 0;
}