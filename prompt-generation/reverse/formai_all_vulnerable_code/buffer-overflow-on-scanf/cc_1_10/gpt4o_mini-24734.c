//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcome() {
    printf("🎉 Welcome to the Happy Math Exercise! 🎉\n");
    printf("Let's have some fun while we learn math! 😄\n");
    printf("You will be given a series of random arithmetic problems to solve.\n");
    printf("Type your answer, and let's see how well you can do! 🥳\n\n");
}

void askQuestion(int num1, int num2, char operator) {
    if (operator == '+') {
        printf("What is %d + %d? ", num1, num2);
    } else if (operator == '-') {
        printf("What is %d - %d? ", num1, num2);
    } else if (operator == '*') {
        printf("What is %d * %d? ", num1, num2);
    } else if (operator == '/') {
        printf("What is %d / %d? (Round to nearest integer) ", num1, num2);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int correctCount = 0, totalCount = 0;
    char operators[] = {'+', '-', '*', '/'};
    int numQuestions = 5;

    printWelcome();

    for (int i = 0; i < numQuestions; i++) {
        int num1 = rand() % 100; // Random number between 0 and 99
        int num2 = rand() % 100; // Random number between 0 and 99
        char operator = operators[rand() % 4]; // Random operator

        askQuestion(num1, num2, operator);
        int userAnswer;
        scanf("%d", &userAnswer);
        totalCount++;

        int correctAnswer;
        if (operator == '+') {
            correctAnswer = num1 + num2;
        } else if (operator == '-') {
            correctAnswer = num1 - num2;
        } else if (operator == '*') {
            correctAnswer = num1 * num2;
        } else if (operator == '/' && num2 != 0) {
            correctAnswer = num1 / num2;
        } else if (operator == '/' && num2 == 0) {
            correctAnswer = 0; // For division by zero, just a placeholder
        }

        if (userAnswer == correctAnswer) {
            printf("🎉 Hooray! That's correct! 🎉\n\n");
            correctCount++;
        } else {
            printf("Oh no! The correct answer was %d. Better luck next time! 😊\n\n", correctAnswer);
        }
    }

    printf("🎊 You've completed the math exercises! 🎊\n");
    printf("You got %d out of %d questions right! That's fantastic!\n", correctCount, totalCount);

    if (correctCount == numQuestions) {
        printf("🌟 You're a math whiz! 🌟\n");
    } else if (correctCount >= numQuestions / 2) {
        printf("👍 Great job! Keep practicing! 👍\n");
    } else {
        printf("Don't worry! Just keep trying, and you'll get better! 💪\n");
    }

    printf("Thank you for playing! Have a wonderful day! 😄🎈\n");

    return 0;
}