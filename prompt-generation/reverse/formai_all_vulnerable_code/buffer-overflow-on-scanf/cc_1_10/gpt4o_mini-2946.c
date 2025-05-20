//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

// Function to generate a random operation (+, -, *, /)
char random_operation() {
    char operations[] = {'+', '-', '*', '/'};
    return operations[rand() % 4];
}

// Function to generate a random integer within a specified range
int random_integer(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to perform the operation and return the result
double calculate(int a, int b, char operation) {
    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return (double)a / b;
            } else {
                return 0; // To avoid division by zero
            }
        default:
            return 0;
    }
}

// Function to play the guessing game
void math_game() {
    int score = 0;
    int attempts = 0;

    printf("🎉 Welcome to the Exciting Math Guessing Game! 🎲\n");
    printf("You'll be presented with a series of math questions.\n");
    printf("Try to guess the result of the operations correctly!\n\n");

    while (attempts < MAX_QUESTIONS) {
        int a = random_integer(1, 10); // Numbers between 1 and 10
        int b = random_integer(1, 10);
        char operation = random_operation();

        double result = calculate(a, b, operation);

        printf("Question %d: What is %d %c %d? ", attempts + 1, a, operation, b);

        double user_answer;
        scanf("%lf", &user_answer);

        if (user_answer == result) {
            printf("🎉 Correct! Well done!\n\n");
            score++;
        } else {
            printf("❌ Oops! The correct answer was %.2f\n\n", result);
        }

        attempts++;
    }

    printf("Game Over! You've finished the game.\n");
    printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);
    printf("Thank you for playing! 🎊\n");
}

int main() {
    srand(time(0)); // Seed the random number generator
    math_game(); // Start the game
    return 0;
}