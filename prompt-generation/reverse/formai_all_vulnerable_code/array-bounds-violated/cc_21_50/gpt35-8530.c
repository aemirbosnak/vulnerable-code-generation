//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>

int main() {
  // The game board is represented as a 2D array of chars
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  // Print the initial game board
  printf("Welcome to Tic Tac Toe!\n");
  printf("--------------\n");
  for (int i = 0; i < 3; i++) {
    printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
    printf("--------------\n");
  }

  // Loop through the game until there is a winner or a tie
  int win = 0;
  int turn = 1;
  while (!win) {
    int row, col;
    if (turn == 1) {
      // Player 1's turn
      printf("Player 1, enter row and column (in that order): ");
      scanf("%d %d", &row, &col);

      // Check if the move is valid and update the board
      if (board[row][col] == ' ') {
        board[row][col] = 'X';
        turn = 2; // Switch to player 2's turn
      } else {
        printf("That space is taken. Try again.\n");
      }
    } else {
      // Player 2's turn
      printf("Player 2's turn.\n");

      // AI move
      int move_made = 0;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (board[i][j] == ' ') {
            board[i][j] = 'O';
            move_made = 1;
            break;
          }
        }
        if (move_made) {
          break;
        }
      }
      
      turn = 1; // Switch to player 1's turn
    }

    // Print the updated game board
    printf("--------------\n");
    for (int i = 0; i < 3; i++) {
      printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
      printf("--------------\n");
    }

    // Check if there is a winner
    for (int i = 0; i < 3; i++) {
      if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
        printf("%c wins!\n", board[i][0]);
        win = 1;
        break;
      } else if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
        printf("%c wins!\n", board[0][i]);
        win = 1;
        break;
      }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
      printf("%c wins!\n", board[0][0]);
      win = 1;
    } else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
      printf("%c wins!\n", board[0][2]);
      win = 1;
    }

    // Check if there is a tie
    int empty_spaces = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == ' ') {
          empty_spaces = 1;
          break;
        }
      }
      if (empty_spaces) {
        break;
      }
    }
    if (!empty_spaces && !win) {
      printf("It's a tie!\n");
      break;
    }
  }

  return 0;
}