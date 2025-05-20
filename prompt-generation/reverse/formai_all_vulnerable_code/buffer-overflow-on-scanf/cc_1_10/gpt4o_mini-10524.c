//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function declarations for bitwise operations
int bitwise_and(int a, int b);
int bitwise_or(int a, int b);
int bitwise_xor(int a, int b);
int bitwise_not(int a);
void display_menu();

// Main driver function
int main() {
    int choice, a, b, result;
    while (1) {
        display_menu();
        printf("Enter your choice (1-5) or 0 to exit: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting program...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two integers for AND operation: ");
                scanf("%d %d", &a, &b);
                result = bitwise_and(a, b);
                printf("Result of %d AND %d = %d\n", a, b, result);
                break;
            case 2:
                printf("Enter two integers for OR operation: ");
                scanf("%d %d", &a, &b);
                result = bitwise_or(a, b);
                printf("Result of %d OR %d = %d\n", a, b, result);
                break;
            case 3:
                printf("Enter two integers for XOR operation: ");
                scanf("%d %d", &a, &b);
                result = bitwise_xor(a, b);
                printf("Result of %d XOR %d = %d\n", a, b, result);
                break;
            case 4:
                printf("Enter an integer for NOT operation: ");
                scanf("%d", &a);
                result = bitwise_not(a);
                printf("Result of NOT %d = %d\n", a, result);
                break;
            case 5:
                printf("Enter two integers for bitwise operations (AND, OR, XOR): ");
                scanf("%d %d", &a, &b);
                printf("AND: %d, OR: %d, XOR: %d\n", 
                        bitwise_and(a, b), 
                        bitwise_or(a, b), 
                        bitwise_xor(a, b));
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

// Function for bitwise AND operation
int bitwise_and(int a, int b) {
    return a & b;
}

// Function for bitwise OR operation
int bitwise_or(int a, int b) {
    return a | b;
}

// Function for bitwise XOR operation
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function for bitwise NOT operation
int bitwise_not(int a) {
    return ~a;
}

// Function to display the menu
void display_menu() {
    printf("\n-------- Bitwise Operations Menu --------\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Multiple Operations (AND, OR, XOR)\n");
    printf("------------------------------------------\n");
}