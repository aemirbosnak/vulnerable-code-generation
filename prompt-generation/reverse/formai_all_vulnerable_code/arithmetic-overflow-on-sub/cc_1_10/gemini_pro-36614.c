//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE / 2)

typedef struct {
    int row;
    int col;
} Position;

char board[BOARD_SIZE][BOARD_SIZE];
int matched[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    int i, j, k;
    srand(time(NULL));

    // Fill the board with random numbers
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % NUM_PAIRS + 1;
        }
    }

    // Shuffle the board
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int r = rand() % BOARD_SIZE;
            int c = rand() % BOARD_SIZE;
            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }

    // Initialize the matched array
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            matched[i][j] = 0;
        }
    }
}

void print_board() {
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (matched[i][j]) {
                printf("   ");
            } else {
                printf(" %c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int make_move(Position *pos1, Position *pos2) {
    if (pos1->row == pos2->row && pos1->col == pos2->col) {
        printf("You can't select the same position twice!\n");
        return 0;
    }

    if (matched[pos1->row][pos1->col] || matched[pos2->row][pos2->col]) {
        printf("You can't select a matched position!\n");
        return 0;
    }

    printf("You selected %c at (%d, %d) and %c at (%d, %d)\n",
        board[pos1->row][pos1->col], pos1->row + 1, pos1->col + 1,
        board[pos2->row][pos2->col], pos2->row + 1, pos2->col + 1);

    if (board[pos1->row][pos1->col] == board[pos2->row][pos2->col]) {
        printf("You found a match!\n");
        matched[pos1->row][pos1->col] = 1;
        matched[pos2->row][pos2->col] = 1;
        return 1;
    } else {
        printf("Sorry, no match!\n");
        return 0;
    }
}

int main() {
    int moves = 0;
    int pairs_found = 0;
    Position pos1, pos2;

    init_board();

    while (pairs_found < NUM_PAIRS) {
        print_board();

        printf("Enter the position of the first card (row, col): ");
        scanf("%d %d", &pos1.row, &pos1.col);
        --pos1.row;
        --pos1.col;

        printf("Enter the position of the second card (row, col): ");
        scanf("%d %d", &pos2.row, &pos2.col);
        --pos2.row;
        --pos2.col;

        if (make_move(&pos1, &pos2)) {
            pairs_found++;
        }

        moves++;
    }

    printf("Congratulations! You found all the pairs in %d moves.\n", moves);

    return 0;
}