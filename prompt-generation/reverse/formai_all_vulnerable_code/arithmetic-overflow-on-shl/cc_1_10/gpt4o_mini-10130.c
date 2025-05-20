//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display menu
void displayMenu() {
    printf("\nBitwise Operations Program\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
    printf("Choose an option (1-7): ");
}

// Function for AND operation
void bitwiseAnd(int a, int b) {
    printf("Result of %d AND %d = %d\n", a, b, a & b);
}

// Function for OR operation
void bitwiseOr(int a, int b) {
    printf("Result of %d OR %d = %d\n", a, b, a | b);
}

// Function for XOR operation
void bitwiseXor(int a, int b) {
    printf("Result of %d XOR %d = %d\n", a, b, a ^ b);
}

// Function for NOT operation
void bitwiseNot(int a) {
    printf("Result of NOT %d = %d\n", a, ~a);
}

// Function for left shift operation
void leftShift(int a, int positions) {
    printf("Result of %d left shifted by %d = %d\n", a, positions, a << positions);
}

// Function for right shift operation
void rightShift(int a, int positions) {
    printf("Result of %d right shifted by %d = %d\n", a, positions, a >> positions);
}

// Main function
int main() {
    int choice, a, b, positions;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            printf("Invalid option. Please choose between 1 to 7.\n");
            continue;
        }

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter first integer (a): ");
        scanf("%d", &a);

        if (choice == 4) { // Only NOT operation takes one operand
            bitwiseNot(a);
        } else {
            printf("Enter second integer (b): ");
            scanf("%d", &b);

            switch (choice) {
                case 1:
                    bitwiseAnd(a, b);
                    break;
                case 2:
                    bitwiseOr(a, b);
                    break;
                case 3:
                    bitwiseXor(a, b);
                    break;
                case 5:
                    printf("Enter number of positions to shift: ");
                    scanf("%d", &positions);
                    leftShift(a, positions);
                    break;
                case 6:
                    printf("Enter number of positions to shift: ");
                    scanf("%d", &positions);
                    rightShift(a, positions);
                    break;
                default:
                    printf("Invalid operation selected.\n");
                    break;
            }
        }
    }

    return 0;
}