//FormAI DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to check if the user's answer is correct
int checkAnswer(int correctAnswer, int userAnswer) {
    if (correctAnswer == userAnswer) {
        printf("Correct! You're a math wizard!\n");
        return 1;
    } else {
        printf("Incorrect! Keep practicing!\n");
        return 0;
    }
}

int main() {
    // seed the random number generator
    srand(time(0));

    // print the welcome message
    printf("Welcome to Retro Math Exercise!\n\n");

    // initialize the score and max number of questions
    int score = 0;
    int maxQuestions = 10;

    // loop through the questions
    for (int i = 1; i <= maxQuestions; i++) {
        // generate two random numbers between 1 and 100
        int num1 = rand() % 100 + 1;
        int num2 = rand() % 100 + 1;

        // generate a random operation (+, -, or *)
        int operation = rand() % 3;

        // initialize the correct answer and the user's answer
        int correctAnswer, userAnswer;

        // perform the operation and get the correct answer
        switch (operation) {
            case 0:
                // addition
                correctAnswer = num1 + num2;
                printf("%d + %d = ", num1, num2);
                break;
            case 1:
                // subtraction
                correctAnswer = num1 - num2;
                printf("%d - %d = ", num1, num2);
                break;
            case 2:
                // multiplication
                correctAnswer = num1 * num2;
                printf("%d * %d = ", num1, num2);
                break;
        }

        // get the user's answer
        scanf("%d", &userAnswer);

        // check if the user's answer is correct and update the score
        score += checkAnswer(correctAnswer, userAnswer);
    }

    // print the final score
    printf("\nFinal Score: %d out of %d\n", score, maxQuestions);

    return 0;
}