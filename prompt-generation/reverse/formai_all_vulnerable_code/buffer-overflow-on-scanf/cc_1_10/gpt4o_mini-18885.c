//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5

void displayInstructions() {
    printf("Welcome to the Math Quiz Game!\n");
    printf("You will be presented with %d questions.\n", NUM_QUESTIONS);
    printf("Answer each question with the correct number.\n");
    printf("Let's see how many you can get right!\n\n");
}

int generateQuestion(int *num1, int *num2) {
    *num1 = rand() % 100;
    *num2 = rand() % 100;
    return (rand() % 4); // will return a number between 0 and 3 for different operations
}

void askQuestion(int num1, int num2, int operator, int *correctAnswer) {
    switch (operator) {
        case 0:
            printf("What is %d + %d? ", num1, num2);
            *correctAnswer = num1 + num2;
            break;
        case 1:
            printf("What is %d - %d? ", num1, num2);
            *correctAnswer = num1 - num2;
            break;
        case 2:
            printf("What is %d * %d? ", num1, num2);
            *correctAnswer = num1 * num2;
            break;
        case 3:
            printf("What is %d / %d? (give an integer answer) ", num1, num2);
            *correctAnswer = (num2 != 0) ? num1 / num2 : 0;
            break;
    }
}

int main() {
    int score = 0;
    int num1, num2, operator;
    int userAnswer;
    int correctAnswer;

    srand(time(NULL)); // Initialize random seed

    displayInstructions();

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        operator = generateQuestion(&num1, &num2);
        askQuestion(num1, num2, operator, &correctAnswer);

        // Read the user's answer
        scanf("%d", &userAnswer);

        // Check the answer
        if (userAnswer == correctAnswer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %d.\n\n", correctAnswer);
        }
    }

    printf("You've completed the quiz! Your score is %d out of %d.\n", score, NUM_QUESTIONS);
    
    return 0;
}