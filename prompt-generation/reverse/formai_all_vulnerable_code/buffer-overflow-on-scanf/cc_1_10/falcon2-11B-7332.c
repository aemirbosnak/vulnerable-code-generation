//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef enum {RED, BLACK} Color;
typedef struct {
    int x, y;
    Color color;
} Piece;

typedef struct {
    Piece pieces[8][8];
    int width, height;
} Board;

Board* new_board(int width, int height) {
    Board* board = malloc(sizeof(Board));
    board->width = width;
    board->height = height;
    for (int i = 0; i < board->width; i++) {
        for (int j = 0; j < board->height; j++) {
            board->pieces[i][j] = (Piece){.x = i,.y = j,.color = BLACK};
        }
    }
    return board;
}

void print_board(Board* board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            printf("%c%c ", (char)(j + 'A'), (char)(i + '1'));
            if (board->pieces[j][i].color == RED) {
                printf("X");
            } else if (board->pieces[j][i].color == BLACK) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int width, height;
    printf("Enter the width of the board: ");
    scanf("%d", &width);
    printf("Enter the height of the board: ");
    scanf("%d", &height);
    Board* board = new_board(width, height);
    print_board(board);
    free(board);
    return 0;
}