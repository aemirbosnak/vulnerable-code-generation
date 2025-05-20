//FormAI DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

/* Function declarations */
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]);
void print_board(int board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE]);
int check_match(int board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0};
    int num_moves = 0;
    int row1, col1, row2, col2;

    /* Set random seed for shuffling the board */
    srand(time(NULL));

    /* Initialize the board */
    initialize_board(board);

    while (1) { /* Main game loop */

        /* Print the board */
        print_board(board, revealed);

        /* Prompt for first card */
        printf("Enter row and column of first card: ");
        scanf("%d %d", &row1, &col1);

        /* Check if card has already been revealed */
        if (revealed[row1][col1]) {
            printf("Card has already been revealed. Try again.\n");
            continue;
        }

        /* Reveal first card */
        revealed[row1][col1] = 1;
        print_board(board, revealed);

        /* Prompt for second card */
        printf("Enter row and column of second card: ");
        scanf("%d %d", &row2, &col2);

        /* Check if card has already been revealed */
        if (revealed[row2][col2]) {
            printf("Card has already been revealed. Try again.\n");
            revealed[row1][col1] = 0;
            continue;
        }

        /* Reveal second card */
        revealed[row2][col2] = 1;
        print_board(board, revealed);

        /* Check if cards match */
        if (check_match(board, row1, col1, row2, col2)) {
            printf("Match found!\n");
        }
        else {
            printf("No match found.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }

        /* Increment move counter */
        num_moves++;

        /* Check if all cards have been revealed */
        if (num_moves == BOARD_SIZE * BOARD_SIZE / 2) {
            printf("Congratulations, you win!\n");
            break;
        }
    }

    return 0;
}

/* Initialize the board with random values */
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    int values[BOARD_SIZE*BOARD_SIZE/2];
    int i, j, k;

    /* Generate random values */
    for (i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++) {
        values[i] = i+1;
    }

    /* Shuffle the values */
    for (i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++) {
        j = rand() % (BOARD_SIZE*BOARD_SIZE/2);
        k = rand() % (BOARD_SIZE*BOARD_SIZE/2);
        int temp = values[j];
        values[j] = values[k];
        values[k] = temp;
    }

    /* Fill the board with the shuffled values */
    k = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = values[k/2];
            k++;
        }
    }
}

/* Print the board */
void print_board(int board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("--");
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

/* Check if two cards match */
int check_match(int board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2)
{
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    }
    else {
        return 0;
    }
}