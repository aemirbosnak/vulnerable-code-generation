//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

#define MAX_SPEED 100
#define MAX_ANGLE 90
#define PI 3.14159265

typedef struct {
  double x;
  double y;
  double angle;
} Position;

typedef struct {
  double linear_speed;
  double angular_speed;
} Velocity;

typedef struct {
  Position position;
  Velocity velocity;
} RobotState;

void move_forward(RobotState *robot, double distance) {
  double time = distance / robot->velocity.linear_speed;
  robot->position.x += distance * cos(robot->position.angle);
  robot->position.y += distance * sin(robot->position.angle);
  usleep(time * 1000000);
}

void move_backward(RobotState *robot, double distance) {
  double time = distance / robot->velocity.linear_speed;
  robot->position.x -= distance * cos(robot->position.angle);
  robot->position.y -= distance * sin(robot->position.angle);
  usleep(time * 1000000);
}

void turn_left(RobotState *robot, double angle) {
  double time = angle / robot->velocity.angular_speed;
  robot->position.angle += angle;
  usleep(time * 1000000);
}

void turn_right(RobotState *robot, double angle) {
  double time = angle / robot->velocity.angular_speed;
  robot->position.angle -= angle;
  usleep(time * 1000000);
}

void print_robot_state(RobotState *robot) {
  printf("Position: (%.2f, %.2f, %.2f)\n", robot->position.x, robot->position.y, robot->position.angle);
  printf("Velocity: (%.2f, %.2f)\n", robot->velocity.linear_speed, robot->velocity.angular_speed);
}

int main() {
  RobotState robot = {{0, 0, 0}, {0, 0}};

  move_forward(&robot, 100);
  turn_left(&robot, 90);
  move_forward(&robot, 100);
  turn_right(&robot, 90);
  move_forward(&robot, 100);
  turn_left(&robot, 90);
  move_forward(&robot, 100);
  turn_right(&robot, 90);

  print_robot_state(&robot);

  return 0;
}