//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random maze
void generateRandomMaze(int m, int n, char **maze){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            //Place walls on edges
            if(i==0 || i==m-1 || j==0 || j==n-1){
                maze[i][j] = '#';
            }
            else{
                //Randomly place walls
                int val = rand()%2;
                if(val == 1){
                    maze[i][j] = '#';
                }
                else{
                    maze[i][j] = ' ';
                }
            }
        }
    }
}

//Function to print maze
void printMaze(int m, int n, char **maze){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

//Structure to hold coordinates of a point
typedef struct{
    int x;
    int y;
} point;

//Function to check if a point is valid
int isValid(int m, int n, char **maze, point pt){
    if(pt.x<0 || pt.x>=m || pt.y<0 || pt.y>=n){
        return 0;
    }
    if(maze[pt.x][pt.y] == '#'){
        return 0;
    }
    return 1;
}

//Function to implement BFS algorithm
void BFS(int m, int n, char **maze, point start, point end){
    point queue[m*n];
    int visited[m][n];
    int dirx[] = {-1, 0, 1, 0};
    int diry[] = {0, 1, 0, -1};
    int front = -1, rear = -1;
    int i;

    //Mark all cells as unvisited
    for(i=0;i<m;i++){
        int j;
        for(j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }

    queue[++rear] = start;
    visited[start.x][start.y] = 1;

    while(front != rear){
        point curr = queue[++front];
        if(curr.x == end.x && curr.y == end.y){
            //If destination is found, display path
            printf("Path:\n");
            while(curr.x != start.x || curr.y != start.y){
                printf("(%d,%d)\n", curr.x, curr.y);
                curr = queue[visited[curr.x][curr.y]-1];
            }
            printf("(%d,%d)\n", curr.x, curr.y);
            return;
        }
        //Explore neighboring cells
        for(i=0;i<4;i++){
            point next = {curr.x + dirx[i], curr.y + diry[i]};
            if(isValid(m,n,maze,next) && visited[next.x][next.y] == 0){
                visited[next.x][next.y] = visited[curr.x][curr.y] + 1;
                queue[++rear] = next;
            }
        }
    }
    printf("No path found!\n");
}

int main(){
    srand(time(NULL));
    //Input maze dimensions
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    //Allocate memory for maze
    char **maze = (char**) malloc(m*sizeof(char*));
    int i;
    for(i=0;i<m;i++){
        maze[i] = (char*) malloc(n*sizeof(char));
    }
    //Generate random maze
    generateRandomMaze(m,n,maze);
    //Print maze
    printf("Maze:\n");
    printMaze(m,n,maze);
    //Input start and end points
    int sx, sy, ex, ey;
    printf("Enter start point (row column): ");
    scanf("%d %d", &sx, &sy);
    printf("Enter end point (row column): ");
    scanf("%d %d", &ex, &ey);
    point start = {sx, sy};
    point end = {ex, ey};
    //Perform BFS
    BFS(m,n,maze,start,end);
    //Free memory allocated for maze
    for(i=0;i<m;i++){
        free(maze[i]);
    }
    free(maze);
    return 0;
}