//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, columns, i, j, x, y, count = 0, random_number;
    printf("Enter the number of rows for the game board: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for the game board: ");
    scanf("%d", &columns);
    int board[rows][columns];
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            board[i][j] = rand() % 10;
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("Enter the coordinates you want to put the zero in the format of 'x y' (e.g. 3 5): ");
    scanf("%d %d", &x, &y);
    board[x][y] = 0;
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (board[i][j] == 0) {
                break;
            }
            else {
                count++;
            }
        }
        if (board[i][j] == 0) {
            break;
        }
    }
    if (count == rows * columns - 1) {
        printf("\nCongratulations! You won the game!\n");
    }
    else {
        printf("\nSorry, you lost the game!\n");
    }
    return 0;
}