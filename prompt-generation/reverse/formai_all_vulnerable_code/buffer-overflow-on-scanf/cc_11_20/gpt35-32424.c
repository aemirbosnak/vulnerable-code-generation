//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic Tac Toe board

// Function to display the board
void display_board() {
    printf("\n\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}

// Function to check if someone has won the game
char check_win() {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
            return board[0][j];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];

    return ' '; // Game is still ongoing
}

// Function to check if there is a possible win for the given player
int check_possible_win(char player) {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == ' ')
            return i*10+2;

        if (board[i][1] == player && board[i][2] == player && board[i][0] == ' ')
            return i*10+0;

        if (board[i][0] == player && board[i][2] == player && board[i][1] == ' ')
            return i*10+1;
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == ' ')
            return 2*10+j;

        if (board[1][j] == player && board[2][j] == player && board[0][j] == ' ')
            return 0*10+j;

        if (board[0][j] == player && board[2][j] == player && board[1][j] == ' ')
            return 1*10+j;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == ' ')
        return 22;

    if (board[1][1] == player && board[2][2] == player && board[0][0] == ' ')
        return 00;

    if (board[0][0] == player && board[2][2] == player && board[1][1] == ' ')
        return 11;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == ' ')
        return 20;

    if (board[1][1] == player && board[2][0] == player && board[0][2] == ' ')
        return 02;

    if (board[0][2] == player && board[2][0] == player && board[1][1] == ' ')
        return 11;

    return -1; // No possible win
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");

    // Initialize board
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    // Print board
    display_board();

    // Randomly choose if user or computer goes first
    srand(time(NULL));
    int turn = rand() % 2;

    while (1) {
        if (turn == 0) {
            printf("Your turn! Enter the row and column numbers (e.g. '1 1' is the top-left corner): ");
            int row, col;
            scanf("%d %d", &row, &col);

            // Check if input is valid
            if (row < 1 || row > 3 || col < 1 || col > 3) {
                printf("Invalid input! Try again.\n");
                continue;
            }

            // Check if cell is already occupied
            if (board[row-1][col-1] != ' ') {
                printf("That cell is already occupied! Try again.\n");
                continue;
            }

            board[row-1][col-1] = 'X';

            // Print board
            display_board();

            // Check if game is over
            char winner = check_win();
            if (winner != ' ') {
                printf("%c wins!\n", winner);
                break;
            }

            turn = 1; // Computer's turn
        } else {
            printf("Computer's turn.\n");

            // Check if computer can win
            int possible_win = check_possible_win('O');
            if (possible_win != -1) {
                int row = possible_win / 10;
                int col = possible_win % 10;
                board[row][col] = 'O';
            } else {
                // Check if user can win
                possible_win = check_possible_win('X');
                if (possible_win != -1) {
                    int row = possible_win / 10;
                    int col = possible_win % 10;
                    board[row][col] = 'O';
                } else {
                    // Choose a random empty cell
                    while (1) {
                        int rand_row = rand() % 3;
                        int rand_col = rand() % 3;
                        if (board[rand_row][rand_col] == ' ') {
                            board[rand_row][rand_col] = 'O';
                            break;
                        }
                    }
                }
            }

            // Print board
            display_board();

            // Check if game is over
            char winner = check_win();
            if (winner != ' ') {
                printf("%c wins!\n", winner);
                break;
            }

            turn = 0; // User's turn
        }
    }

    return 0;
}