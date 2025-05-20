//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>

// Function prototypes
void displayMenu();
int getInput();
void bitwiseAND(int a, int b);
void bitwiseOR(int a, int b);
void bitwiseXOR(int a, int b);
void leftShift(int a, int positions);
void rightShift(int a, int positions);
void displayBinary(int n);

int main() {
    int choice, num1, num2, positions;

    do {
        displayMenu();
        choice = getInput();

        switch (choice) {
            case 1:
                printf("Enter two integers: ");
                num1 = getInput();
                num2 = getInput();
                bitwiseAND(num1, num2);
                break;
            case 2:
                printf("Enter two integers: ");
                num1 = getInput();
                num2 = getInput();
                bitwiseOR(num1, num2);
                break;
            case 3:
                printf("Enter two integers: ");
                num1 = getInput();
                num2 = getInput();
                bitwiseXOR(num1, num2);
                break;
            case 4:
                printf("Enter an integer and number of positions to left shift: ");
                num1 = getInput();
                positions = getInput();
                leftShift(num1, positions);
                break;
            case 5:
                printf("Enter an integer and number of positions to right shift: ");
                num1 = getInput();
                positions = getInput();
                rightShift(num1, positions);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Bitwise Operations Menu ---\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Left Shift\n");
    printf("5. Right Shift\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

// Function to get integer input
int getInput() {
    int input;
    scanf("%d", &input);
    return input;
}

// Function to perform bitwise AND
void bitwiseAND(int a, int b) {
    int result = a & b;
    printf("Bitwise AND of ");
    displayBinary(a);
    printf(" and ");
    displayBinary(b);
    printf(" is ");
    displayBinary(result);
    printf(" (%d)\n", result);
}

// Function to perform bitwise OR
void bitwiseOR(int a, int b) {
    int result = a | b;
    printf("Bitwise OR of ");
    displayBinary(a);
    printf(" and ");
    displayBinary(b);
    printf(" is ");
    displayBinary(result);
    printf(" (%d)\n", result);
}

// Function to perform bitwise XOR
void bitwiseXOR(int a, int b) {
    int result = a ^ b;
    printf("Bitwise XOR of ");
    displayBinary(a);
    printf(" and ");
    displayBinary(b);
    printf(" is ");
    displayBinary(result);
    printf(" (%d)\n", result);
}

// Function to perform left shift
void leftShift(int a, int positions) {
    int result = a << positions;
    printf("Left shift ");
    displayBinary(a);
    printf(" by %d is ", positions);
    displayBinary(result);
    printf(" (%d)\n", result);
}

// Function to perform right shift
void rightShift(int a, int positions) {
    int result = a >> positions;
    printf("Right shift ");
    displayBinary(a);
    printf(" by %d is ", positions);
    displayBinary(result);
    printf(" (%d)\n", result);
}

// Function to display the binary representation of an integer
void displayBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
    printf(" ");
}