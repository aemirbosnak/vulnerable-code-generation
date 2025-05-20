//Falcon-180B DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3];
    int player = 1;
    int choice;
    int flag = 0;
    
    srand(time(0));
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = rand()%2;
        }
    }
    
    while(flag == 0) {
        system("clear");
        printf("\n");
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == 0) {
                    printf(" %d ", ++player);
                }
                else {
                    printf(" %d ", player);
                }
            }
            printf("\n");
        }
        printf("\n");
        printf("Player %d's Turn\n", player);
        printf("Enter your move: ");
        scanf("%d", &choice);
        if(choice > 0 && choice <= 9 && board[choice/3][choice%3] == 0) {
            board[choice/3][choice%3] = player;
            player++;
            flag = 1;
        }
        else {
            printf("Invalid Move! Try Again.\n");
        }
    }
    
    system("clear");
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}