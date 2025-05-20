//FormAI DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void display_board(int board[][COLS]);
int choose_card(int row, int col, int board[][COLS], int revealed[][COLS]);
void update_revealed(int row1, int col1, int row2, int col2, int revealed[][COLS]);
int check_win(int revealed[][COLS]);

int main() {
    int board[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 3, 4}, {5, 6, 7, 8}};
    int revealed[ROWS][COLS] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int row1, col1, row2, col2;
    int card1, card2;
    int moves = 0;

    srand(time(NULL));
    display_board(board);

    while (!check_win(revealed)) {
        printf("Enter row and column of first card: ");
        scanf("%d %d", &row1, &col1);
        while (revealed[row1][col1]) {
            printf("Card already revealed. Enter row and column of first card: ");
            scanf("%d %d", &row1, &col1);
        }
        card1 = choose_card(row1, col1, board, revealed);
        revealed[row1][col1] = 1;

        printf("Enter row and column of second card: ");
        scanf("%d %d", &row2, &col2);
        while (revealed[row2][col2]) {
            printf("Card already revealed. Enter row and column of second card: ");
            scanf("%d %d", &row2, &col2);
        }
        card2 = choose_card(row2, col2, board, revealed);
        revealed[row2][col2] = 1;

        display_board(board);

        if (card1 != card2) {
            printf("Cards do not match. Try again.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        } else {
            printf("Cards match!\n");
        }

        moves++;
    }

    printf("You won in %d moves!\n", moves);

    return 0;
}

void display_board(int board[][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] < 10) {
                printf(" %d  ", board[i][j]);
            } else {
                printf("%d  ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int choose_card(int row, int col, int board[][COLS], int revealed[][COLS]) {
    printf("You chose %d.\n", board[row][col]);
    return board[row][col];
}

void update_revealed(int row1, int col1, int row2, int col2, int revealed[][COLS]) {
    revealed[row1][col1] = 1;
    revealed[row2][col2] = 1;
}

int check_win(int revealed[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!revealed[i][j]) {
                return 0;
            }
        }
    }
    return -1;
}