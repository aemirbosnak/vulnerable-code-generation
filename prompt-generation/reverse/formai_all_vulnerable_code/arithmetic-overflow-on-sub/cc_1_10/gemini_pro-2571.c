//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Define the game state
enum game_state {
  PLAYING,
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW
};

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf(" %c |", board[i][j]);
    }
    printf("\n");
    if (i != BOARD_SIZE - 1) {
      printf("---+---+---\n");
    }
  }
  printf("\n");
}

// Check if the game is over
enum game_state check_game_over() {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for diagonal wins
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
    return board[2][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }

  // Check for a draw
  bool draw = true;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        draw = false;
      }
    }
  }
  if (draw) {
    return DRAW;
  }

  // The game is still playing
  return PLAYING;
}

// Get the player's move
void get_player_move(char symbol) {
  int row, col;

  do {
    printf("Enter your move for %c (row, col): ", symbol);
    scanf("%d %d", &row, &col);
  } while (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ');

  // Place the symbol on the board
  board[row - 1][col - 1] = symbol;
}

// Get the AI's move
void get_ai_move() {
  // Check if the AI can win
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = player2_symbol;
        if (check_game_over() == PLAYER2_WIN) {
          return;
        }
        board[i][j] = ' ';
      }
    }
  }

  // Check if the player can win
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = player1_symbol;
        if (check_game_over() == PLAYER1_WIN) {
          board[i][j] = player2_symbol;
          return;
        }
        board[i][j] = ' ';
      }
    }
  }

  // Place the symbol in the center if it is empty
  if (board[1][1] == ' ') {
    board[1][1] = player2_symbol;
    return;
  }

  // Place the symbol in a corner if it is empty
  for (int i = 0; i < BOARD_SIZE; i += 2) {
    for (int j = 0; j < BOARD_SIZE; j += 2) {
      if (board[i][j] == ' ') {
        board[i][j] = player2_symbol;
        return;
      }
    }
  }

  // Place the symbol in a side if it is empty
  for (int i = 0; i < BOARD_SIZE; i += 2) {
    for (int j = 1; j < BOARD_SIZE; j += 2) {
      if (board[i][j] == ' ') {
        board[i][j] = player2_symbol;
        return;
      }
    }
  }
}

// Play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Print the game board
  print_board();

  // Get the players' names
  char player1_name[20], player2_name[20];
  printf("Enter player 1 name: ");
  scanf("%s", player1_name);
  printf("Enter player 2 name: ");
  scanf("%s", player2_name);

  // Determine who goes first
  int first_player;
  printf("Who goes first? (1 for %s, 2 for %s): ", player1_name, player2_name);
  scanf("%d", &first_player);

  // Play the game
  enum game_state state = PLAYING;
  while (state == PLAYING) {
    // Get the player's move
    if (first_player == 1) {
      get_player_move(player1_symbol);
    } else {
      get_ai_move();
    }

    // Print the game board
    print_board();

    // Check the game state
    state = check_game_over();

    // Switch turns
    first_player = 3 - first_player;
  }

  // Declare the winner
  if (state == PLAYER1_WIN) {
    printf("%s wins!\n", player1_name);
  } else if (state == PLAYER2_WIN) {
    printf("%s wins!\n", player2_name);
  } else {
    printf("It's a draw!\n");
  }
}

// Main function
int main() {
  // Play the game
  play_game();

  return 0;
}