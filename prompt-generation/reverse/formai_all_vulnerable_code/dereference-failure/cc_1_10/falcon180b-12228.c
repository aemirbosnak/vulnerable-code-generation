//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLS 30

void createMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);
int checkExit(int x, int y);

int main()
{
    srand(time(0));
    char maze[ROWS][COLS];
    createMaze(maze);
    printMaze(maze);
    return 0;
}

void createMaze(char maze[ROWS][COLS])
{
    int x, y;
    for(x=0; x<ROWS; x++)
    {
        for(y=0; y<COLS; y++)
        {
            maze[x][y] = rand()%2? '.' : '#';
        }
    }
    
    int startX = rand()%ROWS;
    int startY = rand()%COLS;
    maze[startX][startY] = 'S';
    maze[startX][startY+1] = '.';
    
    int endX = rand()%ROWS;
    int endY = rand()%COLS;
    maze[endX][endY] = 'E';
    maze[endX][endY+1] = '.';
}

void printMaze(char maze[ROWS][COLS])
{
    int x, y;
    for(x=0; x<ROWS; x++)
    {
        for(y=0; y<COLS; y++)
        {
            printf("%c", maze[x][y]);
        }
        printf("\n");
    }
}

int checkExit(int x, int y)
{
    if(x==COLS-1 && y==ROWS-2)
        return 1;
    else if(x==COLS-1 && y==ROWS-1)
        return 1;
    else if(x==0 && y==0)
        return 1;
    else if(x==0 && y==ROWS-1)
        return 1;
    else
        return 0;
}