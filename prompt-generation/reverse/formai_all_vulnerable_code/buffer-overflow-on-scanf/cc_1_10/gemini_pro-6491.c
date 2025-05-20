//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define EMPTY 0
#define PLAYER_1 1
#define PLAYER_2 2
#define DRAW 3

// The game board
int board[BOARD_SIZE][BOARD_SIZE];

// The current player
int current_player;

// The winner of the game
int winner;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
}

// Print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY) {
        printf(" ");
      } else if (board[i][j] == PLAYER_1) {
        printf("X");
      } else if (board[i][j] == PLAYER_2) {
        printf("O");
      }
    }
    printf("\n");
  }
}

// Check if the game is over
int is_game_over() {
  // Check if there is a winner
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
    if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return board[0][i];
    }
  }
  if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2];
  }

  // Check if the game is a draw
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != EMPTY) {
        count++;
      }
    }
  }
  if (count == BOARD_SIZE * BOARD_SIZE) {
    return DRAW;
  }

  // The game is not over yet
  return 0;
}

// Get the next move from the player
int get_next_move() {
  int move;

  printf("Enter your move (1-9): ");
  scanf("%d", &move);

  // Check if the move is valid
  while (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] != EMPTY) {
    printf("Invalid move. Enter your move (1-9): ");
    scanf("%d", &move);
  }

  return move;
}

// Make a move on the game board
void make_move(int move) {
  board[(move - 1) / 3][(move - 1) % 3] = current_player;
}

// Play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Set the current player
  current_player = PLAYER_1;

  // Play the game until it is over
  while ((winner = is_game_over()) == 0) {
    // Print the game board
    print_board();

    // Get the next move from the player
    int move = get_next_move();

    // Make the move
    make_move(move);

    // Switch the current player
    current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
  }

  // Print the final game board
  print_board();

  // Print the winner of the game
  if (winner == PLAYER_1) {
    printf("Player 1 wins!\n");
  } else if (winner == PLAYER_2) {
    printf("Player 2 wins!\n");
  } else {
    printf("Draw!\n");
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}