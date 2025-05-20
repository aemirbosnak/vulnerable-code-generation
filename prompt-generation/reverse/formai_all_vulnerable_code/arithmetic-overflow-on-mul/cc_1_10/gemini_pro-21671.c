//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

typedef struct {
    int row;
    int col;
} Coord;

typedef struct {
    Coord coord;
    int value;
    int flipped;
} Tile;

Tile board[BOARD_SIZE][BOARD_SIZE];
int flipped_count = 0;
int matched_count = 0;

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].flipped) {
                printf("%d ", board[i][j].value);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int get_input() {
    int row, col;
    printf("Enter the row and column of the tile you want to flip (e.g. 1 2): ");
    scanf("%d %d", &row, &col);
    return row * BOARD_SIZE + col;
}

void flip_tile(int index) {
    int row = index / BOARD_SIZE;
    int col = index % BOARD_SIZE;
    board[row][col].flipped = 1;
}

int check_match(int index1, int index2) {
    int row1 = index1 / BOARD_SIZE;
    int col1 = index1 % BOARD_SIZE;
    int row2 = index2 / BOARD_SIZE;
    int col2 = index2 % BOARD_SIZE;
    return board[row1][col1].value == board[row2][col2].value;
}

int main() {
    srand(time(NULL));

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].coord.row = i;
            board[i][j].coord.col = j;
            board[i][j].flipped = 0;
        }
    }

    // Place the pairs on the board
    int values[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        values[i] = i + 1;
    }
    for (int i = 0; i < NUM_PAIRS; i++) {
        int index1 = rand() % (BOARD_SIZE * BOARD_SIZE);
        int index2 = rand() % (BOARD_SIZE * BOARD_SIZE);
        while (index1 == index2) {
            index2 = rand() % (BOARD_SIZE * BOARD_SIZE);
        }
        board[index1 / BOARD_SIZE][index1 % BOARD_SIZE].value = values[i];
        board[index2 / BOARD_SIZE][index2 % BOARD_SIZE].value = values[i];
    }

    // Game loop
    while (matched_count < NUM_PAIRS) {
        print_board();
        int index1 = get_input();
        flip_tile(index1);
        print_board();
        int index2 = get_input();
        flip_tile(index2);
        if (check_match(index1, index2)) {
            matched_count++;
            printf("Match!\n");
        } else {
            printf("No match.\n");
        }
    }

    printf("Congratulations! You won!\n");

    return 0;
}