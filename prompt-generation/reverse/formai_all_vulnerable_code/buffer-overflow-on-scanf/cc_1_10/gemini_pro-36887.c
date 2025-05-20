//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the players
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define NO_PLAYER ' '

// Define the game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_DRAW 1
#define GAME_STATE_PLAYER_X_WINS 2
#define GAME_STATE_PLAYER_O_WINS 3

// Function to print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != NO_PLAYER && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER_X ? GAME_STATE_PLAYER_X_WINS : GAME_STATE_PLAYER_O_WINS;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != NO_PLAYER && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j] == PLAYER_X ? GAME_STATE_PLAYER_X_WINS : GAME_STATE_PLAYER_O_WINS;
    }
  }

  // Check diagonals
  if (board[0][0] != NO_PLAYER && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER_X ? GAME_STATE_PLAYER_X_WINS : GAME_STATE_PLAYER_O_WINS;
  }
  if (board[0][2] != NO_PLAYER && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER_X ? GAME_STATE_PLAYER_X_WINS : GAME_STATE_PLAYER_O_WINS;
  }

  // No winner yet
  return GAME_STATE_PLAYING;
}

// Function to get the next player's move
int get_next_move(char player) {
  int row, col;
  printf("Player %c, enter your move (row, column): ", player);
  scanf("%d %d", &row, &col);
  return row * BOARD_SIZE + col;
}

// Function to play the game
void play_game() {
  // Initialize the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = NO_PLAYER;
    }
  }

  // Set the starting player
  char player = PLAYER_X;

  // Continue playing until there is a winner or a draw
  int game_state = GAME_STATE_PLAYING;
  while (game_state == GAME_STATE_PLAYING) {
    // Get the next player's move
    int move = get_next_move(player);

    // Check if the move is valid
    if (move < 0 || move >= BOARD_SIZE * BOARD_SIZE || board[move / BOARD_SIZE][move % BOARD_SIZE] != NO_PLAYER) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Place the player's symbol on the board
    board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

    // Check if the player has won
    game_state = check_win();

    // Switch to the other player
    player = player == PLAYER_X ? PLAYER_O : PLAYER_X;
  }

  // Print the game board
  print_board();

  // Print the game result
  switch (game_state) {
    case GAME_STATE_DRAW:
      printf("Draw!\n");
      break;
    case GAME_STATE_PLAYER_X_WINS:
      printf("Player X wins!\n");
      break;
    case GAME_STATE_PLAYER_O_WINS:
      printf("Player O wins!\n");
      break;
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}