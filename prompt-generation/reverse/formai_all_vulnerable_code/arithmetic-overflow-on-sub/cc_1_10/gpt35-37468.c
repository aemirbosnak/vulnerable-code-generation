//FormAI DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 20

int table[ROWS][COLS];
int moves[MAX_MOVES][2];
int num_moves = 0;

void print_table() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
}

void init_table() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = 0;
        }
    }
    srand(time(NULL));
    int i = rand() % ROWS;
    int j = rand() % COLS;
    table[i][j] = 1;
}

int is_valid_move(int i, int j) {
    if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
        return 0;
    }
    if (table[i][j] != 0) {
        return 0;
    }
    return 1;
}

void generate_moves(int i, int j) {
    num_moves = 0;
    if (is_valid_move(i + 1, j)) {
        moves[num_moves][0] = i + 1;
        moves[num_moves][1] = j;
        num_moves++;
    }
    if (is_valid_move(i - 1, j)) {
        moves[num_moves][0] = i - 1;
        moves[num_moves][1] = j;
        num_moves++;
    }
    if (is_valid_move(i, j + 1)) {
        moves[num_moves][0] = i;
        moves[num_moves][1] = j + 1;
        num_moves++;
    }
    if (is_valid_move(i, j - 1)) {
        moves[num_moves][0] = i;
        moves[num_moves][1] = j - 1;
        num_moves++;
    }
}

void make_move(int i, int j) {
    table[i][j] = table[i-1][j-1] + 1;
}

int play_game() {
    int i, j;
    init_table();
    print_table();
    while (1) {
        printf("\nEnter row and column to move: ");
        scanf("%d %d", &i, &j);
        if (!is_valid_move(i-1,j-1)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        make_move(i-1, j-1);
        generate_moves(i-1, j-1);
        if (num_moves == 0) {
            printf("No more valid moves. Game over!\n");
            print_table();
            return 0;
        }
        print_table();
        if (table[i-1][j-1] == ROWS*COLS) {
            printf("You won! Congratulations!\n");
            print_table();
            return 1;
        }
    }
}

int main() {
    play_game();
    return 0;
}