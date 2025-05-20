//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_PLAYERS 4

char board[ROWS][COLS];
int playerPositions[MAX_PLAYERS];

void initializeBoard();
void displayBoard();
void movePlayer(int player, int direction);
int checkWin(int player);
void getPlayerInput(int player);
void takeTurn(int player);

int main() {
    srand(time(0));
    initializeBoard();
    
    for(int i = 0; i < MAX_PLAYERS; i++) {
        playerPositions[i] = 0; // Each player starts at the beginning
    }

    int currentPlayer = 0;
    while(1) {
        displayBoard();
        takeTurn(currentPlayer);
        if (checkWin(currentPlayer)) {
            printf("Player %d wins!\n", currentPlayer + 1);
            break;
        }
        currentPlayer = (currentPlayer + 1) % MAX_PLAYERS;
    }

    return 0;
}

void initializeBoard() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = '-';
}

void displayBoard() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void movePlayer(int player, int direction) {
    int currentPos = playerPositions[player];
    int newPos = currentPos + direction;

    // Ensure the new position is valid
    if (newPos >= 0 && newPos < ROWS * COLS) {
        int currentRow = currentPos / COLS;
        int currentCol = currentPos % COLS;
        board[currentRow][currentCol] = '-'; // Clear current position
        
        int newRow = newPos / COLS;
        int newCol = newPos % COLS;
        board[newRow][newCol] = '1' + player; // Mark new position
        
        playerPositions[player] = newPos; // Update player's position
    }

    printf("Player %d moved to position %d\n", player + 1, newPos);
}

int checkWin(int player) {
    return playerPositions[player] == (ROWS * COLS) - 1;
}

void getPlayerInput(int player) {
    int input;
    printf("Player %d, enter your move amount (1 for right, -1 for left): ", player + 1);
    scanf("%d", &input);
    movePlayer(player, input);
}

void takeTurn(int player) {
    getPlayerInput(player);
}