//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: systematic
/* 
C Maze Route Finder Example Program
Author: [Your Name]
Date: [Date]

This program will take a maze as input from the user, where:
    0 = valid path
    1 = wall
    S = start point
    E = end point
    
The program will then find a route from the start point to the end point.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10 //change value according to your maze size

void printMaze(int maze[][MAZE_SIZE]){
    for(int i=0; i < MAZE_SIZE; i++){
        for(int j=0; j < MAZE_SIZE; j++){
            printf("%c ", maze[i][j] == 1 ? '|' : maze[i][j] == 0 ? ' ' : maze[i][j]);          
        }
        printf("\n");
    }
}

int checkPoint(int x, int y){
    if(x >= 0 && y >=0 && x < MAZE_SIZE && y < MAZE_SIZE ){
        return 1;
    }
    return 0;
}

int solveMaze(int maze[][MAZE_SIZE], int x, int y){
    
    if(maze[x][y] == 3){
        return 1;
    }
 
    if(checkPoint(x,y) && maze[x][y] == 0){
        
        maze[x][y] = 4; /* Path Marking */
        
        if(solveMaze(maze, x+1, y)){/* Move Forward */
            return 1;
        }
            
        if(solveMaze(maze, x, y+1)){/* Move Downward */
            return 1;
        }
        
        if(solveMaze(maze, x-1, y)){/* Move Backward */
            return  1;
        }        
        
        if(solveMaze(maze, x, y-1)){/* Move Upward */
            return 1;
        }
        maze[x][y] = 0; /* Backtracking */
        return 0;
    }
    return 0;
}

int main(){
    
    int maze[MAZE_SIZE][MAZE_SIZE];
    char mazeChar[MAZE_SIZE];
    
    printf("Enter %d * %d Maze using 0 for Valid Path and 1 for Wall:\n", MAZE_SIZE, MAZE_SIZE);
    printf("S = Start, E = End\n\n");
    
    for(int i=0; i < MAZE_SIZE; i++){
        scanf("%s", mazeChar);
        
        for(int j=0; j < MAZE_SIZE; j++){
            if(mazeChar[j] == 'S'){
                maze[i][j] = 2;
            }else if(mazeChar[j] == 'E'){
                maze[i][j] = 3;
            }else{
                maze[i][j] = (int)mazeChar[j] - 48;
            }
        }
    }
    
    printf("\nMaze Entered:\n\n");
    printMaze(maze);
    
    printf("\nSolving Maze...\n");
    if(solveMaze(maze,0,2)){
        printf("Maze Solved!\n");
    }else{
        printf("Maze Unsolvable...\n");
    }
    
    printf("\nSolution:\n\n");
    printMaze(maze);
    
    return 0;
}