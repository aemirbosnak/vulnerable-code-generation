//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
#define MAX_PLAYERS 4

typedef struct {
    int id;
    int position;
} Player;

void initializeGame(Player players[], int playerCount);
void displayBoard(int board[], int size);
void playTurn(Player *player, int board[], int size);
int rollDice();
int checkWinner(Player players[], int playerCount);
void printGameStatus(Player players[], int playerCount);

int main() {
    srand(time(NULL));
    
    int playerCount;
    Player players[MAX_PLAYERS];
    
    printf("Welcome to the Epic Dice Board Game!\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &playerCount);
    
    while (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Please enter a valid number of players (2-4): ");
        scanf("%d", &playerCount);
    }
    
    initializeGame(players, playerCount);

    int board[SIZE] = {0, 1, 2, 3, 4, 5};  // Represents the board
    int winner = -1;

    while (winner == -1) {
        for (int i = 0; i < playerCount; i++) {
            playTurn(&players[i], board, SIZE);
            printGameStatus(players, playerCount);
            winner = checkWinner(players, playerCount);
            if (winner != -1) {
                break;  // Stop when a winner is found
            }
        }
    }
    
    printf("Player %d wins the game!\n", winner + 1);
    return 0;
}

void initializeGame(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        players[i].id = i;
        players[i].position = 0;  // Starting position
    }
}

void displayBoard(int board[], int size) {
    printf("Board positions: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", board[i]);
    }
    printf("\n");
}

void playTurn(Player *player, int board[], int size) {
    printf("Player %d's Turn!\n", player->id + 1);
    int diceRoll = rollDice();
    printf("Player %d rolled a %d\n", player->id + 1, diceRoll);
    
    player->position += diceRoll;
    
    if (player->position >= size) {
        player->position = size - 1;  // Don't go past the board
    }
    
    printf("Player %d moves to position %d\n", player->id + 1, player->position);
}

int rollDice() {
    return (rand() % 6) + 1;  // Random number between 1 and 6
}

int checkWinner(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        if (players[i].position >= SIZE - 1) {
            return i;  // Return winner index
        }
    }
    return -1;  // No winner yet
}

void printGameStatus(Player players[], int playerCount) {
    printf("\nCurrent Game Status:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("Player %d is at position %d\n", players[i].id + 1, players[i].position);
    }
    printf("\n");
}