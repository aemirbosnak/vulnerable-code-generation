//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROUNDS 5
#define MAX_SCORE 100
#define MIN_SCORE 0

typedef struct {
    char name[50];
    int score;
} Player;

// Function to clear the screen
void clearScreen() {
    printf("\033[H\033[J");
}

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the Cryptic Number Game!\n");
    printf("You will challenge your wit to guess a number within a range.\n");
    printf("For every correct guess, you will earn points. You have %d rounds.\n", MAX_ROUNDS);
    printf("May the odds be in your favor!\n\n");
}

// Function to get player name
void getPlayerName(Player *player) {
    printf("Enter your name: ");
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline character
    player->score = 0;
}

// Function to generate a random number
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to play a single round
void playRound(Player *player, int round) {
    int min = 1, max = 100;
    int secretNumber = generateRandomNumber(min, max);
    int guess;
    int attempts = 0;
    
    printf("Round %d: Guess the secret number between %d and %d!\n", round, min, max);
    
    while (attempts < 3) {
        printf("Attempt %d: Your guess? ", attempts + 1);
        scanf("%d", &guess);
        attempts++;

        if (guess < min || guess > max) {
            printf("Out of range! Try again.\n");
        } else if (guess < secretNumber) {
            printf("Higher!\n");
        } else if (guess > secretNumber) {
            printf("Lower!\n");
        } else {
            printf("Correct! The number was %d\n", secretNumber);
            player->score += MAX_SCORE - (attempts - 1) * 20; // Score decreases with more attempts
            return;
        }
    }
    printf("Sorry! The correct number was %d. Better luck next time!\n", secretNumber);
}

// Function to display the final score
void displayScore(Player *player) {
    printf("\nGame Over! %s, your final score is: %d\n", player->name, player->score);
}

// Main function
int main() {
    Player player;
    srand(time(NULL));

    clearScreen();
    displayInstructions();
    getPlayerName(&player);

    for (int i = 1; i <= MAX_ROUNDS; i++) {
        playRound(&player, i);
    }

    displayScore(&player);
    return 0;
}