//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MAX_NUM 10

void displayIntro() {
    printf("========================================\n");
    printf("Welcome to the Math Quiz Game!\n");
    printf("========================================\n");
    printf("Test your math skills by answering the questions.\n");
    printf("Get ready to have some fun!\n");
    printf("========================================\n\n");
}

int generateRandomNumber(int limit) {
    return rand() % limit + 1;
}

char getOperation() {
    char operations[] = {'+', '-', '*', '/'};
    return operations[rand() % 4];
}

int askQuestion(int num1, int num2, char operation) {
    int answer;
    printf("What is %d %c %d? ", num1, operation, num2);
    scanf("%d", &answer);
    
    int correctAnswer;
    switch (operation) {
        case '+': correctAnswer = num1 + num2; break;
        case '-': correctAnswer = num1 - num2; break;
        case '*': correctAnswer = num1 * num2; break;
        case '/': 
            if (num2 != 0) {
                correctAnswer = num1 / num2;
            } else {
                printf("Division by zero is not allowed! Rephrasing question...\n");
                return -1; // For invalid division.
            }
            break;
        default: correctAnswer = 0; break;
    }

    return correctAnswer == answer ? 1 : 0;
}

void playGame() {
    int score = 0;
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int num1 = generateRandomNumber(MAX_NUM);
        int num2 = generateRandomNumber(MAX_NUM);
        char operation = getOperation();
        
        printf("\nQuestion %d:\n", i + 1);
        int result = askQuestion(num1, num2, operation);
        
        // Check if it was an invalid division (division by zero)
        if (result == -1) {
            i--; // Retry the same question
            continue;
        }
        
        if (result) {
            printf("Correct! You've earned a point!\n");
            score++;
        } else {
            printf("Oops! That's not quite right.\n");
            switch (operation) {
                case '+': printf("The correct answer was: %d\n", num1 + num2); break;
                case '-': printf("The correct answer was: %d\n", num1 - num2); break;
                case '*': printf("The correct answer was: %d\n", num1 * num2); break;
                case '/': printf("The correct answer was: %d\n", num1 / (num2 == 0 ? 1 : num2)); break;
            }
        }
    }

    printf("\nGame Over! Your final score is: %d out of %d\n", score, MAX_QUESTIONS);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    displayIntro();
    playGame();
    return 0;
}