//GEMINI-pro DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_DRAW 1
#define GAME_STATE_X_WINS 2
#define GAME_STATE_O_WINS 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
char current_player = PLAYER_X;

// Define the game state
int game_state = GAME_STATE_PLAYING;

// Function to initialize the game board
void initialize_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to get the player's move
int get_player_move() {
  int move;
  printf("Enter your move (1-9): ");
  scanf("%d", &move);
  return move;
}

// Function to make a move
void make_move(int move) {
  int row = (move - 1) / BOARD_SIZE;
  int col = (move - 1) % BOARD_SIZE;
  board[row][col] = current_player;
}

// Function to check if the game is over
int check_game_over() {
  // Check for a win
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return current_player == PLAYER_X ? GAME_STATE_X_WINS : GAME_STATE_O_WINS;
    }
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return current_player == PLAYER_X ? GAME_STATE_X_WINS : GAME_STATE_O_WINS;
    }
  }

  // Check for a diagonal win
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return current_player == PLAYER_X ? GAME_STATE_X_WINS : GAME_STATE_O_WINS;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return current_player == PLAYER_X ? GAME_STATE_X_WINS : GAME_STATE_O_WINS;
  }

  // Check for a draw
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == BOARD_SIZE * BOARD_SIZE) {
    return GAME_STATE_DRAW;
  }

  // The game is still playing
  return GAME_STATE_PLAYING;
}

// Function to play the game
void play_game() {
  initialize_board();
  print_board();

  while (game_state == GAME_STATE_PLAYING) {
    // Get the player's move
    int move = get_player_move();

    // Make the move
    make_move(move);

    // Print the board
    print_board();

    // Check if the game is over
    game_state = check_game_over();
  }

  // Print the game result
  if (game_state == GAME_STATE_DRAW) {
    printf("Game over! It's a draw.\n");
  } else if (game_state == GAME_STATE_X_WINS) {
    printf("Game over! Player X wins!\n");
  } else if (game_state == GAME_STATE_O_WINS) {
    printf("Game over! Player O wins!\n");
  }
}

// Main function
int main() {
  play_game();
  return 0;
}