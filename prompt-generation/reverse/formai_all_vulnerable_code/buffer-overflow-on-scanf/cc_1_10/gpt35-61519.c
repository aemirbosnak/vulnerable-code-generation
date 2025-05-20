//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize_board(int board[ROWS][COLS]) {
    int i, j, value = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = value++;
        }
    }
}

void shuffle_board(int board[ROWS][COLS]) {
    int i, j, k, l, temp;
    srand((unsigned int)(time(NULL)));
    for (i = ROWS - 1; i >= 0; i--) {
        for (j = COLS - 1; j >= 0; j--) {
            k = rand() % (i + 1);
            l = rand() % (j + 1);
            temp = board[i][j];
            board[i][j] = board[k][l];
            board[k][l] = temp;
        }
    }
}

void display_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    int i, j;
    printf("\n\n");
    printf("     0    1    2    3\n");
    printf("   +----+----+----+----+\n");
    for (i = 0; i < ROWS; i++) {
        printf(" %d |", i);
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf(" %2d |", board[i][j]);
            } else {
                printf(" ?? |");
            }
        }
        printf("\n");
        printf("   +----+----+----+----+\n");
    }
    printf("\n\n");
}

int main() {
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    int i0, j0, i1, j1;
    int num_moves = 0;
    initialize_board(board);
    shuffle_board(board);
    while (1) {
        display_board(board, revealed);
        printf("Enter the first card: row column\n");
        scanf("%d %d", &i0, &j0);
        if (i0 < 0 || i0 > ROWS - 1 || j0 < 0 || j0 > COLS - 1) {
            printf("Invalid choice. Try again.\n");
            continue;
        }
        if (revealed[i0][j0]) {
            printf("You already selected that card. Try again.\n");
            continue;
        }
        revealed[i0][j0] = 1;
        display_board(board, revealed);
        printf("Enter the second card: row column\n");
        scanf("%d %d", &i1, &j1);
        if (i1 < 0 || i1 > ROWS - 1 || j1 < 0 || j1 > COLS - 1) {
            printf("Invalid choice. Try again.\n");
            revealed[i0][j0] = 0;
            continue;
        }
        if (revealed[i1][j1]) {
            printf("You already selected that card. Try again.\n");
            revealed[i0][j0] = 0;
            continue;
        }
        revealed[i1][j1] = 1;
        display_board(board, revealed);
        num_moves++;
        if (board[i0][j0] != board[i1][j1]) {
            printf("Sorry, the cards do not match.\n");
            revealed[i0][j0] = 0;
            revealed[i1][j1] = 0;
        }
        if (num_moves == ROWS * COLS / 2) {
            printf("Congratulations! You won in %d moves.\n", num_moves);
            break;
        }
    }
    return 0;
}