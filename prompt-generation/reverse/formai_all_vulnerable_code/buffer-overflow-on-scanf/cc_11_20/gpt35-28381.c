//FormAI DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, choice, result;

    printf("Welcome to the Math Quiz!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Addition Quiz\n");

                num1 = rand() % 100;
                num2 = rand() % 100;

                printf("%d + %d = ", num1, num2);
                scanf("%d", &result);

                if (result == num1 + num2) {
                    printf("Correct!\n\n");
                } else {
                    printf("Incorrect. The correct answer is %d\n\n", num1 + num2);
                }

                break;

            case 2:
                printf("Subtraction Quiz\n");

                num1 = rand() % 100;
                num2 = rand() % 100;

                printf("%d - %d = ", num1, num2);
                scanf("%d", &result);

                if (result == num1 - num2) {
                    printf("Correct!\n\n");
                } else {
                    printf("Incorrect. The correct answer is %d\n\n", num1 - num2);
                }

                break;

            case 3:
                printf("Multiplication Quiz\n");

                num1 = rand() % 10;
                num2 = rand() % 10;

                printf("%d * %d = ", num1, num2);
                scanf("%d", &result);

                if (result == num1 * num2) {
                    printf("Correct!\n\n");
                } else {
                    printf("Incorrect. The correct answer is %d\n\n", num1 * num2);
                }

                break;

            case 4:
                printf("Division Quiz\n");

                num1 = rand() % 10 + 1;
                num2 = rand() % 10 + 1;

                printf("%d / %d = ", num1 * num2, num2);
                scanf("%d", &result);

                if (result == num1) {
                    printf("Correct!\n\n");
                } else {
                    printf("Incorrect. The correct answer is %d\n\n", num1);
                }

                break;

            case 5:
                printf("Thanks for playing!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    } while (choice != 5);

    return 0;
}