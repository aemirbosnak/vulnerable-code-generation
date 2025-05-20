//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5  // number of rows
#define M 5  // number of columns

// define the board
int board[N][M];

// define the player's position
int player_row = 0;
int player_col = 0;

// define the goal position
int goal_row = N - 1;
int goal_col = M - 1;

// define the number of moves
int moves = 0;

// print the board
void print_board() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// check if the player has won
int check_win() {
  return player_row == goal_row && player_col == goal_col;
}

// move the player up
void move_up() {
  if (player_row > 0) {
    player_row--;
    moves++;
  }
}

// move the player down
void move_down() {
  if (player_row < N - 1) {
    player_row++;
    moves++;
  }
}

// move the player left
void move_left() {
  if (player_col > 0) {
    player_col--;
    moves++;
  }
}

// move the player right
void move_right() {
  if (player_col < M - 1) {
    player_col++;
    moves++;
  }
}

// generate a random board
void generate_board() {
  // seed the random number generator
  srand(time(NULL));

  // generate the board
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      board[i][j] = rand() % 10;
    }
  }
}

// play the game
int play_game() {
  // generate the board
  generate_board();

  // print the board
  print_board();

  // while the player has not won
  while (!check_win()) {
    // get the player's input
    char input;
    scanf(" %c", &input);

    // move the player
    switch (input) {
      case 'w':
        move_up();
        break;
      case 's':
        move_down();
        break;
      case 'a':
        move_left();
        break;
      case 'd':
        move_right();
        break;
      default:
        printf("Invalid input!\n");
        break;
    }

    // print the board
    print_board();
  }

  // print the number of moves
  printf("You win in %d moves!\n", moves);

  return 0;
}

int main() {
  play_game();
  return 0;
}