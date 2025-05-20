//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define NUM_PAIRS 10

typedef struct {
    int value;
    int revealed;
} Cell;

Cell board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int i, j, pair_index;

    srand(time(NULL));

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % 10 + 1;
            board[i][j].revealed = 0;

            if (i < BOARD_SIZE / 2 && j < BOARD_SIZE / 2) {
                pair_index = rand() % NUM_PAIRS;
                board[i + BOARD_SIZE / 2][j + BOARD_SIZE / 2].value = board[i][j].value;
            }
        }
    }
}

void reveal_cell(int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && !board[x][y].revealed) {
        board[x][y].revealed = 1;
        printf(" %d ", board[x][y].value);
    } else {
        printf("Invalid move!\n");
    }
}

void print_board() {
    int i, j;

    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf(" %d ", board[i][j].value);
            } else {
                printf(" __ ");
            }
        }
        printf("\n");
    }
}

int main() {
    int x, y, revealed_pairs = 0;

    initialize_board();

    while (revealed_pairs < NUM_PAIRS) {
        print_board();
        scanf("%d%d", &x, &y);
        reveal_cell(x, y);

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].value == board[x][y].value && !board[i][j].revealed) {
                    reveal_cell(i, j);
                    revealed_pairs++;
                    break;
                }
            }
        }
    }

    printf("\nCongratulations! You've matched all the pairs.\n");

    return 0;
}