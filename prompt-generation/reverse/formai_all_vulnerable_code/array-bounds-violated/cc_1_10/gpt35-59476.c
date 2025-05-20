//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
int all_moves[9] = {1,2,3,4,5,6,7,8,9};

void init_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void print_board() {
  printf("\n");
  printf("\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("\t\t---|---|---\n");
  printf("\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("\t\t---|---|---\n");
  printf("\t\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int is_move_possible(int move) {
  for (int i = 0; i < 9; i++) {
    if (all_moves[i] == move) {
      all_moves[i] = 0;
      return 1;
    }
  }
  return 0;
}

int make_computer_move(char player) {
  int row, col;
  int move = -1;
  srand(time(0));

  while (move == -1) {
    int num = rand() % 9 + 1;

    if (is_move_possible(num)) {
      move = num;
      row = (num - 1) / 3;
      col = (num - 1) % 3;
      board[row][col] = player;
    }
  }

  return move;
}

int is_game_over(char player) {
  // check diagonal matches
  if (board[0][0] == player &&
      board[1][1] == player &&
      board[2][2] == player) {
    return 1;
  }

  if (board[0][2] == player &&
      board[1][1] == player &&
      board[2][0] == player) {
    return 1;
  }

  // check row matches
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player &&
        board[i][1] == player &&
        board[i][2] == player) {
      return 1;
    }
  }

  // check col matches
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == player &&
        board[1][i] == player &&
        board[2][i] == player) {
      return 1;
    }
  }

  return 0;
}

int main() {
  int player_move;
  int total_moves = 0;
  char player = 'X';
  int game_over = 0;
  int computer_move;

  init_board();
  print_board();

  while (!game_over) {
    if (player == 'X') {
      printf("\nPlayer 1 turn: ");
      scanf("%d", &player_move);
      if (!is_move_possible(player_move)) {
        printf("\nInvalid move. Try again.\n");
        continue;
      }
      int row = (player_move - 1) / 3;
      int col = (player_move - 1) % 3;
      board[row][col] = 'X';
      total_moves++;
      player = 'O';
    } else {
      printf("\nComputer's turn: \n");
      computer_move = make_computer_move('O');
      printf("Computer chooses position %d\n", computer_move);
      total_moves++;
      player = 'X';
    }

    print_board();
    game_over = is_game_over('X') || is_game_over('O');

    if (game_over) {
      printf("\nGame Over!\n");
      if (is_game_over('X')) {
        printf("Player 1 wins!\n");
      } else if (is_game_over('O')) {
        printf("Computer wins!\n");
      } else {
        printf("Tie game.\n");
      }
    } else if (total_moves == 9) {
      printf("\nGame Over!\n");
      printf("Tie game.\n");
      game_over = 1;
    }
  }

  return 0;
}