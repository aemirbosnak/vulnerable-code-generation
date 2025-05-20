//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define PLAYER_COUNT 2
#define MAX_TURNS 50

typedef struct {
    char name[30];
    int position;
} Player;

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE], Player players[PLAYER_COUNT]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char cell = board[i][j];
            // Setting player's position to their initials
            for (int p = 0; p < PLAYER_COUNT; p++) {
                if (players[p].position == (i * BOARD_SIZE + j)) {
                    cell = (p == 0) ? 'A' : 'B';
                }
            }
            printf("%c ", cell);
        }
        printf("\n");
    }
}

void movePlayer(Player* player) {
    int roll = rand() % 6 + 1;
    printf("%s rolled a %d\n", player->name, roll);
    player->position += roll;
    if (player->position >= BOARD_SIZE * BOARD_SIZE) {
        player->position = BOARD_SIZE * BOARD_SIZE - 1; // Bounce back within bounds
    }
}

int checkForWin(Player players[PLAYER_COUNT]) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (players[i].position >= (BOARD_SIZE * BOARD_SIZE - 1)) {
            return i; // Return winning player's index
        }
    }
    return -1; // No winner yet
}

int main() {
    srand(time(NULL));
    
    char board[BOARD_SIZE][BOARD_SIZE];
    Player players[PLAYER_COUNT];

    // Get player names
    for (int i = 0; i < PLAYER_COUNT; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0; // Start positions
    }

    initializeBoard(board);
    
    int turn = 0;
    int winner = -1;

    while (turn < MAX_TURNS && winner == -1) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            printf("\n--- %s's Turn ---\n", players[i].name);
            movePlayer(&players[i]);
            printBoard(board, players);
            winner = checkForWin(players);
            if (winner != -1) break; // Exit if there's a winner
        }
        turn++;
    }

    if (winner != -1) {
        printf("\nCongratulations %s! You are the winner!\n", players[winner].name);
    } else {
        printf("\nGame over! Maximum turns reached without a winner.\n");
    }

    return 0;
}