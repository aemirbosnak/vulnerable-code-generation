//FormAI DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Happy Math Excercise program!\n");
    printf("Let's have some fun and learn some math!\n\n");

    // Initialize variables
    int num1, num2, result, answer, correctAnswers = 0, incorrectAnswers = 0;
    char operator, response;

    // Set seed for random number generation
    srand(time(NULL));

    do {
        // Generate random numbers and operator
        num1 = rand() % 101;
        num2 = rand() % 11;
        operator = rand() % 3;

        // Determine operator and calculate result
        if (operator == 0) {
            result = num1 + num2;
            printf("What is %d + %d?\n", num1, num2);
        }
        else if (operator == 1) {
            result = num1 - num2;
            printf("What is %d - %d?\n", num1, num2);
        }
        else {
            result = num1 * num2;
            printf("What is %d * %d?\n", num1, num2);
        }

        // Retrieve answer from user
        scanf("%d", &answer);

        // Check if answer is correct
        if (answer == result) {
            printf("Congratulations! Your answer is correct!\n\n");
            correctAnswers++;
        }
        else {
            printf("Sorry, your answer is incorrect. The correct answer is %d.\n\n", result);
            incorrectAnswers++;
        }

        // Ask user if they want to continue
        printf("Do you want to continue? (y/n)\n");
        scanf(" %c", &response);

        // Clear terminal screen
        system("clear");
    } while (response == 'y' || response == 'Y');

    // Display final results
    printf("Thank you for playing the Happy Math Excercise program!\n\n");
    printf("You correctly answered %d questions.\n", correctAnswers);

    if (incorrectAnswers == 0) {
        printf("You did not make any mistakes. Great job!\n");
    }
    else {
        printf("You made %d mistakes. Keep practicing!\n", incorrectAnswers);
    }

    return 0;
}