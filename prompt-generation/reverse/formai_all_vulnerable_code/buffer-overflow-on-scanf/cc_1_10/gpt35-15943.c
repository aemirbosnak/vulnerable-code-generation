//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 3
#define NUM_COLS 3

char board[NUM_ROWS][NUM_COLS];

void init_board() {
  int i, j;
  for (i = 0; i < NUM_ROWS; i++) {
    for (j = 0; j < NUM_COLS; j++) {
      board[i][j] = ' ';
    }
  }
}

void print_board() {
  printf("    1   2   3\n");
  printf("  +---+---+---+\n");
  printf("1 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
  printf("  +---+---+---+\n");
  printf("2 | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
  printf("  +---+---+---+\n");
  printf("3 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
  printf("  +---+---+---+\n");
}

int get_num_moves() {
  int i, j, count = 0;
  for (i = 0; i < NUM_ROWS; i++) {
    for (j = 0; j < NUM_COLS; j++) {
      if (board[i][j] == ' ') {
        count++;
      }
    }
  }
  return count;
}

int check_game_over() {
  int i, j;
  // Check rows
  for (i = 0; i < NUM_ROWS; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return 1;
    }
  }
  // Check columns
  for (j = 0; j < NUM_COLS; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return 1;
    }
  }
  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return 1;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return 1;
  }
  // Check if board is full
  if (get_num_moves() == 0) {
    return 2;
  }
  return 0;
}

void get_move(int *row, int *col) {
  printf("Enter move (row, column): ");
  scanf("%d %d", row, col);
  (*row)--;
  (*col)--;
}

void do_move(int row, int col, char player) {
  board[row][col] = player;
}

void play_game() {
  int turn = 0;
  int row, col;
  int game_over = 0;
  char player = 'X';
  init_board();
  print_board();
  while (!game_over) {
    printf("Player %c's turn.\n", player);
    get_move(&row, &col);
    if (board[row][col] != ' ') {
      printf("Position already taken. Try again.\n");
    } else {
      do_move(row, col, player);
      print_board();
      game_over = check_game_over();
      if (game_over == 1) {
        printf("Player %c wins!\n", player);
      } else if (game_over == 2) {
        printf("Game over. It's a tie.\n");
      } else {
        if (turn == 0) {
          player = 'O';
          turn = 1;
        } else {
          player = 'X';
          turn = 0;
        }
      }
    }
  }
}

int main() {
  int choice;
  srand(time(NULL));
  printf("Welcome to my unique C table game!\n");
  do {
    printf("Choose an option:\n");
    printf("1. Play game\n");
    printf("2. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        play_game();
        break;
      case 2:
        printf("Thanks for playing!\n");
        break;
      default:
        printf("Invalid option. Try again.\n");
        break;
    }
  } while (choice != 2);
  return 0;
}