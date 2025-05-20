//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>

// This program generates a random arithmetic expression using +, -, *, and /
// and asks the user to evaluate it

int main()
{
    int num1, num2, result;
    char operator;

    printf("Welcome to the Arithmetic Quiz!\n");

    // generate random numbers between 1-50
    num1 = rand() % 50 + 1;
    num2 = rand() % 50 + 1;

    // generate random arithmetic operator
    switch (rand() % 4) {
        case 0:
            operator = '+';
            result = num1 + num2;
            break;

        case 1:
            operator = '-';
            result = num1 - num2;
            break;

        case 2:
            operator = '*';
            result = num1 * num2;
            break;

        case 3:
            operator = '/';
            // prevent division by zero
            while (num2 == 0) {
                num2 = rand() % 50 + 1;
            }
            result = num1 / num2;
            break;
    }

    // display the generated arithmetic expression
    printf("What is %d %c %d?\n", num1, operator, num2);

    // get user input
    int answer;
    scanf("%d", &answer);

    // check if the user's answer matches the actual result
    if (answer == result) {
        printf("Congratulations! %d is the correct answer.\n", result);
    }
    else {
        printf("Sorry, %d is the wrong answer. The correct answer is %d.\n", answer, result);
    }

    return 0;
}