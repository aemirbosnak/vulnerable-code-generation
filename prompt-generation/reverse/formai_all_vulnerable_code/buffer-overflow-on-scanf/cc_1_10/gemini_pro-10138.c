//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

int check_winner() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    return ' ';
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int turn = 0;
    int winner = ' ';
    int ai_move_row, ai_move_col;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Game loop
    while (winner == ' ' && turn < 9) {
        // Get player move
        int player_move_row, player_move_col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &player_move_row, &player_move_col);

        // Check if player move is valid
        while (board[player_move_row][player_move_col] != ' ') {
            printf("Invalid move. Try again: ");
            scanf("%d %d", &player_move_row, &player_move_col);
        }

        // Place player move
        board[player_move_row][player_move_col] = 'X';

        // Check for winner
        winner = check_winner();

        // Get AI move
        if (winner == ' ') {
            // Generate random AI move
            srand(time(NULL));
            ai_move_row = rand() % BOARD_SIZE;
            ai_move_col = rand() % BOARD_SIZE;

            // Check if AI move is valid
            while (board[ai_move_row][ai_move_col] != ' ') {
                ai_move_row = rand() % BOARD_SIZE;
                ai_move_col = rand() % BOARD_SIZE;
            }

            // Place AI move
            board[ai_move_row][ai_move_col] = 'O';

            // Check for winner
            winner = check_winner();
        }

        // Print the board
        print_board();

        // Increment turn
        turn++;
    }

    // Print game result
    if (winner == 'X') {
        printf("You win!\n");
    } else if (winner == 'O') {
        printf("AI wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}