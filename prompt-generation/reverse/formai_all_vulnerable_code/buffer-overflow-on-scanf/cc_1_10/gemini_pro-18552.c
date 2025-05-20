//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 100
#define PAIR_FOUND 0
#define MISMATCH -1
#define GAME_OVER 1

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int value;
    int revealed;
} Tile;

Tile board[BOARD_SIZE][BOARD_SIZE];
int moves;
int pairs_found;

void init_board() {
    int values[BOARD_SIZE * BOARD_SIZE / 2];
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        values[i] = i + 1;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
            board[i][j].value = values[index];
            board[i][j].revealed = 0;
            values[index] = values[BOARD_SIZE * BOARD_SIZE / 2 - 1];
            BOARD_SIZE * BOARD_SIZE / 2 - 1;
        }
    }
}

void print_board() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%d ", board[i][j].value);
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

int get_input() {
    int row, col;
    printf("Enter row and column (1-4): ");
    scanf("%d %d", &row, &col);
    return row * BOARD_SIZE + col - 1;
}

int check_pair(int pos1, int pos2) {
    int row1 = pos1 / BOARD_SIZE;
    int col1 = pos1 % BOARD_SIZE;
    int row2 = pos2 / BOARD_SIZE;
    int col2 = pos2 % BOARD_SIZE;

    if (board[row1][col1].value == board[row2][col2].value) {
        return PAIR_FOUND;
    } else {
        return MISMATCH;
    }
}

void reveal_tile(int pos) {
    int row = pos / BOARD_SIZE;
    int col = pos % BOARD_SIZE;
    board[row][col].revealed = 1;
}

int check_game_over() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    init_board();

    while (moves < MAX_MOVES && !check_game_over()) {
        print_board();

        int pos1 = get_input();
        reveal_tile(pos1);

        int pos2 = get_input();
        reveal_tile(pos2);

        int result = check_pair(pos1, pos2);
        if (result == PAIR_FOUND) {
            pairs_found++;
            printf("Pair found!\n");
        } else if (result == MISMATCH) {
            printf("Mismatch!\n");
        }

        moves++;
    }

    if (check_game_over()) {
        printf("Congratulations! You found all the pairs in %d moves.\n", moves);
    } else {
        printf("Game over! You ran out of moves.\n");
    }

    return 0;
}