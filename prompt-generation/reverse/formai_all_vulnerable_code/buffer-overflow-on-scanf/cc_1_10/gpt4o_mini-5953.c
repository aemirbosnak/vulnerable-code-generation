//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

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
void display_binary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Main menu to choose an operation
void display_menu() {
    printf("\nBitwise Operations Menu:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Display Binary Representation\n");
    printf("0. Exit\n");
}

// Function to get input from the user
int get_user_input() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int a, b, shift, choice, result;
    
    while (1) {
        display_menu();
        choice = get_user_input();
        
        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter two integers:\n");
                scanf("%d %d", &a, &b);
                result = bitwise_and(a, b);
                printf("Result of %d AND %d = %d\n", a, b, result);
                break;
                
            case 2:
                printf("Enter two integers:\n");
                scanf("%d %d", &a, &b);
                result = bitwise_or(a, b);
                printf("Result of %d OR %d = %d\n", a, b, result);
                break;

            case 3:
                printf("Enter two integers:\n");
                scanf("%d %d", &a, &b);
                result = bitwise_xor(a, b);
                printf("Result of %d XOR %d = %d\n", a, b, result);
                break;

            case 4:
                printf("Enter an integer:\n");
                scanf("%d", &a);
                result = bitwise_not(a);
                printf("Result of NOT %d = %d\n", a, result);
                break;

            case 5:
                printf("Enter an integer and the number of positions to shift left:\n");
                scanf("%d %d", &a, &shift);
                result = left_shift(a, shift);
                printf("Result of %d << %d = %d\n", a, shift, result);
                break;

            case 6:
                printf("Enter an integer and the number of positions to shift right:\n");
                scanf("%d %d", &a, &shift);
                result = right_shift(a, shift);
                printf("Result of %d >> %d = %d\n", a, shift, result);
                break;

            case 7:
                printf("Enter an integer to display its binary representation:\n");
                scanf("%d", &a);
                printf("Binary representation of %d: ", a);
                display_binary(a);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}