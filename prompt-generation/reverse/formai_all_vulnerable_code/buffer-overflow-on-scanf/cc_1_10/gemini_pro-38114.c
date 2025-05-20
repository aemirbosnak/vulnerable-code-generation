//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
char board[3][3];

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Define the game state
enum GameState {
  GAME_IN_PROGRESS,
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
    printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if (i < 2) {
      printf("---+---+---\n");
    }
  }
  printf("\n");
}

// Function to get the player's move
int get_player_move(char player_symbol) {
  int move;
  printf("Player %c, enter your move (1-9): ", player_symbol);
  scanf("%d", &move);
  return move;
}

// Function to check if the move is valid
int is_valid_move(int move) {
  if (move < 1 || move > 9) {
    return 0;
  }
  int row = (move - 1) / 3;
  int col = (move - 1) % 3;
  if (board[row][col] != ' ') {
    return 0;
  }
  return 1;
}

// Function to make the player's move
void make_move(int move, char player_symbol) {
  int row = (move - 1) / 3;
  int col = (move - 1) % 3;
  board[row][col] = player_symbol;
}

// Function to check if the game is over
enum GameState check_game_over() {
  // Check for rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      if (board[i][0] == player1_symbol) {
        return PLAYER1_WIN;
      } else {
        return PLAYER2_WIN;
      }
    }
  }

  // Check for columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      if (board[0][i] == player1_symbol) {
        return PLAYER1_WIN;
      } else {
        return PLAYER2_WIN;
      }
    }
  }

  // Check for diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    if (board[0][0] == player1_symbol) {
      return PLAYER1_WIN;
    } else {
      return PLAYER2_WIN;
    }
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    if (board[0][2] == player1_symbol) {
      return PLAYER1_WIN;
    } else {
      return PLAYER2_WIN;
    }
  }

  // Check for tie
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == 9) {
    return TIE;
  }

  // Game is still in progress
  return GAME_IN_PROGRESS;
}

// Function to play the game
void play_game() {
  // Initialize the game board
  initialize_board();

  // Print the initial game board
  print_board();

  // Loop until the game is over
  enum GameState game_state = GAME_IN_PROGRESS;
  while (game_state == GAME_IN_PROGRESS) {
    // Get the player 1's move
    int player1_move = get_player_move(player1_symbol);

    // Check if the move is valid
    while (!is_valid_move(player1_move)) {
      printf("Invalid move. Please try again.\n");
      player1_move = get_player_move(player1_symbol);
    }

    // Make the player 1's move
    make_move(player1_move, player1_symbol);

    // Print the updated game board
    print_board();

    // Check if the game is over
    game_state = check_game_over();

    // If the game is over, break out of the loop
    if (game_state != GAME_IN_PROGRESS) {
      break;
    }

    // Get the player 2's move
    int player2_move = get_player_move(player2_symbol);

    // Check if the move is valid
    while (!is_valid_move(player2_move)) {
      printf("Invalid move. Please try again.\n");
      player2_move = get_player_move(player2_symbol);
    }

    // Make the player 2's move
    make_move(player2_move, player2_symbol);

    // Print the updated game board
    print_board();

    // Check if the game is over
    game_state = check_game_over();
  }

  // Print the final game state
  switch (game_state) {
    case PLAYER1_WIN:
      printf("Player 1 wins!\n");
      break;
    case PLAYER2_WIN:
      printf("Player 2 wins!\n");
      break;
    case TIE:
      printf("Tie game!\n");
      break;
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