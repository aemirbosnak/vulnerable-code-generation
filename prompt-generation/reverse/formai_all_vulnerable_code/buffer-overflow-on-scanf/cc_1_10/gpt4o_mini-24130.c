//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5

// Function prototypes
void generateQuestion(int *num1, int *num2, char *operator);
int calculateAnswer(int num1, int num2, char operator);
void playGame();

int main() {
    printf("🎉 Welcome to the Ultimate Math Quiz Game! 🎉\n");
    printf("Get ready to challenge your math skills. Let's go!\n");
    
    playGame(); // Start the game

    return 0;
}

void playGame() {
    int score = 0;
    int num1, num2, userAnswer, correctAnswer;
    char operator;

    for(int i = 0; i < NUM_QUESTIONS; i++) {
        printf("\nQuestion %d:\n", i + 1);

        generateQuestion(&num1, &num2, &operator);

        // Calculate correct answer
        correctAnswer = calculateAnswer(num1, num2, operator);

        // Display question
        printf("What is %d %c %d? ", num1, operator, num2);
        
        // Get user input
        printf("\nYour answer: ");
        scanf("%d", &userAnswer);

        // Check answer
        if(userAnswer == correctAnswer) {
            printf("🎉 Correct! 🎉\n");
            score++;
        } else {
            printf("😢 Incorrect. The correct answer was %d.\n", correctAnswer);
        }
    }

    // Final Score
    printf("\n🔥 Game Over! You scored %d out of %d. 🔥\n", score, NUM_QUESTIONS);
}

void generateQuestion(int *num1, int *num2, char *operator) {
    // Seed the random number generator
    srand(time(0));
    
    // Randomly select two numbers and an operator
    *num1 = rand() % 100; // Numbers between 0 and 99
    *num2 = rand() % 100;
    int op = rand() % 4; // Randomly pick an operator from 0 to 3

    switch(op) {
        case 0: 
            *operator = '+'; 
            break;
        case 1: 
            *operator = '-'; 
            break;
        case 2: 
            *operator = '*'; 
            break;
        case 3: 
            *operator = '/'; 
            *num2 = (*num2 == 0) ? 1 : *num2; // Avoid division by zero
            break;
    }
}

int calculateAnswer(int num1, int num2, char operator) {
    switch(operator) {
        case '+': 
            return num1 + num2;
        case '-': 
            return num1 - num2;
        case '*': 
            return num1 * num2;
        case '/': 
            return num1 / num2;
        default: 
            return 0; // This should not occur
    }
}