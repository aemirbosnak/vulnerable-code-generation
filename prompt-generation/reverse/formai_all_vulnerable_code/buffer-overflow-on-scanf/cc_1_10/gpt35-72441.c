//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // 3x3 game board

void initialize_board() {
    // fill the game board with blank spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    // print the game board
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int check_for_winner() {
    // check if there is a winner
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 1; // X wins
            } else if (board[i][0] == 'O') {
                return 2; // O wins
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') {
                return 1; // X wins
            } else if (board[0][i] == 'O') {
                return 2; // O wins
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 1; // X wins
        } else if (board[0][0] == 'O') {
            return 2; // O wins
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            return 1; // X wins
        } else if (board[0][2] == 'O') {
            return 2; // O wins
        }
    }
    return 0; // no winner yet
}

void player_move(char player) {
    // ask the player to make a move
    int row, col;
    printf("Player %c, enter row (1-3): ", player);
    scanf("%d", &row);
    printf("Player %c, enter col (1-3): ", player);
    scanf("%d", &col);
    row--;
    col--;
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move! Please enter row and col between 1 and 3.\n");
        player_move(player);
    } else if (board[row][col] != ' ') {
        printf("That space is already occupied! Please choose an empty space.\n");
        player_move(player);
    } else {
        board[row][col] = player;
    }
}

void computer_move(char player) {
    // make a move for the computer
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = player;
}

int main() {
    initialize_board();
    print_board();
    char player = 'X';
    while (check_for_winner() == 0) {
        if (player == 'X') {
            player_move(player);
        } else {
            computer_move(player);
        }
        print_board();
        player = (player == 'X') ? 'O' : 'X';
    }
    int winner = check_for_winner();
    if (winner == 1) {
        printf("X wins!\n");
    } else if (winner == 2) {
        printf("O wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}