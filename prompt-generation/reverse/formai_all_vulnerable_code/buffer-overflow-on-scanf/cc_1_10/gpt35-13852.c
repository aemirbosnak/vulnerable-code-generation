//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// function to print the game board
void print_board(char board[][3]) {
    printf("\n   0 1 2\n\n");
    for (int i = 0; i < 3; i++) {
        printf("%d  ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// function to get the user's move
void get_move(char board[][3], char player) {
    int row, col;
    printf("Player %c's turn.\n", player);
    printf("Enter row number: ");
    scanf("%d", &row);
    printf("Enter column number: ");
    scanf("%d", &col);
    while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
        printf("Invalid move. Try again.\n");
        printf("Enter row number: ");
        scanf("%d", &row);
        printf("Enter column number: ");
        scanf("%d", &col);
    }
    board[row][col] = player;
}

// function to check if the game has been won or tied
int check_game_over(char board[][3], char player) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            printf("Player %c wins!\n", player);
            return 1;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            printf("Player %c wins!\n", player);
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        printf("Player %c wins!\n", player);
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        printf("Player %c wins!\n", player);
        return 1;
    }
    // check if board is full
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '-') {
                count++;
            }
        }
    }
    if (count == 9) {
        printf("Tie game.\n");
        return 1;
    }
    return 0;
}

// main function
int main() {
    char board[3][3];
    // initialize board with '-'
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
    char player = 'X';
    int game_over = 0;
    while (!game_over) {
        print_board(board);
        get_move(board, player);
        game_over = check_game_over(board, player);
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }
    return 0;
}