//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void printMenu() {
    printf("\n");
    printf("  ***********************************  \n");
    printf("  *         Bitwise Operations      *  \n");
    printf("  *        by Retro C Programmer    *  \n");
    printf("  ***********************************  \n");
    printf("  *     1. Bitwise AND              *  \n");
    printf("  *     2. Bitwise OR               *  \n");
    printf("  *     3. Bitwise XOR              *  \n");
    printf("  *     4. Bitwise NOT              *  \n");
    printf("  *     5. Left Shift                *  \n");
    printf("  *     6. Right Shift               *  \n");
    printf("  *     7. Exit                     *  \n");
    printf("  ***********************************  \n");
    printf("Please choose an option (1-7): ");
}

int main() {
    int choice;
    int num1, num2, result;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Thank you for using the Bitwise Operations Tool!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid option! Please try again.\n");
            continue;
        }

        if (choice != 4) {
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
        } else {
            printf("Enter a number: ");
            scanf("%d", &num1);
        }

        switch (choice) {
            case 1:
                result = num1 & num2;
                printf("Result of %d AND %d = %d\n", num1, num2, result);
                break;
            case 2:
                result = num1 | num2;
                printf("Result of %d OR %d = %d\n", num1, num2, result);
                break;
            case 3:
                result = num1 ^ num2;
                printf("Result of %d XOR %d = %d\n", num1, num2, result);
                break;
            case 4:
                result = ~num1;
                printf("Result of NOT %d = %d\n", num1, result);
                break;
            case 5:
                result = num1 << num2;
                printf("Result of %d left shifted by %d = %d\n", num1, num2, result);
                break;
            case 6:
                result = num1 >> num2;
                printf("Result of %d right shifted by %d = %d\n", num1, num2, result);
                break;
        }
    }

    return 0;
}