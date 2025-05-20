//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//global variables
int maze[20][20], rows, cols;
int x_beg, y_beg, x_end, y_end;
int visited[20][20];

//Function prototypes
void generateMaze();
void printMaze();
void generateEntryAndExit();
void generateRandomMaze(int, int);
void generatePath(int, int);

//function to generate maze with random walls
void generateMaze(){
    int i, j;
    for(i = 0; i <rows; i++){
        for(j = 0; j <cols; j++){
            //generate random walls
            maze[i][j] = rand() % 2;
        }
    }
}

//function to print maze
void printMaze(){
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

//function to set entry and exit points
void generateEntryAndExit(){
    //setting entry point at top left and exit at bottom right
    x_beg = 0;
    y_beg = 0;
    x_end = rows - 1;
    y_end = cols - 1;
    //making sure that entry and exit points are not blocked
    maze[x_beg][y_beg+1] = 0;
    maze[x_end][y_end-1] = 0;
}

//function to generate random maze with no deadends
void generateRandomMaze(int x, int y){
    //mark the visited cell as 1
    visited[x][y] = 1;
    //generate random path till we reach the end point
    while(x != x_end || y != y_end){
        //generate random direction
        int direction = rand() % 4;
        //check if we can move in that direction
        switch(direction){
            //move up
            case 0: if(x > 0 && visited[x-1][y] == 0){
                        maze[x][y] = 0;
                        generatePath(x-1, y);
                    }
                    break;
            //move right
            case 1: if(y < cols-1 && visited[x][y+1] == 0){
                        maze[x][y+1] = 0;
                        generatePath(x, y+1);
                    }
                    break;
            //move down
            case 2: if(x < rows-1 && visited[x+1][y] == 0){
                        maze[x+1][y] = 0;
                        generatePath(x+1, y);
                    }
                    break;
            //move left
            case 3: if(y > 0 && visited[x][y-1] == 0){
                        maze[x][y] = 0;
                        generatePath(x, y-1);
                    }
                    break;
        }
    }
}

//function to generate path
void generatePath(int x, int y){
    visited[x][y] = 1;
    while(1){
        //find all valid directions
        int directions[4] = {0};
        int count = 0;
        if(x > 0 && visited[x-1][y] == 0){
            directions[count++] = 0; //up
        }
        if(y < cols-1 && visited[x][y+1] == 0){
            directions[count++] = 1; //right
        }
        if(x < rows-1 && visited[x+1][y] == 0){
            directions[count++] = 2; //down
        }
        if(y > 0 && visited[x][y-1] == 0){
            directions[count++] = 3; //left
        }
        //if no valid direction found, break out of loop
        if(count == 0){
            break;
        }
        //generate random direction
        int index = rand() % count;
        int direction = directions[index];
        //remove wall in that direction
        switch(direction){
            //move up
            case 0: maze[x][y] &= ~1;
                    generatePath(x-1, y);
                    break;
            //move right
            case 1: maze[x][y+1] &= ~4;
                    generatePath(x, y+1);
                    break;
            //move down
            case 2: maze[x+1][y] &= ~1;
                    generatePath(x+1, y);
                    break;
            //move left
            case 3: maze[x][y] &= ~4;
                    generatePath(x, y-1);
                    break;
        }
    }
}

int main(){
    //seed the random number generator
    srand(time(NULL));
    //get maze dimensions from user
    printf("Enter number of rows and columns of maze: ");
    scanf("%d %d", &rows, &cols);
    //generate maze with random walls
    generateMaze();
    //set entry and exit points
    generateEntryAndExit();
    //initialize all cells as unvisited
    int i, j;
    for(i = 0; i <rows; i++){
        for(j = 0; j <cols; j++){
            visited[i][j] = 0;
        }
    }
    //generate random path with no deadends
    generateRandomMaze(x_beg, y_beg+1);
    //print maze
    printMaze();
    return 0;
}