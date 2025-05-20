//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int map[10][10] = {0}; // create a 10x10 map and initialize all values to 0
  int x = 5; // initial starting position for the vehicle (row)
  int y = 5; // initial starting position for the vehicle (column)
  int target_x, target_y; // variables to store the location of the target
  
  // randomly generate a target location that is not the same as the starting position
  srand(time(0)); // seed the random number generator
  do {
    target_x = rand() % 10;
    target_y = rand() % 10;
  } while (target_x == x && target_y == y); // repeat if the target is the same as the starting position
  
  // print out the initial state of the map with the starting position and the target
  printf("Initial Map:\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == x && j == y) {
        printf("V "); // denote the starting position with "V"
      } else if (i == target_x && j == target_y) {
        printf("T "); // denote the target with "T"
      } else {
        printf("_ "); // denote empty spaces with "_"
      }
    }
    printf("\n"); // move to the next row
  }
  
  // simulate the remote control vehicle movement
  char move; // variable to store the user's input
  while (x != target_x || y != target_y) { // continue until the vehicle reaches the target
    printf("Enter a direction (WASD): ");
    scanf(" %c", &move); // read a character from the user
    
    // compute the new position based on the user's input
    int new_x = x;
    int new_y = y;
    if (move == 'w' || move == 'W') {
      new_x--;
    } else if (move == 'a' || move == 'A') {
      new_y--;
    } else if (move == 's' || move == 'S') {
      new_x++;
    } else if (move == 'd' || move == 'D') {
      new_y++;
    } else {
      printf("Invalid input\n");
      continue; // ask for input again
    }
    
    // check if the new position is within the boundaries of the map
    if (new_x < 0 || new_x >= 10 || new_y < 0 || new_y >= 10) {
      printf("Out of bounds\n");
      continue; // ask for input again
    }
    
    // check if the new position is already occupied
    if (map[new_x][new_y] == 1) {
      printf("Obstacle detected\n");
      continue; // ask for input again
    }
    
    // update the map with a "1" at the new position
    map[new_x][new_y] = 1;
    
    // move the vehicle to the new position
    x = new_x;
    y = new_y;
    
    // print out the updated state of the map with the vehicle and the target
    printf("Current Map:\n");
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (i == x && j == y) {
          printf("V "); // denote the vehicle with "V"
        } else if (i == target_x && j == target_y) {
          printf("T "); // denote the target with "T"
        } else if (map[i][j] == 1) {
          printf("X "); // denote occupied spaces with "X"
        } else {
          printf("_ "); // denote empty spaces with "_"
        }
      }
      printf("\n"); // move to the next row
    }
  }
  
  printf("Target reached!\n");
  
  return 0;
}