//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, num, count;
    int board[10][10];
    char ch;
    srand(time(NULL));

    printf("Enter the number of rows (1-10): ");
    scanf("%d", &rows);
    printf("Enter the number of columns (1-10): ");
    scanf("%d", &cols);

    //initialize the board with random numbers
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            board[i][j] = rand()%15 + 1;
        }
    }

    //print the board
    printf("\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter your choice of number (1-75): ");
    scanf("%d", &num);

    //check if the number is present in the board
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(board[i][j] == num) {
                count++;
            }
        }
    }

    if(count == 0) {
        printf("\nThe number %d is not present in the board.\n", num);
    }
    else {
        printf("\nThe number %d is present in the board %d times.\n", num, count);
    }

    return 0;
}