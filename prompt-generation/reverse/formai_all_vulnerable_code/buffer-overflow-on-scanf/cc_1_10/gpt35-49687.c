//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

// Define vehicle struct
typedef struct {
  int x;
  int y;
} Vehicle;

// Define direction enum
typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT
} Direction;

// Function to generate random number
int rand_num(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to display map with vehicle's position
void display_map(Vehicle vehicle, int map[MAP_SIZE][MAP_SIZE]) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (vehicle.x == i && vehicle.y == j) {
        printf("v ");
      } else if (map[i][j] == 0) {
        printf("- ");
      } else {
        printf("* ");
      }
    }
    printf("\n");
  }
}

int main() {
  // Initialize random seed
  srand(time(NULL));
  
  // Initialize map
  int map[MAP_SIZE][MAP_SIZE] = {0};
  
  // Generate obstacles
  for (int i = 0; i < MAP_SIZE / 2; i++) {
    int x = rand_num(0, MAP_SIZE - 1);
    int y = rand_num(0, MAP_SIZE - 1);
    map[x][y] = 1;
  }
  
  // Initialize vehicle's starting position
  Vehicle vehicle = {0, 0};
  
  // Display initial map
  display_map(vehicle, map);
  
  // Remote control loop
  while (1) {
    // Get user input
    printf("Enter direction (u/d/l/r): ");
    char input;
    scanf(" %c", &input);
    
    // Move vehicle
    switch (input) {
      case 'u':
        if (vehicle.x > 0) {
          vehicle.x--;
        }
        break;
      case 'd':
        if (vehicle.x < MAP_SIZE - 1) {
          vehicle.x++;
        }
        break;
      case 'l':
        if (vehicle.y > 0) {
          vehicle.y--;
        }
        break;
      case 'r':
        if (vehicle.y < MAP_SIZE - 1) {
          vehicle.y++;
        }
        break;
      default:
        printf("Invalid input!\n");
        continue;
    }
    
    // Display updated map
    display_map(vehicle, map);
    
    // Check if vehicle reached the end of the map
    if (vehicle.x == MAP_SIZE - 1 && vehicle.y == MAP_SIZE - 1) {
      printf("Congratulations, you reached the end of the map!\n");
      break;
    }
  }
  
  return 0;
}