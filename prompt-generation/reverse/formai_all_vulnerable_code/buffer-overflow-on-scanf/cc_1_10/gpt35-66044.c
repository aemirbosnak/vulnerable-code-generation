//FormAI DATASET v1.0 Category: Robot movement control ; Style: high level of detail
#include <stdio.h>

#define MAX_SPEED 255

// function to move robot forward
void move_forward(int speed) {
  printf("Moving forward at speed %d\n", speed);
  // code to move the robot forward at given speed
}

// function to move robot backward
void move_backward(int speed) {
  printf("Moving backward at speed %d\n", speed);
  // code to move the robot backward at given speed
}

// function to turn robot left
void turn_left(int speed) {
  printf("Turning left at speed %d\n", speed);
  // code to turn the robot left at given speed
}

// function to turn robot right
void turn_right(int speed) {
  printf("Turning right at speed %d\n", speed);
  // code to turn the robot right at given speed
}

int main() {
  int speed = 0;
  // ask user for desired speed
  printf("Enter desired speed between 0-255: ");
  scanf("%d", &speed);
  
  if (speed < 0 || speed > MAX_SPEED) {
    printf("Invalid speed entered. Program terminated.\n");
    return 0;
  }
  
  // ask user for desired movement
  printf("Enter desired movement (f for forward, b for backward, l for left, r for right): ");
  char movement;
  scanf(" %c", &movement); // note the space before %c to ignore any whitespace
  
  // call appropriate function based on user input
  if (movement == 'f') {
    move_forward(speed);
  } else if (movement == 'b') {
    move_backward(speed);
  } else if (movement == 'l') {
    turn_left(speed);
  } else if (movement == 'r') {
    turn_right(speed);
  } else {
    printf("Invalid movement entered. Program terminated.\n");
  }
  
  return 0;
}