//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void print_board(int board[3][3]);
int check_win(int board[3][3], int player);
int get_player_move(int board[3][3], int player);
int get_computer_move(int board[3][3], int player);
void clear_board(int board[3][3]);

int main() {
  int board[3][3];
  int player = 1;
  int computer = 2;
  int winner = 0;
  int turn = 0;
  srand(time(NULL));

  // clear the board to start the game
  clear_board(board);

  // main game loop
  while (winner == 0 && turn < 9) {
    // print the current state of the board
    printf("Player %d's turn:\n", player);
    print_board(board);

    // get the current player's move
    int move;
    if (player == 1) {
      move = get_player_move(board, player);
    } else {
      move = get_computer_move(board, player);
    }

    // update the board with the current player's move
    int x = (move - 1) / 3;
    int y = (move - 1) % 3;
    board[x][y] = player;

    // check if the current player has won
    winner = check_win(board, player);

    // switch to the other player
    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }

    // increment the turn counter
    turn++;
  }

  // print the final state of the board
  printf("Final board state:\n");
  print_board(board);

  // declare the winner
  if (winner == 0) {
    printf("The game is a tie!\n");
  } else {
    printf("Player %d wins!\n", winner);
  }

  return 0;
}

/**
 * Prints the current state of the board.
 */
void print_board(int board[3][3]) {
  printf("   1 2 3\n");
  for (int i = 0; i < 3; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < 3; j++) {
      char c = ' ';
      if (board[i][j] == 1) {
        c = 'X';
      } else if (board[i][j] == 2) {
        c = 'O';
      }
      printf("%c ", c);
    }
    printf("\n");
  }
}

/**
 * Checks if the current player has won.
 */
int check_win(int board[3][3], int player) {
  // check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return player;
    }
  }

  // check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return player;
    }
  }

  // check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return player;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return player;
  }

  // no winner
  return 0;
}

/**
 * Gets the current player's move.
 */
int get_player_move(int board[3][3], int player) {
  int move = 0;
  do {
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
  } while (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] != 0);
  return move;
}

/**
 * Gets the computer's move.
 */
int get_computer_move(int board[3][3], int player) {
  // look for a winning move
  for (int i = 1; i <= 9; i++) {
    int x = (i - 1) / 3;
    int y = (i - 1) % 3;
    if (board[x][y] == 0) {
      board[x][y] = player;
      if (check_win(board, player) == player) {
        board[x][y] = 0;
        return i;
      }
      board[x][y] = 0;
    }
  }

  // look for a blocking move
  int other_player = (player == 1) ? 2 : 1;
  for (int i = 1; i <= 9; i++) {
    int x = (i - 1) / 3;
    int y = (i - 1) % 3;
    if (board[x][y] == 0) {
      board[x][y] = other_player;
      if (check_win(board, other_player) == other_player) {
        board[x][y] = player;
        return i;
      }
      board[x][y] = 0;
    }
  }

  // pick a random move
  int move = rand() % 9 + 1;
  while (board[(move - 1) / 3][(move - 1) % 3] != 0) {
    move = rand() % 9 + 1;
  }
  return move;
}

/**
 * Clears the board to start the game.
 */
void clear_board(int board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }
}