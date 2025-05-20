//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, matches = 0, attempts = 0;
    int board[3][4];
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8};
    char ch;
    srand(time(0));
    printf("Welcome to the memory game!\n");
    printf("How many rows and columns? ");
    scanf("%d%d", &rows, &cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            board[i][j] = values[rand() % 8];
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            board[i][j] = -1;
        }
    }
    while (matches < rows * cols) {
        i = rand() % rows;
        j = rand() % cols;
        if (board[i][j]!= -1) {
            board[i][j] = -1;
            attempts++;
            if (attempts == 2) {
                board[i][j] = values[rand() % 8];
                attempts = 0;
            }
        }
    }
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i][j]!= -1) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("Congratulations! You completed the game in %d attempts.\n", attempts);
    return 0;
}