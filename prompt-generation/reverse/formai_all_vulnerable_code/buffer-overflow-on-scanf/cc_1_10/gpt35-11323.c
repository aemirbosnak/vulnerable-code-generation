//FormAI DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program generates a random math exercise for the user to solve.
// The user must input their answer and the program will inform them if they were correct.
// The program will continue generating exercises until the user chooses to exit.

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char operation; // The mathematical operation for the exercise
    int num1, num2, answer, userAnswer; // The two numbers used in the exercise, the actual answer, and the user's answer
    int numCorrect = 0, numWrong = 0; // Track the number of correct and incorrect answers

    printf("Welcome to the Math Exercise Program!\n");

    do {
        // Generate random numbers for the exercise
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // Generate random operation for the exercise
        switch (rand() % 4) {
            case 0:
                operation = '+';
                answer = num1 + num2;
                break;
            case 1:
                operation = '-';
                answer = num1 - num2;
                break;
            case 2:
                operation = '*';
                answer = num1 * num2;
                break;
            case 3:
                operation = '/';
                answer = num1 / num2;
                break;
            default:
                answer = 0;
                break;
        }

        // Print out the exercise for the user to solve
        printf("\nWhat is %d %c %d?\n", num1, operation, num2);

        // Get the user's answer
        scanf("%d", &userAnswer);

        // Check if the answer is correct
        if (userAnswer == answer) {
            printf("That's correct! Good job.\n");
            numCorrect++;
        } else {
            printf("Sorry, that's incorrect. The correct answer is %d.\n", answer);
            numWrong++;
        }

        // Ask the user if they want to continue
        printf("\nDo you want to continue? (y/n)\n");
        char response = getchar(); // Need to clear the buffer of any remaining new lines
        response = getchar();

        // Quit the program if the user enters 'n'
        if (response == 'n') {
            printf("\nThanks for playing! You answered %d exercises correctly and %d exercises incorrectly.\n", numCorrect, numWrong);
            return 0;
        }
    } while (1); // Loop forever until the user chooses to exit

    return 0;
}