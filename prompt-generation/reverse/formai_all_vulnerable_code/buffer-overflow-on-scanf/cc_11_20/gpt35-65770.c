//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_board(int a[]);

int main()
{
    // Replace MAX with the size of board you would like.
    const int MAX = 3;
    int board[MAX][MAX];
    int x, y;
    int turn = 0;
    int count = 0;

    // Set all board positions to 0.
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            board[i][j] = 0;
        }
    }

    // Display the board before the start of the game.
    print_board(&board[0][0]);

    while(count < MAX*MAX){

        // Player 1
        if(turn%2==0){
            printf("Player 1 - Enter X and Y Co-ordinates separated by 'SPACE':");
            scanf("%d %d",&x,&y);

            // If the position is already occupied.
            if(board[x][y] != 0){
                printf("Position already occupied.\n");
                continue;
            }

            printf("Player 1 - Your turn marked at - ");
            board[x][y] = 1;

        // Player 2
        }else{
            printf("Player 2 - Enter X and Y Co-ordinates separated by 'SPACE':");
            scanf("%d %d",&x,&y);

            // If the position is already occupied.
            if(board[x][y] != 0){
                printf("Position already occupied.\n");
                continue;
            }

            printf("Player 2 - Your turn marked at - ");
            board[x][y] = 2;
        }

        // Display the board after the player's turn.
        print_board(&board[0][0]);
        count++;

        // Checking for winner horizontally
        for(int i=0; i<MAX; i++){
            int sum = 0;
            for(int j=0; j<MAX; j++){
                sum += board[i][j];
            }
            if(sum == MAX){
                printf("Player 1 Wins\n");
                return 0;
            }else if(sum == 2*MAX){
                printf("Player 2 Wins\n");
                return 0;
            }
        }

        // Checking for winner vertically
        for(int j=0; j<MAX; j++){
            int sum = 0;
            for(int i=0; i<MAX; i++){
                sum += board[i][j];
            }
            if(sum == MAX){
                printf("Player 1 Wins\n");
                return 0;
            }else if(sum == 2*MAX){
                printf("Player 2 Wins\n");
                return 0;
            }
        }

        // Checking for winner diagonally
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<MAX; i++){
            sum1 += board[i][i];
            sum2 += board[i][MAX-i-1];
        }
        if(sum1 == MAX){
            printf("Player 1 Wins\n");
            return 0;
        }else if(sum1 == 2*MAX){
            printf("Player 2 Wins\n");
            return 0;
        }
        if(sum2 == MAX){
            printf("Player 1 Wins\n");
            return 0;
        }else if (sum2 == 2*MAX){
            printf("Player 2 Wins\n");
            return 0;
        }
        turn++;

        // Draw match if all positions have been occupied
        if(count == MAX*MAX){
            printf("Match Drawn\n");
        }

    }

    return 0;
}

/*
Printing the board.
*/
void print_board(int *a){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ",*(a + i*3 + j));
        }
        printf("\n");
    }
}