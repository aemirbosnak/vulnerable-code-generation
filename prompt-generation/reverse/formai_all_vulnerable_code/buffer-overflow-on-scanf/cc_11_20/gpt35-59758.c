//FormAI DATASET v1.0 Category: Table Game ; Style: content
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //initialize the variables
    int n, m, i, j;
    int count=0, player1=0, player2=0;
    
    //prompt the users for dimensions of the table
    printf("Enter the number of rows and columns of the table:\n");
    scanf("%d %d",&n,&m);
    
    //create the table with random elements
    int table[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            table[i][j]=rand()%100;
        }
    }
    
    //display the table
    printf("The table looks like this:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    
    //start the game
    printf("Game is starting...\n");
    while(count<(n*m))
    {
        //prompt player 1 for their choice
        printf("Player 1, enter the row and column indices you would like to choose:\n");
        int row1, col1;
        scanf("%d %d",&row1,&col1);
        if(row1<0 || row1>=n || col1<0 || col1>=m)
        {
            printf("Invalid input! Try again.\n");
            continue;
        }
        if(table[row1][col1]%2==0)
        {
            player1+=table[row1][col1];
            printf("Congratulations! Player 1 earned %d points!\n",table[row1][col1]);
        }
        else
        {
            printf("Sorry! Player 1 did not earn any points.\n");
        }
        count++;
        if(count==(n*m)) break;
        
        //prompt player 2 for their choice
        printf("Player 2, enter the row and column indices you would like to choose:\n");
        int row2, col2;
        scanf("%d %d",&row2,&col2);
        if(row2<0 || row2>=n || col2<0 || col2>=m)
        {
            printf("Invalid input! Try again.\n");
            continue;
        }
        if(table[row2][col2]%2!=0)
        {
            player2+=table[row2][col2];
            printf("Congratulations! Player 2 earned %d points!\n",table[row2][col2]);
        }
        else
        {
            printf("Sorry! Player 2 did not earn any points.\n");
        }
        count++;
    }
    
    //declare the winner
    printf("\nFinal Scores:\nPlayer 1: %d points\nPlayer 2: %d points\n",player1,player2);
    if(player1>player2)
    {
        printf("Congratulations! Player 1 is the winner!\n");
    }
    else if(player2>player1)
    {
        printf("Congratulations! Player 2 is the winner!\n");
    }
    else
    {
        printf("It's a tie! Well played by both players.\n");
    }
    
    return 0;
}