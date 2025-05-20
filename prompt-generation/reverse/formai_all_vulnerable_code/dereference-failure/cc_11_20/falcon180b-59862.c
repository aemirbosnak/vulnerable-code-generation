//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int **board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            board[i][j] = rand() % 100;
        }
    }
    printf("The board is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    int moves = 0;
    int num_matches = 0;
    while (num_matches < rows * cols) {
        int choice;
        printf("Enter your move (1 for row, 2 for column): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the row: ");
            scanf("%d", &moves);
            if (moves >= 0 && moves < rows) {
                int col = rand() % cols;
                if (board[moves][col] == board[moves][col + 1]) {
                    num_matches++;
                    board[moves][col] = rand() % 100;
                    board[moves][col + 1] = rand() % 100;
                } else {
                    printf("No match!\n");
                }
            } else {
                printf("Invalid row!\n");
            }
        } else if (choice == 2) {
            printf("Enter the column: ");
            scanf("%d", &moves);
            if (moves >= 0 && moves < cols) {
                int row = rand() % rows;
                if (board[row][moves] == board[row + 1][moves]) {
                    num_matches++;
                    board[row][moves] = rand() % 100;
                    board[row + 1][moves] = rand() % 100;
                } else {
                    printf("No match!\n");
                }
            } else {
                printf("Invalid column!\n");
            }
        } else {
            printf("Invalid choice!\n");
        }
        printf("The board is:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    printf("You made %d moves and found %d matches.\n", moves, num_matches);
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}