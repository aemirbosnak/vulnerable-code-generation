//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define EMPTY ' '

void print_board(char board[SIZE][SIZE]) {
    printf("\n-----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("| ");
        for (int j = 0; j < SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-----------------\n");
    }
}

int check_win(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int check_draw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0; // Game is still ongoing
            }
        }
    }
    return 1; // It's a draw
}

void player_move(char board[SIZE][SIZE], char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void ai_move(char board[SIZE][SIZE]) {
    srand(time(NULL));
    int row, col;
    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (board[row][col] == EMPTY) {
            board[row][col] = 'O'; // AI player is 'O'
            printf("AI chose position (%d, %d)\n", row, col);
            break;
        }
    }
}

int main() {
    char board[SIZE][SIZE] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };
    char current_player = 'X';

    printf("Welcome to the Artistic Tic-Tac-Toe!\n");
    printf("Player 'X' vs AI 'O'\n");
    print_board(board);

    while (1) {
        player_move(board, current_player);
        print_board(board);
        if (check_win(board, current_player)) {
            printf("Congratulations! Player %c wins!\n", current_player);
            break;
        }
        if (check_draw(board)) {
            printf("It's a draw!\n");
            break;
        }

        // AI's turn
        ai_move(board);
        print_board(board);
        if (check_win(board, 'O')) {
            printf("AI wins! Better luck next time, Player X!\n");
            break;
        }
        if (check_draw(board)) {
            printf("It's a draw!\n");
            break;
        }
    }

    printf("Thanks for playing Artistic Tic-Tac-Toe!\n");
    return 0;
}