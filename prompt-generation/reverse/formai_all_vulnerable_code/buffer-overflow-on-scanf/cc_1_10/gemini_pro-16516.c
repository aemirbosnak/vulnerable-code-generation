//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 4

typedef struct {
    int row, col;
} Position;

char board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '*';
            revealed[i][j] = 0;
        }
    }
}

void print_board() {
    int i, j;
    printf("  ");
    for (j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int get_input() {
    int row, col;
    printf("Enter row and column (0-3): ");
    scanf("%d %d", &row, &col);
    return row * BOARD_SIZE + col;
}

int check_match(int pos1, int pos2) {
    int row1 = pos1 / BOARD_SIZE;
    int col1 = pos1 % BOARD_SIZE;
    int row2 = pos2 / BOARD_SIZE;
    int col2 = pos2 % BOARD_SIZE;
    return board[row1][col1] == board[row2][col2];
}

int main() {
    int i, j, pos1, pos2, matches = 0;
    char c;
    init_board();
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10 + '0';
        }
    }
    do {
        print_board();
        pos1 = get_input();
        revealed[pos1 / BOARD_SIZE][pos1 % BOARD_SIZE] = 1;
        print_board();
        pos2 = get_input();
        revealed[pos2 / BOARD_SIZE][pos2 % BOARD_SIZE] = 1;
        if (check_match(pos1, pos2)) {
            matches++;
            printf("Match! You have %d matches.\n", matches);
        } else {
            printf("No match. Try again.\n");
        }
        printf("Continue? (y/n): ");
        scanf(" %c", &c);
    } while (c == 'y');
    return 0;
}