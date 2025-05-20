//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUESTION_COUNT 5
#define MAX_NUMBER 10

// Function declarations
void generateQuestion(int *num1, int *num2, char *operation);
void displayQuestion(int num1, int num2, char operation);
int checkAnswer(int num1, int num2, char operation, int userAnswer);

int main() {
    int score = 0;
    char choice;
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Math Quiz!\n");
    
    do {
        // Reset the score
        score = 0;

        // Quiz loop
        for (int i = 0; i < QUESTION_COUNT; i++) {
            int num1, num2;
            char operation;

            // Generate a random math question
            generateQuestion(&num1, &num2, &operation);
            
            // Display the question
            displayQuestion(num1, num2, operation);

            // Get the user's answer
            int userAnswer;
            printf("Your answer: ");
            scanf("%d", &userAnswer);

            // Check if the answer is correct
            if (checkAnswer(num1, num2, operation, userAnswer)) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer was %d.\n", checkAnswer(num1, num2, operation, -1));
            }
        }

        // Display the final score
        printf("You scored %d out of %d!\n", score, QUESTION_COUNT);

        // Ask if the user wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for playing!\n");
    return 0;
}

// Function to generate a random math question
void generateQuestion(int *num1, int *num2, char *operation) {
    *num1 = rand() % MAX_NUMBER;
    *num2 = rand() % MAX_NUMBER;

    // Randomly select an operation
    switch (rand() % 4) {
        case 0:
            *operation = '+';
            break;
        case 1:
            *operation = '-';
            break;
        case 2:
            *operation = '*';
            break;
        case 3:
            *operation = '/';
            // Ensure we don't divide by zero
            if (*num2 == 0) {
                *num2 = 1;
            }
            break;
    }
}

// Function to display the math question
void displayQuestion(int num1, int num2, char operation) {
    printf("Question: %d %c %d = ?\n", num1, operation, num2);
}

// Function to check the user’s answer
int checkAnswer(int num1, int num2, char operation, int userAnswer) {
    int correctAnswer;

    switch (operation) {
        case '+':
            correctAnswer = num1 + num2;
            break;
        case '-':
            correctAnswer = num1 - num2;
            break;
        case '*':
            correctAnswer = num1 * num2;
            break;
        case '/':
            correctAnswer = num1 / num2;
            break;
        default:
            correctAnswer = 0; // should not reach here
            break;
    }
    
    // If userAnswer is -1, we return the correct answer without checking user’s answer
    if (userAnswer == -1) {
        return correctAnswer;
    }

    // Check if the user's answer matches the correct answer
    return (userAnswer == correctAnswer);
}