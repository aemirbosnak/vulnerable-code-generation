//FormAI DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include<stdio.h>

int main()
{
    int players;
    printf("Welcome to C Pattern printing game! Please enter the number of players: ");
    scanf("%d", &players);
    
    //initialize pattern array
    char pattern[50][50];
    int row = 25;
    int col = 0;
    int count = 0;
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            pattern[i][j] = ' ';
        }
    }
    
    //add first letter 'C' to the pattern
    for(int i = 0; i < row; i++)
    {
        pattern[i][col] = '*';
    }
    col++;
    for(int j = col; j < col+5; j++)
    {
        pattern[row][j] = '*';
    }
    col += 6;
    for(int i = row+1; i < 50; i++)
    {
        pattern[i][col] = '*';
    }
    
    //print pattern to screen
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }
    
    //start game loop
    int currentPlayer = 1;
    while(1)
    {
        printf("Player %d, enter row and column (1-50) to place your '*': ", currentPlayer);
        int p_row, p_col;
        scanf("%d%d", &p_row, &p_col);
        
        //validate input
        if(p_row > 50 || p_row < 1 || p_col > 50 || p_col < 1)
        {
            printf("Invalid position, please choose again\n");
            continue;
        }
        
        //check if position already occupied
        if(pattern[p_row-1][p_col-1] != ' ')
        {
            printf("Position already occupied, please choose again\n");
            continue;
        }
        
        //add '*' to pattern
        pattern[p_row-1][p_col-1] = '*';
        
        //print updated pattern to screen
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                printf("%c", pattern[i][j]);
            }
            printf("\n");
        }
        
        //check for game over
        count++;
        if(count == 50*50)
        {
            printf("Game Over! Nobody Wins!\n");
            break;
        }
        
        //check for player winning
        int win = 1;
        for(int i = 0; i < row; i++)
        {
            if(pattern[i][col-1] != '*')
            {
                win = 0;
                break;
            }
        }
        if(win)
        {
            printf("Player %d Wins!\n", currentPlayer);
            break;
        }
        
        //switch to next player
        currentPlayer++;
        if(currentPlayer > players)
        {
            currentPlayer = 1;
        }
    }
    
    return 0;
}