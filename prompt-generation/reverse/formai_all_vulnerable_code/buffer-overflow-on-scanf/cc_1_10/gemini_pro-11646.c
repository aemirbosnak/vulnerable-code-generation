//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game board
char board[3][3];

// Player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Game state
enum GameState {
  PLAYING,
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW
};

// Function to initialize the game board
void init_board() {
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
      printf(" %c |", board[i][j]);
    }
    printf("\n-----------");
    printf("\n");
  }
  printf("\n");
}

// Function to check if the game is over
enum GameState check_game_over() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
  }

  // Check draw
  int empty_cells = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        empty_cells++;
      }
    }
  }
  if (empty_cells == 0) {
    return DRAW;
  }

  // Game is still playing
  return PLAYING;
}

// Function to get the player's move
int get_player_move(char player) {
  int row, col;

  printf("Player %c, enter your move (row, col): ", player);
  scanf("%d %d", &row, &col);

  // Check if the move is valid
  while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
    printf("Invalid move. Please enter a valid move (row, col): ");
    scanf("%d %d", &row, &col);
  }

  return row - 1;
}

// Function to get the computer's move
int get_computer_move() {
  // Generate a random number between 0 and 8
  srand(time(NULL));
  int move = rand() % 9;

  // Check if the move is valid
  while (board[move / 3][move % 3] != ' ') {
    // Generate a new random number
    move = rand() % 9;
  }

  return move;
}

// Function to play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Game loop
  enum GameState state = PLAYING;
  char current_player = PLAYER1;
  while (state == PLAYING) {
    // Print the game board
    print_board();

    // Get the player's move
    int move;
    if (current_player == PLAYER1) {
      move = get_player_move(PLAYER1);
    } else {
      move = get_computer_move();
    }

    // Update the game board
    board[move / 3][move % 3] = current_player;

    // Check if the game is over
    state = check_game_over();

    // Switch players
    current_player = current_player == PLAYER1 ? PLAYER2 : PLAYER1;
  }

  // Print the game board
  print_board();

  // Print the game result
  switch (state) {
    case PLAYER1_WIN:
      printf("Player 1 wins!\n");
      break;
    case PLAYER2_WIN:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }
}

// Main function
int main() {
  // Play the game
  play_game();

  return 0;
}