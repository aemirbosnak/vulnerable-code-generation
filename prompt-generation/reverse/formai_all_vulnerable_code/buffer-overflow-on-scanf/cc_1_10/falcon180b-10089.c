//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int board[ROWS][COLS] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

void shuffle_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int rand_row = rand() % ROWS;
            int rand_col = rand() % COLS;

            int temp = board[i][j];
            board[i][j] = board[rand_row][rand_col];
            board[rand_row][rand_col] = temp;
        }
    }
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("_ ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    init_board();
    shuffle_board();

    int player_score = 0;
    int computer_score = 0;

    while (1) {
        print_board();

        int choice;
        scanf("%d", &choice);

        if (choice < 0 || choice >= ROWS * COLS) {
            printf("Invalid choice.\n");
            continue;
        }

        if (board[choice / COLS][choice % COLS] == -1) {
            printf("Invalid choice.\n");
            continue;
        }

        if (board[choice / COLS][choice % COLS] == 1) {
            printf("You won!\n");
            player_score++;
        } else {
            printf("You lost.\n");
            computer_score++;
        }

        if (player_score == 8 || computer_score == 8) {
            printf("Game over!\n");
            break;
        }
    }

    return 0;
}