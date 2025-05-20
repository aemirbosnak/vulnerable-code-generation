//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the game table
#define TABLE_SIZE 5
char table[TABLE_SIZE][TABLE_SIZE];

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game states
#define GAME_IN_PROGRESS 0
#define PLAYER1_WINS 1
#define PLAYER2_WINS 2
#define TIE 3

// Function to initialize the game table
void init_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = ' ';
    }
  }
}

// Function to print the game table
void print_table() {
  printf("\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("| %c ", table[i][j]);
    }
    printf("|\n");
  }
  printf("\n");
}

// Function to check if a player has won
int check_win(char player) {
  // Check rows
  for (int i = 0; i < TABLE_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < TABLE_SIZE; j++) {
      if (table[i][j] == player) {
        count++;
      }
    }
    if (count == TABLE_SIZE) {
      return player == PLAYER1 ? PLAYER1_WINS : PLAYER2_WINS;
    }
  }

  // Check columns
  for (int j = 0; j < TABLE_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
      if (table[i][j] == player) {
        count++;
      }
    }
    if (count == TABLE_SIZE) {
      return player == PLAYER1 ? PLAYER1_WINS : PLAYER2_WINS;
    }
  }

  // Check diagonals
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i][i] == player) {
      count1++;
    }
    if (table[i][TABLE_SIZE - i - 1] == player) {
      count2++;
    }
  }
  if (count1 == TABLE_SIZE || count2 == TABLE_SIZE) {
    return player == PLAYER1 ? PLAYER1_WINS : PLAYER2_WINS;
  }

  // No winner yet
  return GAME_IN_PROGRESS;
}

// Function to get the next player's move
int get_move(char player) {
  int row, col;
  printf("%c's turn (row, col): ", player);
  scanf("%d %d", &row, &col);
  return (row - 1) * TABLE_SIZE + (col - 1);
}

// Function to play the game
void play_game() {
  int state = GAME_IN_PROGRESS;
  int move;
  char player = PLAYER1;

  while (state == GAME_IN_PROGRESS) {
    // Get the player's move
    move = get_move(player);

    // Check if the move is valid
    if (table[move / TABLE_SIZE][move % TABLE_SIZE] != ' ') {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // Place the player's symbol on the table
    table[move / TABLE_SIZE][move % TABLE_SIZE] = player;

    // Print the game table
    print_table();

    // Check if the player has won
    state = check_win(player);

    // Switch players
    player = player == PLAYER1 ? PLAYER2 : PLAYER1;
  }

  // Print the game result
  switch (state) {
    case PLAYER1_WINS:
      printf("Player 1 wins!\n");
      break;
    case PLAYER2_WINS:
      printf("Player 2 wins!\n");
      break;
    case TIE:
      printf("Tie!\n");
      break;
  }
}

int main() {
  // Initialize the game table
  init_table();

  // Play the game
  play_game();

  return 0;
}