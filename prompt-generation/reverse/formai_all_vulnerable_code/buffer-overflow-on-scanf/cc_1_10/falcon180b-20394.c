//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the structure for a player
typedef struct {
    char name[50];
    int score;
} Player;

// Define the structure for a game
typedef struct {
    int numPlayers;
    Player players[10];
    int currentPlayer;
} Game;

// Function to initialize the game
void initGame(Game* game) {
    srand(time(NULL));
    game->numPlayers = rand() % 10 + 1; // Random number of players between 1 and 10
    for (int i = 0; i < game->numPlayers; i++) {
        strcpy(game->players[i].name, "Player ");
        game->players[i].score = 0;
    }
    game->currentPlayer = 0;
}

// Function to print the current player's name and score
void printPlayerInfo(Game* game) {
    printf("Current player: %s\n", game->players[game->currentPlayer].name);
    printf("Score: %d\n", game->players[game->currentPlayer].score);
}

// Function to update the current player's score
void updateScore(Game* game) {
    game->players[game->currentPlayer].score++;
}

// Function to rotate to the next player
void rotatePlayer(Game* game) {
    game->currentPlayer = (game->currentPlayer + 1) % game->numPlayers;
}

// Function to start the game
void startGame(Game* game) {
    printf("Welcome to the game!\n");
    printPlayerInfo(game);
    int choice;
    do {
        printf("Enter your choice:\n1. Play\n2. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            updateScore(game);
            printf("Your score has been updated.\n");
            rotatePlayer(game);
            break;
        case 2:
            printf("Exiting game...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 2);
}

// Main function
int main() {
    Game game;
    initGame(&game);
    startGame(&game);
    return 0;
}