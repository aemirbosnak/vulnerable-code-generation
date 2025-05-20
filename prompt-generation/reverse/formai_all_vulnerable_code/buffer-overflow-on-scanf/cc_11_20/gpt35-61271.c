//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>

// Print the Tic-Tac-Toe board
void print_board(char board[]) {
  printf("\n     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
  printf("_____|_____|_____\n");

  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
  printf("_____|_____|_____\n");

  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
  printf("     |     |     \n");
}

// Check if the player with the specified mark has won the game
int check_win(char board[], char mark) {
  // Check rows
  if ((board[0] == mark && board[1] == mark && board[2] == mark) ||
      (board[3] == mark && board[4] == mark && board[5] == mark) ||
      (board[6] == mark && board[7] == mark && board[8] == mark)) {
    return 1;
  }

  // Check columns
  if ((board[0] == mark && board[3] == mark && board[6] == mark) ||
      (board[1] == mark && board[4] == mark && board[7] == mark) ||
      (board[2] == mark && board[5] == mark && board[8] == mark)) {
    return 1;
  }

  // Check diagonals
  if ((board[0] == mark && board[4] == mark && board[8] == mark) ||
      (board[2] == mark && board[4] == mark && board[6] == mark)) {
    return 1;
  }

  // No win condition met
  return 0;
}

// Check if the game is over (no more moves available or a player has won)
int game_over(char board[]) {
  int i;
  // Check if all spaces have been filled (i.e. no moves left)
  for (i = 0; i < 9; i++) {
    if (board[i] == ' ') {
      break;
    }
  }
  if (i == 9) {
    return 1;
  }

  // Check if a player has won
  if (check_win(board, 'X') || check_win(board, 'O')) {
    return 1;
  }

  // Game is not over
  return 0;
}

// Evaluate a board configuration (currently uses simple heuristic)
int evaluate(char board[], char player) {
  int i, score = 0;

  // Look for rows that can be won
  for (i = 0; i < 9; i += 3) {
    if ((board[i] == player && board[i+1] == player && board[i+2] == ' ') ||
        (board[i] == player && board[i+1] == ' ' && board[i+2] == player) ||
        (board[i] == ' ' && board[i+1] == player && board[i+2] == player)) {
      score += 10;
    }
  }

  // Look for columns that can be won
  for (i = 0; i < 3; i++) {
    if ((board[i] == player && board[i+3] == player && board[i+6] == ' ') ||
        (board[i] == player && board[i+3] == ' ' && board[i+6] == player) ||
        (board[i] == ' ' && board[i+3] == player && board[i+6] == player)) {
      score += 10;
    }
  }

  // Look for diagonal that can be won
  if ((board[0] == player && board[4] == player && board[8] == ' ') ||
      (board[0] == player && board[4] == ' ' && board[8] == player) ||
      (board[0] == ' ' && board[4] == player && board[8] == player) ||
      (board[2] == player && board[4] == player && board[6] == ' ') ||
      (board[2] == player && board[4] == ' ' && board[6] == player) ||
      (board[2] == ' ' && board[4] == player && board[6] == player)) {
    score += 10;
  }

  // Return the score
  return score;
}

// Minimax algorithm with alpha-beta pruning
int minimax(char board[], int depth, int alpha, int beta, char player) {
  int i, score, best_score, best_move = -1;

  // Check if game is over or depth limit has been reached
  if (game_over(board) || depth == 0) {
    return evaluate(board, 'O');
  }

  // Use minimax algorithm to determine the best move to make
  if (player == 'O') {
    best_score = beta;
    for (i = 0; i < 9; i++) {
      if (board[i] == ' ') {
        board[i] = 'O';
        score = minimax(board, depth-1, alpha, best_score, 'X');
        board[i] = ' ';
        if (score < best_score) {
          best_score = score;
          best_move = i;
        }
        if (best_score <= alpha) {
          return best_score;
        }
      }
    }
  }
  else { // player == 'X'
    best_score = alpha;
    for (i = 0; i < 9; i++) {
      if (board[i] == ' ') {
        board[i] = 'X';
        score = minimax(board, depth-1, best_score, beta, 'O');
        board[i] = ' ';
        if (score > best_score) {
          best_score = score;
          best_move = i;
        }
        if (best_score >= beta) {
          return best_score;
        }
      }
    }
  }

  // Return the best move score or position
  if (depth == 3) {
    return best_move; // Return position of best move
  }
  else {
    return best_score; // Return score of best move
  }
}

// Make the computer's move using minimax algorithm
void computer_move(char board[]) {
  int move = minimax(board, 3, -10000, 10000, 'O');
  board[move] = 'O';
  printf("\nComputer move (O): %d\n", move+1);
}

int main() {
  int i, pos;
  char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

  printf("\nWelcome to Tic-Tac-Toe!\n\n");
  printf("Positions:\n");
  printf("  1 | 2 | 3 \n");
  printf("____|___|____\n");
  printf("  4 | 5 | 6 \n");
  printf("____|___|____\n");
  printf("  7 | 8 | 9 \n");
  printf("    |   |    \n");

  while (!game_over(board)) {
    // Get player's move
    printf("\nPlayer move (X): ");
    scanf("%d", &pos);
    if (board[pos-1] != ' ') {
      printf("\nInvalid move!\n");
      continue;
    }
    board[pos-1] = 'X';

    // Print the board
    print_board(board);

    // Check if game is over
    if (game_over(board)) {
      break;
    }

    // Make the computer's move
    computer_move(board);

    // Print the board
    print_board(board);
  }

  // Print the final board configuration
  printf("\nFinal board configuration:\n");
  print_board(board);

  // Print the winner or a tie
  if (check_win(board, 'X')) {
    printf("\nPlayer (X) has won the game!\n");
  }
  else if (check_win(board, 'O')) {
    printf("\nComputer (O) has won the game!\n");
  }
  else {
    printf("\nIt is a tie!\n");
  }

  return 0;
}