//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    printf("\033[H\033[J");
}

void displayLogo() {
    printf("==================================\n");
    printf("         C DICE ROLLER          \n");
    printf("==================================\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void showCurrentScore(int score, int rounds, int totalScore) {
    printf("Current Score: %d\n", score);
    printf("Rounds Played: %d\n", rounds);
    printf("Total Score: %d\n", totalScore);
}

void printInstructions() {
    printf("Instructions:\n");
    printf("1. Choose the number of sides on the dice.\n");
    printf("2. Roll the dice as many times as you wish.\n");
    printf("3. Type 'exit' to quit the game at any time.\n");
}

void playGame() {
    char input[10];
    int sides, score, roundScore, totalScore = 0, rounds = 0;

    printf("Enter the number of sides on your dice (e.g., 6 for a standard dice): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &sides);

    clearScreen();
    printInstructions();

    while(1) {
        printf("Press ENTER to roll the dice or type 'exit' to quit: ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        roundScore = rollDice(sides);
        score = roundScore;
        totalScore += score;
        rounds++;

        clearScreen();
        displayLogo();
        printf("You rolled a %d!\n", roundScore);
        showCurrentScore(score, rounds, totalScore);
    }

    printf("Thanks for playing! Your total score was: %d\n", totalScore);
}

int main() {
    srand(time(NULL));
    clearScreen();
    displayLogo();
    playGame();

    return 0;
}