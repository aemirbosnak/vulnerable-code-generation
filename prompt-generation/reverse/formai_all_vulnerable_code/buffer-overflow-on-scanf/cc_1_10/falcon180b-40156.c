//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define BLACK 'X'
#define WHITE 'O'

void print_board(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[HEIGHT][WIDTH]) {
    // Check rows
    for (int i = 0; i < HEIGHT; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < WIDTH; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void play_game(char board[HEIGHT][WIDTH]) {
    int player = 1;
    int choice;

    while (1) {
        print_board(board);
        printf("Player %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &choice, &choice);

        if (choice < 0 || choice > 2) {
            printf("Invalid move\n");
            continue;
        }

        int row = (player - 1) / 3;
        int col = (player - 1) % 3;

        if (board[row][col]!= BLACK && board[row][col]!= WHITE) {
            board[row][col] = (player % 2 == 0)? BLACK : WHITE;
            if (check_winner(board)) {
                printf("Player %d wins!\n", player);
                break;
            } else {
                player++;
            }
        } else {
            printf("Invalid move\n");
        }
    }
}

int main() {
    srand(time(0));

    char board[HEIGHT][WIDTH] = {{0}};

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = (rand() % 2 == 0)? BLACK : WHITE;
        }
    }

    play_game(board);

    return 0;
}