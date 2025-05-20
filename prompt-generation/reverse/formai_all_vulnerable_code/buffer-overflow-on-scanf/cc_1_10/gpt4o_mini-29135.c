//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_QUESTIONS 10

void printIntroduction() {
    printf("Welcome to the Math Quiz!\n");
    printf("You will be asked a total of %d questions.\n", TOTAL_QUESTIONS);
    printf("Answer each question with the correct answer.\n");
    printf("Let's see how well you can do!\n\n");
}

int generateOperation() {
    return rand() % 4;  // Returns a number between 0 and 3
}

int generateQuestion(int *num1, int *num2, int *operation) {
    *num1 = rand() % 100;  // Generates a random number between 0 and 99
    *num2 = rand() % 100;  // Generates another random number
    
    *operation = generateOperation();

    // Prevent division by zero
    if (*operation == 3 && *num2 == 0) {
        *num2 = 1;  // Change to 1 to avoid division by zero
    }

    return *operation;
}

void askQuestion(int num1, int num2, int operation) {
    switch (operation) {
        case 0: // Addition
            printf("What is %d + %d? ", num1, num2);
            break;
        case 1: // Subtraction
            printf("What is %d - %d? ", num1, num2);
            break;
        case 2: // Multiplication
            printf("What is %d * %d? ", num1, num2);
            break;
        case 3: // Division
            printf("What is %d / %d? (Provide integer answer) ", num1, num2);
            break;
    }
}

int calculateAnswer(int num1, int num2, int operation) {
    switch (operation) {
        case 0: return num1 + num2;
        case 1: return num1 - num2;
        case 2: return num1 * num2;
        case 3: return num1 / num2;  // Integer division
    }
    return 0;
}

void printScore(int score) {
    printf("\nYou scored %d out of %d.\n", score, TOTAL_QUESTIONS);
    if (score == TOTAL_QUESTIONS) {
        printf("Perfect! You're a math genius!\n");
    } else if (score > TOTAL_QUESTIONS / 2) {
        printf("Good job! You have a solid understanding of basic math.\n");
    } else {
        printf("Don't worry! Keep practicing, and you'll get better.\n");
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    int score = 0;
    int num1, num2, operation;

    printIntroduction();

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        operation = generateQuestion(&num1, &num2, &operation);
        
        askQuestion(num1, num2, operation);

        int userAnswer;
        scanf("%d", &userAnswer);

        int correctAnswer = calculateAnswer(num1, num2, operation);

        if (userAnswer == correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %d.\n", correctAnswer);
        }
    }

    printScore(score);
    return 0;
}