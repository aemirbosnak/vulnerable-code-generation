//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the board size and the number of players
#define BOARD_SIZE 3
#define NUM_PLAYERS 2

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Define the game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_PLAYER1_WIN 1
#define GAME_STATE_PLAYER2_WIN 2
#define GAME_STATE_TIE 3

// Define the board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
int current_player = 1;

// Function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }

  // Check for a tie
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }
  if (num_empty_cells == 0) {
    return GAME_STATE_TIE;
  }

  // No winner yet
  return GAME_STATE_PLAYING;
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

// Function to get the player's move
int get_move(int player) {
  int row, col;
  while (1) {
    printf("Player %d, enter your move (row, col): ", player);
    scanf("%d %d", &row, &col);
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ') {
      return row * BOARD_SIZE + col;
    } else {
      printf("Invalid move. Please try again.\n");
    }
  }
}

// Function to make a move
void make_move(int player, int move) {
  int row = move / BOARD_SIZE;
  int col = move % BOARD_SIZE;
  board[row][col] = player == 1 ? PLAYER1_SYMBOL : PLAYER2_SYMBOL;
}

// Function to play the game
void play_game() {
  int game_state;
  while (1) {
    // Print the board
    print_board();

    // Get the player's move
    int move = get_move(current_player);

    // Make the move
    make_move(current_player, move);

    // Check if the game is over
    game_state = check_win();

    // Print the winner
    if (game_state == GAME_STATE_PLAYER1_WIN) {
      printf("Player 1 wins!\n");
      break;
    } else if (game_state == GAME_STATE_PLAYER2_WIN) {
      printf("Player 2 wins!\n");
      break;
    } else if (game_state == GAME_STATE_TIE) {
      printf("Tie!\n");
      break;
    }

    // Switch to the other player
    current_player = 3 - current_player;
  }
}

// Main function
int main() {
  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Play the game
  play_game();

  return 0;
}