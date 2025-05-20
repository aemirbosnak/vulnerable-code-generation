//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>

// Function prototypes
void displayBits(int num);
int bitwiseAnd(int a, int b);
int bitwiseOr(int a, int b);
int bitwiseXor(int a, int b);
int leftShift(int num, int positions);
int rightShift(int num, int positions);

int main() {
    int num1, num2;
    int choice;

    printf("Welcome to the Bitwise Operations Funhouse!\n");
    printf("Let's make some magic with bitwise operations!\n\n");
    
    // Get user inputs
    printf("Enter the first integer (num1): ");
    scanf("%d", &num1);
    printf("Enter the second integer (num2): ");
    scanf("%d", &num2);

    printf("\nYou entered: \n");
    printf("num1 = %d | Binary = ", num1);
    displayBits(num1);
    printf("num2 = %d | Binary = ", num2);
    displayBits(num2);

    while(1) {
        // Display menu
        printf("\nChoose an operation to perform on num1 and num2:\n");
        printf("1. Bitwise AND\n");
        printf("2. Bitwise OR\n");
        printf("3. Bitwise XOR\n");
        printf("4. Left Shift num1\n");
        printf("5. Right Shift num1\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPerforming Bitwise AND:\n");
                printf("%d & %d = %d | Binary = ", num1, num2, bitwiseAnd(num1, num2));
                displayBits(bitwiseAnd(num1, num2));
                break;
                
            case 2:
                printf("\nPerforming Bitwise OR:\n");
                printf("%d | %d = %d | Binary = ", num1, num2, bitwiseOr(num1, num2));
                displayBits(bitwiseOr(num1, num2));
                break;

            case 3:
                printf("\nPerforming Bitwise XOR:\n");
                printf("%d ^ %d = %d | Binary = ", num1, num2, bitwiseXor(num1, num2));
                displayBits(bitwiseXor(num1, num2));
                break;
                
            case 4:
                printf("\nEnter number of positions to left shift num1: ");
                int leftPositions;
                scanf("%d", &leftPositions);
                printf("Left Shifting %d by %d positions: %d | Binary = ", num1, leftPositions, leftShift(num1, leftPositions));
                displayBits(leftShift(num1, leftPositions));
                break;

            case 5:
                printf("\nEnter number of positions to right shift num1: ");
                int rightPositions;
                scanf("%d", &rightPositions);
                printf("Right Shifting %d by %d positions: %d | Binary = ", num1, rightPositions, rightShift(num1, rightPositions));
                displayBits(rightShift(num1, rightPositions));
                break;

            case 6:
                printf("Thank you for visiting the Bitwise Operations Funhouse! Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void displayBits(int num) {
    for(int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int bitwiseAnd(int a, int b) {
    return a & b;
}

int bitwiseOr(int a, int b) {
    return a | b;
}

int bitwiseXor(int a, int b) {
    return a ^ b;
}

int leftShift(int num, int positions) {
    return num << positions;
}

int rightShift(int num, int positions) {
    return num >> positions;
}