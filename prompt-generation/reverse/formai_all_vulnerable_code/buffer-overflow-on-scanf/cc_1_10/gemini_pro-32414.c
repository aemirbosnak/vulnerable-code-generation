//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Card struct
typedef struct card {
  int value;
  int revealed;
} card;

// Board struct
typedef struct board {
  card cards[BOARD_SIZE][BOARD_SIZE];
} board;

// Function to initialize the board
void init_board(board *b) {
  int values[NUM_PAIRS * 2];
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    values[i] = i / 2;
  }

  // Shuffle the values
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    int j = rand() % (NUM_PAIRS * 2);
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
  }

  // Set the values on the board
  int index = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      b->cards[i][j].value = values[index];
      b->cards[i][j].revealed = 0;
      index++;
    }
  }
}

// Function to print the board
void print_board(board *b) {
  printf("   ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (b->cards[i][j].revealed) {
        printf("%2d ", b->cards[i][j].value);
      } else {
        printf("** ");
      }
    }
    printf("\n");
  }
}

// Function to get the player's input
void get_input(int *row, int *col) {
  printf("Enter the row and column of the card you want to reveal (e.g. 1 2): ");
  scanf("%d %d", row, col);
  *row -= 1;
  *col -= 1;
}

// Function to check if the game is over
int game_over(board *b) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (!b->cards[i][j].revealed) {
        return 0;
      }
    }
  }
  return 1;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the board
  board b;
  init_board(&b);

  // Print the board
  print_board(&b);

  // Get the player's input
  int row1, col1, row2, col2;
  get_input(&row1, &col1);
  get_input(&row2, &col2);

  // Reveal the cards
  b.cards[row1][col1].revealed = 1;
  b.cards[row2][col2].revealed = 1;

  // Print the board
  print_board(&b);

  // Check if the game is over
  if (game_over(&b)) {
    printf("Congratulations! You won!\n");
  } else {
    printf("Keep playing!\n");
  }

  return 0;
}