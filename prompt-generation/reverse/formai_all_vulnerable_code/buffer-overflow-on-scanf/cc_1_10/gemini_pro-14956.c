//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

// The game board
char board[BOARD_SIZE][BOARD_SIZE];

// The current player
char current_player;

// The winner of the game
char winner;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Check if the game is over
int is_game_over() {
  // Check for a win
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      winner = board[i][0];
      return 1;
    }
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      winner = board[0][i];
      return 1;
    }
  }

  // Check for a tie
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }

  if (count == BOARD_SIZE * BOARD_SIZE) {
    winner = 'T';
    return 1;
  }

  // The game is not over
  return 0;
}

// Get the next move from the player
void get_move(char player) {
  int row, col;

  printf("Player %c, enter your move (row, col): ", player);
  scanf("%d %d", &row, &col);

  // Check if the move is valid
  while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
    printf("Invalid move. Please try again.\n");
    scanf("%d %d", &row, &col);
  }

  // Make the move
  board[row][col] = player;
}

// The AI's move
void ai_move() {
  // Check for a winning move
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        // Try to make a winning move
        board[i][j] = current_player;
        if (is_game_over()) {
          return;
        }
        // Undo the move
        board[i][j] = ' ';
      }
    }
  }

  // Check for a blocking move
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        // Try to make a blocking move
        board[i][j] = current_player == 'X' ? 'O' : 'X';
        if (is_game_over()) {
          // Undo the move
          board[i][j] = ' ';
          // Make the blocking move
          board[i][j] = current_player;
          return;
        }
        // Undo the move
        board[i][j] = ' ';
      }
    }
  }

  // Make a random move
  while (1) {
    int row = rand() % 3;
    int col = rand() % 3;
    if (board[row][col] == ' ') {
      board[row][col] = current_player;
      return;
    }
  }
}

// Play the game
void play_game() {
  init_board();

  // Set the current player
  current_player = 'X';

  // Play the game until it is over
  while (!is_game_over()) {
    // Get the player's move
    if (current_player == 'X') {
      get_move(current_player);
    } else {
      ai_move();
    }

    // Print the game board
    print_board();

    // Switch the current player
    current_player = current_player == 'X' ? 'O' : 'X';
  }

  // Print the winner
  if (winner == 'X' || winner == 'O') {
    printf("Player %c wins!\n", winner);
  } else {
    printf("Tie!\n");
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}