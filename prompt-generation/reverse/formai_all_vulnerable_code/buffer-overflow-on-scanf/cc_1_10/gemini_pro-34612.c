//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
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
enum game_state {
  PLAYING,
  PLAYER1_WON,
  PLAYER2_WON,
  DRAW
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

// Function to check if a player has won
enum game_state check_win() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
  }

  // Check if the board is full
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }

  if (count == 9) {
    return DRAW;
  }

  // No winner yet
  return PLAYING;
}

// Function to get the player's move
int get_move(char symbol) {
  int move;
  while (1) {
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    // Check if the move is valid
    if (move < 1 || move > 9) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Check if the square is empty
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] != ' ') {
      printf("Square is already occupied. Please try again.\n");
      continue;
    }

    // Move is valid, return it
    return move;
  }
}

// Function to play the game
void play_game() {
  // Initialize the game board
  initialize_board();

  // Print the game board
  print_board();

  // Set the current player to player 1
  char current_player = player1_symbol;

  // Game loop
  while (1) {
    // Get the player's move
    int move = get_move(current_player);

    // Apply the move to the game board
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = current_player;

    // Print the game board
    print_board();

    // Check if the game is over
    enum game_state state = check_win();

    // Game over
    if (state != PLAYING) {
      if (state == PLAYER1_WON) {
        printf("Player 1 wins!\n");
      } else if (state == PLAYER2_WON) {
        printf("Player 2 wins!\n");
      } else {
        printf("Draw!\n");
      }
      break;
    }

    // Switch to the other player
    current_player = current_player == player1_symbol ? player2_symbol : player1_symbol;
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