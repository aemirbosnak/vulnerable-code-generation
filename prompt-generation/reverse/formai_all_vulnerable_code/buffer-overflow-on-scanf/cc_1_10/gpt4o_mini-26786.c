//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("\nBitwise Operations Menu:\n");
    printf("1. AND Operation\n");
    printf("2. OR Operation\n");
    printf("3. XOR Operation\n");
    printf("4. NOT Operation\n");
    printf("5. Left Shift Operation\n");
    printf("6. Right Shift Operation\n");
    printf("7. Exit\n");
    printf("Choose an operation (1-7): ");
}

int main() {
    int choice;
    int num1, num2;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two integers for AND operation: ");
                scanf("%d %d", &num1, &num2);
                printf("Result of %d AND %d = %d\n", num1, num2, num1 & num2);
                break;

            case 2:
                printf("Enter two integers for OR operation: ");
                scanf("%d %d", &num1, &num2);
                printf("Result of %d OR %d = %d\n", num1, num2, num1 | num2);
                break;

            case 3:
                printf("Enter two integers for XOR operation: ");
                scanf("%d %d", &num1, &num2);
                printf("Result of %d XOR %d = %d\n", num1, num2, num1 ^ num2);
                break;

            case 4:
                printf("Enter an integer for NOT operation: ");
                scanf("%d", &num1);
                printf("Result of NOT %d = %d\n", num1, ~num1);
                break;

            case 5:
                printf("Enter an integer and shift amount for Left Shift operation: ");
                scanf("%d %d", &num1, &num2);
                printf("Result of %d << %d = %d\n", num1, num2, num1 << num2);
                break;

            case 6:
                printf("Enter an integer and shift amount for Right Shift operation: ");
                scanf("%d %d", &num1, &num2);
                printf("Result of %d >> %d = %d\n", num1, num2, num1 >> num2);
                break;

            default:
                printf("Invalid choice! Please choose a valid option (1-7).\n");
                break;
        }
    }
    return 0;
}