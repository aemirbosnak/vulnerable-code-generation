//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the game map
char map[10][10] = {
  {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
  {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

// Defining the player's position
int player_x = 1;
int player_y = 1;

// Defining the goal's position
int goal_x = 8;
int goal_y = 8;

// Function to print the game map
void print_map() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

// Function to check if the player has reached the goal
int check_win() {
  if (player_x == goal_x && player_y == goal_y) {
    return 1;
  } else {
    return 0;
  }
}

// Function to move the player
void move_player(char direction) {
  switch (direction) {
    case 'w':
      if (map[player_x - 1][player_y] != '*') {
        player_x--;
      }
      break;
    case 'a':
      if (map[player_x][player_y - 1] != '*') {
        player_y--;
      }
      break;
    case 's':
      if (map[player_x + 1][player_y] != '*') {
        player_x++;
      }
      break;
    case 'd':
      if (map[player_x][player_y + 1] != '*') {
        player_y++;
      }
      break;
  }
}

// Main game loop
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Print a welcome message
  printf("Welcome to the Maze Adventure!\n");
  printf("Your goal is to reach the exit at the bottom right corner of the maze.\n");
  printf("Use the 'w', 'a', 's', and 'd' keys to move up, left, down, and right, respectively.\n");
  printf("Good luck!\n\n");

  // Print the initial game map
  print_map();

  // Game loop
  while (!check_win()) {
    // Get the player's input
    char direction;
    printf("Enter a direction (w, a, s, d): ");
    scanf(" %c", &direction);

    // Move the player
    move_player(direction);

    // Print the updated game map
    print_map();
  }

  // Print a victory message
  printf("Congratulations! You reached the exit!\n");

  return 0;
}