//MISTRAL-7B DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define NUMBERS_COUNT 75

typedef struct {
    int numbers[BOARD_SIZE][BOARD_SIZE];
    int marked[BOARD_SIZE][BOARD_SIZE];
} BingoBoard;

void print_board(const BingoBoard *board) {
    int i, j;

    printf("+------+------+------+------+------+\n");
    for (i = 0; i < BOARD_SIZE; ++i) {
        printf("|");
        for (j = 0; j < BOARD_SIZE; ++j) {
            printf("%2d ", board->numbers[i][j]);
            if (j < BOARD_SIZE - 1)
                printf("|");
        }
        printf("|\n");
        if (i < BOARD_SIZE - 1) {
            printf("+------+------+------+------+------+\n");
        }
    }

    printf("\n");
}

void mark_number(BingoBoard *board, int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        board->marked[x][y] = 1;
    }
}

int check_bingo(const BingoBoard *board) {
    int i, j, bingo = 0;

    for (i = 0; i < BOARD_SIZE && !bingo; ++i) {
        for (j = 0; j < BOARD_SIZE && !bingo; ++j) {
            if (!board->marked[i][j]) {
                bingo = 0;
                break;
            }
            bingo = 1;
        }
        if (bingo)
            break;
    }

    if (bingo)
        return 1;

    for (i = 0; i < BOARD_SIZE && !bingo; ++i) {
        for (j = 0; j < BOARD_SIZE && !bingo; ++j) {
            if (!board->marked[j][i]) {
                bingo = 0;
                break;
            }
        }
        if (bingo)
            break;
    }

    if (bingo)
        return 1;

    for (i = 0; i < BOARD_SIZE; ++i) {
        if (!board->marked[i][i]) {
            bingo = 0;
            break;
        }
        bingo = 1;
    }

    if (bingo)
        return 1;

    for (i = 0; i < BOARD_SIZE; ++i) {
        if (!board->marked[i][BOARD_SIZE - 1 - i]) {
            bingo = 0;
            break;
        }
        bingo = 1;
    }

    if (bingo)
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));

    BingoBoard board;
    int i, j, number;

    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            board.numbers[i][j] = i * BOARD_SIZE + j + 1;
            board.marked[i][j] = 0;
        }
    }

    printf("Your Bingo Board:\n");
    print_board(&board);

    for (i = 0; i < NUMBERS_COUNT; ++i) {
        do {
            number = 1 + rand() % (NUMBERS_COUNT - i);
        } while (board.marked[number / BOARD_SIZE][number % BOARD_SIZE]);

        mark_number(&board, number / BOARD_SIZE, number % BOARD_SIZE);

        if (check_bingo(&board)) {
            printf("\nCongratulations! You've won the game!\n");
            break;
        }

        printf("Number %d called. Your board now looks like this:\n", number);
        print_board(&board);
    }

    return 0;
}