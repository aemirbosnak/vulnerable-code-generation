//FormAI DATASET v1.0 Category: Sudoku solver ; Style: creative
#include <stdio.h>

int board[9][9]; // 9x9 Sudoku board matrix

//Function to accept input from the users
void accept_input() {
   printf("Enter Sudoku Puzzle:\n");
   for(int i=0;i<=8;i++) {
      for(int j=0;j<=8;j++) {
         scanf("%d", &board[i][j]);
      }
   }
}

//Function that returns a boolean value based on whether a number is valid in a given location or not
int can_place(int row, int col, int num) {
   for (int i = 0; i < 9; i++) {
      if (board[row][i] == num) return 0;
      if (board[i][col] == num) return 0;
      if (board[3 * (row / 3) + i / 3][3 * (col / 3) +  i % 3] == num) return 0;
   }
   return 1;
}

//Function that checks whether the given Sudoku puzzle has been solved or not
int is_solved() {
   for(int i=0; i<=8; i++) {
      for(int j=0; j<=8; j++) {
         if (board[i][j] == 0) {
            return 0; //If there are any empty cells, the puzzle has not been fully solved
         }
      }
   }
   return 1;
}

//Function that solves the Sudoku puzzle using the backtracking algorithm
int solve_puzzle() {
   int row=0, col=0;
   //finding empty cell to fill with candidates
   for(row=0; row<=8; row++) {
      for(col=0; col<=8; col++) {
         if(board[row][col] == 0) {
            goto next_step;
         }
      }
   }
   //if there is no empty cell, return true
   return 1;
   next_step:

   for(int number=1; number<=9; number++) {
      if(can_place(row, col, number)) {
         board[row][col] = number;
         if(solve_puzzle()) { //recursively repeating same steps until we get to the end
            return 1;
         }
         board[row][col] = 0; //backtracking and resetting the cell value to zero
      }
   }
   return 0; //if no numbers between 1-9 work in a cell
}

//Function to print the solved Sudoku puzzle
void print_solution() {
   printf("\nSolved Puzzle:\n");
   for(int i=0;i<=8;i++) {
      for(int j=0;j<=8;j++) {
         printf("%d ",board[i][j]);
      }
      printf("\n");
   }
}

//Main Function
int main() {
   accept_input();
   if(is_solved() || solve_puzzle()) {
      print_solution();
   }
   else {
      printf("Invalid Puzzle. Please enter a valid Sudoku Puzzle!");
   }
   return 0;
}