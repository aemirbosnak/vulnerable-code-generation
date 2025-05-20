//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int num1, num2, operator;
    char operation;
    int correctAnswers = 0;
    int incorrectAnswers = 0;
    int totalQuestions = 0;

    // Loop until the user decides to quit
    while (1) {
        // Generate two random numbers between 1 and 10
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // Generate a random operator
        operator = rand() % 4;

        // Convert the operator to a character representation
        switch (operator) {
            case 0:
                operation = '+';
                break;
            case 1:
                operation = '-';
                break;
            case 2:
                operation = '*';
                break;
            case 3:
                operation = '/';
                break;
        }

        // Display the question to the user
        printf("What is %d %c %d? ", num1, operation, num2);

        // Read the user's answer
        int answer;
        scanf("%d", &answer);

        // Determine if the user's answer is correct
        if (answer == num1 + num2) {
            correctAnswers++;
        } else {
            incorrectAnswers++;
        }

        // Increment the total number of questions
        totalQuestions++;

        // Ask the user if they want to continue
        char choice;
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &choice);

        // If the user doesn't want to continue, exit the loop
        if (choice == 'n') {
            break;
        }
    }

    // Display the results to the user
    printf("You answered %d out of %d questions correctly.\n", correctAnswers, totalQuestions);
    printf("You answered %d out of %d questions incorrectly.\n", incorrectAnswers, totalQuestions);

    return 0;
}