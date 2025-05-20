//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WIDTH 10
#define HEIGHT 10

int maze[HEIGHT][WIDTH] = { {0,0,0,0,1,1,1,0,1,0},
                            {1,1,1,1,1,0,1,0,1,0},
                            {0,0,0,0,0,0,1,0,1,0},
                            {0,1,1,1,0,1,1,0,0,0},
                            {0,0,0,1,0,0,0,0,1,0},
                            {1,1,0,1,1,1,1,1,1,0},
                            {0,0,0,0,1,0,0,1,0,0},
                            {1,1,1,1,1,1,1,1,1,1},
                            {0,0,0,0,1,0,0,0,0,0},
                            {1,1,1,0,0,0,1,0,1,0}
                          };


int visited[HEIGHT][WIDTH];

typedef struct{
    int x;
    int y;
}Position;

Position currentPosition;

//Function to print the maze
void printMaze(){
    printf("   ");
    for(int i=0;i<WIDTH;i++)
        printf("%d ",i);

    printf("\n");

    for(int j=0;j<HEIGHT;j++){
        printf("%2d ",j);
        for(int i=0;i<WIDTH;i++){
            printf("%s",maze[j][i]?"█":" ");
        }
        printf("\n");
    }
}

//Function to check if a given position is valid or not
int isValidPosition(int x, int y){
    if(x<0 || x>=WIDTH || y<0 || y>=HEIGHT)
        return 0;
    if(visited[y][x]==1 || maze[y][x]==1)
        return 0;
    return 1;
}

//Function to find the route by recursion
int findRoute(int x, int y, int endX, int endY){
    if(x==endX && y==endY){
        visited[y][x] = 1;
        return 1;
    }

    if(isValidPosition(x,y)==1){
        visited[y][x] = 1;
        currentPosition.x = x;
        currentPosition.y = y;
        if(findRoute(x+1,y,endX,endY)==1)
            return 1;
        if(findRoute(x,y+1,endX,endY)==1)
            return 1;
        if(findRoute(x-1,y,endX,endY)==1)
            return 1;
        if(findRoute(x,y-1,endX,endY)==1)
            return 1;
        visited[y][x] = 0;
    }

    return 0;
}

//Function to initialize the visited matrix
void initializeVisited(){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            visited[i][j] = 0;
        }
    }
}

int main(){
    int startX,startY,endX,endY;

    printf("Enter the starting position:\n");
    printf("X = ");
    scanf("%d",&startX);
    printf("Y = ");
    scanf("%d",&startY);

    printf("Enter the ending position:\n");
    printf("X = ");
    scanf("%d",&endX);
    printf("Y = ");
    scanf("%d",&endY);

    initializeVisited();
    currentPosition.x = startX;
    currentPosition.y = startY;

    if(findRoute(startX,startY,endX,endY)==1){
        printf("Route Found!\n");
        printMaze();
        visited[currentPosition.y][currentPosition.x] = 0;
        while(currentPosition.x!=startX || currentPosition.y!=startY){
            if(currentPosition.x>0 && visited[currentPosition.y][currentPosition.x-1]==1){
                printf("Moved Left\n");
                currentPosition.x--;
            }
            else if(currentPosition.y>0 && visited[currentPosition.y-1][currentPosition.x]==1){
                printf("Moved Up\n");
                currentPosition.y--;
            }
            else if(currentPosition.x<WIDTH-1 && visited[currentPosition.y][currentPosition.x+1]==1){
                printf("Moved Right\n");
                currentPosition.x++;
            }
            else if(currentPosition.y<HEIGHT-1 && visited[currentPosition.y+1][currentPosition.x]==1){
                printf("Moved Down\n");
                currentPosition.y++;
            }
            visited[currentPosition.y][currentPosition.x] = 0;
        }
    }
    else{
        printf("Route not found!\n");
        printMaze();
    }

    return 0;
}