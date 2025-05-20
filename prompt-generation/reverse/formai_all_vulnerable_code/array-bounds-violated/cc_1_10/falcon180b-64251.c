//Falcon-180B DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS];
int start_row, start_col;
int end_row, end_col;

void generate_maze(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = 1;
        }
    }

    start_row = rand() % rows;
    start_col = rand() % cols;
    maze[start_row][start_col] = 0;

    end_row = rand() % rows;
    end_col = rand() % cols;
    maze[end_row][end_col] = 2;
}

void print_maze(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else if (maze[i][j] == 2) {
                printf("E");
            } else if (maze[i][j] == 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    generate_maze(rows, cols);
    print_maze(rows, cols);

    return 0;
}