//GEMINI-pro DATASET v1.0 Category: Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the game states
#define GAME_STATE_PLAYING 0
#define GAME_STATE_X_WINS 1
#define GAME_STATE_O_WINS 2
#define GAME_STATE_DRAW 3

// Define the player types
#define PLAYER_TYPE_HUMAN 0
#define PLAYER_TYPE_COMPUTER 1

// Define the game board
int game_board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
int current_player = PLAYER_TYPE_HUMAN;

// Define the game state
int game_state = GAME_STATE_PLAYING;

// Function to print the game board
void print_game_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (game_board[i][j] == PLAYER_TYPE_HUMAN) {
        printf("X");
      } else if (game_board[i][j] == PLAYER_TYPE_COMPUTER) {
        printf("O");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Function to get the player's move
int get_player_move() {
  int move;
  printf("Enter your move (1-9): ");
  scanf("%d", &move);
  return move - 1;
}

// Function to get the computer's move
int get_computer_move() {
  // Generate a random move
  int move = rand() % (BOARD_SIZE * BOARD_SIZE);

  // Check if the move is valid
  while (game_board[move / BOARD_SIZE][move % BOARD_SIZE] != 0) {
    move = rand() % (BOARD_SIZE * BOARD_SIZE);
  }

  return move;
}

// Function to check if the game is over
int check_game_over() {
  // Check if there are any winning combinations
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2] && game_board[i][0] != 0) {
      return game_board[i][0];
    }
    if (game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i] && game_board[0][i] != 0) {
      return game_board[0][i];
    }
  }
  if (game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2] && game_board[0][0] != 0) {
    return game_board[0][0];
  }
  if (game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0] && game_board[0][2] != 0) {
    return game_board[0][2];
  }

  // Check if the game is a draw
  int draw = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (game_board[i][j] == 0) {
        draw = 0;
      }
    }
  }
  if (draw) {
    return GAME_STATE_DRAW;
  }

  // The game is still playing
  return GAME_STATE_PLAYING;
}

// Function to play the game
void play_game() {
  // Print the game board
  print_game_board();

  // Get the player's move
  int move;
  if (current_player == PLAYER_TYPE_HUMAN) {
    move = get_player_move();
  } else {
    move = get_computer_move();
  }

  // Place the player's move on the game board
  game_board[move / BOARD_SIZE][move % BOARD_SIZE] = current_player;

  // Check if the game is over
  game_state = check_game_over();

  // Print the game board
  print_game_board();

  // Switch to the other player
  current_player = (current_player + 1) % 2;

  // If the game is not over, play again
  if (game_state == GAME_STATE_PLAYING) {
    play_game();
  } else {
    // The game is over, print the winner
    if (game_state == GAME_STATE_X_WINS) {
      printf("X wins!\n");
    } else if (game_state == GAME_STATE_O_WINS) {
      printf("O wins!\n");
    } else if (game_state == GAME_STATE_DRAW) {
      printf("Draw!\n");
    }
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