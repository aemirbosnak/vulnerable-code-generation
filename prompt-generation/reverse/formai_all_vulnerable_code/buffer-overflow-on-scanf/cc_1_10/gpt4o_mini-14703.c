//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Surprise! Welcome to the Bitwise Operations Adventure!
// In this thrilling program, we will explore the world of bit manipulation
// through an interactive adventure that performs operations based on user choice!

// Function to display the options
void displayMenu() {
    printf("***** Welcome to Bitwise Operations Adventure! *****\n");
    printf("Choose an operation to perform:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
    printf("****************************************************\n");
}

// Function to perform bitwise AND
void bitwiseAND(int a, int b) {
    printf("Bitwise AND of %d and %d is: %d\n", a, b, a & b);
}

// Function to perform bitwise OR
void bitwiseOR(int a, int b) {
    printf("Bitwise OR of %d and %d is: %d\n", a, b, a | b);
}

// Function to perform bitwise XOR
void bitwiseXOR(int a, int b) {
    printf("Bitwise XOR of %d and %d is: %d\n", a, b, a ^ b);
}

// Function to perform bitwise NOT
void bitwiseNOT(int a) {
    printf("Bitwise NOT of %d is: %d\n", a, ~a);
}

// Function to perform left shift
void leftShift(int a, int positions) {
    printf("Left shift of %d by %d positions is: %d\n", a, positions, a << positions);
}

// Function to perform right shift
void rightShift(int a, int positions) {
    printf("Right shift of %d by %d positions is: %d\n", a, positions, a >> positions);
}

// Function to read integer input safely
int readInteger() {
    int n;
    while (scanf("%d", &n) != 1) {
        printf("Invalid input! Please enter an integer: ");
        while (getchar() != '\n'); // Clear invalid input
    }
    return n;
}

int main() {
    int choice, a, b, positions;

    printf("Hey Adventurer! Let's start this journey.\n");

    while (1) {
        displayMenu();
        choice = readInteger();

        if (choice == 7) { 
            printf("Thank you for participating in the Bitwise Operations Adventure!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two integers for Bitwise AND: ");
                a = readInteger();
                b = readInteger();
                bitwiseAND(a, b);
                break;

            case 2:
                printf("Enter two integers for Bitwise OR: ");
                a = readInteger();
                b = readInteger();
                bitwiseOR(a, b);
                break;

            case 3:
                printf("Enter two integers for Bitwise XOR: ");
                a = readInteger();
                b = readInteger();
                bitwiseXOR(a, b);
                break;

            case 4:
                printf("Enter an integer for Bitwise NOT: ");
                a = readInteger();
                bitwiseNOT(a);
                break;

            case 5:
                printf("Enter an integer and number of positions for Left Shift: ");
                a = readInteger();
                positions = readInteger();
                leftShift(a, positions);
                break;

            case 6:
                printf("Enter an integer and number of positions for Right Shift: ");
                a = readInteger();
                positions = readInteger();
                rightShift(a, positions);
                break;

            default:
                printf("Surprise! Invalid choice, please try again!\n");
                break;
        }
        printf("\n");
    }

    return 0;
}