//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 20

typedef struct {
    char name[50];
    int position;
    int score;
} Player;

void initializePlayers(Player players[], int playerCount);
void printBoard(Player players[], int playerCount);
void rollDice(Player *player);
void movePlayer(Player *player);
void updateScore(Player *player);
void announceWinner(Player players[], int playerCount);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Creative Table Game!\n");
    printf("Please enter the number of players (2 to 4): ");
    scanf("%d", &playerCount);

    while (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players! Please choose between 2 and 4: ");
        scanf("%d", &playerCount);
    }

    initializePlayers(players, playerCount);

    int gameRunning = 1;
    while (gameRunning) {
        for (int i = 0; i < playerCount; i++) {
            printf("\n%s's turn:\n", players[i].name);
            rollDice(&players[i]);
            movePlayer(&players[i]);
            updateScore(&players[i]);
            printBoard(players, playerCount);

            // Check for winner condition
            if (players[i].position >= BOARD_SIZE) {
                gameRunning = 0;
                announceWinner(players, playerCount);
                break;
            }
        }
    }

    return 0;
}

void initializePlayers(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
        players[i].score = 0;
    }
}

void printBoard(Player players[], int playerCount) {
    printf("\nCurrent Board Status:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s is at position %d with a score of %d\n", players[i].name, players[i].position, players[i].score);
    }
    printf("\n");
}

void rollDice(Player *player) {
    int roll = rand() % 6 + 1;  // Roll a die (1-6)
    printf("%s rolled a %d!\n", player->name, roll);
}

void movePlayer(Player *player) {
    player->position += rand() % 6 + 1; // Move the player based on the die roll
    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE; // Do not exceed the board
    }
}

void updateScore(Player *player) {
    player->score += 10; // Increase score by 10 for each turn
}

void announceWinner(Player players[], int playerCount) {
    int winnerIndex = -1;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].position >= BOARD_SIZE) {
            winnerIndex = i;
            break;
        }
    }
    if (winnerIndex != -1) {
        printf("\nCongratulations, %s! You are the winner with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].score);
    }
}