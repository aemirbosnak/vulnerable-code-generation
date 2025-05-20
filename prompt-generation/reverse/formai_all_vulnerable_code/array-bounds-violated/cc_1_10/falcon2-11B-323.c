//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 16
#define WHITE 1
#define BLACK 2
#define UNDEF 0

typedef struct {
    int color;
    char piece[MAX_SIZE];
} Piece;

typedef struct {
    int size;
    Piece board[MAX_SIZE];
} Board;

void printBoard(Board b) {
    printf("Board: \n");
    for (int i = 0; i < b.size; i++) {
        printf(" %c", b.board[i].piece);
    }
    printf("\n");
}

void movePiece(Board *b, char from, char to) {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < b->size; i++) {
        if (strcmp(b->board[i].piece, from) == 0) {
            fromIndex = i;
        }
        if (strcmp(b->board[i].piece, to) == 0) {
            toIndex = i;
        }
    }
    if (fromIndex!= -1 && toIndex!= -1) {
        b->board[fromIndex].color = UNDEF;
        b->board[toIndex].color = b->board[fromIndex].color;
        b->board[fromIndex].piece[0] = '\0';
        b->board[toIndex].piece[0] = from;
    }
}

void makeMove(Board *b, int from, int to) {
    movePiece(b, b->board[from].piece, b->board[to].piece);
}

int main() {
    Board b;
    b.size = 0;
    b.board[0].color = WHITE;
    b.board[0].piece[0] = 'K';
    b.board[1].color = WHITE;
    b.board[1].piece[0] = 'Q';
    b.board[2].color = WHITE;
    b.board[2].piece[0] = 'R';
    b.board[3].color = WHITE;
    b.board[3].piece[0] = 'B';
    b.board[4].color = WHITE;
    b.board[4].piece[0] = 'N';
    b.board[5].color = WHITE;
    b.board[5].piece[0] = 'P';
    b.board[6].color = WHITE;
    b.board[6].piece[0] = 'P';
    b.board[7].color = WHITE;
    b.board[7].piece[0] = 'P';
    b.board[8].color = BLACK;
    b.board[8].piece[0] = 'K';
    b.board[9].color = BLACK;
    b.board[9].piece[0] = 'Q';
    b.board[10].color = BLACK;
    b.board[10].piece[0] = 'R';
    b.board[11].color = BLACK;
    b.board[11].piece[0] = 'B';
    b.board[12].color = BLACK;
    b.board[12].piece[0] = 'N';
    b.board[13].color = BLACK;
    b.board[13].piece[0] = 'P';
    b.board[14].color = BLACK;
    b.board[14].piece[0] = 'P';
    b.board[15].color = BLACK;
    b.board[15].piece[0] = 'P';

    while (1) {
        printf("Current board: \n");
        printBoard(b);
        printf("Choose a move (0-7): ");
        int move;
        scanf("%d", &move);
        if (move == -1) {
            break;
        }
        if (move < 0 || move > 7) {
            printf("Invalid move. Choose again.\n");
            continue;
        }
        int from = move - 1;
        int to = move + 1;
        if (b.board[from].color == WHITE) {
            makeMove(&b, from, to);
            printBoard(b);
        } else {
            makeMove(&b, to, from);
            printBoard(b);
        }
    }

    return 0;
}