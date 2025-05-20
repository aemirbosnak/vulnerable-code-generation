//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\nWelcome to the C Math Exercise Program!\n");

    int num1, num2, correctAnswer, userAnswer, difficultyLevel, numOfQuestions, numOfCorrectAnswers = 0;

    printf("\nPlease enter the difficulty level (1 - Easy, 2 - Medium, 3 - Hard): ");
    scanf("%d", &difficultyLevel);

    printf("Please enter the number of questions you want to answer: ");
    scanf("%d", &numOfQuestions);

    printf("\nLet's begin!\n");

    srand(time(NULL));

    for(int i = 1; i <= numOfQuestions; i++) {
        switch(difficultyLevel) {
            case 1:
                num1 = rand() % 50;
                num2 = rand() % 50 + 1;
                correctAnswer = num1 + num2;
                printf("\nQuestion %d: What is %d + %d? ", i, num1, num2);
                break;

            case 2:
                num1 = rand() % 100;
                num2 = rand() % 100 + 1;
                correctAnswer = num1 * num2;
                printf("\nQuestion %d: What is %d x %d? ", i, num1, num2);
                break;

            case 3:
                num1 = rand() % 1000;
                num2 = rand() % 50 + 1;
                correctAnswer = (num1 / num2) + (num1 % num2);
                printf("\nQuestion %d: What is %d divided by %d, and what is the remainder? ", i, num1, num2);
                break;

            default:
                printf("Invalid Input!");
                return 0;
                break;
        }

        scanf("%d", &userAnswer);

        if(userAnswer == correctAnswer) {
            printf("Correct!\n");
            numOfCorrectAnswers++;
        }
        else {
            printf("Incorrect. The correct answer is %d.\n", correctAnswer);
        }
    }

    printf("\nCongratulations! You answered %d out of %d correctly.\n", numOfCorrectAnswers, numOfQuestions);

    return 0;
}