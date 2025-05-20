//FormAI DATASET v1.0 Category: Math exercise ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a math exercise where the user has to input the number of correct answers.
 * The program then calculates the number of correct answers and gives a grade based on the results. */

int main(void) {
    srand(time(NULL));
    int numQuestions, minNum, maxNum;
    double numCorrect = 0.0;

    printf("Welcome to the math exercise program!\n");
    printf("How many questions would you like to answer: ");
    scanf("%d", &numQuestions);

    printf("What is the minimum number? ");
    scanf("%d", &minNum);

    printf("What is the maximum number? ");
    scanf("%d", &maxNum);

    printf("Let's get started!\n");

    for (int i = 0; i < numQuestions; i++) {
        int num1 = rand() % (maxNum - minNum + 1) + minNum;
        int num2 = rand() % (maxNum - minNum + 1) + minNum;
        int answer, userAnswer;

        printf("Question %d: %d + %d = ", i + 1, num1, num2);
        answer = num1 + num2;

        scanf("%d", &userAnswer);

        if (userAnswer == answer) {
            numCorrect++;
        }
    }

    double percentCorrect = (numCorrect / numQuestions) * 100;

    printf("You got %.0f out of %d questions correct!\n", numCorrect, numQuestions);
    printf("Your score is %.2f percent.\n", percentCorrect);

    if (percentCorrect >= 90) {
        printf("Great job, you got an A!\n");
    } else if (percentCorrect >= 80) {
        printf("Good job, you got a B.\n");
    } else if (percentCorrect >= 70) {
        printf("Not bad, you got a C.\n");
    } else if (percentCorrect >= 60) {
        printf("You got a D. Try harder next time.\n");
    } else {
        printf("You got an F. You need to study more.\n");
    }

    return 0;
}