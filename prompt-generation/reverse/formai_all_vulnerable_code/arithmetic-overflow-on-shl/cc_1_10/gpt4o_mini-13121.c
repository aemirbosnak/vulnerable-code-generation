//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void performBitwiseAND(int num1, int num2);
void performBitwiseOR(int num1, int num2);
void performBitwiseXOR(int num1, int num2);
void performBitwiseNOT(int num);
void performLeftShift(int num, int positions);
void performRightShift(int num, int positions);
void printBinary(int num);

int main() {
    int choice;
    int num1, num2, positions;

    while (1) {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers for AND operation: ");
                scanf("%d %d", &num1, &num2);
                performBitwiseAND(num1, num2);
                break;
            case 2:
                printf("Enter two numbers for OR operation: ");
                scanf("%d %d", &num1, &num2);
                performBitwiseOR(num1, num2);
                break;
            case 3:
                printf("Enter two numbers for XOR operation: ");
                scanf("%d %d", &num1, &num2);
                performBitwiseXOR(num1, num2);
                break;
            case 4:
                printf("Enter number for NOT operation: ");
                scanf("%d", &num1);
                performBitwiseNOT(num1);
                break;
            case 5:
                printf("Enter number and number of positions to left shift: ");
                scanf("%d %d", &num1, &positions);
                performLeftShift(num1, positions);
                break;
            case 6:
                printf("Enter number and number of positions to right shift: ");
                scanf("%d %d", &num1, &positions);
                performRightShift(num1, positions);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Bitwise Operations Menu ===\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("0. Exit\n");
}

void performBitwiseAND(int num1, int num2) {
    int result = num1 & num2;
    printf("Result of %d AND %d = %d\n", num1, num2, result);
    printf("Binary: ");
    printBinary(result);
}

void performBitwiseOR(int num1, int num2) {
    int result = num1 | num2;
    printf("Result of %d OR %d = %d\n", num1, num2, result);
    printf("Binary: ");
    printBinary(result);
}

void performBitwiseXOR(int num1, int num2) {
    int result = num1 ^ num2;
    printf("Result of %d XOR %d = %d\n", num1, num2, result);
    printf("Binary: ");
    printBinary(result);
}

void performBitwiseNOT(int num) {
    int result = ~num;
    printf("Result of NOT %d = %d\n", num, result);
    printf("Binary: ");
    printBinary(result);
}

void performLeftShift(int num, int positions) {
    int result = num << positions;
    printf("Result of %d << %d = %d\n", num, positions, result);
    printf("Binary: ");
    printBinary(result);
}

void performRightShift(int num, int positions) {
    int result = num >> positions;
    printf("Result of %d >> %d = %d\n", num, positions, result);
    printf("Binary: ");
    printBinary(result);
}

void printBinary(int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}