//FormAI DATASET v1.0 Category: Game ; Style: all-encompassing
#include <stdio.h>

// Declare functions
int random(int min, int max);
void init_grid(char grid[][3]);
void print_grid(char grid[][3]);
char check_winner(char grid[][3]);

// Main function
int main() {
  // Initialize the playing grid
  char grid[3][3];
  init_grid(grid);

  // Player 1 starts the game
  int turn_num = 1;
  char player_marker = 'X';

  // Game loop
  while (1) {
    // Print the grid
    printf("\n---------------------------------\n");
    printf("TURN %d: it is Player %d's turn\n", turn_num, (turn_num % 2) + 1);
    printf("Player 1: X, Player 2: O\n");
    print_grid(grid);

    // Get player input
    int row, col;
    do {
      printf("\nEnter the row and column of where you want to place your marker (e.g. 1 1): ");
      scanf("%d %d", &row, &col);
    } while (row < 1 || row > 3 || col < 1 || col > 3 || grid[row-1][col-1] != '-');

    // Place player marker on grid
    grid[row-1][col-1] = player_marker;

    // Check for winner or tie
    char winner = check_winner(grid);
    if (winner != '-') {
      printf("\n---------------------------------\n");
      printf("Congratulations! Player %c has won!\n", winner);
      break;
    } else if (turn_num == 9) {
      printf("\n---------------------------------\n");
      printf("It's a tie!\n");
      break;
    }

    // Switch to next player
    turn_num++;
    if (player_marker == 'X') {
      player_marker = 'O';
    } else {
      player_marker = 'X';
    }
  }

  return 0;
}

// Helper functions

int random(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

void init_grid(char grid[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid[i][j] = '-';
    }
  }
}

void print_grid(char grid[][3]) {
  printf("\n  1 2 3\n");
  for (int i = 0; i < 3; i++) {
    printf("%d ", i+1);
    for (int j = 0; j < 3; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
}

char check_winner(char grid[][3]) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '-') {
      return grid[i][0];
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++) {
    if (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j] && grid[0][j] != '-') {
      return grid[0][j];
    }
  }

  // Check diagonals
  if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '-') {
    return grid[0][0];
  }
  if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '-') {
    return grid[0][2];
  }

  // No winner yet
  return '-';
}