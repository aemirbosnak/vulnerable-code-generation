//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the number of rows and columns in the table
#define ROWS 5
#define COLS 5

// Define the player types
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game states
#define GAME_IN_PROGRESS 0
#define PLAYER_X_WINS 1
#define PLAYER_O_WINS 2
#define TIE 3

// Create the game table
char table[ROWS][COLS];

// Create the player turns
char player_turns[2] = {PLAYER_X, PLAYER_O};

// Create the game state
int game_state = GAME_IN_PROGRESS;

// Function to initialize the game table
void initialize_table() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      table[i][j] = ' ';
    }
  }
}

// Function to print the game table
void print_table() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%c ", table[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a player has won
int check_winner() {
  // Check rows
  for (int i = 0; i < ROWS; i++) {
    if (table[i][0] != ' ' && table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][2] == table[i][3] && table[i][3] == table[i][4]) {
      return table[i][0] == PLAYER_X ? PLAYER_X_WINS : PLAYER_O_WINS;
    }
  }

  // Check columns
  for (int j = 0; j < COLS; j++) {
    if (table[0][j] != ' ' && table[0][j] == table[1][j] && table[1][j] == table[2][j] && table[2][j] == table[3][j] && table[3][j] == table[4][j]) {
      return table[0][j] == PLAYER_X ? PLAYER_X_WINS : PLAYER_O_WINS;
    }
  }

  // Check diagonals
  if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[2][2] == table[3][3] && table[3][3] == table[4][4]) {
    return table[0][0] == PLAYER_X ? PLAYER_X_WINS : PLAYER_O_WINS;
  }

  if (table[0][4] != ' ' && table[0][4] == table[1][3] && table[1][3] == table[2][2] && table[2][2] == table[3][1] && table[3][1] == table[4][0]) {
    return table[0][4] == PLAYER_X ? PLAYER_X_WINS : PLAYER_O_WINS;
  }

  // Check for a tie
  int num_empty_cells = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (table[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }

  if (num_empty_cells == 0) {
    return TIE;
  }

  // No winner yet
  return GAME_IN_PROGRESS;
}

// Function to get the next player turn
char get_next_player_turn() {
  return player_turns[game_state % 2];
}

// Function to get the user input
int get_user_input(char *input) {
  printf("Enter your move (row, column): ");
  return scanf("%s", input) == 2;
}

// Function to play the game
void play_game() {
  // Initialize the game table
  initialize_table();

  // Print the game table
  print_table();

  // While the game is in progress
  while (game_state == GAME_IN_PROGRESS) {
    // Get the next player turn
    char player_turn = get_next_player_turn();

    // Get the user input
    char input[3];
    while (!get_user_input(input)) {
      printf("Invalid input. Please enter your move (row, column): ");
    }

    // Parse the user input
    int row = atoi(input) - 1;
    int col = atoi(input + 2) - 1;

    // Check if the move is valid
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || table[row][col] != ' ') {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Place the player's move on the table
    table[row][col] = player_turn;

    // Print the game table
    print_table();

    // Check if the player has won
    game_state = check_winner();
  }

  // Print the game result
  switch (game_state) {
    case PLAYER_X_WINS:
      printf("Player X wins!\n");
      break;
    case PLAYER_O_WINS:
      printf("Player O wins!\n");
      break;
    case TIE:
      printf("Tie!\n");
      break;
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}