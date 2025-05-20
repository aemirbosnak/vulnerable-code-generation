//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 6

char maze[ROWS][COLS] = {
    "00000X",
    "01110X",
    "02220X",
    "03330X",
    "04440X",
    "05550X",
    "06660X",
    "07770X",
    "08880X",
    "09990X"
};

void print_maze(int row, int col) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int start_row, start_col, end_row, end_col;

    printf("Enter starting position (row,col): ");
    scanf("%d%d", &start_row, &start_col);

    printf("Enter ending position (row,col): ");
    scanf("%d%d", &end_row, &end_col);

    if (maze[start_row][start_col] == 'X') {
        printf("Invalid starting position\n");
        return 1;
    }

    if (maze[end_row][end_col] == 'X') {
        printf("Invalid ending position\n");
        return 1;
    }

    if (start_row == end_row) {
        if (start_col > end_col) {
            for (int i = start_col; i >= end_col; i--) {
                printf("%d ", i);
            }
        } else {
            for (int i = start_col; i <= end_col; i++) {
                printf("%d ", i);
            }
        }
    } else if (start_col == end_col) {
        if (start_row > end_row) {
            for (int i = start_row; i >= end_row; i--) {
                printf("%d ", i);
            }
        } else {
            for (int i = start_row; i <= end_row; i++) {
                printf("%d ", i);
            }
        }
    } else {
        printf("No path found\n");
    }

    return 0;
}