//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>

// Function prototypes
void displayMenu();
void performBitwiseOperations(int a, int b);
void bitwiseAND(int a, int b);
void bitwiseOR(int a, int b);
void bitwiseXOR(int a, int b);
void bitwiseNOT(int a);
void leftShift(int a, int shift);
void rightShift(int a, int shift);

int main() {
    int num1, num2;
    int choice;

    // User input for two integers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Perform bitwise operations
    if (num1 < 0 || num2 < 0) {
        printf("Please enter non-negative integers.\n");
        return 1;
    }

    do {
        displayMenu();
        printf("Choose an operation (1-7, 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bitwiseAND(num1, num2);
                break;
            case 2:
                bitwiseOR(num1, num2);
                break;
            case 3:
                bitwiseXOR(num1, num2);
                break;
            case 4:
                bitwiseNOT(num1);
                bitwiseNOT(num2);
                break;
            case 5:
                leftShift(num1, 1); // Shifting by 1
                leftShift(num2, 1);
                break;
            case 6:
                rightShift(num1, 1); // Shifting by 1
                rightShift(num2, 1);
                break;
            case 7:
                printf("Current numbers: (%d, %d)\n", num1, num2);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Bitwise Operations Menu ---\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Display Current Numbers\n");
    printf("0. Exit\n");
}

// Function to perform bitwise AND
void bitwiseAND(int a, int b) {
    printf("Bitwise AND of %d and %d is %d\n", a, b, a & b);
}

// Function to perform bitwise OR
void bitwiseOR(int a, int b) {
    printf("Bitwise OR of %d and %d is %d\n", a, b, a | b);
}

// Function to perform bitwise XOR
void bitwiseXOR(int a, int b) {
    printf("Bitwise XOR of %d and %d is %d\n", a, b, a ^ b);
}

// Function to perform bitwise NOT
void bitwiseNOT(int a) {
    printf("Bitwise NOT of %d is %d\n", a, ~a);
}

// Function to perform left shift
void leftShift(int a, int shift) {
    printf("Left shift of %d by %d is %d\n", a, shift, a << shift);
}

// Function to perform right shift
void rightShift(int a, int shift) {
    printf("Right shift of %d by %d is %d\n", a, shift, a >> shift);
}