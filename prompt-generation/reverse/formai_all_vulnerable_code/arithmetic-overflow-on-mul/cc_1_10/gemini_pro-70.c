//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the board size
#define BOARD_SIZE 5

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_PLAYER1_WIN 1
#define GAME_STATE_PLAYER2_WIN 2
#define GAME_STATE_DRAW 3

// Define the board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
char current_player = PLAYER1;

// Define the game state
int game_state = GAME_STATE_PLAYING;

// Function to initialize the board
void initialize_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to get the player input
int get_player_input() {
  int row, col;
  printf("Enter the row and column (1-5): ");
  scanf("%d %d", &row, &col);
  return row * BOARD_SIZE + col - 1;
}

// Function to check if the move is valid
int is_valid_move(int move) {
  int row = move / BOARD_SIZE;
  int col = move % BOARD_SIZE;
  return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

// Function to make a move
void make_move(int move) {
  int row = move / BOARD_SIZE;
  int col = move % BOARD_SIZE;
  board[row][col] = current_player;
}

// Function to check if the game is over
int is_game_over() {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
      return current_player == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j]) {
      return current_player == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check for diagonal wins
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
    return current_player == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }
  if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
    return current_player == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }

  // Check for a draw
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }
  if (num_empty_cells == 0) {
    return GAME_STATE_DRAW;
  }

  // The game is still playing
  return GAME_STATE_PLAYING;
}

// Function to switch the current player
void switch_player() {
  current_player = current_player == PLAYER1 ? PLAYER2 : PLAYER1;
}

// Main function
int main() {
  // Initialize the board
  initialize_board();

  // Print the board
  print_board();

  // While the game is playing
  while (game_state == GAME_STATE_PLAYING) {
    // Get the player input
    int move = get_player_input();

    // Check if the move is valid
    if (!is_valid_move(move)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    make_move(move);

    // Print the board
    print_board();

    // Check if the game is over
    game_state = is_game_over();

    // Switch the player
    switch_player();
  }

  // Print the game result
  if (game_state == GAME_STATE_PLAYER1_WIN) {
    printf("Player 1 wins!\n");
  } else if (game_state == GAME_STATE_PLAYER2_WIN) {
    printf("Player 2 wins!\n");
  } else if (game_state == GAME_STATE_DRAW) {
    printf("It's a draw!\n");
  }

  return 0;
}