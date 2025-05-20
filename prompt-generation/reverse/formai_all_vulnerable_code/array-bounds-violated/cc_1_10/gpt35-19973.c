//FormAI DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the size of the board
#define ROWS 3
#define COLS 3

// Define player and computer moves
#define PLAYER_MOVE 'X'
#define COMP_MOVE 'O'

// Initialize the board with empty spaces
char board[ROWS][COLS] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Used to seed the random number generator
void randomSeed()
{
    srand(time(NULL));
}

// Get a random number between min and max (inclusive)
int getRandomNum(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Print the current state of the board
void printBoard()
{
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("\t %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != ROWS - 1) {
            printf("\t---|---|---\n");
        }
    }
    printf("\n");
}

// Check to see if the game is over
bool isGameOver()
{
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')) {
        return true;
    }

    // Check for a draw
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    
    return true;
}

// Get the player's move
void getPlayerMove(int *row, int *col)
{
    printf("Enter row number (1-3): ");
    scanf("%d", row);
    printf("Enter column number (1-3): ");
    scanf("%d", col);

    // Subtract 1 to adjust for 0-based indexing
    *row -= 1;
    *col -= 1;
}

// Make the computer's move
void makeCompMove()
{
    int row, col;

    do {
        row = getRandomNum(0, ROWS - 1);
        col = getRandomNum(0, COLS - 1);
    } while (board[row][col] != ' ');

    board[row][col] = COMP_MOVE;
}

int main()
{
    randomSeed();
    printf("Welcome to Tic Tac Toe!\n");

    printBoard();

    while (!isGameOver()) {
        int row, col;
        getPlayerMove(&row, &col);

        while (board[row][col] != ' ') {
            printf("That spot is already taken, please choose another.\n");
            getPlayerMove(&row, &col);
        }

        board[row][col] = PLAYER_MOVE;

        printBoard();

        if (isGameOver()) {
            break;
        }

        printf("Computer is making its move...\n");
        makeCompMove();

        printBoard();
    }

    if (isGameOver()) {
        printf("Game over!\n");
    }

    return 0;
}