//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result, correct_answers = 0, incorrect_answers = 0;
    char play_again;

    // Seed the random number generator
    srand(time(NULL));

    // Loop until the user decides to quit
    do {
        // Generate two random numbers and an operator
        num1 = rand() % 100;
        num2 = rand() % 100;
        operator = rand() % 4;

        // Perform the operation and store the result
        switch (operator) {
            case 0:
                result = num1 + num2;
                break;
            case 1:
                result = num1 - num2;
                break;
            case 2:
                result = num1 * num2;
                break;
            case 3:
                if (num2 == 0) {
                    result = 0;
                } else {
                    result = num1 / num2;
                }
                break;
        }

        // Ask the user for the answer
        printf("What is %d %c %d? ", num1, (operator + 1), num2);
        scanf("%d", &play_again);

        // Check if the answer is correct
        if (play_again == result) {
            correct_answers++;
        } else {
            incorrect_answers++;
        }

        // Print the result and ask if the user wants to play again
        printf("The correct answer is %d.\n", result);
        printf("You have %d correct answers and %d incorrect answers.\n", correct_answers, incorrect_answers);
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}