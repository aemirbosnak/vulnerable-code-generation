//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the table
  int table[TABLE_SIZE][TABLE_SIZE];

  // Initialize the table
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = 0;
    }
  }

  // Place the players on the table
  int player1_x = 0;
  int player1_y = 0;
  int player2_x = TABLE_SIZE - 1;
  int player2_y = TABLE_SIZE - 1;

  // Place the obstacles on the table
  int num_obstacles = 10;
  for (int i = 0; i < num_obstacles; i++) {
    int obstacle_x = rand() % TABLE_SIZE;
    int obstacle_y = rand() % TABLE_SIZE;
    table[obstacle_x][obstacle_y] = 1;
  }

  // Print the table
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      if (table[i][j] == 0) {
        printf(" ");
      } else if (table[i][j] == 1) {
        printf("X");
      } else if (table[i][j] == 2) {
        printf("1");
      } else if (table[i][j] == 3) {
        printf("2");
      }
    }
    printf("\n");
  }

  // Get the player's moves
  int player1_move_x;
  int player1_move_y;
  int player2_move_x;
  int player2_move_y;

  while (1) {
    // Get player 1's move
    printf("Player 1, enter your move (x, y): ");
    scanf("%d %d", &player1_move_x, &player1_move_y);

    // Check if the move is valid
    if (player1_move_x < 0 || player1_move_x >= TABLE_SIZE ||
        player1_move_y < 0 || player1_move_y >= TABLE_SIZE ||
        table[player1_move_x][player1_move_y] == 1) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Update the table
    table[player1_x][player1_y] = 0;
    table[player1_move_x][player1_move_y] = 2;

    // Check if player 1 has won
    if (player1_move_x == player2_x && player1_move_y == player2_y) {
      printf("Player 1 wins!\n");
      break;
    }

    // Get player 2's move
    printf("Player 2, enter your move (x, y): ");
    scanf("%d %d", &player2_move_x, &player2_move_y);

    // Check if the move is valid
    if (player2_move_x < 0 || player2_move_x >= TABLE_SIZE ||
        player2_move_y < 0 || player2_move_y >= TABLE_SIZE ||
        table[player2_move_x][player2_move_y] == 1) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Update the table
    table[player2_x][player2_y] = 0;
    table[player2_move_x][player2_move_y] = 3;

    // Check if player 2 has won
    if (player2_move_x == player1_x && player2_move_y == player1_y) {
      printf("Player 2 wins!\n");
      break;
    }
  }

  return 0;
}