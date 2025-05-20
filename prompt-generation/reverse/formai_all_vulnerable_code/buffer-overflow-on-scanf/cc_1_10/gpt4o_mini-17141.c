//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10

void clearScreen() {
    printf("\033[H\033[J");
}

void displayIntroduction() {
    clearScreen();
    printf("Welcome to the Fantastic Math Quiz!\n");
    printf("Get ready to challenge your math skills.\n");
    printf("You will be given 10 random math problems.\n");
    printf("Score points for each correct answer.\n\n");
    printf("Press Enter to start the quiz...\n");
    getchar();
}

int generateRandomNumber(int limit) {
    return rand() % limit + 1; // Generates random number between 1 and limit
}

char getRandomOperator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[generateRandomNumber(4) - 1]; // Get random operator
}

int performOperation(int num1, int num2, char operator) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2; // Assumes num2 != 0
        default: return 0; // Just in case, shouldn't happen
    }
}

int main() {
    int score = 0;
    char operator;
    int num1, num2, userAnswer, correctAnswer;

    srand(time(NULL)); // Seed the random generator
    displayIntroduction();

    for (int i = 1; i <= NUM_QUESTIONS; i++) {
        num1 = generateRandomNumber(10); // Generate numbers from 1 to 10
        num2 = generateRandomNumber(10);

        operator = getRandomOperator();

        // Special condition for division to avoid fractions
        if (operator == '/') {
            // Make sure num1 is a multiple of num2
            num1 = num1 * num2;
        }

        correctAnswer = performOperation(num1, num2, operator);

        printf("Question %d: %d %c %d = ?\n", i, num1, operator, num2);

        printf("Your answer: ");
        scanf("%d", &userAnswer);

        if (userAnswer == correctAnswer) {
            printf("Correct! 🎉\n");
            score++;
        } else {
            printf("Oops! The correct answer was %d. 😢\n", correctAnswer);
        }

        // Give user a moment to absorb the question
        printf("Press Enter for the next question...\n");
        getchar(); // To consume the leftover newline from previous input
        getchar();
    }

    // Display final score
    clearScreen();
    printf("Quiz Complete!\n");
    printf("You answered %d out of %d questions correctly!\n", score, NUM_QUESTIONS);
    printf("Your final score is: %d\n", score * 10); // Calculate percentage score

    if (score > 7) {
        printf("You're a Math Wizard! 🌟\n");
    } else if (score > 4) {
        printf("Great Job! Keep practicing! 😊\n");
    } else {
        printf("Don't worry! Practice makes perfect! 💪\n");
    }

    printf("Thanks for playing! Press Enter to exit...\n");
    getchar();

    return 0;
}