//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void main() {
  int x = 0, y = 0, z = 0, score = 0, life = 3;
  char board[20] = "______________________";
  board[x] = 'O';
  board[y] = 'O';

  printf("Welcome to the Game of Life!\n");
  printf("------------------------\n");
  printf("%s\n", board);

  // Game loop
  while (life > 0) {
    printf("Enter move (x, y): ");
    scanf("%d %d", &x, &y);

    // Check if move is valid
    if (x < 0 || x >= 4 || y < 0 || y >= 5) {
      printf("Invalid move!\n");
      continue;
    }

    // Check if space is empty
    if (board[x * 5 + y] != '_') {
      printf("Space already occupied!\n");
      continue;
    }

    // Make move
    board[x * 5 + y] = 'O';

    // Check if player won
    if (board[0] == 'O' || board[1] == 'O' || board[2] == 'O' || board[3] == 'O' || board[4] == 'O') {
      printf("You won!\n");
      score++;
      life = 0;
    } else if (board[10] == 'O' || board[11] == 'O' || board[12] == 'O' || board[13] == 'O' || board[14] == 'O') {
      printf("You won!\n");
      score++;
      life = 0;
    } else if (board[15] == 'O' || board[16] == 'O' || board[17] == 'O' || board[18] == 'O' || board[19] == 'O') {
      printf("You won!\n");
      score++;
      life = 0;
    } else if (board[x] == 'O' && board[y] == 'O') {
      printf("You won!\n");
      score++;
      life = 0;
    } else {
      // Next turn
      board[x] = 'O';
      printf("%s\n", board);
    }
  }

  // Game over
  printf("Game over. Your score is: %d", score);
  printf("\nThank you for playing!\n");

  return;
}