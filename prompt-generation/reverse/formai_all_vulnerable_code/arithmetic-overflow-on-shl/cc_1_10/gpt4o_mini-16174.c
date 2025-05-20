//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

// Function to perform bitwise AND operation
void bitwise_and(int a, int b) {
    printf("Bitwise AND of %d and %d is %d\n", a, b, (a & b));
}

// Function to perform bitwise OR operation
void bitwise_or(int a, int b) {
    printf("Bitwise OR of %d and %d is %d\n", a, b, (a | b));
}

// Function to perform bitwise XOR operation
void bitwise_xor(int a, int b) {
    printf("Bitwise XOR of %d and %d is %d\n", a, b, (a ^ b));
}

// Function to perform bitwise NOT operation
void bitwise_not(int a) {
    printf("Bitwise NOT of %d is %d\n", a, (~a));
}

// Function to left shift the bits
void left_shift(int a, int shift) {
    printf("Left Shift of %d by %d is %d\n", a, shift, (a << shift));
}

// Function to right shift the bits
void right_shift(int a, int shift) {
    printf("Right Shift of %d by %d is %d\n", a, shift, (a >> shift));
}

// Function to display the binary representation of an integer
void print_binary(int n) {
    int i;
    for (i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise operations based on user's choice
void perform_operations(int a, int b) {
    int choice;
    
    do {
        printf("\nChoose a bitwise operation:\n");
        printf("1. AND\n");
        printf("2. OR\n");
        printf("3. XOR\n");
        printf("4. NOT (Only first number)\n");
        printf("5. Left Shift\n");
        printf("6. Right Shift\n");
        printf("7. Show binary representation\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                bitwise_and(a, b);
                break;
            case 2:
                bitwise_or(a, b);
                break;
            case 3:
                bitwise_xor(a, b);
                break;
            case 4:
                bitwise_not(a);
                break;
            case 5:
                printf("Enter shift value: ");
                int shift_left;
                scanf("%d", &shift_left);
                left_shift(a, shift_left);
                break;
            case 6:
                printf("Enter shift value: ");
                int shift_right;
                scanf("%d", &shift_right);
                right_shift(a, shift_right);
                break;
            case 7:
                printf("Binary representation of %d: ", a);
                print_binary(a);
                printf("Binary representation of %d: ", b);
                print_binary(b);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8);
}

int main() {
    int num1, num2;

    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);
    
    printf("\nYou entered:\n");
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);
    
    perform_operations(num1, num2);

    return 0;
}