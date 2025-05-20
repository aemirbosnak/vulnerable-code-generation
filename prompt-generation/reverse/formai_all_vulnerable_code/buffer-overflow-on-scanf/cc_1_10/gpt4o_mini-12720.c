//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURES 3

char board[SIZE][SIZE];
int treasures[TREASURES][2];
int foundTreasures[2] = {0, 0}; // Found treasures for player 1 and player 2

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void placeTreasures() {
    srand(time(NULL));
    for (int i = 0; i < TREASURES; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (board[x][y] != '.'); // Keep searching until an empty spot is found
        board[x][y] = 'T';
        treasures[i][0] = x;
        treasures[i][1] = y;
    }
}

void displayBoard() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int makeMove(int player) {
    int x, y;
    printf("Player %d, enter your move (row and column): ", player + 1);
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        printf("Invalid move! Try again.\n");
        return 0; // Move invalid
    }

    if (board[x][y] == 'T') {
        foundTreasures[player]++;
        board[x][y] = 'F'; // Mark found
        printf("Player %d found a treasure!\n", player + 1);
        return 1; // Found a treasure
    } else if (board[x][y] == '.') {
        printf("No treasure at this position. Keep looking!\n");
        board[x][y] = 'X'; // Mark checked
        return 0; // Did not find a treasure
    } else {
        printf("You have already checked this position!\n");
        return -1; // Position already checked
    }
}

int main() {
    initializeBoard();
    placeTreasures();

    int player = 0;
    while (foundTreasures[0] < TREASURES && foundTreasures[1] < TREASURES) {
        displayBoard();
        int result = makeMove(player);
        
        if (result != -1) { // Only switch players if move was valid or found treasure
            player = 1 - player; // Switch player
        }
    }

    // Determine and display the winner
    if (foundTreasures[0] == TREASURES)
        printf("Player 1 wins with %d treasures found!\n", foundTreasures[0]);
    else
        printf("Player 2 wins with %d treasures found!\n", foundTreasures[1]);

    return 0;
}