//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10

// The table
char table[TABLE_SIZE][TABLE_SIZE];

// The player's position
int player_x, player_y;

// The goal position
int goal_x, goal_y;

// The number of moves
int moves;

// The game state
enum game_state {
  PLAYING,
  WON,
  LOST
};

// Initialize the table
void init_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = '.';
    }
  }
}

// Place the player and the goal on the table
void place_player_and_goal() {
  // Place the player
  player_x = rand() % TABLE_SIZE;
  player_y = rand() % TABLE_SIZE;
  table[player_x][player_y] = 'P';

  // Place the goal
  goal_x = rand() % TABLE_SIZE;
  goal_y = rand() % TABLE_SIZE;
  table[goal_x][goal_y] = 'G';
}

// Print the table
void print_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("%c", table[i][j]);
    }
    printf("\n");
  }
}

// Get the player's move
char get_move() {
  char move;
  printf("Enter your move (w, a, s, d): ");
  scanf(" %c", &move);
  return move;
}

// Move the player
void move_player(char move) {
  switch (move) {
    case 'w':
      if (player_x > 0) {
        table[player_x][player_y] = '.';
        player_x--;
        table[player_x][player_y] = 'P';
      }
      break;
    case 'a':
      if (player_y > 0) {
        table[player_x][player_y] = '.';
        player_y--;
        table[player_x][player_y] = 'P';
      }
      break;
    case 's':
      if (player_x < TABLE_SIZE - 1) {
        table[player_x][player_y] = '.';
        player_x++;
        table[player_x][player_y] = 'P';
      }
      break;
    case 'd':
      if (player_y < TABLE_SIZE - 1) {
        table[player_x][player_y] = '.';
        player_y++;
        table[player_x][player_y] = 'P';
      }
      break;
  }
}

// Check if the player has won
int check_win() {
  return player_x == goal_x && player_y == goal_y;
}

// Check if the player has lost
int check_lose() {
  return moves >= 100;
}

// Play the game
void play_game() {
  // Initialize the table
  init_table();

  // Place the player and the goal on the table
  place_player_and_goal();

  // Print the table
  print_table();

  // Get the player's move
  char move = get_move();

  // Move the player
  move_player(move);

  // Increment the number of moves
  moves++;

  // Check if the player has won
  if (check_win()) {
    printf("You won!\n");
    return;
  }

  // Check if the player has lost
  if (check_lose()) {
    printf("You lost!\n");
    return;
  }

  // Play the game again
  play_game();
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}