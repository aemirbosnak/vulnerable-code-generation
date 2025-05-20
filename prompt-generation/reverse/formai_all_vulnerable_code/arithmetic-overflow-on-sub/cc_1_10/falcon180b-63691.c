//Falcon-180B DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int board[SIZE][SIZE] = {0};
    int player = 1;
    int choice;
    int flag = 0;
    int count = 0;
    int i, j;

    srand(time(NULL));

    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            board[i][j] = rand()%2;
        }
    }

    while(!flag) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Player %d's Turn\n", player);
        printf("Score: Player 1: %d and Player 2: %d\n", count, SIZE-count);

        for(i=0; i<SIZE; i++) {
            for(j=0; j<SIZE; j++) {
                if(board[i][j] == 1) {
                    printf("  ");
                } else {
                    printf(" %d ", board[i][j]);
                }
            }
            printf("\n");
        }

        printf("Enter your move (row and column): ");
        scanf("%d%d", &i, &j);

        if(board[i-1][j-1]!= 0) {
            printf("Invalid Move! Try Again.\n");
        } else {
            board[i-1][j-1] = player;
            count++;

            if(count == SIZE*SIZE) {
                flag = 1;
                printf("Game Over! Player %d Wins.\n", player);
            } else if(player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        }
    }

    return 0;
}