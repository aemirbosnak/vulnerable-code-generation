//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    char piece;
    char color;
    int x;
    int y;
} Piece;

void init_board(Piece board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j].piece = '-';
            board[i][j].color = '-';
            board[i][j].x = -1;
            board[i][j].y = -1;
        }
    }
}

void print_board(Piece board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j].piece);
        }
        printf("\n");
    }
}

int is_valid_move(Piece board[SIZE][SIZE], int from_x, int from_y, int to_x, int to_y, char piece_color) {
    int dx = to_x - from_x;
    int dy = to_y - from_y;

    if (dx == 0 && dy == 0)
        return 0;

    if (dx == 0 && piece_color == 'b')
        return 1;

    if (dy == 0 && piece_color == 'w')
        return 1;

    if (dx == 1 && dy == 1)
        return 1;

    if (dx == -1 && dy == -1)
        return 1;

    return 0;
}

int main() {
    Piece board[SIZE][SIZE];
    init_board(board);

    int x, y;
    char piece;
    char color;

    while (1) {
        printf("Enter the piece, color and position: ");
        scanf("%c %c %d %d", &piece, &color, &x, &y);

        if (board[x][y].piece!= '-') {
            printf("Invalid move!\n");
            continue;
        }

        board[x][y].piece = piece;
        board[x][y].color = color;
        board[x][y].x = x;
        board[x][y].y = y;

        print_board(board);
    }

    return 0;
}