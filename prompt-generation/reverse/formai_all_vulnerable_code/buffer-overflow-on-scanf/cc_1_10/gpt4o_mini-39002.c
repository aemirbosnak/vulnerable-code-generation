//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_SIZE 5
#define MAX_NUMBERS 75
#define MAX_PLAYERS 10

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    bool marked[BOARD_SIZE][BOARD_SIZE];
    int playerID;
    bool hasBingo;
} Player;

void initializeBoard(Player *player) {
    int numCount = 0;
    bool numberInBoard[MAX_NUMBERS] = {false};

    while (numCount < BOARD_SIZE * BOARD_SIZE) {
        int number = rand() % MAX_NUMBERS + 1;
        if (!numberInBoard[number - 1]) {
            player->board[numCount / BOARD_SIZE][numCount % BOARD_SIZE] = number;
            player->marked[numCount / BOARD_SIZE][numCount % BOARD_SIZE] = false;
            numberInBoard[number - 1] = true;
            numCount++;
        }
    }
}

void printBoard(Player *player) {
    printf("Player %d's Board:\n", player->playerID);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (player->marked[i][j]) {
                printf("[ X ] ");
            } else {
                printf("[%2d] ", player->board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void markNumber(Player *player, int number) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (player->board[i][j] == number) {
                player->marked[i][j] = true;
            }
        }
    }
}

bool checkBingo(Player *player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        bool rowComplete = true;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!player->marked[i][j]) {
                rowComplete = false;
                break;
            }
        }
        if (rowComplete) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        bool colComplete = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (!player->marked[i][j]) {
                colComplete = false;
                break;
            }
        }
        if (colComplete) {
            return true;
        }
    }

    // Check diagonals
    bool diag1Complete = true, diag2Complete = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (!player->marked[i][i]) {
            diag1Complete = false;
        }
        if (!player->marked[i][BOARD_SIZE - 1 - i]) {
            diag2Complete = false;
        }
    }
    return diag1Complete || diag2Complete;
}

void playBingo(Player players[], int numPlayers) {
    int round = 0;
    int drawnNumber;
    bool winners[MAX_PLAYERS] = {false};

    while (round < MAX_NUMBERS) {
        drawnNumber = rand() % MAX_NUMBERS + 1;
        printf("Drawn Number: %d\n", drawnNumber);
        for (int i = 0; i < numPlayers; i++) {
            markNumber(&players[i], drawnNumber);
            if (!winners[i] && checkBingo(&players[i])) {
                printf("Player %d has Bingo!\n", players[i].playerID);
                winners[i] = true;
                players[i].hasBingo = true;
            }
        }
        printf("\n");
        round++;
        // Show boards
        for (int i = 0; i < numPlayers; i++) {
            printBoard(&players[i]);
        }
        // Check if all players have Bingo
        bool allWinners = true;
        for (int i = 0; i < numPlayers; i++) {
            if (!players[i].hasBingo) {
                allWinners = false;
                break;
            }
        }
        if (allWinners) {
            printf("All players have won!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    // Ensure valid number of players
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        players[i].playerID = i + 1;
        players[i].hasBingo = false;
        initializeBoard(&players[i]);
    }

    playBingo(players, numPlayers);

    return 0;
}