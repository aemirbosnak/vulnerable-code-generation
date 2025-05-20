//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic-Tac-Toe board

// Function to display the Tic-Tac-Toe board
void display_board() {
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// Function to check if the board is full
int is_board_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Function to check if a player has won
int check_win(char c) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return 1;
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == c && board[1][j] == c && board[2][j] == c)
            return 1;
    }
    // Check diagonals
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return 1;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return 1;
    return 0;
}

// Function to get the user's move
void get_user_move(int* row, int* col) {
    printf("Enter row (0-2): ");
    scanf("%d", row);
    printf("Enter column (0-2): ");
    scanf("%d", col);
}

// Function to get the computer's move
void get_computer_move(int* row, int* col) {
    // Generate a random move
    srand(time(NULL));
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (board[*row][*col] != ' ');
    printf("Computer chose row %d, column %d.\n", *row, *col);
}

// Function for the computer to make a move using AI
void make_computer_move(char c) {
    int row, col;
    // Check if the computer can win in one move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = c;
                if (check_win(c)) {
                    printf("Computer chose row %d, column %d.\n", i, j);
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check if the player can win in one move and block them
    if (c == 'X') {
        c = 'O';
    } else {
        c = 'X';
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = c;
                if (check_win(c)) {
                    board[i][j] = 'O';
                    printf("Computer chose row %d, column %d.\n", i, j);
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // If neither can win in one move, make a random move
    get_computer_move(&row, &col);
    board[row][col] = 'O';
}

// Main function
int main() {
    // Initialize board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    printf("Welcome to Tic-Tac-Toe!\n");
    display_board();
    // Game loop
    while (1) {
        // Get user's move
        int row, col;
        get_user_move(&row, &col);
        board[row][col] = 'X';
        display_board();
        if (check_win('X')) {
            printf("You win!\n");
            break;
        }
        if (is_board_full()) {
            printf("Draw!\n");
            break;
        }
        // Computer's move
        printf("Computer's turn:\n");
        make_computer_move('O');
        display_board();
        if (check_win('O')) {
            printf("Computer wins!\n");
            break;
        }
        if (is_board_full()) {
            printf("Draw!\n");
            break;
        }
    }
    return 0;
}