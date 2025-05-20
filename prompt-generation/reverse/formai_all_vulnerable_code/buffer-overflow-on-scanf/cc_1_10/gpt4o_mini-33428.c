//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10 // Number of questions in the quiz
#define MAX_VALUE 10    // Maximum value for operands

// Function to generate a random number within a specified range
int generateRandomNumber(int max) {
    return rand() % max + 1; // Ensure at least 1
}

// Function to ask a question based on operation type
void askQuestion(int num1, int num2, char operation) {
    printf("What is %d %c %d? ", num1, operation, num2);
}

// Function to calculate the answer based on the operation type
int calculateAnswer(int num1, int num2, char operation) {
    switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return (num2 != 0) ? num1 / num2 : 0; // Avoid division by zero
        default: return 0;
    }
}

// Function to play the math quiz
void playQuiz() {
    int score = 0;
    char operations[] = {'+', '-', '*', '/'}; // Array of possible operations

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int num1 = generateRandomNumber(MAX_VALUE);
        int num2 = generateRandomNumber(MAX_VALUE);
        char operation = operations[rand() % (sizeof(operations) / sizeof(operations[0]))];

        askQuestion(num1, num2, operation);

        int userAnswer;
        scanf("%d", &userAnswer);

        int correctAnswer = calculateAnswer(num1, num2, operation);
        if (userAnswer == correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", correctAnswer);
        }
    }

    printf("Quiz finished! Your score is %d out of %d.\n", score, NUM_QUESTIONS);
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    char playAgain;

    do {
        printf("Welcome to the Math Quiz!\n");
        playQuiz();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain); // Space before %c to consume any leftover newline

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}