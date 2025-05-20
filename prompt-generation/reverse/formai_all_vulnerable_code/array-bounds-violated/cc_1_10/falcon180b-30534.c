//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int board[3][3]; //initialize the board
    int player = 1; //initialize the player
    int choice; //initialize the choice
    int flag = 0; //initialize the flag
    int i, j; //initialize the variables i and j

    srand(time(NULL)); //initialize the random seed

    printf("Welcome to Tic Tac Toe!\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            board[i][j] = rand()%2; //initialize the board with random numbers (0 or 1)
            printf("%d ", board[i][j]); //print the board
        }
        printf("\n");
    }

    while(flag == 0) //loop until the game is over
    {
        printf("Player %d's turn.\n", player);
        printf("Enter your move: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 9) //check if the move is valid
        {
            i = choice/3; //calculate the row and column of the chosen cell
            j = choice%3;
            if(board[i][j] == 0) //check if the cell is empty
            {
                board[i][j] = player; //place the player's mark on the cell
                player = (player == 1)? 2 : 1; //switch the player
                flag = 1; //set the flag to 1 (game over)
                printf("Player %d wins!\n", player);
            }
            else
            {
                printf("Invalid move! Try again.\n");
            }
        }
        else
        {
            printf("Invalid move! Try again.\n");
        }
    }

    return 0;
}