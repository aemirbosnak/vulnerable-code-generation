//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3  // Size of the board

void printBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE], char player);
int checkTie(char board[SIZE][SIZE]);
int getValidMove(char board[SIZE][SIZE]);
void updateBoard(char board[SIZE][SIZE], int move, char player);

int main()
{
    char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char players[2] = {'X', 'O'};
    int currentPlayer = 0;
    int move;
    int winner = 0;

    srand(time(0));  // Initialize random number generator

    printf("Welcome to Tic Tac Toe!\n");

    // Game loop
    do {
        printBoard(board);

        // Get valid move from current player
        move = getValidMove(board);
        updateBoard(board, move, players[currentPlayer]);

        // Check for winner
        winner = checkWinner(board, players[currentPlayer]);
        currentPlayer = (currentPlayer + 1) % 2;  // Swap players
    } while (!winner && !checkTie(board));  // Continue until there is a winner or a tie

    printBoard(board);

    if (winner) {
        printf("Congratulations Player %c! You won!\n", players[(currentPlayer + 1) % 2]);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

// Print the current state of the board
void printBoard(char board[SIZE][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if a player has won
int checkWinner(char board[SIZE][SIZE], char player)
{
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Check if the board is full and there is no winner
int checkTie(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }

    return 1;
}

// Get a valid move input from the user
int getValidMove(char board[SIZE][SIZE])
{
    int move;
    int validMove = 0;

    do {
        printf("Player %c's turn. Enter a valid move: ", board[0][0] == 'X' ? 'O' : 'X');
        scanf("%d", &move);

        // Check for valid move
        if (move < 1 || move > 9) {
            printf("Invalid move. Please enter a number between 1 and 9.\n");
        } else {
            int row = (move - 1) / SIZE;
            int col = (move - 1) % SIZE;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                validMove = 1;
            } else {
                printf("Spot already taken. Please choose a different spot.\n");
            }
        }
    } while (!validMove);

    return move;
}

// Update the board with the current player's move
void updateBoard(char board[SIZE][SIZE], int move, char player)
{
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;

    board[row][col] = player;
}