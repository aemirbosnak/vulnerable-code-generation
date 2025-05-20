//GEMINI-pro DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game states
#define GAME_STATE_PLAYING 0
#define GAME_STATE_DRAW 1
#define GAME_STATE_PLAYER_1_WIN 2
#define GAME_STATE_PLAYER_2_WIN 3

// Function to initialize the game board
void init_board() {
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

// Function to check if a player has won
int check_win(char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return player == PLAYER_1 ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return player == PLAYER_1 ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return player == PLAYER_1 ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return player == PLAYER_1 ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
  }

  // No winner yet
  return GAME_STATE_PLAYING;
}

// Function to check if the game is a draw
int check_draw() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return GAME_STATE_PLAYING;
      }
    }
  }

  return GAME_STATE_DRAW;
}

// Function to get the next move from a player
int get_move(char player) {
  int row, column;
  printf("Player %c, enter your move (row, column): ", player);
  scanf("%d %d", &row, &column);

  // Check if the move is valid
  if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE || board[row][column] != ' ') {
    printf("Invalid move. Please try again.\n");
    return get_move(player);
  }

  return row * BOARD_SIZE + column;
}

// Function to play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Set the current player to player 1
  char current_player = PLAYER_1;

  // Play the game until there is a winner or a draw
  int game_state = GAME_STATE_PLAYING;
  while (game_state == GAME_STATE_PLAYING) {
    // Get the next move from the current player
    int move = get_move(current_player);

    // Update the game board
    board[move / BOARD_SIZE][move % BOARD_SIZE] = current_player;

    // Print the game board
    print_board();

    // Check if the current player has won
    game_state = check_win(current_player);

    // If there is no winner, check if the game is a draw
    if (game_state == GAME_STATE_PLAYING) {
      game_state = check_draw();
    }

    // Switch the current player
    current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
  }

  // Print the final game state
  if (game_state == GAME_STATE_PLAYER_1_WIN) {
    printf("Player 1 wins!\n");
  } else if (game_state == GAME_STATE_PLAYER_2_WIN) {
    printf("Player 2 wins!\n");
  } else if (game_state == GAME_STATE_DRAW) {
    printf("The game is a draw.\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}