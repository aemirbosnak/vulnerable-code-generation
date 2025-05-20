//FormAI DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 4

void print_board(int board[][NUM_COLS], int hidden[][NUM_COLS])
{
    printf("  | 1 | 2 | 3 | 4 |\n");
    printf("--|---|---|---|---|\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < NUM_COLS; j++) {
            if (hidden[i][j] == 1) {
                printf(" %d |", board[i][j]);
            } else {
                printf("   |");
            }
        }
        printf("\n");
    }
    printf("--|---|---|---|---|\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle_board(int board[][NUM_COLS])
{
    srand(time(NULL));
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            int row1 = rand() % NUM_ROWS;
            int col1 = rand() % NUM_COLS;
            int row2 = rand() % NUM_ROWS;
            int col2 = rand() % NUM_COLS;
            swap(&board[row1][col1], &board[row2][col2]);
        }
    }
}

int main()
{
    int board[NUM_ROWS][NUM_COLS] = {{1, 2, 3, 4},
                                     {5, 6, 7, 8},
                                     {1, 2, 3, 4},
                                     {5, 6, 7, 8}};
    int hidden[NUM_ROWS][NUM_COLS] = {{0, 0, 0, 0},
                                      {0, 0, 0, 0},
                                      {0, 0, 0, 0},
                                      {0, 0, 0, 0}};

    printf("Welcome to the Memory Game!\n");
    printf("You need to find all matching pairs in the board.\n");
    printf("Let's begin!\n");

    shuffle_board(board);

    int num_found_pairs = 0;
    int num_turns = 0;

    while (num_found_pairs < NUM_ROWS * NUM_COLS / 2) {
        printf("Turn %d\n", num_turns + 1);
        print_board(board, hidden);

        int row1, col1, row2, col2;
        printf("Enter the row and column of the first card: ");
        scanf("%d%d", &row1, &col1);
        printf("Enter the row and column of the second card: ");
        scanf("%d%d", &row2, &col2);

        if (row1 < 1 || row1 > NUM_ROWS || col1 < 1 || col1 > NUM_COLS ||
            row2 < 1 || row2 > NUM_ROWS || col2 < 1 || col2 > NUM_COLS) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        row1--;
        col1--;
        row2--;
        col2--;

        if (hidden[row1][col1] == 1 || hidden[row2][col2] == 1) {
            printf("Those cards are already revealed. Try again.\n");
            continue;
        }

        hidden[row1][col1] = 1;
        hidden[row2][col2] = 1;

        if (board[row1][col1] == board[row2][col2]) {
            printf("Found a pair!\n");
            num_found_pairs++;
        } else {
            printf("No match. Try again.\n");
            hidden[row1][col1] = 0;
            hidden[row2][col2] = 0;
        }

        num_turns++;
    }

    printf("Congratulations! You found all the pairs in %d turns.\n", num_turns);

    return 0;
}