//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // Tic Tac Toe board

void display_board() {
    // Draw the Tic Tac Toe board
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// Check if the game is over
int game_over() {
    // Check for rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check for columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check for diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Check if the board is full
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        return 2;
    }

    return 0;
}

// Get a random move for the AI
void get_ai_move(int *row, int *col) {
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (board[*row][*col] != ' ');
}

int main() {
    int row, col; // Coordinates for player's move
    int turn = 1; // 1 for player, 2 for AI

    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to Tic Tac Toe!\n");
    display_board();

    while (1) {
        if (turn == 1) {
            // Player's turn
            printf("Enter row and column (1-3): ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (board[row][col] == ' ') {
                board[row][col] = 'X';
                turn = 2;
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            // AI's turn
            printf("AI's turn...\n");
            get_ai_move(&row, &col);
            board[row][col] = 'O';
            turn = 1;
        }

        display_board();

        int result = game_over();
        if (result == 1) {
            printf("Game over. ");
            if (turn == 1) {
                printf("Player wins!\n");
            } else {
                printf("AI wins!\n");
            }
            break;
        } else if (result == 2) {
            printf("Game over. It's a tie!\n");
            break;
        }
    }

    return 0;
}