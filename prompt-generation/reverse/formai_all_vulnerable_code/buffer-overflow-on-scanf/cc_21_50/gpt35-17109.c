//FormAI DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3];
    int player = 1;
    int row, col;
    int winner = 0;
    
    // initialize board with zeros
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = 0;
        }
    }
    
    // display instructions
    printf("Welcome to C Table Game!\n");
    printf("Player 1 is X and Player 2 is O.\n");
    printf("Enter row and column of your move separated by space (e.g. 1 2)\n");
    
    // game loop
    while(!winner) {
        printf("\nPlayer %d's turn:\n", player);
        scanf("%d %d", &row, &col);
        
        // validate input
        while(row<1 || row>3 || col<1 || col>3 || board[row-1][col-1]!=0) {
            printf("Invalid move, please try again: ");
            scanf("%d %d", &row, &col);
        }
        
        // update board with player's move
        board[row-1][col-1] = player;
        
        // display updated board
        printf("\n");
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == 1) {
                    printf(" X ");
                } else if(board[i][j] == 2) {
                    printf(" O ");
                } else {
                    printf("   ");
                }
                
                if(j < 2) {
                    printf("|");
                }
            }
            printf("\n");
            if(i < 2) {
                printf("---+---+---\n");
            }
        }
        
        // check for winner
        for(int i=0; i<3; i++) {
            if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                winner = player;
                break;
            }
            if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                winner = player;
                break;
            }
        }
        if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            winner = player;
        }
        if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            winner = player;
        }
        
        // switch player for next turn
        player = (player == 1) ? 2 : 1;
    }
    
    // display winner
    printf("\nPlayer %d wins!\n", winner);
    
    return 0;
}