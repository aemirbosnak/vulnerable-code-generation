//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Constants for paranoia thresholds
#define MAX_BITWISE_VALUE 255
#define BITWISE_THRESHOLD 128

// Function to perform paranoia checks on a number
void paranoia_check(int number) {
    if (number < 0 || number > MAX_BITWISE_VALUE) {
        printf("Warning: Input %d is out of paranoia bounds!\n", number);
        exit(EXIT_FAILURE);
    }
}

// Function to show the binary representation of a number
void print_binary(int number) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
    }
}

// Function to perform bitwise AND operation
int paranoid_and(int a, int b) {
    paranoia_check(a);
    paranoia_check(b);
    int result = a & b;
    printf("Paranoid AND Operation: %d & %d = %d | ", a, b, result);
    print_binary(result);
    printf("\n");
    return result;
}

// Function to perform bitwise OR operation
int paranoid_or(int a, int b) {
    paranoia_check(a);
    paranoia_check(b);
    int result = a | b;
    printf("Paranoid OR Operation: %d | %d = %d | ", a, b, result);
    print_binary(result);
    printf("\n");
    return result;
}

// Function to perform bitwise XOR operation
int paranoid_xor(int a, int b) {
    paranoia_check(a);
    paranoia_check(b);
    int result = a ^ b;
    printf("Paranoid XOR Operation: %d ^ %d = %d | ", a, b, result);
    print_binary(result);
    printf("\n");
    return result;
}

// Function to perform bitwise NOT operation
int paranoid_not(int a) {
    paranoia_check(a);
    int result = ~a & MAX_BITWISE_VALUE; // Ensuring the result stays within bounds
    printf("Paranoid NOT Operation: ~%d = %d | ", a, result);
    print_binary(result);
    printf("\n");
    return result;
}

// Function to perform bitwise left shift operation
int paranoid_left_shift(int a, int shift) {
    paranoia_check(a);
    
    // Additional paranoia check for shift limit
    if (shift < 0 || shift > 7) {
        printf("Warning: Shift %d is out of paranoia bounds!\n", shift);
        exit(EXIT_FAILURE);
    }
    
    int result = (a << shift) & MAX_BITWISE_VALUE; // Ensuring the result stays within bounds
    printf("Paranoid Left Shift Operation: %d << %d = %d | ", a, shift, result);
    print_binary(result);
    printf("\n");
    return result;
}

// Function to perform bitwise right shift operation
int paranoid_right_shift(int a, int shift) {
    paranoia_check(a);
    
    // Additional paranoia check for shift limit
    if (shift < 0 || shift > 7) {
        printf("Warning: Shift %d is out of paranoia bounds!\n", shift);
        exit(EXIT_FAILURE);
    }
    
    int result = a >> shift;
    printf("Paranoid Right Shift Operation: %d >> %d = %d | ", a, shift, result);
    print_binary(result);
    printf("\n");
    return result;
}

int main() {
    // Demonstrating paranoia about bitwise operations
    int a = 60;   // Binary: 00111100
    int b = 13;   // Binary: 00001101
    
    printf("Starting the Paranoid Bitwise Operations...\n");

    // Performing various operations
    paranoid_and(a, b);
    paranoid_or(a, b);
    paranoid_xor(a, b);
    paranoid_not(a);
    paranoid_left_shift(a, 2);
    paranoid_right_shift(b, 1);
    
    // Introducing random paranoia with input from user
    int user_input_a, user_input_b;
    
    printf("Enter two values for paranoid operations (0-255): ");
    scanf("%d %d", &user_input_a, &user_input_b);
    
    // Checking user inputs within the paranoid limits
    paranoid_and(user_input_a, user_input_b);
    paranoid_or(user_input_a, user_input_b);
    
    printf("Paranoid operations completed successfully.\n");
    
    return 0;
}