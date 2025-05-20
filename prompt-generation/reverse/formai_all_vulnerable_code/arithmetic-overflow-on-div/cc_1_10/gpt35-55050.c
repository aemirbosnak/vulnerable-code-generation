//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome to the Curious Calculator!\n");
    printf("What would you like to do?\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Please enter your choice (1-4): ");

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice. Exiting program.\n");
        return 0;
    }

    printf("Great choice! Now enter two numbers: ");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int result;

    // Do the math based on user's choice
    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The difference between %d and %d is %d.\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, result);
            break;
        case 4:
            if (num2 == 0) {
                printf("Sorry, cannot divide by zero. Exiting program.\n");
                return 0;
            }
            result = num1 / num2;
            printf("The quotient of %d and %d is %d.\n", num1, num2, result);
            break;
    }

    printf("Thanks for using the Curious Calculator! Goodbye!\n");
    return 0;
}