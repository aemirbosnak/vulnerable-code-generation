//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int matrix[ROW][COL];       // the matrix where the pathfinding will occur
bool visited[ROW][COL];     // to track whether a cell has been visited or not

// A utility function to check whether given cell (row, col) is a valid cell or not
bool isValid(int row, int col){
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// A utility function to check whether the destination cell has been reached or not
bool isDestination(int row, int col, int dest_row, int dest_col){
    return (row == dest_row) && (col == dest_col);
}

// A utility function to print the matrix
void printMatrix(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// A recursive function to find the shortest path between source cell (src_row, src_col) and
// destination cell (dest_row, dest_col)
bool findPathUtil(int src_row, int src_col, int dest_row, int dest_col){

    if(!isValid(src_row, src_col))      // if source cell is not valid
        return false;

    if(!isValid(dest_row, dest_col))    // if destination cell is not valid
        return false;

    if(!matrix[src_row][src_col])       // if source cell is blocked
        return false;

    if(isDestination(src_row, src_col, dest_row, dest_col)){   // if destination is reached
        matrix[src_row][src_col] = 9;
        return true;
    }

    visited[src_row][src_col] = true;   // mark the source cell as visited
    matrix[src_row][src_col] = 1;

    // now check all the adjacent cells for possible paths
    bool pathExists = false;
    if(isValid(src_row-1, src_col) && !visited[src_row-1][src_col])
        pathExists = findPathUtil(src_row-1, src_col, dest_row, dest_col);
    if(!pathExists && isValid(src_row, src_col+1) && !visited[src_row][src_col+1])
        pathExists = findPathUtil(src_row, src_col+1, dest_row, dest_col);
    if(!pathExists && isValid(src_row+1, src_col) && !visited[src_row+1][src_col])
        pathExists = findPathUtil(src_row+1, src_col, dest_row, dest_col);
    if(!pathExists && isValid(src_row, src_col-1) && !visited[src_row][src_col-1])
        pathExists = findPathUtil(src_row, src_col-1, dest_row, dest_col);

    if(pathExists){
        matrix[src_row][src_col] = 9;         // mark the current cell in the path with 9
    }
    return pathExists;
}

// A function to find the shortest path between given source cell and destination cell
void findPath(int src_row, int src_col, int dest_row, int dest_col){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            visited[i][j] = false;
        }
    }
    if(findPathUtil(src_row, src_col, dest_row, dest_col)){
        printf("Shortest path found:\n");
        printMatrix();
    } else {
        printf("No path exists between given source and destination!\n");
    }
}

int main(){

    printf("Enter the matrix:\n");
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nThe matrix is:\n");
    printMatrix();

    int src_row, src_col, dest_row, dest_col;
    printf("\nEnter the coordinates of the source cell: ");
    scanf("%d%d", &src_row, &src_col);
    printf("Enter the coordinates of the destination cell: ");
    scanf("%d%d", &dest_row, &dest_col);

    findPath(src_row, src_col, dest_row, dest_col);
    return 0;
}