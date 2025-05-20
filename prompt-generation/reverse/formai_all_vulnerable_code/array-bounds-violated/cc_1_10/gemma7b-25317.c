//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>

int main() {
  // Game Setup
  int board[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  // Player Setup
  int player_pos = 0;
  int player_direction = 1;

  // Game Loop
  while (!board[player_pos][player_pos]) {
    // Display Board
    for (int r = 0; r < 6; r++) {
      for (int c = 0; c < 6; c++) {
        printf("%d ", board[r][c]);
      }
      printf("\n");
    }

    // Move Player
    switch (player_direction) {
      case 1:
        board[player_pos][player_pos] = 1;
        player_pos++;
        break;
      case 2:
        board[player_pos][player_pos] = 1;
        player_pos--;
        break;
      case 3:
        board[player_pos][player_pos] = 1;
        player_pos++;
        player_direction = -1;
        break;
      case 4:
        board[player_pos][player_pos] = 1;
        player_pos--;
        player_direction = -1;
        break;
    }

    // Check if Game is Over
    if (board[player_pos][player_pos] == 2) {
      printf("Game Over!\n");
      break;
    }

    // Pause
    printf("Press any key to continue...");
    getchar();
  }

  return 0;
}