//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_PAIRS 8

char board[ROWS][COLS] = {
    {'1', '2', '3', '4'},
    {'5', '6', '7', '8'},
    {'9', '10', '11', '12'},
    {'13', '14', '15', '16'}
};

int values[NUM_PAIRS];
int num_pairs;

void init_board() {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < NUM_PAIRS; i++) {
        do {
            values[i] = rand() % 16;
        } while (values[i] == values[i - 1]);
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '0' + rand() % 16;
        }
    }
}

void print_board() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_pair(int x, int y) {
    if (board[x][y] == '0' + values[num_pairs - 1]) {
        board[x][y] = 'X';
        return 1;
    }

    if (board[x][y] == '0' + values[num_pairs - 2]) {
        board[x][y] = 'X';
        return 1;
    }

    return 0;
}

int main() {
    int x, y;

    init_board();
    print_board();

    while (num_pairs < NUM_PAIRS) {
        printf("Enter row and column: ");
        scanf("%d %d", &x, &y);

        if (check_pair(x, y)) {
            num_pairs++;
        } else {
            printf("Try again.\n");
        }
    }

    printf("Congratulations! You won in %d turns.\n", num_pairs);

    return 0;
}