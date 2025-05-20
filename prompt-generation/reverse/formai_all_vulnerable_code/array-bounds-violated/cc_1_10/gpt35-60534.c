//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include<stdio.h>
#define MAX_SIZE 101

int maze[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE], path[MAX_SIZE], count = 0, row, col;

void findPath(int x, int y)
{
    visited[x][y] = 1;
    
    if (x == row && y == col) { // if current cell is the destination
        for (int i = 0; i < count; i++)
            printf("%d -> ", path[i]);
        printf("Destination Reached\n");
        return;
    }
    
    if (maze[x-1][y] == 1 && visited[x-1][y] == 0) { // go up
        path[count++] = (x-1)*MAX_SIZE + y;
        findPath(x-1, y);
        count--;
        visited[x-1][y] = 0;
    }
    
    if (maze[x][y+1] == 1 && visited[x][y+1] == 0) { // go right
        path[count++] = x*MAX_SIZE + (y+1);
        findPath(x, y+1);
        count--;
        visited[x][y+1] = 0;
    }
    
    if (maze[x+1][y] == 1 && visited[x+1][y] == 0) { // go down
        path[count++] = (x+1)*MAX_SIZE + y;
        findPath(x+1, y);
        count--;
        visited[x+1][y] = 0;
    }
    
    if (maze[x][y-1] == 1 && visited[x][y-1] == 0) { // go left
        path[count++] = x*MAX_SIZE + (y-1);
        findPath(x, y-1);
        count--;
        visited[x][y-1] = 0;
    }
}

int main()
{
    int start, dest;
    
    printf("Enter number of rows and columns of maze: ");
    scanf("%d %d", &row, &col);
    
    printf("Enter the maze (1s for open path, 0s for blocked path):\n");
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            scanf("%d", &maze[i][j]);
    
    printf("Enter the starting point: ");
    scanf("%d", &start);
    
    path[count++] = start;
    
    printf("Enter the destination point: ");
    scanf("%d", &dest);
    
    findPath(start/MAX_SIZE, start%MAX_SIZE);
    
    return 0;
}