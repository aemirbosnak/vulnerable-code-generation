//FormAI DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function that generates a random number between a given range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int num1, num2, answer, userAnswer, correctAnswers = 0, totalQuestions = 0;
    char operator;

    // seed the random number generator
    srand(time(NULL));

    // loop through 10 questions
    for (int i = 0; i < 10; i++) {
        num1 = generateRandomNumber(1, 10);
        num2 = generateRandomNumber(1, 10);

        // randomly select an operator
        switch (rand() % 3) {
            case 0:
                operator = '+';
                answer = num1 + num2;
                break;
            case 1:
                operator = '-';
                answer = num1 - num2;
                break;
            case 2:
                operator = '*';
                answer = num1 * num2;
                break;
        }

        // ask the user the question
        printf("Question %d: %d %c %d = ", i + 1, num1, operator, num2);
        scanf("%d", &userAnswer);

        // check the answer and provide feedback
        if (userAnswer == answer) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %d\n", answer);
        }

        totalQuestions++;
    }

    // display the results
    printf("You got %d out of %d questions correct.\n", correctAnswers, totalQuestions);

    return 0;
}