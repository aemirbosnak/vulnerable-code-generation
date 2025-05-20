//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed

  printf("Welcome to the Haunted House Simulator!\n");
  printf("Press any key to start...\n");
  scanf("%*c"); // wait for user input

  int rooms[5][5] = {0}; // create 2D array of rooms
  rooms[0][0] = 1; // start in room 1,1
  int current_row = 0;
  int current_col = 0;
  int num_ghosts = 10; // number of random ghosts to place
  int num_traps = 5; // number of random traps to place
  int num_moves = 0; // number of moves taken

  // place ghosts randomly
  for (int i = 0; i < num_ghosts; i++) {
    int row = rand() % 5;
    int col = rand() % 5;
    rooms[row][col] = -1; // -1 represents a ghost
  }

  // place traps randomly
  for (int i = 0; i < num_traps; i++) {
    int row = rand() % 5;
    int col = rand() % 5;
    if (rooms[row][col] != -1) { // avoid overlapping with ghosts
      rooms[row][col] = -2; // -2 represents a trap
    }
  }

  // game loop
  while (1) {
    // print current state of rooms
    printf("You are in room %d,%d\n", current_row+1, current_col+1);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (rooms[i][j] == 0) {
          printf("[ ]");
        } else if (rooms[i][j] == 1) {
          printf("[*]"); // current room marker
        } else if (rooms[i][j] == -1) {
          printf("[G]"); // ghost marker
        } else if (rooms[i][j] == -2) {
          printf("[T]"); // trap marker
        }
      }
      printf("\n");
    }

    // check if game has ended
    if (rooms[current_row][current_col] == -1) {
      printf("\nYou ran into a ghost and died!\n");
      printf("You made %d moves before meeting your demise.\n", num_moves);
      break;
    } else if (rooms[current_row][current_col] == -2) {
      printf("\nYou fell into a trap and died!\n");
      printf("You made %d moves before meeting your demise.\n", num_moves);
      break;
    } else if (current_row == 4 && current_col == 4) {
      printf("\nCongratulations, you have escaped the haunted house!\n");
      printf("It took you %d moves to make it out alive.\n", num_moves);
      break;
    }

    // read user input
    printf("\nWhere would you like to go? (N/S/E/W): ");
    char direction;
    scanf(" %c", &direction);

    // move to new room
    if (direction == 'N' && current_row > 0) {
      current_row--;
      rooms[current_row][current_col] = 1; // mark new room
      rooms[current_row+1][current_col] = 0; // unmark old room
      num_moves++;
    } else if (direction == 'S' && current_row < 4) {
      current_row++;
      rooms[current_row][current_col] = 1;
      rooms[current_row-1][current_col] = 0;
      num_moves++;
    } else if (direction == 'E' && current_col < 4) {
      current_col++;
      rooms[current_row][current_col] = 1;
      rooms[current_row][current_col-1] = 0;
      num_moves++;
    } else if (direction == 'W' && current_col > 0) {
      current_col--;
      rooms[current_row][current_col] = 1;
      rooms[current_row][current_col+1] = 0;
      num_moves++;
    } else {
      printf("Invalid direction, please try again.\n");
    }
  }

  return 0;
}