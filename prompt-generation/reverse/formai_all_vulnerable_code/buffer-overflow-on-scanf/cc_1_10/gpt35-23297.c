//FormAI DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6
#define MAX_MOVES 40

// Function to print the game board
void print_board(int board[][BOARD_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_move_valid(int board[][BOARD_SIZE], int row, int col, int x, int y) {
    if (x < 0 || y < 0 || x >= row || y >= col || board[x][y] != 0) {
        return 0;
    }
    return 1;
}

// Function to generate a random number between min and max values
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if the game is over
int is_game_over(int board[][BOARD_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE];
    int moves[MAX_MOVES][2];
    int n = 0;

    // Initialize the board with zeros
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Set the starting cell
    int x = rand_num(0, BOARD_SIZE - 1);
    int y = rand_num(0, BOARD_SIZE - 1);
    board[x][y] = 1;

    // Play the game
    while (!is_game_over(board, BOARD_SIZE, BOARD_SIZE)) {
        print_board(board, BOARD_SIZE, BOARD_SIZE);

        // Get the user input
        int new_x, new_y;
        printf("Enter your move (x,y): ");
        scanf("%d,%d", &new_x, &new_y);

        if (is_move_valid(board, BOARD_SIZE, BOARD_SIZE, new_x, new_y)) {
            n++;
            board[new_x][new_y] = n+1;
            moves[n-1][0] = new_x;
            moves[n-1][1] = new_y;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    // Print the moves
    printf("You made %d moves. The moves were:\n", n);
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) ", moves[i][0], moves[i][1]);
    }
    printf("\n");

    // Print the final board
    print_board(board, BOARD_SIZE, BOARD_SIZE);

    return 0;
}