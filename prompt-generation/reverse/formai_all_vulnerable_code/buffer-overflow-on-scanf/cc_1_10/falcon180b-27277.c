//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 50
#define MAX_COLS 50

int board[MAX_ROWS][MAX_COLS];
int num_rows, num_cols;

void init_board(int rows, int cols) {
    num_rows = rows;
    num_cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 && j == 0) || (i!= 0 && j!= 0)) {
                int r = row + i;
                int c = col + j;
                if (r >= 0 && r < num_rows && c >= 0 && c < num_cols) {
                    count += board[r][c];
                }
            }
        }
    }
    return count;
}

void next_generation() {
    int new_board[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            int neighbors = count_neighbors(i, j);
            if (board[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    init_board(rows, cols);
    int choice;
    while (1) {
        system("clear");
        printf("Game of Life\n");
        printf("Press 1 to print the board\n");
        printf("Press 2 to simulate one generation\n");
        printf("Press 3 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_board();
                break;
            case 2:
                next_generation();
                print_board();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}