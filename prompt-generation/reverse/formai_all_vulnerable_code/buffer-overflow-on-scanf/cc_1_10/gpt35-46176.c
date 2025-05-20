//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print out the Tic Tac Toe board
void print_board(char board[3][3]) {
    printf("    1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("  +---+---+---+\n");
        printf("%d |", i + 1);
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                printf(" %c |", board[i][j]);
            }
            else {
                printf("   |");
            }
        }
        printf("\n");
    }
    printf("  +---+---+---+\n");
}

// Function to check if a player has won
int check_win(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
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
    // If no win, return 0
    return 0;
}

// Function to check if the game is a tie
int check_tie(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get the move from the player
void player_move(char board[3][3], char player) {
    int row, col;
    printf("Player %c's turn\n", player);
    printf("Enter the row (1-3): ");
    scanf("%d", &row);
    printf("Enter the column (1-3): ");
    scanf("%d", &col);
    // Check if move is valid
    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O') {
        printf("Invalid move. Please try again.\n");
        printf("Enter the row (1-3): ");
        scanf("%d", &row);
        printf("Enter the column (1-3): ");
        scanf("%d", &col);
    }
    board[row - 1][col - 1] = player;
}

// Function to get the move from the AI player
void ai_move(char board[3][3], char player) {
    int row, col;
    // Randomly generate move
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] == 'X' || board[row][col] == 'O');
    board[row][col] = player;
    printf("AI player %c's turn\n", player);
}

// Main function
int main() {
    // Initialize the board
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    // Initialize player as X
    char player = 'X';
    // Initialize game state as unfinished
    int game_state = -1;
    // Initialize random seed
    srand(time(NULL));
    // Loop until game is finished
    while (game_state == -1) {
        print_board(board);
        if (player == 'X') {
            player_move(board, player);
        }
        else {
            ai_move(board, player);
        }
        if (check_win(board, player)) {
            game_state = 1;
            printf("Player %c wins!\n", player);
        }
        if (check_tie(board)) {
            game_state = 0;
            printf("Tie game!\n");
        }
        // Switch player
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }
    print_board(board);
    return 0;
}