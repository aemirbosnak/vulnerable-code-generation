//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5

// Function to generate a random number within a given range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to ask questions and calculate score
void mathQuiz() {
    int score = 0;
    
    printf("Welcome to the Math Quiz Challenge!\n");
    printf("You will be presented with %d questions.\n", NUM_QUESTIONS);
    printf("Let's see how many you can answer correctly! Good luck!\n\n");
    
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int num1 = generateRandomNumber(1, 10);
        int num2 = generateRandomNumber(1, 10);
        char operator;
        int answer = 0, userAnswer = 0;

        int op = generateRandomNumber(1, 4);
        switch (op) {
            case 1:
                operator = '+';
                answer = num1 + num2;
                break;
            case 2:
                operator = '-';
                answer = num1 - num2;
                break;
            case 3:
                operator = '*';
                answer = num1 * num2;
                break;
            case 4:
                operator = '/';
                answer = num1 / num2; // Integer division
                break;
        }

        printf("Question %d: What is %d %c %d? ", i + 1, num1, operator, num2);
        scanf("%d", &userAnswer);

        if (userAnswer == answer) {
            printf("Correct! 🎉\n");
            score++;
        } else {
            printf("Oops! The correct answer was %d.\n", answer);
        }
        printf("\n");
    }

    printf("You answered %d out of %d questions correctly! Your score is: %d/5\n", score, NUM_QUESTIONS, score);
    
    if (score == NUM_QUESTIONS) {
        printf("Amazing! You're a Math Wizard! 🧙‍♂️\n");
    } else if (score >= NUM_QUESTIONS / 2) {
        printf("Great job! Keep practicing to reach wizard status! 💪\n");
    } else {
        printf("Don't worry! Practice makes perfect! 🌱\n");
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    mathQuiz();

    return 0;
}