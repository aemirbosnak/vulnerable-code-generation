//GPT-4o-mini DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void clearScreen() {
    // Clear the console screen using ANSI escape codes
    printf("\033[H\033[J");
}

int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

char generateRandomOperator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[generateRandomNumber(0, 3)];
}

float calculateAnswer(float num1, float num2, char operator) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return (num2 != 0) ? num1 / num2 : 0; // Avoid division by zero
        default: return 0;
    }
}

void displayInstructions(int timeLimit) {
    printf("Welcome to the Math Game!\n");
    printf("You will be given a series of arithmetic problems to solve.\n");
    printf("You have %d seconds to answer as many questions as you can!\n", timeLimit);
    printf("Press Enter to start the game...\n");
    getchar();
}

int main() {
    srand(time(0));  // Seed the random number generator
    int score = 0;
    int questionCount = 10; // Total questions
    int timeLimit = 30; // Time limit in seconds

    clearScreen();
    displayInstructions(timeLimit);
    
    time_t startTime = time(NULL);
    time_t currentTime;

    for (int i = 0; i < questionCount; i++) {
        float num1 = generateRandomNumber(1, 20);
        float num2 = generateRandomNumber(1, 20);
        char operator = generateRandomOperator();
        
        // Avoid division when num2 is zero
        if (operator == '/' && num2 == 0) {
            num2 = generateRandomNumber(1, 20);
        }

        float correctAnswer = calculateAnswer(num1, num2, operator);

        printf("Question %d: %.2f %c %.2f = ?\n", i + 1, num1, operator, num2);

        // Check if the time is up
        currentTime = time(NULL);
        if (difftime(currentTime, startTime) > timeLimit) {
            printf("Time's up! You answered %d questions correctly.\n", score);
            return 0;
        }

        float userAnswer;
        printf("Your answer: ");
        scanf("%f", &userAnswer);

        if (userAnswer == correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %.2f\n", correctAnswer);
        }

        sleep(1); // Wait for 1 second before the next question
        clearScreen(); // Clear screen for the next question
    }

    printf("Game Over! You answered %d questions correctly out of %d.\n", score, questionCount);
    return 0;
}