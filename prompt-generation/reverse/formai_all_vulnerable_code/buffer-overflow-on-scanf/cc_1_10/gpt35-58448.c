//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include<stdio.h>

//Function to check if a path is valid
int is_valid(int i, int j, int n, int m, int maze[n][m], int visited[n][m]){
    if(i>=0 && i<n && j>=0 && j<m && maze[i][j]==1 && visited[i][j]==0){
        return 1;
    }
    return 0;
}

//Function to print the path
void print_path(int path[], int len){
    for(int i=0; i<len; i++){
        printf("%d ", path[i]);
    }
    printf("\n");
}

//Function to find the route
void find_route(int i, int j, int n, int m, int maze[n][m], int visited[n][m], int path[], int len, int *min_len){
    //If goal is reached
    if(i==n-1 && j==m-1){
        if(len<*min_len){
            //Update the minimum path length and print the path
            *min_len = len;
            print_path(path, len);
        }
    }
    //If goal is not reached yet
    else{
        //Try moving right
        if(is_valid(i, j+1, n, m, maze, visited)){
            visited[i][j+1] = 1;
            path[len] = 1;
            find_route(i, j+1, n, m, maze, visited, path, len+1, min_len);
            visited[i][j+1] = 0;
        }
        //Try moving down
        if(is_valid(i+1, j, n, m, maze, visited)){
            visited[i+1][j] = 1;
            path[len] = 2;
            find_route(i+1, j, n, m, maze, visited, path, len+1, min_len);
            visited[i+1][j] = 0;
        }
        //Try moving left
        if(is_valid(i, j-1, n, m, maze, visited)){
            visited[i][j-1] = 1;
            path[len] = 3;
            find_route(i, j-1, n, m, maze, visited, path, len+1, min_len);
            visited[i][j-1] = 0;
        }
        //Try moving up
        if(is_valid(i-1, j, n, m, maze, visited)){
            visited[i-1][j] = 1;
            path[len] = 4;
            find_route(i-1, j, n, m, maze, visited, path, len+1, min_len);
            visited[i-1][j] = 0;
        }
    }
}

int main(){
    int n, m;
    printf("Enter the number of rows and columns of the maze:\n");
    scanf("%d %d", &n, &m);
    int maze[n][m];
    printf("Enter the maze:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    int visited[n][m];
    int path[n*m];
    int min_len = n*m;
    //Initialize the visited matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = 0;
        }
    }
    //Mark the start point as visited
    visited[0][0] = 1;
    //Find the route
    find_route(0, 0, n, m, maze, visited, path, 0, &min_len);
    //Print the minimum path length
    printf("Minimum path length: %d\n", min_len);
    return 0;
}