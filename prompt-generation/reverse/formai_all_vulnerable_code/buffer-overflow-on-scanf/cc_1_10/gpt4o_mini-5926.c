//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayBinary(int num);
void performBitwiseOperations(int a, int b);

int main() {
    int choice;
    int num1, num2;

    printf("*********************** Welcome to the Shocking Bitwise Operations Program **********************\n");

    do {
        printf("\nMenu:\n");
        printf("1. Perform Bitwise Operations\n");
        printf("2. Exit\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two integers:\n");
                printf("First integer (A): ");
                scanf("%d", &num1);
                printf("Second integer (B): ");
                scanf("%d", &num2);
                performBitwiseOperations(num1, num2);
                break;
            case 2:
                printf("Exiting the program... Thank you for playing with bits!\n");
                break;
            default:
                printf("Oh no! That's not a valid choice. Please choose again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

void displayBinary(int num) {
    printf("Binary representation of %d: ", num);
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

void performBitwiseOperations(int a, int b) {
    printf("\n*************** Performing Bitwise Operations on A: %d and B: %d ***************\n", a, b);
    
    // Display binary representations
    displayBinary(a);
    displayBinary(b);
    
    // Bitwise AND
    int and_result = a & b;
    printf("Bitwise AND (A & B): %d\n", and_result);
    displayBinary(and_result);
    
    // Bitwise OR
    int or_result = a | b;
    printf("Bitwise OR (A | B): %d\n", or_result);
    displayBinary(or_result);
    
    // Bitwise XOR
    int xor_result = a ^ b;
    printf("Bitwise XOR (A ^ B): %d\n", xor_result);
    displayBinary(xor_result);
    
    // Bitwise NOT
    int not_a = ~a;
    int not_b = ~b;
    printf("Bitwise NOT (~A): %d\n", not_a);
    displayBinary(not_a);
    printf("Bitwise NOT (~B): %d\n", not_b);
    displayBinary(not_b);
    
    // Left Shift
    int left_shift_a = a << 1;
    int left_shift_b = b << 1;
    printf("Left Shift (A << 1): %d\n", left_shift_a);
    displayBinary(left_shift_a);
    printf("Left Shift (B << 1): %d\n", left_shift_b);
    displayBinary(left_shift_b);
    
    // Right Shift
    int right_shift_a = a >> 1;
    int right_shift_b = b >> 1;
    printf("Right Shift (A >> 1): %d\n", right_shift_a);
    displayBinary(right_shift_a);
    printf("Right Shift (B >> 1): %d\n", right_shift_b);
    displayBinary(right_shift_b);

    printf("*************** Bitwise Operations Completed! ***************\n");
}