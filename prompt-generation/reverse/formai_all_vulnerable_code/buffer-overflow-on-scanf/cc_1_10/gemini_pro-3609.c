//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: irregular
#include <stdio.h>

// Define the table size
#define TABLE_SIZE 5

// Define the table of contents
char table[TABLE_SIZE][TABLE_SIZE] = {
  {'A', 'B', 'C', 'D', 'E'},
  {'F', 'G', 'H', 'I', 'J'},
  {'K', 'L', 'M', 'N', 'O'},
  {'P', 'Q', 'R', 'S', 'T'},
  {'U', 'V', 'W', 'X', 'Y'}
};

// Define the player's position
int player_position[2] = {0, 0};

// Define the game loop
int game_loop() {
  // Get the player's input
  char input;
  printf("Enter a move (w, a, s, d): ");
  scanf(" %c", &input);

  // Update the player's position
  switch (input) {
    case 'w':
      player_position[0] -= 1;
      break;
    case 'a':
      player_position[1] -= 1;
      break;
    case 's':
      player_position[0] += 1;
      break;
    case 'd':
      player_position[1] += 1;
      break;
  }

  // Check if the player has won
  if (player_position[0] == 0 && player_position[1] == 4) {
    printf("You win!\n");
    return 1;
  }

  // Check if the player has lost
  if (player_position[0] < 0 || player_position[0] >= TABLE_SIZE ||
      player_position[1] < 0 || player_position[1] >= TABLE_SIZE) {
    printf("You lose!\n");
    return 1;
  }

  // Draw the table
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      if (i == player_position[0] && j == player_position[1]) {
        printf("X ");
      } else {
        printf("%c ", table[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}

int main() {
  // Draw the table
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("%c ", table[i][j]);
    }
    printf("\n");
  }

  // Start the game loop
  while (!game_loop());

  return 0;
}