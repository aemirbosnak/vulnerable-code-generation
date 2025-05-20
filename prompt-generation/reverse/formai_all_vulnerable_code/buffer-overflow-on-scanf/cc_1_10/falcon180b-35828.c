//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1, num2, operator;
    char operation;
    int result = 0;

    printf("Welcome to the Arithmetic Puzzle!\n");
    printf("I will generate random numbers and operators.\n");
    printf("Your task is to solve the equation and enter the correct answer.\n");
    printf("Are you ready? (y/n) ");
    scanf("%c", &operation);

    while (operation == 'y' || operation == 'Y') {
        num1 = rand() % 100;
        num2 = rand() % 100;
        operator = rand() % 4;

        switch (operator) {
            case 0:
                result = num1 + num2;
                printf("Solve this equation: %d + %d = ", num1, num2);
                break;
            case 1:
                result = num1 - num2;
                printf("Solve this equation: %d - %d = ", num1, num2);
                break;
            case 2:
                result = num1 * num2;
                printf("Solve this equation: %d * %d = ", num1, num2);
                break;
            case 3:
                if (num2 == 0) {
                    result = 0;
                    printf("Cannot divide by zero. Try again.\n");
                } else {
                    result = num1 / num2;
                    printf("Solve this equation: %d / %d = ", num1, num2);
                }
                break;
        }

        int user_answer;
        scanf("%d", &user_answer);

        if (user_answer == result) {
            printf("Correct! You're a genius!\n");
        } else {
            printf("Wrong! The correct answer is %d.\n", result);
        }

        printf("Do you want to continue? (y/n) ");
        scanf("%c", &operation);
    }

    return 0;
}