//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int **board;
int board_size;
int num_pairs;
int num_guesses;
int num_matches;

// Function prototypes
void init_board();
void print_board();
int get_input();
int check_match(int r1, int c1, int r2, int c2);
void update_board(int r1, int c1, int r2, int c2);
int check_win();

int main() {
  // Set the random seed
  srand(time(NULL));

  // Get the board size from the user
  printf("Enter the board size (e.g., 4 for a 4x4 board): ");
  scanf("%d", &board_size);

  // Calculate the number of pairs
  num_pairs = board_size * board_size / 2;

  // Allocate memory for the board
  board = (int **)malloc(sizeof(int *) * board_size);
  for (int i = 0; i < board_size; i++) {
    board[i] = (int *)malloc(sizeof(int) * board_size);
  }

  // Initialize the board
  init_board();

  // Print the board
  print_board();

  // Get input from the user until the game is won
  while (num_matches < num_pairs) {
    // Get the first card
    int r1, c1;
    printf("Enter the row and column of the first card (e.g., 1 2): ");
    scanf("%d %d", &r1, &c1);

    // Get the second card
    int r2, c2;
    printf("Enter the row and column of the second card (e.g., 3 4): ");
    scanf("%d %d", &r2, &c2);

    // Check if the cards match
    if (check_match(r1, c1, r2, c2)) {
      // Update the board
      update_board(r1, c1, r2, c2);

      // Print the board
      print_board();

      // Increment the number of matches
      num_matches++;
    } else {
      // Print an error message
      printf("The cards do not match.\n");
    }

    // Increment the number of guesses
    num_guesses++;
  }

  // Print a congratulatory message
  printf("Congratulations! You won the game in %d guesses.\n", num_guesses);

  // Free the memory allocated for the board
  for (int i = 0; i < board_size; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}

void init_board() {
  // Create a list of all the pairs
  int *pairs = (int *)malloc(sizeof(int) * num_pairs * 2);
  for (int i = 0; i < num_pairs; i++) {
    pairs[i * 2] = i;
    pairs[i * 2 + 1] = i;
  }

  // Shuffle the list
  for (int i = 0; i < num_pairs * 2; i++) {
    int r = rand() % (num_pairs * 2);
    int temp = pairs[i];
    pairs[i] = pairs[r];
    pairs[r] = temp;
  }

  // Fill the board with the pairs
  int count = 0;
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      board[i][j] = pairs[count++];
    }
  }

  // Free the memory allocated for the list
  free(pairs);
}

void print_board() {
  printf("  ");
  for (int i = 0; i < board_size; i++) {
    printf("%2d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < board_size; i++) {
    printf("%2d", i + 1);
    for (int j = 0; j < board_size; j++) {
      printf("%2d ", board[i][j]);
    }
    printf("\n");
  }
}

int get_input() {
  int input;
  while (1) {
    scanf("%d", &input);
    if (input >= 1 && input <= board_size) {
      return input - 1; // Adjust for 0-based indexing
    } else {
      printf("Invalid input. Please enter a number between 1 and %d: ", board_size);
    }
  }
}

int check_match(int r1, int c1, int r2, int c2) {
  return board[r1][c1] == board[r2][c2];
}

void update_board(int r1, int c1, int r2, int c2) {
  board[r1][c1] = -1;
  board[r2][c2] = -1;
}

int check_win() {
  return num_matches == num_pairs;
}