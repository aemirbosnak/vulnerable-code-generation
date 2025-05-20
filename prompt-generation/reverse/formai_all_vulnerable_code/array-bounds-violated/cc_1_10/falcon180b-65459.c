//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define PAIRS 4

int board[ROWS][COLS];
int pairs[PAIRS][2];
int num_pairs;
int score;

void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

void init_pairs() {
    int i;
    for (i = 0; i < PAIRS; i++) {
        pairs[i][0] = rand() % ROWS;
        pairs[i][1] = rand() % COLS;
    }
    num_pairs = PAIRS;
}

void draw_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_pair(int x, int y) {
    int i;
    for (i = 0; i < num_pairs; i++) {
        if (pairs[i][0] == x && pairs[i][1] == y) {
            return i + 1;
        }
    }
    return 0;
}

void flip_card(int x, int y) {
    if (board[x][y] == -1) {
        board[x][y] = 0;
    } else if (board[x][y] == 0) {
        board[x][y] = -1;
    }
}

int main() {
    int i, j, k, l, x, y, pair_num;
    int found_pairs = 0;
    srand(time(NULL));
    init_board();
    init_pairs();
    draw_board();

    while (found_pairs < num_pairs) {
        printf("Enter two numbers (row and column): ");
        scanf("%d %d", &x, &y);
        x--; y--;
        if (board[x][y] == -1) {
            printf("Invalid move!\n");
        } else if (board[x][y] == 0) {
            flip_card(x, y);
            if (check_pair(x, y) > 0) {
                found_pairs++;
                score += check_pair(x, y);
            }
        }
    }

    printf("Game over!\n");
    printf("Your score is: %d\n", score);

    return 0;
}