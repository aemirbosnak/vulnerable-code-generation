//FormAI DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(int board[][COLS], int revealed[][COLS]);
void fill_board(int board[][COLS], int num[]);
int get_input(int *row, int *col);
void reveal_card(int board[][COLS], int revealed[][COLS], int row, int col);
int check_match(int board[][COLS], int revealed[][COLS], int row1, int col1, int row2, int col2);

int main(void) {
    int board[ROWS][COLS], revealed[ROWS][COLS] = {0};
    int num[ROWS * COLS / 2] = {1, 2, 3, 4, 5, 6, 7, 8};
    int row1, col1, row2, col2, match;
    int attempts = 0;

    srand(time(NULL));

    fill_board(board, num);

    printf("Welcome to the Memory Game program!\n");
    
    while (1) {
        print_board(board, revealed);
        get_input(&row1, &col1);
        reveal_card(board, revealed, row1, col1);
        print_board(board, revealed);
        get_input(&row2, &col2);
        reveal_card(board, revealed, row2, col2);
        match = check_match(board, revealed, row1, col1, row2, col2);
        if (match) {
            printf("Congratulations! You found a match!\n");
        } else {
            printf("Sorry, those cards do not match.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
        attempts++;
        if (match && attempts == ROWS * COLS / 2) {
            printf("You won in %d attempts!", attempts);
            return 0;
        }
    }
}

void print_board(int board[][COLS], int revealed[][COLS]) {
    int i, j;

    printf("\n    1 2 3 4\n  +---------\n");
    for (i = 0; i < ROWS; i++) {
        printf("%d | ", i + 1);
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void fill_board(int board[][COLS], int num[]) {
    int i, j, r, c, count = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    while (count < ROWS * COLS / 2) {
        r = rand() % ROWS;
        c = rand() % COLS;
        if (board[r][c] == 0) {
            board[r][c] = num[count];
            count++;
        }
    }
}

int get_input(int *row, int *col) {
    int rtn_val = 0;

    while (!rtn_val) {
        printf("Enter the row and column numbers of the card you want to reveal: ");
        if (scanf("%d %d", row, col) != 2) {
            printf("Invalid input! Please enter two integers.\n");
            while (getchar() != '\n') ;
        } else if (*row < 1 || *row > ROWS || *col < 1 || *col > COLS) {
            printf("Invalid input! The row and column numbers must be between 1 and %d.\n", ROWS);
        } else {
            rtn_val = 1;
        }
    }

    (*row)--;
    (*col)--;

    return 1;
}

void reveal_card(int board[][COLS], int revealed[][COLS], int row, int col) {
    revealed[row][col] = 1;
}

int check_match(int board[][COLS], int revealed[][COLS], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    } else {
        return 0;
    }
}