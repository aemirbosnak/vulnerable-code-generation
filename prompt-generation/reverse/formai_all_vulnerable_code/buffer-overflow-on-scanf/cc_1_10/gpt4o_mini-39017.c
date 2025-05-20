//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateProblem(int *solution) {
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    char op;
    int operation = rand() % 3; // 0 for +, 1 for -, 2 for *
    
    if (operation == 0) {
        op = '+';
        *solution = num1 + num2;
    } else if (operation == 1) {
        op = '-';
        *solution = num1 - num2;
    } else {
        op = '*';
        *solution = num1 * num2;
    }

    printf("Solve: %d %c %d = ?\n", num1, op, num2);
    return *solution;
}

void provideHint(int operation, int num1, int num2) {
    if (operation == 0) {
        printf("Hint: Check for simple addition, remember that it's like counting apples!\n");
    } else if (operation == 1) {
        printf("Hint: Subtraction is like taking away, how many are left?\n");
    } else {
        printf("Hint: Multiplication is repeated addition, think of groups of items!\n");
    }
}

int main() {
    srand(time(0)); // Seed random number generator
    int numProblems = 5;
    int correctAnswers = 0;
    int totalScore = 0;

    printf("Welcome to the Math Quiz Game! Let's see how well you can solve math problems!\n");
    printf("You will face %d problems. Let's get started!\n", numProblems);

    for (int i = 0; i < numProblems; i++) {
        int solution, userAnswer;
        int operation = rand() % 3;
        int num1 = rand() % 100;
        int num2 = (operation == 1) ? (rand() % num1) : (rand() % 100); // To prevent negative numbers in subtraction

        solution = generateProblem(&solution);

        printf("Your answer: ");
        scanf("%d", &userAnswer);

        if (userAnswer == solution) {
            printf("Correct!\n\n");
            correctAnswers++;
            totalScore += 10; // 10 points for a correct answer
        } else {
            printf("Incorrect! The correct answer was: %d\n", solution);
            provideHint(operation, num1, num2);
            printf("\n");
        }
    }

    // Final score report
    printf("Quiz finished! You answered %d out of %d correctly.\n", correctAnswers, numProblems);
    printf("Your score: %d out of %d\n", totalScore, numProblems * 10);

    // Encouragement based on performance
    if (correctAnswers == numProblems) {
        printf("Outstanding performance! You are a Math genius!\n");
    } else if (correctAnswers > numProblems / 2) {
        printf("Not bad! Keep practicing and you'll get even better!\n");
    } else {
        printf("Don't worry! Practice makes perfect. Try again!\n");
    }

    return 0;
}