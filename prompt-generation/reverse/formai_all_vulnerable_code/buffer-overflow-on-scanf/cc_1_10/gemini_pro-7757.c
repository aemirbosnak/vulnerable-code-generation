//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define N 3

// The board
char board[N][N];

// The player
char player = 'X';

// The AI
char ai = 'O';

// The winner
char winner = ' ';

// Prints the board
void print_board() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Checks if the game is over
int is_game_over() {
  // Check rows
  for (int i = 0; i < N; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      winner = board[i][0];
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < N; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      winner = board[0][j];
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    winner = board[0][0];
    return 1;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    winner = board[0][2];
    return 1;
  }

  // Check if there are any empty cells
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }

  // If there are no empty cells, the game is a draw
  winner = ' ';
  return 1;
}

// The AI's move
void ai_move() {
  // If the AI can win, it will do so
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = ai;
        if (is_game_over()) {
          winner = ai;
          return;
        }
        board[i][j] = ' ';
      }
    }
  }

  // If the player can win, the AI will block it
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = player;
        if (is_game_over()) {
          board[i][j] = ' ';
          board[i][j] = ai;
          return;
        }
        board[i][j] = ' ';
      }
    }
  }

  // If the center is empty, the AI will take it
  if (board[1][1] == ' ') {
    board[1][1] = ai;
    return;
  }

  // If a corner is empty, the AI will take it
  for (int i = 0; i < N; i += 2) {
    for (int j = 0; j < N; j += 2) {
      if (board[i][j] == ' ') {
        board[i][j] = ai;
        return;
      }
    }
  }

  // If a side is empty, the AI will take it
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N - 1; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = ai;
        return;
      }
    }
  }
}

// The player's move
void player_move() {
  int i, j;

  printf("Enter the row and column (0-2): ");
  scanf("%d %d", &i, &j);

  if (i < 0 || i > 2 || j < 0 || j > 2) {
    printf("Invalid move!\n");
    return;
  }

  if (board[i][j] != ' ') {
    printf("Cell already occupied!\n");
    return;
  }

  board[i][j] = player;
}

int main() {
  // Initialize the board
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = ' ';
    }
  }

  // Game loop
  while (!is_game_over()) {
    // Print the board
    print_board();

    // The player's move
    player_move();

    // Check if the game is over
    if (is_game_over()) {
      break;
    }

    // The AI's move
    ai_move();
  }

  // Print the board
  print_board();

  // Print the winner
  if (winner == player) {
    printf("Player wins!\n");
  } else if (winner == ai) {
    printf("AI wins!\n");
  } else {
    printf("Draw!\n");
  }

  return 0;
}