//FormAI DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to print the game board
void printBoard(char board[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
            if (j != COLS - 1)
                printf("|");
        }
        printf("\n");
        if (i != ROWS - 1) {
            for (j = 0; j < COLS; j++)
                printf("---");
            printf("\n");
        }
    }
}

// Function to check if the game is over
int isGameOver(char board[][COLS])
{
    int i, j;
    char rows[ROWS], cols[COLS], diag1[ROWS], diag2[ROWS];

    // Check rows
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            rows[j] = board[i][j];
        if (rows[0] != '-' && rows[0] == rows[1] && rows[1] == rows[2])
            return 1;
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++)
            cols[j] = board[j][i];
        if (cols[0] != '-' && cols[0] == cols[1] && cols[1] == cols[2])
            return 1;
    }

    // Check diagonals
    for (i = 0; i < ROWS; i++) {
        diag1[i] = board[i][i];
        diag2[i] = board[i][ROWS - i - 1];
    }
    if (diag1[0] != '-' && diag1[0] == diag1[1] && diag1[1] == diag1[2])
        return 1;
    if (diag2[0] != '-' && diag2[0] == diag2[1] && diag2[1] == diag2[2])
        return 1;

    return 0;
}

int main()
{
    char board[ROWS][COLS] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    int row, col, i, j, count = 0;
    char turn = 'X';

    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the C Table Game!\n");

    // Game loop
    while (!isGameOver(board)) {
        count++;

        // Print board and current turn
        printf("Turn %d: %c's turn\n", count, turn);
        printBoard(board);

        // Player input loop
        while (1) {
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);

            // Check if input is valid
            if (row < 1 || row > 3 || col < 1 || col > 3) {
                printf("Invalid input, please try again.\n");
                continue;
            }
            if (board[row - 1][col - 1] != '-') {
                printf("Spot already taken, please try again.\n");
                continue;
            }

            // Update board and break out of loop
            board[row - 1][col - 1] = turn;
            break;
        }

        // Check if game is over
        if (isGameOver(board))
            break;

        // Switch player turns
        if (turn == 'X')
            turn = 'O';
        else
            turn = 'X';

        // Computer turn
        printf("Computer's turn.\n");
        while (1) {
            row = rand() % 3;
            col = rand() % 3;
            if (board[row][col] == '-') {
                board[row][col] = turn;
                break;
            }
        }

        // Switch player turns
        if (turn == 'X')
            turn = 'O';
        else
            turn = 'X';
    }

    // Print final game board and winner
    printf("Game over!\n");
    printBoard(board);
    if (count % 2 == 0)
        printf("Player X wins!\n");
    else
        printf("Player O wins!\n");

    return 0;
}