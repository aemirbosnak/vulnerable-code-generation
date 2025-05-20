//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_players, num_rounds;
  printf("Welcome to the Bingo Simulator!!\n\n");
  printf("How many players will be playing? ");
  scanf("%d", &num_players);
  printf("How many rounds do you want to play? ");
  scanf("%d", &num_rounds);

  // Creating an array to represent the Bingo board
  int bingo_board[5][5];
  int num_called[76] = {0};
  int i, j, k;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      bingo_board[i][j] = (i * 15) + (rand() % 15) + 1;
    }
  }

  // Printing out the bingo board
  printf("BINGO BOARD:\n");
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("%d\t", bingo_board[i][j]);
    }
    printf("\n");
  }

  // Starting the game
  int game_over = 0;
  int winner[num_players];
  for (i = 0; i < num_players; i++)
    winner[i] = 0;

  int round = 1;
  while (!game_over && round <= num_rounds) {
    printf("\n========== ROUND %d ==========\n", round);
    int num_drawn = 0;
    while (num_drawn < 75 && !game_over) {
      // Generating a random number between 1 and 75 and checking if it has already been called
      int num = rand() % 75 + 1;
      if (num_called[num] == 0) {
        printf("Number drawn: %d\n", num);
        num_called[num] = 1;
        num_drawn++;

        // Checking if any player has won
        for (i = 0; i < num_players; i++) {
          // Checking for a winning row
          for (j = 0; j < 5; j++) {
            int row_win = 1;
            for (k = 0; k < 5; k++) {
              if (bingo_board[j][k] != -1 && bingo_board[j][k] != num_called[bingo_board[j][k]]) {
                row_win = 0;
                break;
              }
            }
            if (row_win) {
              printf("Player %d has won in row %d!\n", i+1, j+1);
              winner[i] = 1;
            }
          }

          // Checking for a winning column
          for (j = 0; j < 5; j++) {
            int col_win = 1;
            for (k = 0; k < 5; k++) {
              if (bingo_board[k][j] != -1 && bingo_board[k][j] != num_called[bingo_board[k][j]]) {
                col_win = 0;
                break;
              }
            }
            if (col_win) {
              printf("Player %d has won in column %d!\n", i+1, j+1);
              winner[i] = 1;
            }
          }

          // Checking for a winning diagonal
          int diag_win = 1;
          for (j = 0; j < 5; j++) {
            if (bingo_board[j][j] != -1 && bingo_board[j][j] != num_called[bingo_board[j][j]]) {
              diag_win = 0;
              break;
            }
          }
          if (diag_win) {
            printf("Player %d has won in diagonal!\n", i+1);
            winner[i] = 1;
          }

          // Checking for a winning reverse diagonal
          diag_win = 1;
          for (j = 0; j < 5; j++) {
            if (bingo_board[j][4-j] != -1 && bingo_board[j][4-j] != num_called[bingo_board[j][4-j]]) {
              diag_win = 0;
              break;
            }
          }
          if (diag_win) {
            printf("Player %d has won in reverse diagonal!\n", i+1);
            winner[i] = 1;
          }

          if (winner[i]) {
            game_over = 1;
            break; // We only need one winner per round
          }
        }
      }
    }
    round++;
  }

  // Declaring the winner
  printf("\n========== GAME OVER ==========\n");
  for (i = 0; i < num_players; i++) {
    if (winner[i]) {
      printf("Player %d is the winner!\n", i+1);
      break; // We only need one winner
    }
  }

  return 0;
}