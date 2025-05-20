//FormAI DATASET v1.0 Category: Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

// Define the game board as a 2D array of characters
char game_board[GRID_SIZE][GRID_SIZE];

// Define the location of the player as two integers
int player_x, player_y;

// Define the location of the treasure as two integers
int treasure_x, treasure_y;

// Function to initialize the game board with blank spaces
void init_game_board() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      game_board[i][j] = ' ';
    }
  }
}

// Function to randomly place the player and the treasure on the game board
void place_player_and_treasure() {

  // Use the time function to seed the random number generator
  srand(time(NULL));

  // Generate random x and y coordinates for the player
  player_x = rand() % GRID_SIZE;
  player_y = rand() % GRID_SIZE;

  // Generate random x and y coordinates for the treasure
  treasure_x = rand() % GRID_SIZE;
  treasure_y = rand() % GRID_SIZE;

  // Place the player and the treasure on the game board
  game_board[player_y][player_x] = '@';
  game_board[treasure_y][treasure_x] = '$';

}

// Function to print the game board
void print_game_board() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%c ", game_board[i][j]);
    }
    printf("\n");
  }
}

// Function to update the game board with the player's movement
void update_game_board(char direction) {
  // Set the player's current position to a blank space
  game_board[player_y][player_x] = ' ';

  // Update the player's position based on the direction input
  if (direction == 'w') {
    player_y--;
  }
  else if (direction == 'a') {
    player_x--;
  }
  else if (direction == 's') {
    player_y++;
  }
  else if (direction == 'd') {
    player_x++;
  }
  else {
    // Invalid input, keep the player in the same position
  }

  // Check if the player has reached the treasure
  if (player_x == treasure_x && player_y == treasure_y) {
    printf("You found the treasure!\n");
    exit(0);
  }

  // Set the player's new position on the game board
  game_board[player_y][player_x] = '@';
}

int main() {
  char direction;

  // Initialize the game board
  init_game_board();

  // Place the player and the treasure on the game board
  place_player_and_treasure();

  // Loop until the player finds the treasure or quits the game
  while (1) {
    // Print the game board
    print_game_board();

    // Prompt the player for input and update the game board
    printf("Enter a direction (w,a,s,d) or q to quit: ");
    scanf(" %c", &direction);

    if (direction == 'q') {
      exit(0);
    }
    else {
      update_game_board(direction);
    }
  }

  return 0;
}