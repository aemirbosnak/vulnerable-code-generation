//FormAI DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void print_board(int board[][COLS], int r, int c) {
    printf("\n");
    printf("    ");
    for (int i = 1; i <= c; i++) {
        printf("%-3d", i);
    }
    printf("\n");
    printf("    ");
    for (int i = 1; i <= c; i++) {
        printf("---");
    }

    printf("\n");
    for (int i = 0; i < r; i++) {
        printf("%-3d|", i + 1);
        for (int j = 0; j < c; j++) {
            if (board[i][j] == -1) {
                printf("   ");
            } else {
                printf("%-3d", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int board[ROWS][COLS];
    int nums[ROWS * COLS / 2];

    srand(time(0));

    for (int i = 0; i < ROWS * COLS / 2; i++) {
        nums[i] = i + 1;
    }

    shuffle(nums, ROWS * COLS / 2);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }

    int count = 0;

    while (count < ROWS * COLS / 2) {
        int i = rand() % ROWS;
        int j = rand() % COLS;

        if (board[i][j] == -1) {
            board[i][j] = nums[count];
            count++;
        }
    }

    count = 0;

    while (count < ROWS * COLS / 2) {
        int i = rand() % ROWS;
        int j = rand() % COLS;

        if (board[i][j] == -1) {
            board[i][j] = nums[count];
            count++;
        }
    }

    print_board(board, ROWS, COLS);

    int first_r, first_c, second_r, second_c;
    int num_matches = 0;

    while (num_matches < ROWS * COLS / 2) {
        printf("Enter position of first card: ");
        scanf("%d %d", &first_r, &first_c);

        if (board[first_r - 1][first_c - 1] == -1) {
            printf("Invalid position, try again.\n");
            continue;
        }

        printf("Enter position of second card: ");
        scanf("%d %d", &second_r, &second_c);

        if (board[second_r - 1][second_c - 1] == -1) {
            printf("Invalid position, try again.\n");
            continue;
        }

        if (board[first_r - 1][first_c - 1] == board[second_r - 1][second_c - 1]) {
            printf("Matched!\n");
            board[first_r - 1][first_c - 1] = -1;
            board[second_r - 1][second_c - 1] = -1;
            num_matches++;
        } else {
            printf("No match, try again.\n");
            print_board(board, ROWS, COLS);
        }
    }

    printf("Congratulations, you won!\n");

    return 0;
}