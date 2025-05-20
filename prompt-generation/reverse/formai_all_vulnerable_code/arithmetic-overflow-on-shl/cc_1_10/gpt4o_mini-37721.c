//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Welcome to Bitwise Battles!\n");
    printf("Please choose an operation:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
}

int bitwiseAND(int a, int b) {
    return a & b;
}

int bitwiseOR(int a, int b) {
    return a | b;
}

int bitwiseXOR(int a, int b) {
    return a ^ b;
}

int bitwiseNOT(int a) {
    return ~a;
}

int bitwiseLeftShift(int a, int n) {
    return a << n;
}

int bitwiseRightShift(int a, int n) {
    return a >> n;
}

int main() {
    int choice, num1, num2, result;
    int shiftAmount;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting… Thank you for playing Bitwise Battles!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two integers (space-separated): ");
                scanf("%d %d", &num1, &num2);
                result = bitwiseAND(num1, num2);
                printf("Result of %d AND %d is: %d\n", num1, num2, result);
                break;

            case 2:
                printf("Enter two integers (space-separated): ");
                scanf("%d %d", &num1, &num2);
                result = bitwiseOR(num1, num2);
                printf("Result of %d OR %d is: %d\n", num1, num2, result);
                break;

            case 3:
                printf("Enter two integers (space-separated): ");
                scanf("%d %d", &num1, &num2);
                result = bitwiseXOR(num1, num2);
                printf("Result of %d XOR %d is: %d\n", num1, num2, result);
                break;

            case 4:
                printf("Enter an integer: ");
                scanf("%d", &num1);
                result = bitwiseNOT(num1);
                printf("Result of NOT %d is: %d\n", num1, result);
                break;

            case 5:
                printf("Enter an integer and the number of positions to shift: ");
                scanf("%d %d", &num1, &shiftAmount);
                result = bitwiseLeftShift(num1, shiftAmount);
                printf("Result of %d << %d is: %d\n", num1, shiftAmount, result);
                break;

            case 6:
                printf("Enter an integer and the number of positions to shift: ");
                scanf("%d %d", &num1, &shiftAmount);
                result = bitwiseRightShift(num1, shiftAmount);
                printf("Result of %d >> %d is: %d\n", num1, shiftAmount, result);
                break;

            default:
                printf("Invalid choice! Please select a valid operation.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}