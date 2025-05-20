//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 5
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define DRAW 3

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
  printf("\n");
}

// Function to check if a player has won
int check_win(char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == player) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
      if (board[i][j] == player) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check diagonals
  int count_diagonal1 = 0;
  int count_diagonal2 = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][i] == player) {
      count_diagonal1++;
    }
    if (board[i][BOARD_SIZE - i - 1] == player) {
      count_diagonal2++;
    }
  }
  if (count_diagonal1 == BOARD_SIZE || count_diagonal2 == BOARD_SIZE) {
    return player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
  }

  // Check for draw
  int count_empty = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        count_empty++;
      }
    }
  }
  if (count_empty == 0) {
    return DRAW;
  }

  // No winner yet
  return GAME_IN_PROGRESS;
}

// Function to get the player's move
int get_player_move(char player) {
  int move;
  printf("Player %c, enter your move (1-9): ", player);
  scanf("%d", &move);
  return move;
}

// Function to make a move
void make_move(char player, int move) {
  int row = (move - 1) / BOARD_SIZE;
  int col = (move - 1) % BOARD_SIZE;
  board[row][col] = player;
}

// Main game loop
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the game board
  init_board();

  // Print the initial game board
  print_board();

  // Game loop
  int game_state = GAME_IN_PROGRESS;
  while (game_state == GAME_IN_PROGRESS) {
    // Get the player 1's move
    int move1 = get_player_move(PLAYER_1);

    // Make the move
    make_move(PLAYER_1, move1);

    // Print the updated game board
    print_board();

    // Check if player 1 has won
    game_state = check_win(PLAYER_1);
    if (game_state != GAME_IN_PROGRESS) {
      break;
    }

    // Get the player 2's move
    int move2 = get_player_move(PLAYER_2);

    // Make the move
    make_move(PLAYER_2, move2);

    // Print the updated game board
    print_board();

    // Check if player 2 has won
    game_state = check_win(PLAYER_2);
  }

  // Print the final game state
  if (game_state == PLAYER_1_WINS) {
    printf("Player 1 wins!\n");
  } else if (game_state == PLAYER_2_WINS) {
    printf("Player 2 wins!\n");
  } else {
    printf("Draw!\n");
  }

  return 0;
}