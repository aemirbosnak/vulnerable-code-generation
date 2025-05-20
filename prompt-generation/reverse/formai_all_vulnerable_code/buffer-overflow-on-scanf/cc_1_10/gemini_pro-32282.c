//GEMINI-pro DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
char board[3][3];

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Define the game state
enum game_state {
  GAME_IN_PROGRESS,
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW
};

// Initialize the game board
void initialize_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the game board
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

// Get the player's move
int get_player_move(char player_symbol) {
  int move;
  printf("Player %c, enter your move (1-9): ", player_symbol);
  scanf("%d", &move);
  return move - 1;  // Convert the move to a zero-based index
}

// Check if the move is valid
int is_valid_move(int move) {
  return move >= 0 && move < 9 && board[move / 3][move % 3] == ' ';
}

// Make the player's move
void make_move(int move, char player_symbol) {
  board[move / 3][move % 3] = player_symbol;
}

// Check if the game is over
enum game_state check_game_over() {
  // Check for rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }

  // Check for draw
  int num_empty_cells = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }
  if (num_empty_cells == 0) {
    return DRAW;
  }

  // Game in progress
  return GAME_IN_PROGRESS;
}

// Play the game
void play_game() {
  // Initialize the game board
  initialize_board();

  // Print the game board
  print_board();

  // Game loop
  enum game_state state = GAME_IN_PROGRESS;
  while (state == GAME_IN_PROGRESS) {
    // Get the player 1 move
    int move = get_player_move(player1_symbol);

    // Check if the move is valid
    while (!is_valid_move(move)) {
      printf("Invalid move. Please enter a valid move (1-9): ");
      scanf("%d", &move);
    }

    // Make the player 1 move
    make_move(move, player1_symbol);

    // Print the game board
    print_board();

    // Check if the game is over
    state = check_game_over();

    // If the game is not over, get the player 2 move
    if (state == GAME_IN_PROGRESS) {
      // Get the player 2 move
      move = get_player_move(player2_symbol);

      // Check if the move is valid
      while (!is_valid_move(move)) {
        printf("Invalid move. Please enter a valid move (1-9): ");
        scanf("%d", &move);
      }

      // Make the player 2 move
      make_move(move, player2_symbol);

      // Print the game board
      print_board();

      // Check if the game is over
      state = check_game_over();
    }
  }

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

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}