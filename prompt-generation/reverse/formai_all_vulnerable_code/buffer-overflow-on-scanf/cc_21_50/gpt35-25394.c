//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include<stdio.h>

int main()
{
    printf("Welcome to the Maze Route Finder Game!\n");
    printf("In this game, you will navigate through a maze by inputting your movements.\n");
    printf("The maze is represented by a 2D array, where 0 represents an open cell and 1 represents a wall.\n");
    printf("You are represented by the letter 'O', and the exit is represented by the letter 'E'.\n");
    
    int maze[5][5] = { {0, 0, 1, 0, 1},
                       {1, 0, 1, 0, 1},
                       {0, 0, 0, 0, 1},
                       {1, 1, 1, 0, 0},
                       {1, 0, 0, 0, 1} };
    
    int row = 0;
    int col = 0;
    int exit_row = 4;
    int exit_col = 4;
    
    maze[row][col] = 'O';
    maze[exit_row][exit_col] = 'E';
    
    printf("Here is the maze:\n");
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(maze[i][j] == 0 || maze[i][j] == 'O' || maze[i][j] == 'E')
            {
                printf("%c ", maze[i][j]);
            }
            else
            {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }
    
    char move;
    while(1)
    {
        printf("Enter your move: ");
        scanf(" %c", &move);
        
        if(move == 'w')
        {
            if(row > 0 && maze[row-1][col] == 0)
            {
                maze[row][col] = 0;
                --row;
                maze[row][col] = 'O';
            }
            else
            {
                printf("Invalid move! Try again.\n");
            }
        }
        else if(move == 'a')
        {
            if(col > 0 && maze[row][col-1] == 0)
            {
                maze[row][col] = 0;
                --col;
                maze[row][col] = 'O';
            }
            else
            {
                printf("Invalid move! Try again.\n");
            }
        }
        else if(move == 's')
        {
            if(row < 4 && maze[row+1][col] == 0)
            {
                maze[row][col] = 0;
                ++row;
                maze[row][col] = 'O';
            }
            else
            {
                printf("Invalid move! Try again.\n");
            }
        }
        else if(move == 'd')
        {
            if(col < 4 && maze[row][col+1] == 0)
            {
                maze[row][col] = 0;
                ++col;
                maze[row][col] = 'O';
            }
            else
            {
                printf("Invalid move! Try again.\n");
            }
        }
        else
        {
            printf("Invalid input! Try again.\n");
        }
        
        if(row == exit_row && col == exit_col)
        {
            printf("Congratulations! You escaped the maze!\n");
            break;
        }
        
        printf("Your location in the maze:\n");
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(maze[i][j] == 0 || maze[i][j] == 'O' || maze[i][j] == 'E')
                {
                    printf("%c ", maze[i][j]);
                }
                else
                {
                    printf("%d ", maze[i][j]);
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}