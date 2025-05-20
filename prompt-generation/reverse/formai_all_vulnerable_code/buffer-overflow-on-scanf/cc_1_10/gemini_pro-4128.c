//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board size
#define BOARD_SIZE 5

// Define the number of players
#define NUM_PLAYERS 2

// Define the player types
#define HUMAN_PLAYER 0
#define COMPUTER_PLAYER 1

// Define the game states
#define GAME_NOT_STARTED 0
#define GAME_IN_PROGRESS 1
#define GAME_OVER 2

// Define the winning combinations
int winningCombinations[8][3] = {
  {0, 1, 2},
  {3, 4, 5},
  {6, 7, 8},
  {0, 3, 6},
  {1, 4, 7},
  {2, 5, 8},
  {0, 4, 8},
  {2, 4, 6}
};

// Define the board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player turns
int playerTurns[NUM_PLAYERS];

// Define the game state
int gameState;

// Define the current player
int currentPlayer;

// Initialize the board
void initializeBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the board
void printBoard() {
  printf("  0 1 2\n");
  printf("  ------\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d |", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf(" %c |", board[i][j]);
    }
    printf("\n  ------\n");
  }
}

// Get the player input
int getPlayerInput() {
  int move;
  do {
    printf("Player %d, enter your move (0-8): ", currentPlayer + 1);
    scanf("%d", &move);
  } while (move < 0 || move > 8 || board[move / BOARD_SIZE][move % BOARD_SIZE] != ' ');
  return move;
}

// Make a move
void makeMove(int move, int player) {
  board[move / BOARD_SIZE][move % BOARD_SIZE] = player == HUMAN_PLAYER ? 'X' : 'O';
}

// Check if the game is over
int checkGameOver() {
  // Check if there is a winner
  for (int i = 0; i < 8; i++) {
    if (board[winningCombinations[i][0] / BOARD_SIZE][winningCombinations[i][0] % BOARD_SIZE] != ' ' &&
        board[winningCombinations[i][0] / BOARD_SIZE][winningCombinations[i][0] % BOARD_SIZE] == board[winningCombinations[i][1] / BOARD_SIZE][winningCombinations[i][1] % BOARD_SIZE] &&
        board[winningCombinations[i][0] / BOARD_SIZE][winningCombinations[i][0] % BOARD_SIZE] == board[winningCombinations[i][2] / BOARD_SIZE][winningCombinations[i][2] % BOARD_SIZE]) {
      return board[winningCombinations[i][0] / BOARD_SIZE][winningCombinations[i][0] % BOARD_SIZE] == 'X' ? HUMAN_PLAYER : COMPUTER_PLAYER;
    }
  }

  // Check if there is a tie
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == BOARD_SIZE * BOARD_SIZE) {
    return -1;
  }

  // Otherwise, the game is still in progress
  return GAME_IN_PROGRESS;
}

// Main game loop
void gameLoop() {
  // Initialize the game
  initializeBoard();
  gameState = GAME_NOT_STARTED;
  currentPlayer = HUMAN_PLAYER;

  // Start the game
  while (gameState == GAME_IN_PROGRESS) {
    // Print the board
    printBoard();

    // Get the player input
    int move = getPlayerInput();

    // Make the move
    makeMove(move, currentPlayer);

    // Check if the game is over
    gameState = checkGameOver();

    // Switch the current player
    currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
  }

  // Print the final board
  printBoard();

  // Announce the winner
  if (gameState == HUMAN_PLAYER) {
    printf("Human player wins!\n");
  } else if (gameState == COMPUTER_PLAYER) {
    printf("Computer player wins!\n");
  } else {
    printf("Tie!\n");
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Start the game loop
  while (1) {
    gameLoop();

    // Ask the player if they want to play again
    char answer;
    printf("Do you want to play again (y/n)? ");
    scanf(" %c", &answer);
    if (answer == 'n') {
      break;
    }
  }

  return 0;
}