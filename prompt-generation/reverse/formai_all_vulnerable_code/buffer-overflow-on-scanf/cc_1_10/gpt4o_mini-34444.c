//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playMathGame(void);
int getDivisor();
void checkAnswer(int numerator, int denominator, int userGuess);
void handleError(int errorCode);

int main() {
    srand(time(NULL)); // Seed the random number generator
    printf("Welcome to the Puzzling Math Game!\n");
    printf("Here, we divide and conquer... or do we?\n");

    playMathGame();

    return 0;
}

void playMathGame(void) {
    int numerator = rand() % 100; // Random numerator between 0 and 99
    int denominator = getDivisor(); // Get a valid divisor
    int userGuess;

    printf("What is %d divided by %d?\n", numerator, denominator);
    printf("Your guess: ");
    if(scanf("%d", &userGuess) != 1) {
        handleError(1); // Input error
        return;
    }
    
    checkAnswer(numerator, denominator, userGuess);
}

int getDivisor() {
    int denominator;
    do {
        denominator = rand() % 10; // Random denominator between 0 and 9
        if (denominator == 0) {
            printf("Aha! Attempted division by zero! Let's try again...\n");
        }
    } while (denominator == 0); // Repeat until a valid denominator is found

    return denominator; 
}

void checkAnswer(int numerator, int denominator, int userGuess) {
    float correctAnswer = (float) numerator / denominator;

    if ((int) correctAnswer == userGuess) {
        printf("Brilliant! You've solved the enigma correctly.\n");
    } else {
        printf("Alas! The truth eludes you. The correct answer was %.2f\n", correctAnswer);
        if(userGuess > correctAnswer) {
            printf("You guessed too high. Try to ground yourself.\n");
        } else {
            printf("Your guess was below the mark, enlightening yet misleading!\n");
        }
    }
}

void handleError(int errorCode) {
    switch (errorCode) {
        case 1:
            printf("ERR: Invalid input! That's a riddle even I can't solve.\n");
            printf("Be careful with your spells (input) next time!\n");
            // Prompt to restart the game could be added here
            break;
        default:
            printf("ERR: An unknown error has transpired.\n");
            printf("The universe is vast; perhaps try to contemplate its mysteries!\n");
            break;
    }
}