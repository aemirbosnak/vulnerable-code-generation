//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: retro
#include <stdlib.h>
#include <stdio.h>

#define TABLE_SIZE 10

int main() {
  char table[TABLE_SIZE][TABLE_SIZE];
  int player_x, player_y;
  int exit_x, exit_y;
  int score = 0;

  // Initialize the table
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = '.';
    }
  }

  // Place the player
  player_x = 0;
  player_y = 0;
  table[player_x][player_y] = 'P';

  // Place the exit
  exit_x = TABLE_SIZE - 1;
  exit_y = TABLE_SIZE - 1;
  table[exit_x][exit_y] = 'E';

  // Game loop
  while (player_x != exit_x || player_y != exit_y) {
    // Print the table
    for (int i = 0; i < TABLE_SIZE; i++) {
      for (int j = 0; j < TABLE_SIZE; j++) {
        printf("%c ", table[i][j]);
      }
      printf("\n");
    }

    // Get the player's input
    char input;
    printf("Enter a direction (w, a, s, d): ");
    scanf(" %c", &input);

    // Update the player's position
    switch (input) {
      case 'w':
        player_y--;
        break;
      case 'a':
        player_x--;
        break;
      case 's':
        player_y++;
        break;
      case 'd':
        player_x++;
        break;
    }

    // Check if the player has hit a wall
    if (player_x < 0 || player_x >= TABLE_SIZE || player_y < 0 || player_y >= TABLE_SIZE) {
      printf("You hit a wall!\n");
      player_x = 0;
      player_y = 0;
    }

    // Check if the player has reached the exit
    if (player_x == exit_x && player_y == exit_y) {
      printf("You win!\n");
      break;
    }

    // Increment the score
    score++;
  }

  // Print the final score
  printf("Your score: %d\n", score);

  return 0;
}