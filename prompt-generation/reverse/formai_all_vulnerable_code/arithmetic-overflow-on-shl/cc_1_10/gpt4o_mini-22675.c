//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

void displayMenu() {
    printf("\n---- Bitwise Operations Menu ----\n");
    printf("1. AND Operation\n");
    printf("2. OR Operation\n");
    printf("3. XOR Operation\n");
    printf("4. NOT Operation\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");
    printf("----------------------------------\n");
    printf("Choose an operation (1-7): ");
}

int main() {
    int choice, num1, num2, result;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two integers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 & num2;
                printf("Result of %d AND %d is: %d\n", num1, num2, result);
                break;

            case 2:
                printf("Enter two integers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 | num2;
                printf("Result of %d OR %d is: %d\n", num1, num2, result);
                break;

            case 3:
                printf("Enter two integers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 ^ num2;
                printf("Result of %d XOR %d is: %d\n", num1, num2, result);
                break;

            case 4:
                printf("Enter an integer: ");
                scanf("%d", &num1);
                result = ~num1;
                printf("Result of NOT %d is: %d\n", num1, result);
                break;

            case 5:
                printf("Enter an integer to left shift: ");
                scanf("%d", &num1);
                printf("Enter number of positions to shift: ");
                int leftShift;
                scanf("%d", &leftShift);
                result = num1 << leftShift;
                printf("Result of %d left shifted by %d is: %d\n", num1, leftShift, result);
                break;

            case 6:
                printf("Enter an integer to right shift: ");
                scanf("%d", &num1);
                printf("Enter number of positions to shift: ");
                int rightShift;
                scanf("%d", &rightShift);
                result = num1 >> rightShift;
                printf("Result of %d right shifted by %d is: %d\n", num1, rightShift, result);
                break;

            default:
                printf("Invalid choice! Please choose a valid operation (1-7).\n");
                break;
        }
    }
    
    return 0;
}