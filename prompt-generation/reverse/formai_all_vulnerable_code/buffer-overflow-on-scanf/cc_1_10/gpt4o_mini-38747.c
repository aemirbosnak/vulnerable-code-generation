//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE_CNT 3

void initBoard(char board[SIZE][SIZE]);
void placeTreasure(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int makeMove(char board[SIZE][SIZE], int row, int col);
int checkWin(int treasuresFound);

int main() {
    char board[SIZE][SIZE];
    int playerTurn = 0;
    int treasuresFound[2] = {0, 0};
    int row, col;

    srand(time(0));
    initBoard(board);
    placeTreasure(board);

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Two players will take turns to find treasures on a %dx%d board.\n", SIZE, SIZE);

    while (treasuresFound[0] + treasuresFound[1] < TREASURE_CNT) {
        printf("\nPlayer %d's turn!\n", playerTurn + 1);
        printBoard(board);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);

        if (makeMove(board, row, col) == 1) {
            treasuresFound[playerTurn]++;
            printf("Congrats! Player %d found a treasure!\n", playerTurn + 1);
        }
        playerTurn = 1 - playerTurn; // Switch player
    }

    printf("\nGame Over!\n");
    printf("Player 1 found %d treasures.\n", treasuresFound[0]);
    printf("Player 2 found %d treasures.\n", treasuresFound[1]);

    if (treasuresFound[0] > treasuresFound[1]) {
        printf("Player 1 wins!\n");
    } else if (treasuresFound[1] > treasuresFound[0]) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void placeTreasure(char board[SIZE][SIZE]) {
    int count = 0;
    while (count < TREASURE_CNT) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (board[r][c] != 'T') {
            board[r][c] = 'T';
            count++;
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int makeMove(char board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        printf("Invalid move! Please choose a position within the board.\n");
        return 0;
    }

    if (board[row][col] == 'T') {
        board[row][col] = 'F'; // Mark treasure found
        return 1; // Treasure found
    } else if (board[row][col] == '.') {
        board[row][col] = '*'; // Mark empty space visited
        printf("No treasure at this location.\n");
        return 0;
    } else {
        printf("You've already visited this cell!\n");
        return 0;
    }
}