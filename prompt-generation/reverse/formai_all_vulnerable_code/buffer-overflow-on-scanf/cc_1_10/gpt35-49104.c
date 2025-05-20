//FormAI DATASET v1.0 Category: Sudoku solver ; Style: grateful
#include<stdio.h>

#define N 9 //size of the Sudoku puzzle

void print(int sudoku[N][N]){ //function to print the Sudoku grid
    printf("---------------------\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",sudoku[i][j]);
            if((j+1)%3 == 0){ //prints vertical divider
                printf("| ");
            }
        }
        printf("\n");
        if((i+1)%3 == 0){ //prints horizontal divider
            printf("---------------------\n");
        }
    }
}

int find_empty(int sudoku[N][N],int *row,int *col){ //function to find empty cells in Sudoku grid
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(sudoku[i][j]==0){
                *row=i;
                *col=j;
                return 1;
            }
        }
    }
    return 0;
}

int used_row(int sudoku[N][N],int row,int num){ //function to check if row is used
    for(int i=0;i<N;i++){
        if(sudoku[row][i]==num){
            return 1;
        }
    }
    return 0;
}

int used_col(int sudoku[N][N],int col,int num){ //function to check if column is used
    for(int i=0;i<N;i++){
        if(sudoku[i][col]==num){
            return 1;
        }
    }
    return 0;
}

int used_box(int sudoku[N][N],int row,int col,int num){ //function to check if box is used
    int row_start = row - row%3;
    int col_start = col - col%3;

    for(int i=row_start;i<row_start+3;i++){
        for(int j=col_start;j<col_start+3;j++){
            if(sudoku[i][j]==num){
                return 1;
            }
        }
    }
    return 0;
}

int solve_sudoku(int sudoku[N][N]){ //function to solve Sudoku grid
    int row,col;
    if(!find_empty(sudoku,&row,&col)){ //base case
        return 1;
    }
    for(int i=1;i<=9;i++){ //checking 1-9 for empty cell
        if(!used_row(sudoku,row,i) && !used_col(sudoku,col,i) && !used_box(sudoku,row,col,i)){
            sudoku[row][col]=i;
            if(solve_sudoku(sudoku)){ //recursive call
                return 1;
            }
            sudoku[row][col]=0; //backtracking
        }
    }
    return 0;
}

int main(){
    int sudoku[N][N];

    //input Sudoku grid
    printf("Enter your Sudoku grid (0 for empty cells):\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&sudoku[i][j]);
        }
    }

    //solving Sudoku grid if possible
    if(solve_sudoku(sudoku)){
        printf("\nSudoku Solution:\n");
        print(sudoku);
    }
    else{
        printf("\nNo solution exists.\n");
    }

    return 0;
}