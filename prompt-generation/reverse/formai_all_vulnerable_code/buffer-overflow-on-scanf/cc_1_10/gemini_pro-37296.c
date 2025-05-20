//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>

// Romeo and Juliet Table Game

// Define the players
#define ROMEO 0
#define JULIET 1

// Define the board
#define BOARD_SIZE 5
char board[BOARD_SIZE][BOARD_SIZE] = {
  {' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' '},
  {' ', ' ', 'X', ' ', ' '},
  {' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' '}
};

// Define the game state
#define IN_PROGRESS 0
#define ROMEO_WINS 1
#define JULIET_WINS 2
#define DRAW 3
int game_state = IN_PROGRESS;

// Define the current player
int current_player = ROMEO;

// Get the player's move
void get_move(int player) {
  int row, col;
  printf("Player %d, enter your move (row, col): ", player + 1);
  scanf("%d %d", &row, &col);

  // Check if the move is valid
  if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
    printf("Invalid move. Please try again.\n");
    get_move(player);
  } else {
    // Place the player's symbol on the board
    board[row][col] = player == ROMEO ? 'R' : 'J';
  }
}

// Check if the game is over
int check_game_over() {
  // Check for a win in any row
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
      return board[i][0] == 'R' ? ROMEO_WINS : JULIET_WINS;
    }
  }

  // Check for a win in any column
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i]) {
      return board[0][i] == 'R' ? ROMEO_WINS : JULIET_WINS;
    }
  }

  // Check for a win in any diagonal
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
    return board[0][0] == 'R' ? ROMEO_WINS : JULIET_WINS;
  }
  if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
    return board[0][4] == 'R' ? ROMEO_WINS : JULIET_WINS;
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
    return DRAW;
  }

  // The game is still in progress
  return IN_PROGRESS;
}

// Print the game board
void print_board() {
  printf("  0 1 2 3 4\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Play the game
void play_game() {
  // Print the initial board
  print_board();

  // Loop until the game is over
  while (game_state == IN_PROGRESS) {
    // Get the current player's move
    get_move(current_player);

    // Check if the game is over
    game_state = check_game_over();

    // Print the updated board
    print_board();

    // Switch to the other player
    current_player = current_player == ROMEO ? JULIET : ROMEO;
  }

  // Print the game result
  if (game_state == ROMEO_WINS) {
    printf("Romeo wins!\n");
  } else if (game_state == JULIET_WINS) {
    printf("Juliet wins!\n");
  } else {
    printf("Draw!\n");
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}