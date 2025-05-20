//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

// Global variables to track the game state
int board[BOARD_SIZE][BOARD_SIZE];
int player_x, player_y;
int num_treasures;
int num_traps;

// Function to initialize the game
void initialize_game() {
  // Initialize the board with empty cells
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }

  // Place the player at the starting position
  player_x = 0;
  player_y = 0;

  // Place treasures and traps randomly on the board
  srand(time(NULL));
  num_treasures = rand() % 10 + 1;
  num_traps = rand() % 5 + 1;
  for (int i = 0; i < num_treasures; i++) {
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    board[x][y] = 1; // Treasure
  }
  for (int i = 0; i < num_traps; i++) {
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    board[x][y] = -1; // Trap
  }
}

// Function to print the game board
void print_board() {
  printf("-----------------------------------------\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("| ");
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (player_x == i && player_y == j) {
        printf("P ");
      } else if (board[i][j] == 1) {
        printf("T ");
      } else if (board[i][j] == -1) {
        printf("X ");
      } else {
        printf("  ");
      }
    }
    printf("|\n");
  }
  printf("-----------------------------------------\n");
}

// Function to get the player's move
int get_player_move() {
  int move;
  printf("Enter your move (1: up, 2: down, 3: left, 4: right): ");
  scanf("%d", &move);
  return move;
}

// Function to move the player
void move_player(int move) {
  switch (move) {
    case 1: // Up
      if (player_x > 0) {
        player_x--;
      }
      break;
    case 2: // Down
      if (player_x < BOARD_SIZE - 1) {
        player_x++;
      }
      break;
    case 3: // Left
      if (player_y > 0) {
        player_y--;
      }
      break;
    case 4: // Right
      if (player_y < BOARD_SIZE - 1) {
        player_y++;
      }
      break;
  }
}

// Function to check if the player has won
int check_win() {
  return num_treasures == 0;
}

// Function to check if the player has lost
int check_lose() {
  return board[player_x][player_y] == -1;
}

// Main function
int main() {
  int move;

  // Initialize the game
  initialize_game();

  // Print the initial board
  print_board();

  // Loop until the player wins or loses
  while (!check_win() && !check_lose()) {
    // Get the player's move
    move = get_player_move();

    // Move the player
    move_player(move);

    // Print the updated board
    print_board();

    // Check if the player has won or lost
    if (check_win()) {
      printf("Congratulations! You have found all the treasures!\n");
    } else if (check_lose()) {
      printf("Oh no! You have stepped on a trap!\n");
    }
  }

  return 0;
}