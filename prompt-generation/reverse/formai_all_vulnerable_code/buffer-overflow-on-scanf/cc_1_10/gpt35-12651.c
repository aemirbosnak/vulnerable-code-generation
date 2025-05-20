//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>

#define ROW 5
#define COL 5

int maze[ROW][COL] = {
    {1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1},
};

int visited[ROW][COL];

int find_path(int row, int col) {

    if (row < 0 || col < 0 || row >= ROW || col >= COL || maze[row][col] == 0 || visited[row][col] == 1) {
        return 0;
    }

    visited[row][col] = 1;

    if (row == ROW - 1 && col == COL - 1) {
        return 1;
    }

    if (find_path(row, col + 1)) {
        printf("(%d, %d) ", row, col);
        return 1;
    }

    if (find_path(row + 1, col)) {
        printf("(%d, %d) ", row, col);
        return 1;
    }

    if (find_path(row, col - 1)) {
        printf("(%d, %d) ", row, col);
        return 1;
    }

    if (find_path(row - 1, col)) {
        printf("(%d, %d) ", row, col);
        return 1;
    }

    return 0;
}

int main() {

    int row, col;

    printf("Welcome to the Maze Route Finder!\n");
    printf("Enter the starting position in the maze (row, col): ");
    scanf("%d %d", &row, &col);

    printf("Your path to the end of the maze is: ");
    if (find_path(row, col)) {
        printf("(%d, %d)", ROW - 1, COL - 1);
    } else {
        printf("no path found.");
    }

    return 0;
}