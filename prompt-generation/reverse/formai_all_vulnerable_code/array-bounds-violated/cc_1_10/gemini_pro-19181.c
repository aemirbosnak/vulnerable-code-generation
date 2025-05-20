//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Robot's movements
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Robot's sensors
#define SENSOR_FRONT 1
#define SENSOR_LEFT 2
#define SENSOR_RIGHT 3
#define SENSOR_BACK 4

// Robot's states
#define STATE_EXPLORING 1
#define STATE_AVOIDING 2
#define STATE_RETURNING 3

// Robot's parameters
#define SPEED 1
#define SCAN_RANGE 10
#define AVOIDANCE_DISTANCE 5
#define RETURN_DISTANCE 10

// Global variables
int robot_x, robot_y; // Robot's position
int robot_state; // Robot's state
int robot_direction; // Robot's direction
int sensor_values[4]; // Sensor values

// Function prototypes
void move_robot(int direction);
void sense_environment();
void update_state();
void avoid_obstacles();
void return_to_start();

int main() {
  // Initialize the robot
  srand(time(NULL));
  robot_x = 0;
  robot_y = 0;
  robot_state = STATE_EXPLORING;
  robot_direction = RIGHT;

  // Main loop
  while (1) {
    // Sense the environment
    sense_environment();

    // Update the robot's state
    update_state();

    // Move the robot
    switch (robot_state) {
      case STATE_EXPLORING:
        move_robot(robot_direction);
        break;
      case STATE_AVOIDING:
        avoid_obstacles();
        break;
      case STATE_RETURNING:
        return_to_start();
        break;
    }

    // Print the robot's position and state
    printf("Robot position: (%d, %d)\n", robot_x, robot_y);
    printf("Robot state: %s\n",
           robot_state == STATE_EXPLORING ? "EXPLORING" :
           robot_state == STATE_AVOIDING ? "AVOIDING" : "RETURNING");
  }

  return 0;
}

void move_robot(int direction) {
  switch (direction) {
    case UP:
      robot_y++;
      break;
    case DOWN:
      robot_y--;
      break;
    case LEFT:
      robot_x--;
      break;
    case RIGHT:
      robot_x++;
      break;
  }
}

void sense_environment() {
  // Sense the environment in front of the robot
  sensor_values[SENSOR_FRONT] = rand() % SCAN_RANGE;

  // Sense the environment to the left of the robot
  sensor_values[SENSOR_LEFT] = rand() % SCAN_RANGE;

  // Sense the environment to the right of the robot
  sensor_values[SENSOR_RIGHT] = rand() % SCAN_RANGE;

  // Sense the environment behind the robot
  sensor_values[SENSOR_BACK] = rand() % SCAN_RANGE;
}

void update_state() {
  // If the robot is too close to an obstacle, switch to AVOIDING state
  if (sensor_values[SENSOR_FRONT] < AVOIDANCE_DISTANCE ||
      sensor_values[SENSOR_LEFT] < AVOIDANCE_DISTANCE ||
      sensor_values[SENSOR_RIGHT] < AVOIDANCE_DISTANCE) {
    robot_state = STATE_AVOIDING;
  }

  // If the robot is far from the start point, switch to RETURNING state
  else if (abs(robot_x) > RETURN_DISTANCE || abs(robot_y) > RETURN_DISTANCE) {
    robot_state = STATE_RETURNING;
  }

  // Otherwise, stay in EXPLORING state
  else {
    robot_state = STATE_EXPLORING;
  }
}

void avoid_obstacles() {
  // If there is an obstacle in front of the robot, turn left
  if (sensor_values[SENSOR_FRONT] < AVOIDANCE_DISTANCE) {
    robot_direction = LEFT;
  }

  // If there is an obstacle to the left of the robot, turn right
  else if (sensor_values[SENSOR_LEFT] < AVOIDANCE_DISTANCE) {
    robot_direction = RIGHT;
  }

  // If there is an obstacle to the right of the robot, turn left
  else if (sensor_values[SENSOR_RIGHT] < AVOIDANCE_DISTANCE) {
    robot_direction = LEFT;
  }

  // Otherwise, move forward
  else {
    move_robot(robot_direction);
  }
}

void return_to_start() {
  // If the robot is facing away from the start point, turn towards it
  if (robot_x > 0 && robot_direction != LEFT) {
    robot_direction = LEFT;
  } else if (robot_x < 0 && robot_direction != RIGHT) {
    robot_direction = RIGHT;
  } else if (robot_y > 0 && robot_direction != DOWN) {
    robot_direction = DOWN;
  } else if (robot_y < 0 && robot_direction != UP) {
    robot_direction = UP;
  }

  // Move towards the start point
  move_robot(robot_direction);
}