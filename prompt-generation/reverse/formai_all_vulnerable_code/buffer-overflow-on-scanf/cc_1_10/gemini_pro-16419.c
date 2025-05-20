//GEMINI-pro DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_ONE_WINS 1
#define PLAYER_TWO_WINS 2
#define TIE 3

// Create the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game state
int game_state = GAME_IN_PROGRESS;

// Function to print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to get the player's move
int get_player_move(char player_symbol) {
  int row, column;

  printf("Player %c, enter your move (row, column): ", player_symbol);
  scanf("%d %d", &row, &column);

  // Check if the move is valid
  if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE || board[row][column] != ' ') {
    printf("Invalid move. Try again.\n");
    return -1;
  }

  return row * BOARD_SIZE + column;
}

// Function to make a move on the game board
void make_move(int move, char player_symbol) {
  int row = move / BOARD_SIZE;
  int column = move % BOARD_SIZE;

  board[row][column] = player_symbol;
}

// Function to check if the game is over
int check_game_over() {
  // Check for rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
    }
  }

  // Check for columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return board[0][j] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
    }
  }

  // Check for diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == PLAYER_ONE ? PLAYER_ONE_WINS : PLAYER_TWO_WINS;
  }

  // Check for tie
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }

  if (num_empty_cells == 0) {
    return TIE;
  }

  // Game is still in progress
  return GAME_IN_PROGRESS;
}

// Main game loop
int main() {
  // Initialize the random number generator
  srand((unsigned int)time(NULL));

  // Initialize the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Game loop
  while (game_state == GAME_IN_PROGRESS) {
    // Get the player one's move
    int move = get_player_move(PLAYER_ONE);

    // Make the move
    make_move(move, PLAYER_ONE);

    // Check if the game is over
    game_state = check_game_over();

    // If the game is over, print the winner
    if (game_state != GAME_IN_PROGRESS) {
      if (game_state == PLAYER_ONE_WINS) {
        printf("Player %c wins!\n", PLAYER_ONE);
      } else if (game_state == PLAYER_TWO_WINS) {
        printf("Player %c wins!\n", PLAYER_TWO);
      } else {
        printf("Tie!\n");
      }
      break;
    }

    // Get the player two's move
    move = get_player_move(PLAYER_TWO);

    // Make the move
    make_move(move, PLAYER_TWO);

    // Check if the game is over
    game_state = check_game_over();

    // If the game is over, print the winner
    if (game_state != GAME_IN_PROGRESS) {
      if (game_state == PLAYER_ONE_WINS) {
        printf("Player %c wins!\n", PLAYER_ONE);
      } else if (game_state == PLAYER_TWO_WINS) {
        printf("Player %c wins!\n", PLAYER_TWO);
      } else {
        printf("Tie!\n");
      }
      break;
    }
  }

  return 0;
}