//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ROWS 6
#define NUM_COLS 7
#define NUM_TO_WIN 4

typedef struct {
    char color;
    int x;
    int y;
} piece;

typedef struct {
    piece board[NUM_ROWS][NUM_COLS];
    int num_pieces;
} board;

void print_board(board *b) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("| %c ", b->board[i][j].color);
        }
        printf("|\n");
    }
}

int check_win(board *b, piece *p) {
    int count = 1;

    // Check horizontal
    for (int i = 0; i < NUM_COLS; i++) {
        if (b->board[p->x][i].color == p->color) {
            count++;
        } else {
            count = 1;
        }
        if (count >= NUM_TO_WIN) {
            return 1;
        }
    }

    // Check vertical
    count = 1;
    for (int i = 0; i < NUM_ROWS; i++) {
        if (b->board[i][p->y].color == p->color) {
            count++;
        } else {
            count = 1;
        }
        if (count >= NUM_TO_WIN) {
            return 1;
        }
    }

    // Check diagonal (up-right)
    count = 1;
    int i = p->x;
    int j = p->y;
    while (i >= 0 && j < NUM_COLS) {
        if (b->board[i][j].color == p->color) {
            count++;
        } else {
            count = 1;
        }
        if (count >= NUM_TO_WIN) {
            return 1;
        }
        i--;
        j++;
    }

    // Check diagonal (up-left)
    count = 1;
    i = p->x;
    j = p->y;
    while (i >= 0 && j >= 0) {
        if (b->board[i][j].color == p->color) {
            count++;
        } else {
            count = 1;
        }
        if (count >= NUM_TO_WIN) {
            return 1;
        }
        i--;
        j--;
    }

    return 0;
}

int main() {
    board b;
    memset(&b, 0, sizeof(b));
    srand(time(NULL));

    int turn = 0;
    int winner = 0;
    while (!winner) {
        int column;
        printf("Player %d's turn\n", turn + 1);
        printf("Enter a column (1-7): ");
        scanf("%d", &column);

        // Check if the column is valid
        while (column < 1 || column > NUM_COLS || b.board[0][column - 1].color != 0) {
            printf("Invalid column. Enter a column (1-7): ");
            scanf("%d", &column);
        }

        // Drop the piece into the column
        int row = NUM_ROWS - 1;
        while (b.board[row][column - 1].color != 0) {
            row--;
        }
        b.board[row][column - 1].color = turn + 1;
        b.board[row][column - 1].x = row;
        b.board[row][column - 1].y = column - 1;
        b.num_pieces++;

        // Check if the player has won
        winner = check_win(&b, &b.board[row][column - 1]);

        // Switch turns
        turn = (turn + 1) % 2;

        // Print the board
        print_board(&b);
    }

    printf("Player %d wins!\n", winner + 1);

    return 0;
}