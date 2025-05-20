//FormAI DATASET v1.0 Category: Pattern printing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void paranoidPrint(int n)
{
    if(n < 1)
    {
        printf("Invalid input! Must be greater than 0.");
        return;
    }
    else if(n % 2 == 0)
    {
        printf("Even number detected! Are you trying to trick me?");
        return;
    }
    
    int center = n / 2 + 1;
    int direction = -1;
    int row = 1, col = center, currentChar = 65; // ASCII code for 'A'
    
    char pattern[n][n];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            pattern[i][j] = ' ';
        }
    }
    
    while(currentChar <= 90) // ASCII code for 'Z'
    {
        pattern[row - 1][col - 1] = (char) currentChar;
        
        if(row == center && col == center)
        {
            direction = 1;
        }
        
        if(row == n && col == n)
        {
            break;
        }
        
        if(direction == -1)
        {
            row++;
            col--;
        }
        else
        {
            row--;
            col++;
        }
        
        if(row < 1)
        {
            row = 1;
            direction = -1;
            col += 2;
        }
        
        if(col < 1)
        {
            col = 1;
            direction = -1;
            row += 2;
        }
        
        if(row > n)
        {
            row = n;
            col += 2;
            direction = -1;
        }
        
        if(col > n)
        {
            col = n;
            row += 2;
            direction = -1;
        }
        
        currentChar++;
    }
    
    printf("Here's the paranoid pattern: \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%c ", pattern[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int input;
    printf("Please enter an odd number greater than 0: ");
    scanf("%d", &input);
    paranoidPrint(input);
    return 0;
}