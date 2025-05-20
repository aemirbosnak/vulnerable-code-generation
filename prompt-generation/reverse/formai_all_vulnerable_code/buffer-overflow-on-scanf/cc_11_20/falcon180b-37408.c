//Falcon-180B DATASET v1.0 Category: Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}}; //initialize board with zeros
    int x,y,player = 0; //initialize player to zero (player 1)
    char playAgain;
    do {
        system("clear"); //clear console
        printf("Player 1: X and Player 2: O\n");
        printf("Please enter the coordinates of your move (row and column): ");
        scanf("%d %d",&x,&y);
        if(player%2 == 0) { //player 1
            board[x][y] = 1; //place X on board
        }
        else { //player 2
            board[x][y] = 2; //place O on board
        }
        player++; //switch player
        for(int i=0;i<3;i++) { //check for winner
            for(int j=0;j<3;j++) {
                if(board[i][j]!= 0) {
                    if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j]) { //check rows
                        return 0;
                    }
                    else if(board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j]) { //check columns
                        return 0;
                    }
                    else if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j+1]) { //check diagonals
                        return 0;
                    }
                    else if(board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2]) { //check diagonals
                        return 0;
                    }
                }
            }
        }
        if(player%2 == 0) { //player 1
            system("clear");
            printf("It's Player 2's turn.\n");
        }
        else { //player 2
            system("clear");
            printf("It's Player 1's turn.\n");
        }
    }while(1);
    return 0;
}