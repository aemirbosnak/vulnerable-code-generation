//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the robot's possible movements
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Define the robot's maximum speed
#define MAX_SPEED 10

// Define the robot's initial position
#define START_X 0
#define START_Y 0

// Create a function to generate a random movement
int generate_movement() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random number between 1 and 4
  int movement = rand() % 4 + 1;

  // Return the movement
  return movement;
}

// Create a function to move the robot
void move_robot(int movement, int *x, int *y) {
  // Switch on the movement
  switch (movement) {
    case FORWARD:
      *y += 1;
      break;
    case BACKWARD:
      *y -= 1;
      break;
    case LEFT:
      *x -= 1;
      break;
    case RIGHT:
      *x += 1;
      break;
  }
}

// Create a function to print the robot's position
void print_robot_position(int x, int y) {
  printf("The robot is at position (%d, %d).\n", x, y);
}

// Create a function to run the robot
void run_robot(int num_movements) {
  // Initialize the robot's position
  int x = START_X;
  int y = START_Y;

  // Loop through the number of movements
  for (int i = 0; i < num_movements; i++) {
    // Generate a random movement
    int movement = generate_movement();

    // Move the robot
    move_robot(movement, &x, &y);

    // Print the robot's position
    print_robot_position(x, y);
  }
}

// Main function
int main() {
  // Get the number of movements from the user
  int num_movements;
  printf("How many movements do you want the robot to make? ");
  scanf("%d", &num_movements);

  // Run the robot
  run_robot(num_movements);

  return 0;
}