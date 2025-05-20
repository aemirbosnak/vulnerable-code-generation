//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: distributed
int main() {
  int player = 1; // 1 for X, 2 for O
  int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  while (1) {
    // Player 1 makes a move
    int row, col;
    do {
      printf("Enter row and column for player %d: ", player);
      scanf("%d %d", &row, &col);
    } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != 0);
    board[row - 1][col - 1] = player;

    // Check if game is over
    if (is_game_over(board)) {
      printf("Player %d wins!\n", player);
      break;
    }

    // Switch players
    player = player == 1 ? 2 : 1;
  }
  return 0;
}

int is_game_over(int board[3][3]) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return 1;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return 1;
  }

  // Check for draw
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }

  // No winner or draw
  return -1;
}