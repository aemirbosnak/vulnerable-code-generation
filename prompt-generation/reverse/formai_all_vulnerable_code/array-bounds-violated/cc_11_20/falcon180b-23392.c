//Falcon-180B DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, mines;
    char board[10][10];
    int count = 0;
    int flag = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the number of mines: ");
    scanf("%d", &mines);

    srand(time(0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mines > 0) {
                if (rand() % 2 == 0) {
                    board[i][j] = '*';
                    mines--;
                }
            } else {
                board[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    int x, y;

    while (flag == 0) {
        printf("Enter the coordinates of the cell you want to check: ");
        scanf("%d %d", &x, &y);

        if (board[x][y] == '*') {
            printf("You hit a mine! Game over.\n");
            flag = 1;
        } else if (board[x][y] == '.') {
            printf("You missed a mine.\n");
        } else {
            printf("You found a safe cell.\n");
        }

        if (flag == 0) {
            count++;
        }
    }

    return 0;
}