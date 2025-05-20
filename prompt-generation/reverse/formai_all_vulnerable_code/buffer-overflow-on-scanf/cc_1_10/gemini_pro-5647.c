//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// The board is represented as a 3x3 array of characters.
// Each cell can be either 'X', 'O', or ' '.
char board[3][3];

// The player is represented by the character 'X'.
// The computer is represented by the character 'O'.
char player = 'X';

// The computer's difficulty level.
// 0 = easy, 1 = medium, 2 = hard
int difficulty = 0;

// Function to initialize the game board.
void init_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board.
void print_board() {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if the game is over.
// Returns 0 if the game is not over, 1 if the player has won, and 2 if the computer has won.
int check_winner() {
  // Check for rows.
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if (board[i][0] == 'X') {
        return 1;
      } else if (board[i][0] == 'O') {
        return 2;
      }
    }
  }

  // Check for columns.
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      if (board[0][j] == 'X') {
        return 1;
      } else if (board[0][j] == 'O') {
        return 2;
      }
    }
  }

  // Check for diagonals.
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if (board[0][0] == 'X') {
      return 1;
    } else if (board[0][0] == 'O') {
      return 2;
    }
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    if (board[0][2] == 'X') {
      return 1;
    } else if (board[0][2] == 'O') {
      return 2;
    }
  }

  // Check for a tie.
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }

  if (count == 9) {
    return 3;
  }

  // The game is not over.
  return 0;
}

// Function to get the player's move.
void get_player_move() {
  int row, col;

  printf("Enter your move (row, column): ");
  scanf("%d %d", &row, &col);

  // Check if the move is valid.
  while (board[row - 1][col - 1] != ' ') {
    printf("Invalid move. Try again: ");
    scanf("%d %d", &row, &col);
  }

  // Place the player's move on the board.
  board[row - 1][col - 1] = 'X';
}

// Function to get the computer's move.
void get_computer_move() {
  int row, col;

  // Check if the computer can win.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = 'O';
        if (check_winner() == 2) {
          return;
        }
        board[i][j] = ' ';
      }
    }
  }

  // Check if the player can win.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = 'X';
        if (check_winner() == 1) {
          board[i][j] = 'O';
          return;
        }
        board[i][j] = ' ';
      }
    }
  }

  // Choose a random move.
  do {
    row = rand() % 3;
    col = rand() % 3;
  } while (board[row][col] != ' ');

  // Place the computer's move on the board.
  board[row][col] = 'O';
}

// Function to play the game.
void play_game() {
  // Initialize the game board.
  init_board();

  // Print the game board.
  print_board();

  // Loop until the game is over.
  while (check_winner() == 0) {
    // Get the player's move.
    get_player_move();

    // Print the game board.
    print_board();

    // Check if the player has won.
    if (check_winner() == 1) {
      printf("You win!\n");
      return;
    }

    // Get the computer's move.
    get_computer_move();

    // Print the game board.
    print_board();

    // Check if the computer has won.
    if (check_winner() == 2) {
      printf("You lose!\n");
      return;
    }
  }

  // The game is a tie.
  printf("Tie game!\n");
}

// Function to main.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Get the difficulty level from the user.
  printf("Enter the difficulty level (0-2): ");
  scanf("%d", &difficulty);

  // Play the game.
  play_game();

  return 0;
}