//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>

// Global variables
int player1_score = 0;
int player2_score = 0;
int current_player = 1;
int table[6][6];

// Function to display the table
void display_table() {
  printf("   1 2 3 4 5 6\n");
  for (int i = 0; i < 6; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < 6; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
}

// Function to get the next move
int get_next_move() {
  int move;
  printf("Player %d, enter your move (1-6): ", current_player);
  scanf("%d", &move);
  return move;
}

// Function to check if the move is valid
int is_valid_move(int move) {
  if (move < 1 || move > 6) {
    return 0;
  }
  if (table[move - 1][current_player - 1] == 1) {
    return 0;
  }
  return 1;
}

// Function to make the move
void make_move(int move) {
  table[move - 1][current_player - 1] = 1;
}

// Function to check if the game is over
int is_game_over() {
  // Check if all the squares are filled
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (table[i][j] == 0) {
        return 0;
      }
    }
  }

  // Check if either player has won
  for (int i = 0; i < 6; i++) {
    // Check rows
    if (table[i][0] == 1 && table[i][1] == 1 && table[i][2] == 1 && table[i][3] == 1 && table[i][4] == 1 && table[i][5] == 1) {
      return 1;
    }
    // Check columns
    if (table[0][i] == 1 && table[1][i] == 1 && table[2][i] == 1 && table[3][i] == 1 && table[4][i] == 1 && table[5][i] == 1) {
      return 1;
    }
  }

  // Check diagonals
  if (table[0][0] == 1 && table[1][1] == 1 && table[2][2] == 1 && table[3][3] == 1 && table[4][4] == 1 && table[5][5] == 1) {
    return 1;
  }
  if (table[0][5] == 1 && table[1][4] == 1 && table[2][3] == 1 && table[3][2] == 1 && table[4][1] == 1 && table[5][0] == 1) {
    return 1;
  }

  // The game is not over
  return 0;
}

int main() {
  // Initialize the table
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      table[i][j] = 0;
    }
  }

  // Game loop
  while (!is_game_over()) {
    // Display the table
    display_table();

    // Get the next move
    int move = get_next_move();

    // Check if the move is valid
    while (!is_valid_move(move)) {
      printf("Invalid move. Please try again.\n");
      move = get_next_move();
    }

    // Make the move
    make_move(move);

    // Switch players
    current_player = 3 - current_player;
  }

  // Display the table
  display_table();

  // Announce the winner
  if (player1_score > player2_score) {
    printf("Player 1 wins!\n");
  } else if (player1_score < player2_score) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }

  return 0;
}