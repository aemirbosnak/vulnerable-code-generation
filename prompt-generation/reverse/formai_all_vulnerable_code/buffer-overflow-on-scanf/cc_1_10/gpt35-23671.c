//FormAI DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>

int grid[9][9]; //this 2D array will store the sudoku problem

//function to read the sudoku problem from user
void read_sudoku()
{
    printf("\nEnter the sudoku problem: (0 for blank spaces)\n");

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%d",&grid[i][j]);
        }
    }
}

//function to print the sudoku problem
void print_sudoku()
{
    printf("\nSudoku Puzzle:\n");
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d\t",grid[i][j]);
        }
        printf("\n");
    }
}

//function to check if we can place "n" at position (x,y)
int can_place(int x, int y, int n)
{
    //checking if the number already exists in the row or column
    for(int i=0; i<9; i++){
        if(grid[i][y] == n || grid[x][i] == n){
            return 0;
        }
    }
    
    //checking if the number already exists in the 3x3 box
    int row = (x/3)*3;
    int col = (y/3)*3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[row+i][col+j] == n){
                return 0;
            }
        }
    }
    
    //if the number can be placed at position (x,y)
    return 1;
}

//recursive function to solve the sudoku
int solve(int x, int y)
{
    //when x=8 and y=9 that is the end of grid, returns 1 since sudoku is solved
    if(x==8 && y==9){
        return 1;
    }
    
    //when y reaches 9, go to next row
    if(y==9){
        x++;
        y=0;
    }
    
    //check if the cell already has a number, then move to next cell
    if(grid[x][y] != 0){
        return solve(x,y+1);
    }
    
    //try placing numbers from 1 to 9
    for(int i=1; i<=9; i++){
        if(can_place(x,y,i)){
            grid[x][y] = i;
            if(solve(x,y+1)){
                return 1;
            }
            grid[x][y] = 0; //backtracking
        }
    }
    
    return 0; //if the sudoku cannot be solved
}

int main()
{
    printf("Sudoku Solver in C\n");
    
    read_sudoku();
    
    print_sudoku();
    
    if(solve(0,0)){
        printf("\nSolution:\n");
        print_sudoku();
    }
    else{
        printf("\nSorry, The sudoku cannot be solved\n");
    }
    
    return 0;
}