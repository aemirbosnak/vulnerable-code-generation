//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, result;
    char repeat;

    srand(time(NULL));
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    printf("Welcome to the Arithmetic Game!\n");
    printf("You will be given two numbers and an operation.\n");
    printf("Enter the correct result to earn points.\n");

    do {
        operation = rand() % 4;
        if (operation == 0) {
            printf("Addition problem:\n");
            result = num1 + num2;
        } else if (operation == 1) {
            printf("Subtraction problem:\n");
            result = num1 - num2;
        } else if (operation == 2) {
            printf("Multiplication problem:\n");
            result = num1 * num2;
        } else {
            printf("Division problem:\n");
            result = num1 / num2;
        }

        printf("Numbers: %d and %d\n", num1, num2);
        printf("Operation: %d\n", operation);

        scanf("%d", &result);

        switch (operation) {
            case 0:
                if (result == num1 + num2) {
                    printf("Correct!\n");
                    printf("You earned 10 points.\n");
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 1:
                if (result == num1 - num2) {
                    printf("Correct!\n");
                    printf("You earned 10 points.\n");
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 2:
                if (result == num1 * num2) {
                    printf("Correct!\n");
                    printf("You earned 10 points.\n");
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 3:
                if (result == num1 / num2) {
                    printf("Correct!\n");
                    printf("You earned 10 points.\n");
                } else {
                    printf("Incorrect.\n");
                }
                break;
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Thanks for playing the Arithmetic Game!\n");

    return 0;
}