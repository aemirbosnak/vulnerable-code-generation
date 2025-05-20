//GEMINI-pro DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the game board
char board[3][3];

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Define the game state
enum GameState {
  PLAYING,
  PLAYER1_WIN,
  PLAYER2_WIN,
  TIE
};

// Function to initialize the game board
void initialize_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if the game is over
enum GameState check_game_over() {
  // Check for horizontal wins
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for diagonal wins
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }

  // Check for a tie
  int num_empty_cells = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }

  if (num_empty_cells == 0) {
    return TIE;
  }

  // Otherwise, the game is still playing
  return PLAYING;
}

// Function to get the player's move
int get_player_move(char player_symbol) {
  int move;
  do {
    printf("Player %c, enter your move (1-9): ", player_symbol);
    scanf("%d", &move);
  } while (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] != ' ');

  return move;
}

// Function to make a move on the game board
void make_move(char player_symbol, int move) {
  board[(move - 1) / 3][(move - 1) % 3] = player_symbol;
}

// Function to play the game
void play_game() {
  // Initialize the game board
  initialize_board();

  // Print the initial game board
  print_board();

  // Get the first player's move
  int move = get_player_move(player1_symbol);

  // Make the move on the game board
  make_move(player1_symbol, move);

  // Print the updated game board
  print_board();

  // Loop until the game is over
  while (check_game_over() == PLAYING) {
    // Get the second player's move
    move = get_player_move(player2_symbol);

    // Make the move on the game board
    make_move(player2_symbol, move);

    // Print the updated game board
    print_board();
  }

  // Print the game over message
  switch (check_game_over()) {
  case PLAYER1_WIN:
    printf("Player %c wins!", player1_symbol);
    break;
  case PLAYER2_WIN:
    printf("Player %c wins!", player2_symbol);
    break;
  case TIE:
    printf("Tie!");
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