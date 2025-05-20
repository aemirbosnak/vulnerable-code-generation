//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum length of a player's name
#define MAX_NAME_LENGTH 32

// Define the maximum number of moves per player
#define MAX_MOVES 10

// Define the game board size
#define BOARD_SIZE 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player names
char player_names[MAX_PLAYERS][MAX_NAME_LENGTH];

// Define the player symbols
char player_symbols[MAX_PLAYERS] = {'X', 'O', 'A', 'B'};

// Define the current player
int current_player = 0;

// Define the game state
int game_state = 0; // 0 = in progress, 1 = player 1 wins, 2 = player 2 wins, 3 = draw

// Define the function to print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Define the function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0];
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j];
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2];
  }

  // Check for a draw
  int num_moves = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != ' ') {
        num_moves++;
      }
    }
  }
  if (num_moves == BOARD_SIZE * BOARD_SIZE) {
    return 3;
  }

  // No winner yet
  return 0;
}

// Define the function to get the next player's move
int get_next_move() {
  // Get the player's input
  int move;
  printf("%s, enter your move (1-9): ", player_names[current_player]);
  scanf("%d", &move);

  // Validate the player's input
  while (move < 1 || move > 9 || board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] != ' ') {
    printf("Invalid move. Please enter a valid move (1-9): ");
    scanf("%d", &move);
  }

  // Return the player's move
  return move;
}

// Define the function to make a move
void make_move(int move) {
  // Place the player's symbol on the board
  board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] = player_symbols[current_player];

  // Switch to the next player
  current_player = (current_player + 1) % MAX_PLAYERS;
}

// Define the main function
int main() {
  // Initialize the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Get the player names
  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("Enter the name of player %d: ", i + 1);
    scanf("%s", player_names[i]);
  }

  // Start the game loop
  while (game_state == 0) {
    // Print the game board
    print_board();

    // Get the next player's move
    int move = get_next_move();

    // Make the move
    make_move(move);

    // Check if the player has won
    game_state = check_win();
  }

  // Print the game outcome
  if (game_state == 1 || game_state == 2) {
    printf("%s wins!\n", player_names[game_state - 1]);
  } else if (game_state == 3) {
    printf("Draw!\n");
  }

  return 0;
}