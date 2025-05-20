//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the table size
#define TABLE_SIZE 5

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Create the table
char table[TABLE_SIZE][TABLE_SIZE];

// Initialize the table
void initializeTable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = ' ';
    }
  }
}

// Print the table
void printTable() {
  printf("\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("%c ", table[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Get the player's move
int getMove(char playerSymbol) {
  int move;
  printf("Player %c, enter your move (1-9): ", playerSymbol);
  scanf("%d", &move);
  return move;
}

// Check if the move is valid
int isValidMove(int move) {
  return (move >= 1 && move <= TABLE_SIZE * TABLE_SIZE && table[(move - 1) / TABLE_SIZE][(move - 1) % TABLE_SIZE] == ' ');
}

// Make the move
void makeMove(int move, char playerSymbol) {
  table[(move - 1) / TABLE_SIZE][(move - 1) % TABLE_SIZE] = playerSymbol;
}

// Check if there is a winner
int checkWinner() {
  // Check rows
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i][0] != ' ' && table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
      return table[i][0];
    }
  }

  // Check columns
  for (int j = 0; j < TABLE_SIZE; j++) {
    if (table[0][j] != ' ' && table[0][j] == table[1][j] && table[1][j] == table[2][j]) {
      return table[0][j];
    }
  }

  // Check diagonals
  if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
    return table[0][0];
  }

  if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
    return table[0][2];
  }

  // Check if there is a tie
  int count = 0;
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      if (table[i][j] != ' ') {
        count++;
      }
    }
  }

  if (count == TABLE_SIZE * TABLE_SIZE) {
    return 'T';
  }

  // No winner yet
  return ' ';
}

// Main game loop
int main() {
  // Initialize the table
  initializeTable();

  // Print the table
  printTable();

  // Get the player's moves
  int move;
  char playerSymbol = PLAYER1_SYMBOL;
  while ((move = getMove(playerSymbol)) != 0) {
    // Check if the move is valid
    if (!isValidMove(move)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    makeMove(move, playerSymbol);

    // Print the table
    printTable();

    // Check if there is a winner
    char winner = checkWinner();
    if (winner != ' ') {
      if (winner == 'T') {
        printf("Tie game!\n");
      } else {
        printf("Player %c wins!\n", winner);
      }
      break;
    }

    // Switch player
    playerSymbol = (playerSymbol == PLAYER1_SYMBOL) ? PLAYER2_SYMBOL : PLAYER1_SYMBOL;
  }

  return 0;
}