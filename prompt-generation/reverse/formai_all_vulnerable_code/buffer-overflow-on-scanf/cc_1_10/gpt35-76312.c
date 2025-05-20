//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>

#define BOARD_SIZE 3

// Function to print the game board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("-------------\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|\n-------------\n");
    }
}

// Function to check if the game is over
int check_game_over(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        int count = 0;
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == symbol) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        int count = 0;
        for (int row = 0; row < BOARD_SIZE; row++) {
            if (board[row][col] == symbol) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == symbol) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - i - 1] == symbol) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return 1;
    }

    // Check if the board is full
    int is_full = 1;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == '-') {
                is_full = 0;
            }
        }
    }
    if (is_full) {
        return 2;
    }

    return 0;
}

// Function to get player move
void get_move(int *row, int *col) {
    printf("Enter row (0-2): ");
    scanf("%d", row);
    printf("Enter column (0-2): ");
    scanf("%d", col);
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col;
    char player1 = 'X';
    char player2 = 'O';
    char current_player = player1;

    // Initialize board to all '-'
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = '-';
        }
    }

    // Loop until the game is over
    while (1) {
        printf("Current player: %c\n", current_player);
        print_board(board);
        get_move(&row, &col);

        // Check if the move is valid
        if (board[row][col] == '-') {
            board[row][col] = current_player;
        } else {
            printf("Invalid move!\n");
            continue;
        }

        // Check if the game is over
        int game_over = check_game_over(board, current_player);
        if (game_over == 1) {
            printf("Player %c wins!\n", current_player);
            print_board(board);
            break;
        } else if (game_over == 2) {
            printf("Tie game!\n");
            print_board(board);
            break;
        }

        // Switch to the next player
        if (current_player == player1) {
            current_player = player2;
        } else {
            current_player = player1;
        }
    }

    return 0;
}