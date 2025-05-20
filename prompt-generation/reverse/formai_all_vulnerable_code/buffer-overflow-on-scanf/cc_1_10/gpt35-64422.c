//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// The board is represented by a 2D array of chars
char board[3][3];

// Function to check if the board is full
int is_board_full() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to display the board
void display_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("---+---+---\n");
        }
    }
}

// Function to check if a player has won
char check_win() {
    int i;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // No winner
    return ' ';
}

// Function to get the move from the user
void get_move(char player) {
    int row, col;
    printf("\nPlayer %c's turn.\n", player);
    printf("Enter row (0-2): ");
    scanf("%d", &row);
    printf("Enter column (0-2): ");
    scanf("%d", &col);
    while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move. Try again!\n");
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);
    }
    board[row][col] = player;
}

// Function to get the AI's move
void get_ai_move(char player) {
    int row, col, i, j;
    printf("\nPlayer %c's turn.\n", player);
    // Check if the AI can win in one move
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (check_win() == player) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check if the player can win in one move
    char opponent = (player == 'X') ? 'O' : 'X';
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = opponent;
                if (check_win() == opponent) {
                    board[i][j] = player;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // If neither the AI nor the player can win in one move, select a random move
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = player;
}

// Main function
int main() {
    int mode, turn_count = 0;
    char winner;

    // Initialize the board
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    // Get game mode from user (0 for player vs player, 1 for player vs AI)
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose game mode: (0) Player vs Player (1) Player vs AI ");
    scanf("%d", &mode);

    // Game loop
    while (1) {
        display_board();
        if (mode == 0) {
            if (turn_count % 2 == 0) {
                get_move('X');
            } else {
                get_move('O');
            }
        } else {
            if (turn_count % 2 == 0) {
                get_move('X');
            } else {
                get_ai_move('O');
            }
        }
        winner = check_win();
        if (winner != ' ' || is_board_full()) {
            display_board();
            if (winner == ' ') {
                printf("It's a tie!\n");
            } else {
                printf("Player %c wins!\n", winner);
            }
            break;
        }
        turn_count++;
    }

    return 0;
}