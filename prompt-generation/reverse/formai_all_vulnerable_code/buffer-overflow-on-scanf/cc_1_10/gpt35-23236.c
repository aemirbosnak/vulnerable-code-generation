//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>

// function to display the board
void display_board(char board[3][3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// function to check for a winner
int check_winner(char board[3][3], char symbol) {
  int i, j;
  for (i = 0; i < 3; i++) {
    // check rows
    if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
      return 1;
    }
    // check columns
    if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
      return 1;
    }
  }
  // check diagonals
  if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
    return 1;
  }
  if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
    return 1;
  }
  return 0;
}

// function to get the player's move
void get_move(char board[3][3], char player_symbol) {
  int row, col;
  printf("Player %c, enter your move (row column): ", player_symbol);
  scanf("%d %d", &row, &col);
  if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == '_') {
    board[row][col] = player_symbol;
  } else {
    printf("Invalid move, try again.\n");
    get_move(board, player_symbol);
  }
}

// function to get the AI's move
void get_ai_move(char board[3][3], char ai_symbol) {
  int row, col;
  // check for winning move
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == '_') {
        board[i][j] = ai_symbol;
        if (check_winner(board, ai_symbol)) {
          return;
        } else {
          board[i][j] = '_';
        }
      }
    }
  }
  // check for blocking move
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == '_') {
        board[i][j] = 'X';
        if (check_winner(board, 'X')) {
          board[i][j] = ai_symbol;
          return;
        } else {
          board[i][j] = '_';
        }
      }
    }
  }
  // if no winning or blocking move, make a random move
  while (1) {
    row = rand() % 3;
    col = rand() % 3;
    if (board[row][col] == '_') {
      board[row][col] = ai_symbol;
      return;
    }
  }
}

int main() {
  char board[3][3] = {
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
  };
  char player_symbol, ai_symbol;
  printf("Choose your symbol (X or O): ");
  scanf("%c", &player_symbol);
  if (player_symbol == 'X') {
    ai_symbol = 'O';
  } else {
    ai_symbol = 'X';
  }
  int turn = 0;
  while (1) {
    display_board(board);
    if (turn % 2 == 0) {
      get_move(board, player_symbol);
      if (check_winner(board, player_symbol)) {
        printf("Congratulations, you win!\n");
        break;
      }
    } else {
      get_ai_move(board, ai_symbol);
      if (check_winner(board, ai_symbol)) {
        printf("Sorry, you lose.\n");
        break;
      }
    }
    turn++;
    if (turn == 9) {
      printf("It's a tie!\n");
      break;
    }
  }
  return 0;
}