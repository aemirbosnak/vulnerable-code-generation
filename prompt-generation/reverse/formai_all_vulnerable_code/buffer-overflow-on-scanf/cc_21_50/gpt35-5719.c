//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>   
#include <time.h>      

int main()
{
    int r, c, i, j;
    int player = 0;
    int row, column;
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    printf("Welcome to Tic Tac Toe Game!\n");
    printf("Player 1 (X)  vs  Player 2 (O)\n\n");

    srand(time(NULL)); 
    r = rand() % 2; 
    if(r == 0)
    {
        printf("Player 1 starts first!\n\n");
        player = 1;
    }
    else
    {
        printf("Player 2 starts first!\n\n");
        player = 2;
    }

    for(i=0; i<3; i++) 
    {
        for(j=0; j<3; j++) 
        {
            printf(" %c ", board[i][j]); 
            if(j!=2)
            printf("|"); 
        }
        printf("\n");
        if(i!=2)
        printf("---|---|---\n"); 
    }

    printf("\n");

    while(1)
    {
        printf("Player %d's turn.\n",player);
        printf("Enter row number: ");
        scanf("%d",&row);
        printf("Enter column number: ");
        scanf("%d",&column);

        if(row < 1 || row > 3 || column < 1 || column > 3)
        {
            printf("Invalid choice. Please enter row (1-3) and column (1-3).\n");
            continue;
        }
        else if(board[row-1][column-1] == 'X' || board[row-1][column-1] == 'O')
        {
            printf("This slot is already filled. Please enter another one.\n");
            continue;
        }
        else
        {
            if(player == 1)
            {
                board[row-1][column-1] = 'X';
            }
            else
            {
                board[row-1][column-1] = 'O';
            }
        }

        for(i=0; i<3; i++) 
        {
            for(j=0; j<3; j++) 
            {
                printf(" %c ", board[i][j]); 
                if(j!=2)
                printf("|"); 
            }
            printf("\n");
            if(i!=2)
            printf("---|---|---\n"); 
        }

        printf("\n");

        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            printf("Player %d wins!\n",player);
            break;
        }
        else if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            printf("Player %d wins!\n",player);
            break;
        }
        else
        {
            for(i=0; i<3; i++)
            {
                if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
                {
                    printf("Player %d wins!\n",player);
                    break;
                }
                else if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
                {
                    printf("Player %d wins!\n",player);
                    break;
                }
            }
            if(i != 3)
            {
                break;
            }
        }

        if(player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
    }
    return 0;
}