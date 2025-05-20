//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int player = 1;
    int choice;
    int flag = 0;
    int count = 0;
    char play = 'y';

    srand(time(0));

    system("clear");

    while(play == 'y') {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Turn player %d\n",player);
        printf("Enter your move (1-9): ");
        scanf("%d",&choice);
        if(choice < 1 || choice > 9) {
            printf("Invalid move\n");
            count = 0;
        }
        else {
            int row = (choice-1)/3;
            int col = (choice-1)%3;
            if(board[row][col]!= 0) {
                printf("Cell already marked\n");
                count = 0;
            }
            else {
                board[row][col] = player;
                printf("Cell marked with %c\n",player==1?'X':'O');
                count++;
                if(count == 5) {
                    flag = 1;
                }
            }
        }
        player++;
        if(player > 2) {
            player = 1;
        }
        if(flag) {
            break;
        }
    }

    if(player == 1) {
        printf("Player 2 wins\n");
    }
    else {
        printf("Player 1 wins\n");
    }

    return 0;
}