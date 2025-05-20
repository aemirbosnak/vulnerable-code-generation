//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include<stdio.h>

int main(){

    char maze[7][7] = { //7x7 maze represented by a 2D array
        {'#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#'}
    };

    int x = 1, y = 1; //starting point of the maze
    maze[x][y] = 'S'; //mark starting point with 'S'
    int i, j;

    printf("Welcome to the Maze Route Finder!\n\n");

    //print the initial state of the maze
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    printf("\nLet's find the way out!\n\n");

    //keep moving until we reach the end of the maze
    while (maze[x][y] != 'E'){

        //move downwards if possible
        if (maze[x+1][y] == '.'){
            maze[x+1][y] = 'X'; //mark the visited spot with 'X'
            x++;
        }

        //move rightwards if possible
        else if (maze[x][y+1] == '.'){
            maze[x][y+1] = 'X';
            y++;
        }

        //move upwards if possible
        else if (maze[x-1][y] == '.'){
            maze[x-1][y] = 'X';
            x--;
        }

        //move leftwards if possible
        else if (maze[x][y-1] == '.'){
            maze[x][y-1] = 'X';
            y--;
        }

        //if all paths are blocked, there is no way out
        else{
            printf("Sorry, there is no possible route!\n");
            return 0;
        }

        //print the current state of the maze after each move
        for (i = 0; i < 7; i++){
            for (j = 0; j < 7; j++){
                printf("%c ", maze[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("Congratulations, you have found the way out of the maze!\n");

    return 0;
}