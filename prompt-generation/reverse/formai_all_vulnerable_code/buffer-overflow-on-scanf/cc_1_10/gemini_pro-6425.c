//GEMINI-pro DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 5

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_STATE_IN_PROGRESS 0
#define GAME_STATE_PLAYER_1_WINS 1
#define GAME_STATE_PLAYER_2_WINS 2
#define GAME_STATE_DRAW 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

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
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Check if the game is over
int check_game_over() {
  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
      return board[i][0] == PLAYER_1 ? GAME_STATE_PLAYER_1_WINS : GAME_STATE_PLAYER_2_WINS;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j]) {
      return board[0][j] == PLAYER_1 ? GAME_STATE_PLAYER_1_WINS : GAME_STATE_PLAYER_2_WINS;
    }
  }

  // Check for diagonal wins
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
    return board[0][0] == PLAYER_1 ? GAME_STATE_PLAYER_1_WINS : GAME_STATE_PLAYER_2_WINS;
  }

  if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
    return board[0][4] == PLAYER_1 ? GAME_STATE_PLAYER_1_WINS : GAME_STATE_PLAYER_2_WINS;
  }

  // Check for a draw
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }

  if (num_empty_cells == 0) {
    return GAME_STATE_DRAW;
  }

  // The game is still in progress
  return GAME_STATE_IN_PROGRESS;
}

// Get the player's move
int get_player_move(char player_symbol) {
  int move;

  while (1) {
    printf("Player %c, enter your move (1-9): ", player_symbol);
    scanf("%d", &move);

    if (move < 1 || move > 9) {
      printf("Invalid move. Please enter a number between 1 and 9.\n");
    } else {
      int row = (move - 1) / BOARD_SIZE;
      int col = (move - 1) % BOARD_SIZE;

      if (board[row][col] != ' ') {
        printf("That cell is already occupied. Please choose another cell.\n");
      } else {
        return move;
      }
    }
  }
}

// Make the player's move
void make_move(int move, char player_symbol) {
  int row = (move - 1) / BOARD_SIZE;
  int col = (move - 1) % BOARD_SIZE;

  board[row][col] = player_symbol;
}

// Play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Print the game board
  print_board();

  // Get the first player's move
  int move = get_player_move(PLAYER_1);

  // Make the first player's move
  make_move(move, PLAYER_1);

  // Print the game board
  print_board();

  // Check if the game is over
  int game_state = check_game_over();

  // While the game is not over
  while (game_state == GAME_STATE_IN_PROGRESS) {
    // Get the second player's move
    move = get_player_move(PLAYER_2);

    // Make the second player's move
    make_move(move, PLAYER_2);

    // Print the game board
    print_board();

    // Check if the game is over
    game_state = check_game_over();
  }

  // Print the game result
  if (game_state == GAME_STATE_PLAYER_1_WINS) {
    printf("Player %c wins!\n", PLAYER_1);
  } else if (game_state == GAME_STATE_PLAYER_2_WINS) {
    printf("Player %c wins!\n", PLAYER_2);
  } else if (game_state == GAME_STATE_DRAW) {
    printf("Draw!\n");
  }
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}