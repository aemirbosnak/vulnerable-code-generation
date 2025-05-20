//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

/* function declarations */
void print_board(char board[3][3]);
bool is_game_over(char board[3][3], int *winner);
bool fill_or_block(char board[3][3], char symbol, int *row, int *column);
void play_move(char board[3][3], char symbol);

/* main function */
int main() {
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  int winner;
  bool game_over = false;
  
  printf("Welcome to the unique Tic Tac Toe AI program!\n");
  printf("You will be playing against the computer.\n");
  printf("You are X and the computer is O.\n");
  printf("You will make the first move.\n");
  
  while (!game_over) {
    print_board(board);

    // player's turn
    int row, column;
    printf("Enter the row (1-3) and column (1-3) of your move: ");
    scanf("%d %d", &row, &column);
    row--;
    column--;

    if (board[row][column] == ' ') {
      board[row][column] = 'X';
    } else {
      printf("That space is already taken. Try again.\n");
      continue;
    }

    // check if game is over
    game_over = is_game_over(board, &winner);
    if (game_over) break;

    // computer's turn
    fill_or_block(board, 'O', &row, &column);
    if (row != -1 && column != -1) {
      board[row][column] = 'O';
    } else {
      play_move(board, 'O');
    }

    // check if game is over
    game_over = is_game_over(board, &winner);
  }

  print_board(board);

  if (winner == 1) {
    printf("Congratulations, you won!\n");
  } else if (winner == 2) {
    printf("The computer won. Better luck next time!\n");
  } else {
    printf("It's a tie!\n");
  }

  return 0;
}

/* function definitions */

void print_board(char board[3][3]) {
  printf("\n");
  printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}

bool is_game_over(char board[3][3], int *winner) {
  // row check
  for (int i = 0; i < 3; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      *winner = (board[i][0] == 'X') ? 1 : 2;
      return true;
    }
  }

  // column check
  for (int i = 0; i < 3; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      *winner = (board[0][i] == 'X') ? 1 : 2;
      return true;
    }
  }

  // diagonal check
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    *winner = (board[0][0] == 'X') ? 1 : 2;
    return true;
  }

  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    *winner = (board[0][2] == 'X') ? 1 : 2;
    return true;
  }

  // check if there are any empty spaces left
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == ' ') {
        return false;
      }
    }
  }

  // if there are no empty spaces left, it's a tie
  *winner = 0;
  return true;
}

bool fill_or_block(char board[3][3], char symbol, int *row, int *column) {
  // row check
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == symbol && board[i][0] == board[i][1] && board[i][2] == ' ') {
      *row = i;
      *column = 2;
      return true;
    }

    if (board[i][1] == symbol && board[i][1] == board[i][2] && board[i][0] == ' ') {
      *row = i;
      *column = 0;
      return true;
    }

    if (board[i][0] == symbol && board[i][0] == board[i][2] && board[i][1] == ' ') {
      *row = i;
      *column = 1;
      return true;
    }
  }

  // column check
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == symbol && board[0][i] == board[1][i] && board[2][i] == ' ') {
      *row = 2;
      *column = i;
      return true;
    }

    if (board[1][i] == symbol && board[1][i] == board[2][i] && board[0][i] == ' ') {
      *row = 0;
      *column = i;
      return true;
    }

    if (board[0][i] == symbol && board[0][i] == board[2][i] && board[1][i] == ' ') {
      *row = 1;
      *column = i;
      return true;
    }
  }

  // diagonal check
  if (board[0][0] == symbol && board[0][0] == board[1][1] && board[2][2] == ' ') {
    *row = 2;
    *column = 2;
    return true;
  }

  if (board[1][1] == symbol && board[1][1] == board[2][2] && board[0][0] == ' ') {
    *row = 0;
    *column = 0;
    return true;
  }

  if (board[0][0] == symbol && board[0][0] == board[2][2] && board[1][1] == ' ') {
    *row = 1;
    *column = 1;
    return true;
  }

  if (board[0][2] == symbol && board[0][2] == board[1][1] && board[2][0] == ' ') {
    *row = 2;
    *column = 0;
    return true;
  }

  if (board[1][1] == symbol && board[1][1] == board[2][0] && board[0][2] == ' ') {
    *row = 0;
    *column = 2;
    return true;
  }

  if (board[0][2] == symbol && board[0][2] == board[2][0] && board[1][1] == ' ') {
    *row = 1;
    *column = 1;
    return true;
  }

  *row = -1;
  *column = -1;
  return false;
}

void play_move(char board[3][3], char symbol) {
  int row, column;
  srand(time(NULL));
  do {
    row = rand() % 3;
    column = rand() % 3;
  } while (board[row][column] != ' ');
  board[row][column] = symbol;
}