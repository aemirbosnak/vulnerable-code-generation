//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_HUMAN 1
#define PLAYER_AI 2
#define PLAYER_NONE 0

// The game board
int board[BOARD_SIZE][BOARD_SIZE];

// The current player
int current_player;

// Function to initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = PLAYER_NONE;
    }
  }
}

// Function to print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == PLAYER_HUMAN) {
        printf("X ");
      } else if (board[i][j] == PLAYER_AI) {
        printf("O ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

// Function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != PLAYER_NONE) {
      return board[i][0];
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != PLAYER_NONE) {
      return board[0][j];
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != PLAYER_NONE) {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != PLAYER_NONE) {
    return board[0][2];
  }

  // No winner yet
  return PLAYER_NONE;
}

// Function to get the AI's move
int get_ai_move() {
  // The AI will randomly choose an empty square
  srand(time(NULL));
  int move_row = rand() % BOARD_SIZE;
  int move_col = rand() % BOARD_SIZE;
  while (board[move_row][move_col] != PLAYER_NONE) {
    move_row = rand() % BOARD_SIZE;
    move_col = rand() % BOARD_SIZE;
  }

  return move_row * BOARD_SIZE + move_col;
}

// Function to play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Set the current player to human
  current_player = PLAYER_HUMAN;

  // Game loop
  while (1) {
    // Print the game board
    print_board();

    // Get the player's move
    int move;
    if (current_player == PLAYER_HUMAN) {
      printf("Enter your move (1-9): ");
      scanf("%d", &move);
      move--;  // Convert to 0-based index
    } else {
      move = get_ai_move();
    }

    // Place the player's move on the board
    int move_row = move / BOARD_SIZE;
    int move_col = move % BOARD_SIZE;
    board[move_row][move_col] = current_player;

    // Check if there is a winner
    int winner = check_win();
    if (winner == PLAYER_HUMAN) {
      printf("You win!\n");
      break;
    } else if (winner == PLAYER_AI) {
      printf("The AI wins!\n");
      break;
    }

    // Switch to the other player
    current_player = (current_player == PLAYER_HUMAN) ? PLAYER_AI : PLAYER_HUMAN;
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}