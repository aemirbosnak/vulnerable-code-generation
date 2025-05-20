//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10		//Number of rows in the maze
#define COLS 20		//Number of columns in the maze

//Function to display the maze
void display_maze(int maze[][COLS])
{
    int i, j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            if(maze[i][j] == 0)		//If the cell is a wall
                printf("# ");
            else if(maze[i][j] == 1)	//If the cell is empty
                printf("  ");
            else if(maze[i][j] == 2)	//If the cell is the start point
                printf("S ");
            else if(maze[i][j] == 3)	//If the cell is the end point
                printf("E ");
        }
        printf("\n");
    }
}

//Function to find the solution to the maze
int solve_maze(int maze[][COLS], int x, int y, int path_length, char path[])
{
    if(x < 0 || x >= ROWS || y < 0 || y >= COLS)	//If the current cell is out of bounds
        return 0;
    if(maze[x][y] == 0)		//If the current cell is a wall
        return 0;
    if(maze[x][y] == 3)		//If the current cell is the end point
    {
        path[path_length] = '\0';	//Add null character to the end of the path string
        printf("The solution is: %s\n", path);
        return 1;
    }
    maze[x][y] = 0;		//Mark the current cell as visited
    path[path_length] = 'N';	//Add North to the path string
    if(solve_maze(maze, x-1, y, path_length+1, path))
        return 1;
    path[path_length] = 'S';	//Add South to the path string
    if(solve_maze(maze, x+1, y, path_length+1, path))
        return 1;
    path[path_length] = 'E';	//Add East to the path string
    if(solve_maze(maze, x, y+1, path_length+1, path))
        return 1;
    path[path_length] = 'W';	//Add West to the path string
    if(solve_maze(maze, x, y-1, path_length+1, path))
        return 1;
    maze[x][y] = 1;		//Mark the current cell as unvisited
    return 0;			//No solution found
}

int main()
{
    int maze[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0},
        {0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0},
        {0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,0,1,0},
        {0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0},
        {0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,0,1,0},
        {0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0},
        {0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0},
        {0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0},
    };
    int x, y;
    char path[ROWS*COLS];
    printf("Enter the coordinates of the starting point (x,y): ");
    scanf("%d,%d", &x, &y);
    if(maze[x][y] == 0)	//If the starting point is a wall
    {
        printf("Starting point is a wall.\n");
        return 0;
    }
    maze[x][y] = 2;		//Mark the starting point
    printf("\nMaze:\n");
    display_maze(maze);
    printf("\n");
    if(!solve_maze(maze, x, y, 0, path))
        printf("No solution found.\n");
    return 0;
}