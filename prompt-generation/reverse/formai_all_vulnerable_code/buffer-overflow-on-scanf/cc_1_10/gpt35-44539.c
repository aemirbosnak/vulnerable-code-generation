//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>

//function prototypes
int check_win(int [][3]);
void print_board(int [][3]);

int main() {
   //initialize board
   int board[3][3] = {{0,0,0},
                   {0,0,0},
                   {0,0,0}};
   //initialize current player and winner
   int player = 1;
   int winner = 0;

   //main game loop
   while (winner == 0) {
      printf("Player %d's turn\n", player);
      print_board(board);
      //get input for row and column
      int row, col;
      printf("Enter row (1-3): ");
      scanf("%d", &row);
      printf("Enter column (1-3): ");
      scanf("%d", &col);
      //validate input
      if (board[row-1][col-1] != 0) {
         printf("Invalid move, try again.\n\n");
         continue;
      }
      //make move
      board[row-1][col-1] = player;
      //check for win
      winner = check_win(board);
      //switch player
      player = (player == 1) ? 2 : 1;
   }
   //print winner
   printf("Player %d has won!\n", winner);

   return 0;
}

//function to check for win
int check_win(int board[][3]) {
   int i, j;
   //check rows
   for (i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
         return board[i][0];
   }
   //check columns
   for (j = 0; j < 3; j++) {
      if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
         return board[0][j];
   }
   //check diagonals
   if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
      return board[0][0];
   if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
      return board[0][2];
   //no winner yet
   return 0;
}

//function to print board
void print_board(int board[][3]) {
   int i, j;
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         printf("%d ", board[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}