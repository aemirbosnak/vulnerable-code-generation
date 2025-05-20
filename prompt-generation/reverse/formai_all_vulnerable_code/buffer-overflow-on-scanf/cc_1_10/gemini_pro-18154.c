//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the game board size.
#define BOARD_SIZE 8

// Define the player symbols.
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state.
#define GAME_STATE_PLAYING 0
#define GAME_STATE_DRAW 1
#define GAME_STATE_PLAYER_1_WIN 2
#define GAME_STATE_PLAYER_2_WIN 3

// Define the game board.
char board[BOARD_SIZE][BOARD_SIZE];

// Define the current player.
char current_player = PLAYER_1;

// Define the game state.
int game_state = GAME_STATE_PLAYING;

// Function to initialize the game board.
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board.
void print_board() {
  printf("   ");
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

// Function to check if the game is over.
int check_game_over() {
  // Check if there are any empty cells.
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return GAME_STATE_PLAYING;
      }
    }
  }

  // Check if there is a winner.
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Check rows.
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER_1 ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
    }

    // Check columns.
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return board[0][i] == PLAYER_1 ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
    }
  }

  // Check diagonals.
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER_1 ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
  }

  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER_1 ? GAME_STATE_PLAYER_1_WIN : GAME_STATE_PLAYER_2_WIN;
  }

  // The game is a draw.
  return GAME_STATE_DRAW;
}

// Function to get the player's move.
int get_player_move() {
  int move;

  while (1) {
    printf("Player %c, enter your move (1-9): ", current_player);
    scanf("%d", &move);

    if (move >= 1 && move <= 9 && board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] == ' ') {
      return move;
    } else {
      printf("Invalid move. Please try again.\n");
    }
  }
}

// Function to make a move.
void make_move(int move) {
  board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] = current_player;
}

// Function to switch the current player.
void switch_player() {
  current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
}

// Function to play the game.
void play_game() {
  init_board();

  while (game_state == GAME_STATE_PLAYING) {
    print_board();
    int move = get_player_move();
    make_move(move);
    game_state = check_game_over();
    switch_player();
  }

  print_board();

  switch (game_state) {
    case GAME_STATE_PLAYER_1_WIN:
      printf("Player 1 wins!\n");
      break;
    case GAME_STATE_PLAYER_2_WIN:
      printf("Player 2 wins!\n");
      break;
    case GAME_STATE_DRAW:
      printf("The game is a draw.\n");
      break;
  }
}

int main() {
  srand(time(NULL));
  play_game();
  return 0;
}