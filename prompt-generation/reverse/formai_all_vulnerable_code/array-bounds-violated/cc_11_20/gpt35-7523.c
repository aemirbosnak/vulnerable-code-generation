//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include<stdio.h>

int main(){
    printf("Whoa! I have just created a program for a unique pathfinding algorithm! \n");

    //Let's begin by creating our grid
    int rows, cols;
    printf("Enter the number of rows:");
    scanf("%d", &rows);
    printf("Enter the number of columns:");
    scanf("%d", &cols);

    int grid[rows][cols];
    printf("Enter the initial position:");
    int start_row, start_col;
    scanf("%d %d", &start_row, &start_col);

    printf("Enter the target position:");
    int target_row, target_col;
    scanf("%d %d", &target_row, &target_col);

    //Let's now create our pathfinding algorithm

    //First initialize all cells of the grid to a very high number
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            grid[i][j] = 999;
        }
    }

    //Now set the starting cell distance to 0
    grid[start_row][start_col] = 0;

    //Let's now traverse through our grid and update the minimum distances to reach each cell
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            //If the current cell is the target cell, then we have found the shortest distance!
            if(i==target_row && j==target_col){
                printf("Found shortest distance from start to target: %d\n", grid[i][j]);
            }
            else{
                //Check the distance to the cell to the right
                if(j+1 < cols){
                    int distance = grid[i][j] + 1;
                    if(distance < grid[i][j+1]){
                        grid[i][j+1] = distance;
                    }
                }

                //Check the distance to the cell below
                if(i+1 < rows){
                    int distance = grid[i][j] + 1;
                    if(distance < grid[i+1][j]){
                        grid[i+1][j] = distance;
                    }
                }

                //Check the distance to the cell to the left
                if(j-1 >= 0){
                    int distance = grid[i][j] + 1;
                    if(distance < grid[i][j-1]){
                        grid[i][j-1] = distance;
                    }
                }

                //Check the distance to the cell above
                if(i-1 >= 0){
                    int distance = grid[i][j] + 1;
                    if(distance < grid[i-1][j]){
                        grid[i-1][j] = distance;
                    }
                }
            }
        }
    }

    printf("Wick-ed! My program executed successfully!\n");
    return 0;
}