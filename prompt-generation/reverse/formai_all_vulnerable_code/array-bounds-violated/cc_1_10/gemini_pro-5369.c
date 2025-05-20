//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the table size
#define SIZE 5

// Define the number of players
#define PLAYERS 2

// Define the game board
char board[SIZE][SIZE];

// Define the player symbols
char symbols[PLAYERS] = {'X', 'O'};

// Function to print the game board
void print_board() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if the game is over
int check_winner() {
  // Check for horizontal wins
  for (int i = 0; i < SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return 1;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return 1;
    }
  }

  // Check for diagonal wins
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return 1;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return 1;
  }

  // Check for a tie
  int tie = 1;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == ' ') {
        tie = 0;
        break;
      }
    }
  }
  if (tie) {
    return 2;
  }

  // No winner yet
  return 0;
}

// Function to get the player's move
int get_move(int player) {
  int move;
  printf("Player %d, enter your move (1-%d): ", player + 1, SIZE * SIZE);
  scanf("%d", &move);
  return move - 1;
}

// Function to make a move on the board
void make_move(int player, int move) {
  int row = move / SIZE;
  int col = move % SIZE;
  board[row][col] = symbols[player];
}

// Function to play the game
void play_game() {
  int player = 0;
  int winner = 0;
  int move;

  // Print the initial game board
  print_board();

  // Loop until the game is over
  while (winner == 0) {
    // Get the player's move
    move = get_move(player);

    // Make the move on the board
    make_move(player, move);

    // Print the updated game board
    print_board();

    // Check if the game is over
    winner = check_winner();

    // Switch to the other player
    player = (player + 1) % PLAYERS;
  }

  // Print the winner
  if (winner == 1) {
    printf("Player %d wins!\n", player + 1);
  } else {
    printf("Tie game!\n");
  }
}

// Main function
int main() {
  // Initialize the game board
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Play the game
  play_game();

  return 0;
}