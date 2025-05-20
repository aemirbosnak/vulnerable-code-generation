//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
// C Tic Tac Toe AI
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';
char ai = 'O';

// Functions
void print_board();
int get_user_input(int row, int col);
int check_win(char player);
int check_tie();
int ai_move();

int main() {
    // Print the initial board
    print_board();

    // Game loop
    while (1) {
        // Get user input
        int row, col;
        do {
            printf("Enter the row and column: ");
            scanf("%d %d", &row, &col);
        } while (get_user_input(row, col) == 0);

        // Check if the game is over
        if (check_win(player) == 1) {
            printf("You won!\n");
            break;
        } else if (check_tie() == 1) {
            printf("It's a tie!\n");
            break;
        }

        // AI move
        ai_move();

        // Check if the game is over
        if (check_win(ai) == 1) {
            printf("You lost!\n");
            break;
        } else if (check_tie() == 1) {
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}

// Function definitions

void print_board() {
    printf("\n  1 | 2 | 3\n");
    printf("  ----------\n");
    printf("  4 | 5 | 6\n");
    printf("  ----------\n");
    printf("  7 | 8 | 9\n");
    printf("\n");
}

int get_user_input(int row, int col) {
    if (row < 1 || row > 3 || col < 1 || col > 3) {
        printf("Invalid input. Please enter a valid row and column.\n");
        return 0;
    }

    if (board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O') {
        printf("This space is already occupied. Please choose another space.\n");
        return 0;
    }

    board[row - 1][col - 1] = player;
    print_board();

    return 1;
}

int check_win(char player) {
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

int check_tie() {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                count++;
            }
        }
    }

    if (count == 9) {
        return 1;
    }

    return 0;
}

int ai_move() {
    srand(time(NULL));
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] == 'X' || board[row][col] == 'O');

    board[row][col] = ai;
    print_board();

    return 1;
}