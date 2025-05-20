//GEMINI-pro DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

// The player's position
int x, y;

// The map
char map[WIDTH][HEIGHT];

// The goal
int goal_x, goal_y;

// The number of moves the player has made
int moves;

// The time the player started playing
time_t start_time;

// Has the player won?
int won;

// Draw the map
void draw_map() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i == y && j == x) {
        printf("P");
      } else if (i == goal_y && j == goal_x) {
        printf("G");
      } else if (map[i][j] == '#') {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Check if the player has won
int check_win() {
  if (x == goal_x && y == goal_y) {
    return 1;
  } else {
    return 0;
  }
}

// Get the player's input
void get_input() {
  char input;
  scanf(" %c", &input);

  switch (input) {
    case 'w':
      if (map[y-1][x] != '#') {
        y--;
      }
      break;
    case 'a':
      if (map[y][x-1] != '#') {
        x--;
      }
      break;
    case 's':
      if (map[y+1][x] != '#') {
        y++;
      }
      break;
    case 'd':
      if (map[y][x+1] != '#') {
        x++;
      }
      break;
    case 'q':
      exit(0);
      break;
  }
}

// Main game loop
int main() {
  // Initialize the player's position
  x = 1;
  y = 1;

  // Initialize the map
  for (int i = 0; i < HEIGHT; i++) {
    if (i == 0 || i == HEIGHT - 1)
      for (int j = 0; j < WIDTH; j++)
        map[i][j] = '#';
    else
      for (int j = 0; j < WIDTH; j++)
        if (j == 0 || j == WIDTH - 1)
          map[i][j] = '#';
        else if (i == (HEIGHT - 1)/2 && j == (WIDTH - 1)/2)
          map[i][j] = '!';
        else if (rand()%3 == 0)
          map[i][j] = '#';
        else
          map[i][j] = ' ';
  }

  // Initialize the goal
  goal_x = WIDTH - 2;
  goal_y = HEIGHT - 2;

  // Initialize the number of moves
  moves = 0;

  // Initialize the time the player started playing
  start_time = time(NULL);

  // Main game loop
  do {
    // Draw the map
    draw_map();

    // Get the player's input
    get_input();

    // Check if the player has won
    won = check_win();

    // Increment the number of moves
    moves++;
  } while (!won);

  // Print the victory message
  printf("You won in %d moves!\n", moves);

  // Calculate the time it took the player to finish the game
  time_t end_time = time(NULL);
  int time_taken = end_time - start_time;

  // Print the time it took the player to finish the game
  printf("It took you %d seconds to finish the game.\n", time_taken);

  return 0;
}