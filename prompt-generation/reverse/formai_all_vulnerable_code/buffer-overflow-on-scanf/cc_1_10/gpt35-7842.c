//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>

char board[3][3]; // 3x3 Tic Tac Toe board
char computer = 'O'; // The computer will play with the 'O' symbol
char human = 'X'; // The human player will play with the 'X' symbol

void init_board() {
   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           board[i][j] = ' ';
       }
   }
}

void print_board() {
   printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
   printf("-----------\n");
   printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
   printf("-----------\n");
   printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int has_won(char player) {
   for (int i = 0; i < 3; ++i) {
       if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
           return 1;
       }
   }

   for (int j = 0; j < 3; ++j) {
       if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
           return 1;
       }
   }

   if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
       return 1;
   }

   if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
       return 1;
   }

   return 0;
}

int is_tie() {
   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           if (board[i][j] == ' ') {
               return 0;
           }
       }
   }

   return 1;
}

void computer_move() {
   int row, col;

   // Random move strategy, this is just an example
   do {
       row = rand() % 3;
       col = rand() % 3;
   } while (board[row][col] != ' ');

   board[row][col] = computer;
}

void human_move() {
   int row, col;

   do {
       printf("Enter row (0-2): ");
       scanf("%d", &row);

       printf("Enter column (0-2): ");
       scanf("%d", &col);
   } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

   board[row][col] = human;
}

int main() {
   printf("Welcome to Tic Tac Toe!\n");

   init_board();

   while (1) {
       print_board();

       human_move();

       if (has_won(human)) {
           printf("You won! Congrats!\n");
           break;
       }

       if (is_tie()) {
           printf("It's a tie!\n");
           break;
       }

       computer_move();

       if (has_won(computer)) {
           printf("Computer won! Try again!\n");
           break;
       }

       if (is_tie()) {
           printf("It's a tie!\n");
           break;
       }
   }

   return 0;
}