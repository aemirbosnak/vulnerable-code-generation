//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2
#define EMPTY_CELL 0

// The game board
int board[BOARD_SIZE][BOARD_SIZE];

// Function to print the game board
void print_board() {
    printf("-------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// Function to check if a player has won
int check_win(int player) {
    // Check horizontals
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check verticals
    for (int i = 0; i < BOARD_SIZE; i++) {
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

    // No win found
    return 0;
}

// Function to check if the game is a draw
int check_draw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_CELL) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to make a move for the given player
void make_move(int player) {
    int row, col;
    printf("Enter row and column for player %d (e.g. 1 2): ", player);
    scanf("%d %d", &row, &col);
    row--;
    col--;

    // Check if the cell is empty
    if (board[row][col] != EMPTY_CELL) {
        printf("Cell is already occupied. Try again.\n");
        make_move(player);
    }
    else {
        board[row][col] = player;
    }
}

// The main function
int main() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }

    // Game loop
    while (1) {
        // Print the game board
        print_board();

        // Player X makes a move
        make_move(PLAYER_X);

        // Check if player X has won
        if (check_win(PLAYER_X)) {
            printf("Player X has won!\n");
            print_board();
            break;
        }

        // Check for a draw
        if (check_draw()) {
            printf("It's a draw!\n");
            print_board();
            break;
        }

        // Player O makes a move
        make_move(PLAYER_O);

        // Check if player O has won
        if (check_win(PLAYER_O)) {
            printf("Player O has won!\n");
            print_board();
            break;
        }

        // Check for a draw
        if (check_draw()) {
            printf("It's a draw!\n");
            print_board();
            break;
        }
    }

    return 0;
}