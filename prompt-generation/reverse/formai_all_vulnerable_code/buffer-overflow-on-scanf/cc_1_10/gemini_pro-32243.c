//GEMINI-pro DATASET v1.0 Category: Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game states
#define GAME_IN_PROGRESS 0
#define PLAYER1_WINS 1
#define PLAYER2_WINS 2
#define TIE 3

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
}

// Function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == PLAYER1 ? PLAYER1_WINS : PLAYER2_WINS;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == PLAYER1 ? PLAYER1_WINS : PLAYER2_WINS;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == PLAYER1 ? PLAYER1_WINS : PLAYER2_WINS;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == PLAYER1 ? PLAYER1_WINS : PLAYER2_WINS;
  }

  // Check for a tie
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return GAME_IN_PROGRESS;
      }
    }
  }

  return TIE;
}

// Function to get the player's move
int get_move(char player) {
  int row, col;
  printf("Player %c, enter your move (row,col): ", player);
  scanf(" %d %d", &row, &col);
  return row * BOARD_SIZE + col;
}

// Function to play a turn
void play_turn(char player) {
  int move;
  do {
    move = get_move(player);
    if (move < 0 || move >= BOARD_SIZE * BOARD_SIZE || board[move / BOARD_SIZE][move % BOARD_SIZE] != ' ') {
      printf("Invalid move. Try again.\n");
    }
  } while (move < 0 || move >= BOARD_SIZE * BOARD_SIZE || board[move / BOARD_SIZE][move % BOARD_SIZE] != ' ');
  board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
}

// Function to play the game
void play_game() {
  char player = PLAYER1;
  int game_state;

  // Initialize the game board
  init_board();

  // Play the game until someone wins or there is a tie
  do {
    // Print the game board
    print_board();

    // Get the player's move
    play_turn(player);

    // Check if the player has won
    game_state = check_win();

    // Switch the player
    player = player == PLAYER1 ? PLAYER2 : PLAYER1;
  } while (game_state == GAME_IN_PROGRESS);

  // Print the game board
  print_board();

  // Announce the winner
  if (game_state == PLAYER1_WINS) {
    printf("Player 1 wins!\n");
  } else if (game_state == PLAYER2_WINS) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
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