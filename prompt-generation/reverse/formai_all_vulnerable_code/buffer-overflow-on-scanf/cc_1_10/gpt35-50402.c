//FormAI DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// function declarations
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void shuffle_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
  char board[BOARD_SIZE][BOARD_SIZE];

  initialize_board(board);
  shuffle_board(board);
  print_board(board);
  play_game(board);

  return 0;
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  int count = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = (count % 10) + '0';
      count++;
    }
  }
}

void shuffle_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  srand(time(NULL));

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      int rand_i = rand() % BOARD_SIZE;
      int rand_j = rand() % BOARD_SIZE;

      // swap board[i][j] with board[rand_i][rand_j]
      char temp = board[i][j];
      board[i][j] = board[rand_i][rand_j];
      board[rand_i][rand_j] = temp;
    }
  }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  printf("Welcome to the Memory Game!\n\n");
  printf("Instructions:\n");
  printf("1. Memorize the positions of the numbers\n");
  printf("2. Select two cells to reveal their values\n");
  printf("3. If the values match, those cells will be removed from the board\n");
  printf("4. The game ends when all cells have been removed from the board\n\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void play_game(char board[BOARD_SIZE][BOARD_SIZE]) {
  int num_cells = BOARD_SIZE * BOARD_SIZE;
  int num_moves = 0;

  while (num_cells > 0) {
    int row1, col1, row2, col2;
    printf("Enter the row and column of the first cell to reveal: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the row and column of the second cell to reveal: ");
    scanf("%d %d", &row2, &col2);

    if ((row1 < 0) || (row1 >= BOARD_SIZE) || (col1 < 0) || (col1 >= BOARD_SIZE) ||
        (row2 < 0) || (row2 >= BOARD_SIZE) || (col2 < 0) || (col2 >= BOARD_SIZE)) {
      printf("Invalid input. Please enter valid row and column values.\n\n");
    } else if ((row1 == row2) && (col1 == col2)) {
      printf("You must select two different cells. Please try again.\n\n");
    } else {
      printf("\n");

      char value1 = board[row1][col1];
      char value2 = board[row2][col2];

      if (value1 != value2) {
        printf("Sorry, those values do not match.\n\n");
      } else {
        printf("Congratulations, you found a match!\n\n");
        board[row1][col1] = ' ';
        board[row2][col2] = ' ';
        num_cells -= 2;
      }

      num_moves++;
      print_board(board);
    }
  }

  printf("Congratulations, you won the game in %d moves!\n", num_moves);
}