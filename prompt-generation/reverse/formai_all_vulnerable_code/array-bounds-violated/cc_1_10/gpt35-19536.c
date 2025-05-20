//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the dimensions of the space grid
#define SPACE_GRID_WIDTH 10
#define SPACE_GRID_HEIGHT 10

// Initialize the space grid
char space_grid[SPACE_GRID_WIDTH][SPACE_GRID_HEIGHT];

// Define constants for the player position
#define PLAYER_START_X 5
#define PLAYER_START_Y 5

// Initialize player position
int player_x = PLAYER_START_X;
int player_y = PLAYER_START_Y;

// Define constants for the obstacles
#define NUM_OBSTACLES 10

// Create an array to hold the obstacle coordinates
int obstacles[NUM_OBSTACLES][2] = {
  {1, 1},
  {2, 3},
  {3, 5},
  {4, 7},
  {5, 2},
  {6, 4},
  {7, 6},
  {8, 8},
  {9, 1},
  {10, 3}
};

// Define function to initialize the space grid with empty spaces
void init_space_grid() {
  for (int i = 0; i < SPACE_GRID_WIDTH; i++) {
    for (int j = 0; j < SPACE_GRID_HEIGHT; j++) {
      space_grid[i][j] = ' ';
    }
  }
}

// Define function to initialize the obstacles
void init_obstacles() {
  for (int i = 0; i < NUM_OBSTACLES; i++) {
    int x = obstacles[i][0];
    int y = obstacles[i][1];
    space_grid[x][y] = 'O';
  }
}

// Define function to draw the space grid
void draw_space_grid() {
  printf("\n");
  for (int i = 0; i < SPACE_GRID_HEIGHT; i++) {
    for (int j = 0; j < SPACE_GRID_WIDTH; j++) {
      printf("%c ", space_grid[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

// Define function to move the player
void move_player(char direction) {
  switch(direction) {
    case 'w':
      if (player_y > 0) {
        player_y--;
      }
      break;
    case 'a':
      if (player_x > 0) {
        player_x--;
      }
      break;
    case 's':
      if (player_y < SPACE_GRID_HEIGHT - 1) {
        player_y++;
      }
      break;
    case 'd':
      if (player_x < SPACE_GRID_WIDTH - 1) {
        player_x++;
      }
      break;
  }
}

int main() {

  init_space_grid();
  init_obstacles();

  // Draw the initial space grid
  draw_space_grid();

  while (1) {
    // Get user input for direction
    printf("Enter direction (w,a,s,d): ");
    char direction;
    scanf(" %c", &direction);

    // Move the player in the specified direction
    move_player(direction);

    // Check if the player has collided with an obstacle
    for (int i = 0; i < NUM_OBSTACLES; i++) {
      int x = obstacles[i][0];
      int y = obstacles[i][1];
      if (player_x == x && player_y == y) {
        printf("Game over! You collided with an obstacle.\n");
        return 0;
      }
    }

    // Update the space grid with the new player position
    space_grid[player_x][player_y] = 'X';

    // Draw the updated space grid
    draw_space_grid();

    // Check if the player has reached the end
    if (player_x == SPACE_GRID_WIDTH - 1 && player_y == SPACE_GRID_HEIGHT - 1) {
      printf("Congratulations, you have reached the end!\n");
      return 0;
    }
  }

  return 0;
}