//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the rules of the game
void displayInstructions() {
    printf("Welcome to the Mathematical Quiz Game!\n");
    printf("In this game, you will answer a series of mathematical questions.\n");
    printf("For each correct answer, you will earn points. Try to get the highest score!\n");
    printf("You can type 'exit' at any time to end the game.\n");
    printf("Let's get started!\n\n");
}

// Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a math question and get the answer from the player
void mathQuiz(int *score) {
    int num1, num2, answer, userAnswer, operation;
    char operationSymbol;

    num1 = randomNumber(1, 50);
    num2 = randomNumber(1, 50);
    operation = randomNumber(1, 3); // 1 for addition, 2 for subtraction, 3 for multiplication

    if (operation == 1) {
        operationSymbol = '+';
        answer = num1 + num2;
    } else if (operation == 2) {
        operationSymbol = '-';
        answer = num1 - num2;
    } else {
        operationSymbol = '*';
        answer = num1 * num2;
    }

    printf("What is %d %c %d? ", num1, operationSymbol, num2);
    
    // Receive answer from player
    if (scanf(" %d", &userAnswer) != 1) {
        printf("Input error. Exiting the game.\n");
        exit(0);
    }

    // Check if the user's answer is correct
    if (userAnswer == answer) {
        printf("Correct! You've earned a point.\n");
        (*score)++;
    } else {
        printf("Incorrect. The right answer was %d.\n", answer);
    }
    printf("Current score: %d\n\n", *score);
}

// Main game loop
int main() {
    int score = 0;
    char exitCommand[5];

    srand(time(NULL)); // Seed random number generator

    displayInstructions();

    while (1) {
        mathQuiz(&score);

        printf("Do you want to continue? (yes to continue / exit to quit): ");
        scanf("%s", exitCommand);
        
        if (strcmp(exitCommand, "exit") == 0) {
            printf("Thank you for playing! Your final score is: %d\n", score);
            break;
        }
    }

    return 0;
}