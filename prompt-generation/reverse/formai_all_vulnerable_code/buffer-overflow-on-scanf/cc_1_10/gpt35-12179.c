//FormAI DATASET v1.0 Category: Sudoku solver ; Style: active
#include<stdio.h>

int checkValid(int sudoku[9][9],int row,int col,int num)
{
  int boxrow=row-(row%3),boxcol=col-(col%3); //get top left corner of the box
  int i,j;
  for(i=0;i<9;i++)
  {
    if(sudoku[row][i]==num) //check if num exists in the same row
      return 0;
    if(sudoku[i][col]==num) //check if num exists in the same column
      return 0;
    if(sudoku[boxrow+(i%3)][boxcol+(i/3)]==num) //check if num exists in the same 3x3 box
      return 0;
  }
  return 1;
}

int sudokuSolver(int sudoku[9][9],int row,int col)
{
  if(row==8 && col==9) //Reached end of grid
    return 1;
  if(col==9) //Reached end of column, move to next row
  {
    row++;
    col=0;
  }
  if(sudoku[row][col]!=0) //skip filled cells
    return sudokuSolver(sudoku,row,col+1);
  int num;
  for(num=1;num<=9;num++) //try all numbers
  {
    if(checkValid(sudoku,row,col,num)==1) //if valid, then assign the number
    {
      sudoku[row][col]=num;
      if(sudokuSolver(sudoku,row,col+1)==1) //recursively solve the grid
        return 1;
    }
    sudoku[row][col]=0; //backtrack if not solvable with current num
  }
  return 0;
}

int main()
{
  int sudoku[9][9],i,j;
  printf("Enter the Sudoku to solve (enter 0 for empty cells):\n");
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      scanf("%d",&sudoku[i][j]);
    }
  }
  if(sudokuSolver(sudoku,0,0)==1)
  {
    printf("The solved Sudoku is:\n");
    for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
      {
        printf("%d ",sudoku[i][j]);
      }
      printf("\n");
    }
  }
  else
    printf("This Sudoku can't be solved.");
  return 0;
}