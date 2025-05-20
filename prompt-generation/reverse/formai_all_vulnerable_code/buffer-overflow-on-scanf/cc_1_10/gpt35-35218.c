//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the board
#define ROWS 3
#define COLS 3

// Define the players
#define PLAYER1 'X'
#define PLAYER2 'O'

// Function prototypes
void print_board(char board[ROWS][COLS]);
int is_valid_move(char board[ROWS][COLS], int row, int col);
int has_won(char board[ROWS][COLS], char player);
void computer_move(char board[ROWS][COLS], char player);
int get_random_number(int min, int max);

int main() {
    // Declare variables
    char board[ROWS][COLS] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int turn;
    char player;
    int row, col;

    // Seed the random number generator
    srand(time(NULL));

    // Decide who goes first
    turn = get_random_number(1, 2);
    if (turn == 1) {
        player = PLAYER1;
    } else {
        player = PLAYER2;
    }

    // Game loop
    while (1) {
        // Print the board
        print_board(board);

        // Prompt the player for their move
        printf("Player %c, enter your move (row column): ", player);
        scanf("%d %d", &row, &col);

        // Validate the move
        if (!is_valid_move(board, row, col)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = player;

        // Check if the player has won
        if (has_won(board, player)) {
            printf("Player %c has won!\n", player);
            print_board(board);
            break;
        }

        // Check if the board is full
        if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
            board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
            board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
            printf("Draw!\n");
            print_board(board);
            break;
        }

        // Switch to the other player
        if (player == PLAYER1) {
            player = PLAYER2;
        } else {
            player = PLAYER1;
        }
    }

    return 0;
}

// Function to print the board
void print_board(char board[ROWS][COLS]) {
    printf("   0 1 2\n");
    printf("  +------+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d |", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
    printf("  +------+\n");
}

// Function to check if a move is valid
int is_valid_move(char board[ROWS][COLS], int row, int col) {
    if (row < 0 || row > ROWS - 1 || col < 0 || col > COLS - 1) {
        return 0;
    }
    if (board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

// Function to check if a player has won
int has_won(char board[ROWS][COLS], char player) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
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

// Function for the computer move
void computer_move(char board[ROWS][COLS], char player) {
    // Try to win
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (has_won(board, player)) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Try to block
    if (player == PLAYER1) {
        player = PLAYER2;
    } else {
        player = PLAYER1;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (has_won(board, player)) {
                    board[i][j] = PLAYER2;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Choose a random move
    while (1) {
        int row = get_random_number(0, ROWS - 1);
        int col = get_random_number(0, COLS - 1);
        if (board[row][col] == ' ') {
            board[row][col] = PLAYER2;
            return;
        }
    }
}

// Function to get a random number between min and max
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}