//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    char board[6][6];
    char color;
    int moves;

    printf("Welcome to the C Table Game! \n");

    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &n);
    printf("Enter the size of the board: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter the value of the (%d, %d)th cell: ", i, j);
            scanf(" %c", &board[i][j]);
        }
    }

    printf("\n\nHere is your board: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n\nLet's play the game!\n");
    color = 'X';
    moves = 0;

    while(moves < 10) {
        printf("\nEnter the row and column number where you want to place your %c: ", color);
        scanf("%d %d", &i, &j);
        if(board[i][j] == '-') {
            board[i][j] = color;
            moves++;
        } else {
            printf("Oops! That cell is already taken!\n");
        }
    }

    printf("\n\nHere is the final board: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}