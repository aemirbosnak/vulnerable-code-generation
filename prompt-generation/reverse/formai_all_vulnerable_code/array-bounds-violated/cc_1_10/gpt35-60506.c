//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>

// Function to display the Tic Tac Toe board
void display_board(char board[][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given player has won
int check_win(char player, char board[][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
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

// Function to get the next move for the given player
void get_next_move(char player, char board[][3], int *row, int *col) {
    // TODO: Implement your AI logic here
    // For now, just choose a random location on the board
    int valid_move = 0;
    while (!valid_move) {
        *row = rand() % 3;
        *col = rand() % 3;
        if (board[*row][*col] == '-') {
            valid_move = 1;
        }
    }
}

int main() {
    // Initialize board
    char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

    // Choose starting player randomly
    char current_player = rand() % 2 == 0 ? 'X' : 'O';

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing as %c\n", current_player);

    // Game loop
    int game_over = 0;
    while (!game_over) {
        // Display board
        display_board(board);

        // Get next move
        int row, col;
        if (current_player == 'X') {
            printf("It's your turn!\n");
            printf("Enter row number (1-3): ");
            scanf("%d", &row);
            row--;
            printf("Enter column number (1-3): ");
            scanf("%d", &col);
            col--;
            while (board[row][col] != '-') {
                printf("Invalid location, try again\n");
                printf("Enter row number (1-3): ");
                scanf("%d", &row);
                row--;
                printf("Enter column number (1-3): ");
                scanf("%d", &col);
                col--;
            }
        } else {
            printf("It's my turn!\n");
            get_next_move(current_player, board, &row, &col);
            printf("I choose row %d, column %d\n", row+1, col+1);
        }

        // Place move on board
        board[row][col] = current_player;

        // Check for win
        if (check_win(current_player, board)) {
            display_board(board);
            printf("%c wins!\n", current_player);
            game_over = 1;
        }

        // Check for tie
        int tie = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    tie = 0;
                    break;
                }
            }
            if (!tie) {
                break;
            }
        }
        if (tie) {
            display_board(board);
            printf("It's a tie!\n");
            game_over = 1;
        }

        // Switch players
        if (current_player == 'X') {
            current_player = 'O';
        } else {
            current_player = 'X';
        }
    }

    return 0;
}