//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the tic-tac-toe board
void print_board(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) {
                printf("|");
            }
        }
        if (i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

// Function to check if any player has won
bool check_win(char board[3][3], char symbol) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }
    return false;
}

// Function to play the game
void play_game(char board[3][3], char player1[20], char player2[20]) {
    bool game_over = false;
    bool player1_turn = true;
    int row, col;
    char player1_icon = 'X';
    char player2_icon = 'O';

    printf("Welcome to the Tic-Tac-Toe game!\n");
    printf("Player 1 (%s) will be \"%c\" and Player 2 (%s) will be \"%c\".\n", player1, player1_icon, player2, player2_icon);
    printf("Here is the initial board:\n");
    print_board(board);

    // Keep playing until there is a winner or the board is full
    while (!game_over) {
        if (player1_turn) {
            printf("%s, it's your turn! Please enter the row (1-3) and column (1-3) where you want to place \"%c\":\n", player1, player1_icon);
        }
        else {
            printf("%s, it's your turn! Please enter the row (1-3) and column (1-3) where you want to place \"%c\":\n", player2, player2_icon);
        }
        scanf("%d %d", &row, &col);

        // Make sure the input is valid
        while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            printf("Invalid input! Please enter the row (1-3) and column (1-3) where you want to place \"%c\":\n", (player1_turn ? player1_icon : player2_icon));
            scanf("%d %d", &row, &col);
        }

        // Update the board with the player's move
        board[row-1][col-1] = (player1_turn ? player1_icon : player2_icon);
        print_board(board);

        // Check if there is a winner or the board is full
        if (check_win(board, (player1_turn ? player1_icon : player2_icon))) {
            if (player1_turn) {
                printf("%s has won the game!", player1);
            }
            else {
                printf("%s has won the game!", player2);
            }
            game_over = true;
        }
        else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
            printf("The game is a tie!");
            game_over = true;
        }

        // Switch to the other player's turn
        player1_turn = !player1_turn;
    }
}

// Main function to start the game
int main() {
    char board[3][3];
    char player1[20];
    char player2[20];

    // Initialize the board with spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Please enter the name of Player 1:\n");
    scanf("%s", player1);
    printf("Please enter the name of Player 2:\n");
    scanf("%s", player2);

    // Play the game
    play_game(board, player1, player2);

    return 0;
}