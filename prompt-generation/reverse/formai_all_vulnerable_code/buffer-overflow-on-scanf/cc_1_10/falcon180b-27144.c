//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_CARDS (SIZE * SIZE)

enum {
    EMPTY = 0,
    COVERED = 1,
    FLAGGED = 2,
    MINE = 3
};

int board[SIZE][SIZE];
int card_count = 0;

void init_board() {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    for (i = 0; i < NUM_CARDS; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (board[x][y] == EMPTY) {
            board[x][y] = COVERED;
            card_count++;
        }
    }
}

void draw_board() {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case COVERED:
                    printf("X");
                    break;
                case FLAGGED:
                    printf("F");
                    break;
                case MINE:
                    printf("*");
                    break;
            }
        }
        printf("\n");
    }
}

int reveal_card(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        return 0;
    }

    switch (board[x][y]) {
        case EMPTY:
            return 0;
        case COVERED:
            board[x][y] = EMPTY;
            return 1;
        case FLAGGED:
            board[x][y] = EMPTY;
            return 2;
        case MINE:
            board[x][y] = EMPTY;
            return 3;
    }
}

int check_win() {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == COVERED) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    init_board();
    int moves = 0;
    int score = 0;

    while (card_count > 0) {
        draw_board();
        printf("Moves: %d  Score: %d\n", moves, score);

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int x = (choice / SIZE) * SIZE;
        int y = choice % SIZE;

        if (reveal_card(x, y)) {
            if (board[x][y] == MINE) {
                printf("You hit a mine! Game over.\n");
                break;
            } else if (++moves == NUM_CARDS) {
                printf("Congratulations! You won.\n");
                break;
            }
        } else {
            printf("You flagged a card.\n");
        }
    }

    return 0;
}