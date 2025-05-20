//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: lively
/*
 * Unique C Terminal Based Game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void print_instructions();
void print_game_board();
int get_user_input();
int check_game_state();
void update_game_state();

// Global variables
int game_board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int player_turn = 1; // 1 = X, 2 = O

int main() {
  print_instructions();
  print_game_board();

  while (1) {
    int row, col;
    printf("Player %d, enter a row and column: ", player_turn);
    scanf("%d %d", &row, &col);

    if (row < 1 || row > 3 || col < 1 || col > 3) {
      printf("Invalid input! Please enter a valid row and column.\n");
      continue;
    }

    if (game_board[row - 1][col - 1] != 0) {
      printf("That space is already occupied! Please choose another space.\n");
      continue;
    }

    game_board[row - 1][col - 1] = player_turn;
    update_game_state();

    if (check_game_state()) {
      printf("Player %d wins!", player_turn);
      break;
    }

    player_turn = player_turn == 1 ? 2 : 1;
    print_game_board();
  }

  return 0;
}

void print_instructions() {
  printf("Welcome to Tic-Tac-Toe!\n");
  printf("Player 1 is X and Player 2 is O.\n");
  printf("Enter a row and column to place your piece.\n");
}

void print_game_board() {
  printf("\n");
  printf(" %c | %c | %c \n", game_board[0][0], game_board[0][1], game_board[0][2]);
  printf("-----------");
  printf(" %c | %c | %c \n", game_board[1][0], game_board[1][1], game_board[1][2]);
  printf("-----------");
  printf(" %c | %c | %c \n", game_board[2][0], game_board[2][1], game_board[2][2]);
  printf("\n");
}

int get_user_input() {
  int row, col;
  printf("Enter a row and column: ");
  scanf("%d %d", &row, &col);
  return (row - 1) * 3 + (col - 1);
}

int check_game_state() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2] && game_board[i][0] != 0) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i] && game_board[0][i] != 0) {
      return 1;
    }
  }

  // Check diagonals
  if (game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2] && game_board[0][0] != 0) {
    return 1;
  }
  if (game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0] && game_board[0][2] != 0) {
    return 1;
  }

  // Check for draw
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (game_board[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

void update_game_state() {
  int row, col;
  printf("Player %d, enter a row and column: ", player_turn);
  scanf("%d %d", &row, &col);

  if (row < 1 || row > 3 || col < 1 || col > 3) {
    printf("Invalid input! Please enter a valid row and column.\n");
    return;
  }

  if (game_board[row - 1][col - 1] != 0) {
    printf("That space is already occupied! Please choose another space.\n");
    return;
  }

  game_board[row - 1][col - 1] = player_turn;
}