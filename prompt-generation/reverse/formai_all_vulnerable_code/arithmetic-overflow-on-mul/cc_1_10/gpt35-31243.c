//FormAI DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(int board[ROWS][COLS], int num_pairs);
void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]);
void reveal_card(int board[ROWS][COLS], int revealed[ROWS][COLS], int row, int col);
int get_choice(int *row, int *col);
int check_match(int board[ROWS][COLS], int revealed[ROWS][COLS], int row1, int col1, int row2, int col2);
int game_over(int revealed[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    int num_pairs, matches = 0;
    int row1, col1, row2, col2, match;

    srand((unsigned int) time(NULL)); // Seed random number generator

    printf("Welcome to the Memory Game!\n\n");
    printf("Please enter the number of pairs you would like to play with (max %d): ", (ROWS * COLS) / 2);
    scanf("%d", &num_pairs);

    if (num_pairs > (ROWS * COLS) / 2) {
        printf("Invalid input, max number of pairs is %d.\n", (ROWS * COLS) / 2);
        return 1;
    }

    init_board(board, num_pairs);

    while (!game_over(revealed)) {
        print_board(board, revealed);

        printf("Choose first card:\n");
        get_choice(&row1, &col1);
        reveal_card(board, revealed, row1, col1);

        printf("Choose second card:\n");
        get_choice(&row2, &col2);
        reveal_card(board, revealed, row2, col2);

        match = check_match(board, revealed, row1, col1, row2, col2);

        if (match) {
            printf("Match!\n");
            matches++;
        } else {
            printf("No match, try again.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
    }

    printf("Game over, you won with %d matches!\n", matches);

    return 0;
}

void init_board(int board[ROWS][COLS], int num_pairs)
{
    int pairs[num_pairs * 2];
    int i, j, k = 0;

    // Populate pairs array with values
    for (i = 0; i < num_pairs; i++) {
        pairs[i * 2] = i;
        pairs[i * 2 + 1] = i;
    }

    // Shuffle pairs array
    for (i = 0; i < num_pairs * 2; i++) {
        j = rand() % (num_pairs * 2);
        int temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }

    // Populate board array with shuffled pairs
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = pairs[k];
            k++;
        }
    }
}

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS])
{
    int i, j;

    printf("\n  ");

    for (i = 0; i < COLS; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void reveal_card(int board[ROWS][COLS], int revealed[ROWS][COLS], int row, int col)
{
    revealed[row][col] = 1;
}

int get_choice(int *row, int *col)
{
    printf("Enter row: ");
    scanf("%d", row);
    printf("Enter column: ");
    scanf("%d", col);
}

int check_match(int board[ROWS][COLS], int revealed[ROWS][COLS], int row1, int col1, int row2, int col2)
{
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    } else {
        return 0;
    }
}

int game_over(int revealed[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (!revealed[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}