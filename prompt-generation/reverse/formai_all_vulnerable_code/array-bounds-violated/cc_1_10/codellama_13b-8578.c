//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: ultraprecise
/// A unique C Table Game example program in an ultraprecise style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 6
#define COLS 7
#define WIN_CONDITION 4

typedef struct {
    char symbol;
    int row;
    int col;
} token_t;

void print_table(token_t table[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", table[i][j].symbol);
        }
        printf("\n");
    }
}

void print_winner(token_t table[ROWS][COLS], int winner_row, int winner_col) {
    printf("Player %c wins!\n", table[winner_row][winner_col].symbol);
}

int check_win(token_t table[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (table[i][j].symbol == ' ') {
                continue;
            }

            int count = 1;
            for (int k = 1; k < WIN_CONDITION; k++) {
                if (table[i][j + k].symbol == table[i][j].symbol) {
                    count++;
                }
            }

            if (count == WIN_CONDITION) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));

    token_t table[ROWS][COLS];
    memset(table, 0, sizeof(table));

    int player = 1;
    int winner = 0;

    while (winner == 0) {
        int row, col;
        printf("Player %d, enter a row and column: ", player);
        scanf("%d %d", &row, &col);

        if (table[row][col].symbol != ' ') {
            printf("Invalid move.\n");
            continue;
        }

        table[row][col].symbol = player == 1 ? 'X' : 'O';
        table[row][col].row = row;
        table[row][col].col = col;

        print_table(table);

        winner = check_win(table);
        player = player == 1 ? 2 : 1;
    }

    print_winner(table, table[winner][winner].row, table[winner][winner].col);

    return 0;
}