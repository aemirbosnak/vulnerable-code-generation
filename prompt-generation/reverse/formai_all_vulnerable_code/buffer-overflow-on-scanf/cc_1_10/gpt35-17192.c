//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROWS 3
#define COLS 3
#define PLAYER1 'X'
#define PLAYER2 'O'
#define BLANK ' '

// Function prototypes
void display_board(char board[ROWS][COLS]);
int player_move(char board[ROWS][COLS], char player_char);
int check_winner(char board[ROWS][COLS]);

int main()
{
    // Initialize the board with blank spaces
    char board[ROWS][COLS] = {{BLANK, BLANK, BLANK},
                              {BLANK, BLANK, BLANK},
                              {BLANK, BLANK, BLANK}};

    // Initialize variables
    int turn = 0;
    char current_player = PLAYER1;
    int winner;

    // Seed the random number generator for generating random moves for the computer player
    srand(time(NULL));

    // Display the initial board
    display_board(board);

    do {
        // Increment the turn counter
        turn++;

        if (current_player == PLAYER1) {
            printf("Player 1's turn:\n");
        } else {
            printf("Player 2's turn:\n");
        }

        // Get the player's move
        if (current_player == PLAYER2) {
            // Computer player's turn
            printf("Computer player is thinking...\n");
            usleep(2000000); // Pause for 2 seconds to simulate thinking time
            player_move(board, current_player);
        } else {
            // Human player's turn
            player_move(board, current_player);
        }

        // Display the updated board
        display_board(board);

        // Check for a winner
        winner = check_winner(board);

        // Switch to the other player
        if (current_player == PLAYER1) {
            current_player = PLAYER2;
        } else {
            current_player = PLAYER1;
        }

        // Check for a tie game
        if (turn == ROWS * COLS && winner == 0) {
            printf("Tie game!\n");
        }

    } while (winner == 0 && turn < ROWS * COLS);

    // Display the winner
    if (winner == PLAYER1) {
        printf("Player 1 wins!\n");
    } else if (winner == PLAYER2) {
        printf("Player 2 wins!\n");
    }

    return 0;
}

void display_board(char board[ROWS][COLS])
{
    printf("    1   2   3\n");
    printf("  +-----------+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < COLS; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  +-----------+\n");
    }
}

int player_move(char board[ROWS][COLS], char player_char)
{
    int row, col;

    printf("Enter row and column (e.g. 2 3): ");
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 1 || row > ROWS || col < 1 || col > COLS || board[row-1][col-1] != BLANK) {
        printf("Invalid move, try again.\n");
        return 0;
    } else {
        board[row-1][col-1] = player_char;
        return 1;
    }
}

int check_winner(char board[ROWS][COLS])
{
    // Check rows for a win
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] != BLANK && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns for a win
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] != BLANK && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals for a win
    if (board[0][0] != BLANK && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != BLANK && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }

    // If no winner is found, return 0
    return 0;
}