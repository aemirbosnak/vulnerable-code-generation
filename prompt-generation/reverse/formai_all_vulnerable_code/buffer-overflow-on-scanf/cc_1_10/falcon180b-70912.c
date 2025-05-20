//Falcon-180B DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_MINES 5

char board[BOARD_SIZE][BOARD_SIZE];
int num_mines = 0;

void generate_board() {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 2? '*' : '.';
        }
    }
    for (int i = 0; i < NUM_MINES; i++) {
        int x, y;
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while (board[x][y] == '*');
        board[x][y] = '*';
        num_mines++;
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_board();
    print_board();

    int x, y;
    while (1) {
        printf("Enter a coordinate: ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
            if (board[x][y] == '*') {
                printf("You hit a mine! Game over.\n");
                return 0;
            } else {
                printf("You uncovered a tile.\n");
            }
        } else {
            printf("Invalid coordinate.\n");
        }
    }

    return 0;
}