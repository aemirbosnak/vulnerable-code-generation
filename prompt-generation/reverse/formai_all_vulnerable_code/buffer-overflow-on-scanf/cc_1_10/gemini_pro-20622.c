//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

// The board is represented as a 2D array of characters.
char board[BOARD_SIZE][BOARD_SIZE];

// The player's symbol is 'X'.
const char PLAYER_SYMBOL = 'X';

// The AI's symbol is 'O'.
const char AI_SYMBOL = 'O';

// The game is over when the board is full or when one player has won.
const int GAME_OVER = 0;

// The player's turn is represented by the value 1.
const int PLAYER_TURN = 1;

// The AI's turn is represented by the value 2.
const int AI_TURN = 2;

// The game is a draw when the board is full and no player has won.
const int DRAW = -1;

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
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if the game is over.
int is_game_over() {
  // Check if the board is full.
  int full = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        full = 0;
        break;
      }
    }
  }
  if (full) {
    return DRAW;
  }

  // Check if the player has won.
  int player_won = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == PLAYER_SYMBOL && board[i][1] == PLAYER_SYMBOL && board[i][2] == PLAYER_SYMBOL) {
      player_won = 1;
      break;
    }
    if (board[0][i] == PLAYER_SYMBOL && board[1][i] == PLAYER_SYMBOL && board[2][i] == PLAYER_SYMBOL) {
      player_won = 1;
      break;
    }
  }
  if (board[0][0] == PLAYER_SYMBOL && board[1][1] == PLAYER_SYMBOL && board[2][2] == PLAYER_SYMBOL) {
    player_won = 1;
  }
  if (board[0][2] == PLAYER_SYMBOL && board[1][1] == PLAYER_SYMBOL && board[2][0] == PLAYER_SYMBOL) {
    player_won = 1;
  }
  if (player_won) {
    return PLAYER_TURN;
  }

  // Check if the AI has won.
  int ai_won = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == AI_SYMBOL && board[i][1] == AI_SYMBOL && board[i][2] == AI_SYMBOL) {
      ai_won = 1;
      break;
    }
    if (board[0][i] == AI_SYMBOL && board[1][i] == AI_SYMBOL && board[2][i] == AI_SYMBOL) {
      ai_won = 1;
      break;
    }
  }
  if (board[0][0] == AI_SYMBOL && board[1][1] == AI_SYMBOL && board[2][2] == AI_SYMBOL) {
    ai_won = 1;
  }
  if (board[0][2] == AI_SYMBOL && board[1][1] == AI_SYMBOL && board[2][0] == AI_SYMBOL) {
    ai_won = 1;
  }
  if (ai_won) {
    return AI_TURN;
  }

  // The game is not over.
  return GAME_OVER;
}

// Function to get the player's move.
int get_player_move() {
  int move;
  printf("Enter your move (1-9): ");
  scanf("%d", &move);
  return move;
}

// Function to get the AI's move.
int get_ai_move() {
  // Use a simple algorithm to select a move.
  // First, check if the AI can win in one move.
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = AI_SYMBOL;
        if (is_game_over() == AI_TURN) {
          board[i][j] = ' ';
          return i * 3 + j + 1;
        }
        board[i][j] = ' ';
      }
    }
  }

  // Next, check if the player can win in one move.
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = PLAYER_SYMBOL;
        if (is_game_over() == PLAYER_TURN) {
          board[i][j] = ' ';
          return i * 3 + j + 1;
        }
        board[i][j] = ' ';
      }
    }
  }

  // Finally, select a random move.
  srand(time(NULL));
  int move;
  do {
    move = rand() % 9 + 1;
  } while (board[(move - 1) / 3][(move - 1) % 3] != ' ');
  return move;
}

// Function to play the game.
void play_game() {
  int turn = PLAYER_TURN;
  int game_over = GAME_OVER;

  // Initialize the game board.
  init_board();

  // Print the game board.
  print_board();

  // While the game is not over, get the player's move and the AI's move.
  while (game_over == GAME_OVER) {
    if (turn == PLAYER_TURN) {
      int move = get_player_move();
      board[(move - 1) / 3][(move - 1) % 3] = PLAYER_SYMBOL;
      turn = AI_TURN;
    } else {
      int move = get_ai_move();
      board[(move - 1) / 3][(move - 1) % 3] = AI_SYMBOL;
      turn = PLAYER_TURN;
    }

    // Print the game board.
    print_board();

    // Check if the game is over.
    game_over = is_game_over();
  }

  // Print the winner.
  if (game_over == PLAYER_TURN) {
    printf("You win!\n");
  } else if (game_over == AI_TURN) {
    printf("The AI wins!\n");
  } else {
    printf("Draw!\n");
  }
}

// Main function.
int main() {
  play_game();
  return 0;
}