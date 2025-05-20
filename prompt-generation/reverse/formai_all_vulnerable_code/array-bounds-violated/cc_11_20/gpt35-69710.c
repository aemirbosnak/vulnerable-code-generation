//FormAI DATASET v1.0 Category: Memory Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES (ROWS * COLS / 2)

void print_board(int board[ROWS][COLS], int selected[ROWS][COLS]) {
    printf("\n    A B C D\n");
    for (int i = 0; i < ROWS; i++) {
        printf(" %d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (selected[i][j] == 1) {
                printf("%2d ", board[i][j]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main() {
    int moves = 0;
    int board[ROWS][COLS];
    int selected[ROWS][COLS] = {0};
    int pairs[MAX_MOVES][2];
    int n_pairs_found = 0;

    srand(time(NULL));
    // Fill the board with random numbers between 1 and MAX_MOVES
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % MAX_MOVES + 1;
        }
    }
    // Select pairs of cells randomly
    while (n_pairs_found < MAX_MOVES) {
        int r1 = rand() % ROWS;
        int c1 = rand() % COLS;
        int r2 = rand() % ROWS;
        int c2 = rand() % COLS;
        if (r1 == r2 && c1 == c2) {
            continue;  // Don't select the same cell twice
        }
        // Check if the pair has already been selected
        int already_selected = 0;
        for (int i = 0; i < n_pairs_found; i++) {
            if ((pairs[i][0] == r1 && pairs[i][1] == c1 && pairs[i][2] == r2 && pairs[i][3] == c2) ||
                (pairs[i][0] == r2 && pairs[i][1] == c2 && pairs[i][2] == r1 && pairs[i][3] == c1)) {
                already_selected = 1;
                break;
            }
        }
        if (!already_selected) {
            pairs[n_pairs_found][0] = r1;
            pairs[n_pairs_found][1] = c1;
            pairs[n_pairs_found][2] = r2;
            pairs[n_pairs_found][3] = c2;
            n_pairs_found++;
        }
    }
    // Main game loop
    while (1) {
        print_board(board, selected);
        // Check if the game is over
        if (moves == MAX_MOVES) {
            printf("\nCongratulations! You won in %d moves!\n", moves);
            break;
        }
        // Ask the player to select two cells
        int r1, c1, r2, c2;
        printf("\nEnter the coordinates of two cells (e.g. A1 B2): ");
        scanf(" %c%d %c%d", &c1, &r1, &c2, &r2);
        r1--; c1 -= 'A';
        r2--; c2 -= 'A';
        if (r1 < 0 || r1 >= ROWS || c1 < 0 || c1 >= COLS || r2 < 0 || r2 >= ROWS || c2 < 0 || c2 >= COLS) {
            printf("\nInvalid coordinates. Please try again.\n");
            continue;
        }
        if (selected[r1][c1] || selected[r2][c2]) {
            printf("\nCell already selected. Please try again.\n");
            continue;
        }
        if (board[r1][c1] == board[r2][c2]) {
            selected[r1][c1] = selected[r2][c2] = 1;
            printf("\nCongratulations! You found a pair of %d's!\n", board[r1][c1]);
            moves++;
        } else {
            printf("\nSorry, the cells don't match. Try again.\n");
            moves++;
        }
    }
    return 0;
}