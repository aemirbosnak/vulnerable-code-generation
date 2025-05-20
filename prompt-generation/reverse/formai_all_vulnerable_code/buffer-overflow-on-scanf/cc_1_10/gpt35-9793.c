//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';
int moves = 0;

// Display the Tic Tac Toe board
void display_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Check if a player has won
int check_for_win(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return 1;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return 1;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return 1;
    if (board[2][0] == p && board[1][1] == p && board[0][2] == p)
        return 1;
    return 0;
}

// Check if the game is over
int is_game_over() {
    if (check_for_win(player))
        return 1;
    if (check_for_win(player == 'X' ? 'O' : 'X'))
        return 1;
    if (moves == 9)
        return 1;
    return 0;
}

// Make the AI move
void ai_move() {
    int row, col;

    // Check for winning move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (check_for_win(player)) {
                    printf("AI wins!\n");
                    exit(0);
                }
                board[i][j] = ' ';
            }
        }
    }

    // Check for blocking move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player == 'X' ? 'O' : 'X';
                if (check_for_win(player == 'X' ? 'O' : 'X')) {
                    board[i][j] = player;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Choose random move
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = player;
}

// Main function
int main() {
    printf("Welcome to Tic Tac Toe!\n\n");
    display_board();

    while (!is_game_over()) {
        printf("It's %c's turn.\n", player);

        if (player == 'X') {
            int row, col;
            do {
                printf("Enter row and column: ");
                scanf("%d %d", &row, &col);
            } while (row < 1 || row >3 || col < 1 || col > 3 || board[row-1][col-1] != ' ');

            board[row-1][col-1] = player;
        }
        else {
            ai_move();
            printf("The AI makes a move.\n");
        }

        moves++;
        display_board();
        player = player == 'X' ? 'O' : 'X';
    }

    if (check_for_win('X')) {
        printf("X wins!\n");
    }
    else if (check_for_win('O')) {
        printf("O wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}