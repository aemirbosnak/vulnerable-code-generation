//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES (BOARD_SIZE * BOARD_SIZE / 2)

// Structure for holding a tile's position on the board
typedef struct {
  int row;
  int col;
} Position;


// Function declarations
void init_board(int board[BOARD_SIZE][BOARD_SIZE], int num_pairs);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int play_game(int board[BOARD_SIZE][BOARD_SIZE]);
int check_for_match(int board[BOARD_SIZE][BOARD_SIZE], Position pos1, Position pos2);

int main() {
  int board[BOARD_SIZE][BOARD_SIZE];
  int num_pairs = MAX_MOVES / 2;
  srand(time(NULL));

  // Initialize the board and print it
  init_board(board, num_pairs);
  print_board(board);

  // Play the game and get the number of moves made
  int num_moves = play_game(board);

  // Print the final board and the number of moves made
  printf("Final Board:\n");
  print_board(board);
  printf("Number of Moves: %d\n", num_moves);

  return 0;
}


// Function to initialize the game board
void init_board(int board[BOARD_SIZE][BOARD_SIZE], int num_pairs) {
  int values[MAX_MOVES];
  int curr_value, remaining_pairs;
  Position pos;
  
  // Initialize the values array
  for (int i = 1; i <= MAX_MOVES; i++) {
    values[i - 1] = i;
  }
  
  // Shuffle the values array
  for (int i = 0; i < MAX_MOVES; i++) {
    int j = rand() % MAX_MOVES;
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
  }
  
  // Set the board positions to their values
  remaining_pairs = num_pairs;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (remaining_pairs > 0) {
        board[i][j] = values[curr_value];
        curr_value++;
        if (curr_value >= MAX_MOVES) {
          curr_value = 0;
        }
        remaining_pairs--;
      } else {
        board[i][j] = 0;
      }
    }
  }
}


// Function to print the game board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        printf("   ");
      } else {
        printf("%2d ", board[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}


// Function to play the game
int play_game(int board[BOARD_SIZE][BOARD_SIZE]) {
  Position pos1, pos2;
  int num_moves = 0;
  
  do {
    // Get the first tile position from the user
    printf("Enter first tile position (row col): ");
    scanf("%d %d", &pos1.row, &pos1.col);
    
    // Get the second tile position from the user
    printf("Enter second tile position (row col): ");
    scanf("%d %d", &pos2.row, &pos2.col);
    
    // Check for a match and update the board
    if (check_for_match(board, pos1, pos2)) {
      board[pos1.row][pos1.col] = 0;
      board[pos2.row][pos2.col] = 0;
      num_moves++;
    }
    
    // Print the current board state
    print_board(board);
    
  } while (num_moves < MAX_MOVES/2);

  return num_moves;
}


// Function to check if two positions on the board have matching values
int check_for_match(int board[BOARD_SIZE][BOARD_SIZE], Position pos1, Position pos2) {
  if (board[pos1.row][pos1.col] == board[pos2.row][pos2.col]) {
    return 1;
  } else {
    return 0;
  }
}