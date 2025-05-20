//Falcon-180B DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, mines, i, j, k, count = 0, flag = 0;
    int board[10][10];
    char ch;
    srand(time(NULL));
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of mines: ");
    scanf("%d", &mines);

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            board[i][j] = 0;
        }
    }

    for(i=0; i<mines; i++) {
        do {
            k = rand() % rows;
            j = rand() % cols;
        } while(board[k][j] == 1);
        board[k][j] = -1;
    }

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(board[i][j] == 0) {
                printf(" ");
            } else if(board[i][j] == -1) {
                printf("*");
            }
        }
        printf("\n");
    }

    while(1) {
        printf("\nEnter the coordinates of the cell you want to check: ");
        scanf("%d%c%d", &i, &ch, &j);
        if((i>=0 && i<rows) && (j>=0 && j<cols)) {
            if(board[i][j] == -1) {
                printf("You hit a mine. Game Over!\n");
                exit(0);
            } else if(board[i][j] == 0) {
                printf("You missed a mine.\n");
            } else {
                printf("You found a safe cell.\n");
            }
        } else {
            printf("Invalid coordinates.\n");
        }
    }

    return 0;
}