//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define HOUSE_SIZE 5
#define MAX_GHOSTS 3

// define a struct for a room in the haunted house
typedef struct Room {
  bool visited;
  bool ghost;
} Room;

// function declarations
void populate_house(Room house[][HOUSE_SIZE]);
bool game_over(Room house[][HOUSE_SIZE], int player_row, int player_col, int ghost_count);
void print_house(Room house[][HOUSE_SIZE], int player_row, int player_col);

int main() {
  srand(time(NULL)); // seed the random number generator

  Room house[HOUSE_SIZE][HOUSE_SIZE];
  int player_row = rand() % HOUSE_SIZE; // randomly place the player in the house
  int player_col = rand() % HOUSE_SIZE;

  populate_house(house); // randomly place ghosts in the house

  printf("Welcome to the Haunted House Simulator! Try to escape before the ghosts get you...\n\n");

  print_house(house, player_row, player_col);

  while (!game_over(house, player_row, player_col, 0)) {
    char move_direction;
    printf("Move (WASD): ");
    scanf(" %c", &move_direction);

    switch (move_direction) {
      case 'w':
        if (player_row > 0) {
          player_row--;
        }
        break;
      case 'a':
        if (player_col > 0) {
          player_col--;
        }
        break;
      case 's':
        if (player_row < HOUSE_SIZE - 1) {
          player_row++;
        }
        break;
      case 'd':
        if (player_col < HOUSE_SIZE - 1) {
          player_col++;
        }
        break;
      default:
        printf("Invalid move. Try again.\n");
        break;
    }

    printf("\n");
    print_house(house, player_row, player_col);
  }

  printf("Game over!\n");

  return 0;
}

// randomly populate the house with ghosts
void populate_house(Room house[][HOUSE_SIZE]) {
  int ghosts_placed = 0;

  while (ghosts_placed < MAX_GHOSTS) {
    int row = rand() % HOUSE_SIZE;
    int col = rand() % HOUSE_SIZE;

    if (!house[row][col].ghost) { // if the room does not already have a ghost
      house[row][col].ghost = true; // add a ghost to the room
      ghosts_placed++;
    }
  }
}

// check if the game is over (player has landed on a room with a ghost or visited all non-ghost rooms)
bool game_over(Room house[][HOUSE_SIZE], int player_row, int player_col, int ghost_count) {
  if (house[player_row][player_col].ghost) {
    printf("You have been spooked by a ghost and lost the game!\n");
    return true;
  }

  if (ghost_count == MAX_GHOSTS) { // if all ghosts have been visited
    printf("You have successfully explored the haunted house and won the game!\n");
    return true;
  }

  if (!house[player_row][player_col].visited) {
    printf("You have entered a new room...\n");
    if (house[player_row][player_col].ghost) {
      printf("Oh no! A ghost is in this room!\n");
      ghost_count++;
    }
    house[player_row][player_col].visited = true;
  }

  return false;
}

// print the current state of the house
void print_house(Room house[][HOUSE_SIZE], int player_row, int player_col) {
  for (int i = 0; i < HOUSE_SIZE; i++) {
    for (int j = 0; j < HOUSE_SIZE; j++) {
      if (i == player_row && j == player_col) { // print the player as 'P' in its current location
        printf("P ");
      } else if (!house[i][j].visited) { // print '?' for unvisited rooms
        printf("? ");
      } else if (house[i][j].ghost) { // print 'G' for rooms with ghosts
        printf("G ");
      } else { // print '-' for rooms that have been visited but have no ghosts
        printf("- ");
      }
    }
    printf("\n");
  }
  printf("\n");
}