//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SPEED 100
#define MAX_STEERING_ANGLE 30

typedef struct {
  int speed;
  int steering_angle;
} Car;

void init_car(Car *car) {
  car->speed = 0;
  car->steering_angle = 0;
}

void update_car(Car *car, int throttle, int steering) {
  // Update speed
  car->speed += throttle;
  if (car->speed > MAX_SPEED) {
    car->speed = MAX_SPEED;
  } else if (car->speed < 0) {
    car->speed = 0;
  }

  // Update steering angle
  car->steering_angle += steering;
  if (car->steering_angle > MAX_STEERING_ANGLE) {
    car->steering_angle = MAX_STEERING_ANGLE;
  } else if (car->steering_angle < -MAX_STEERING_ANGLE) {
    car->steering_angle = -MAX_STEERING_ANGLE;
  }
}

void draw_car(Car *car) {
  // Draw the car on the screen
  printf("Car speed: %d\n", car->speed);
  printf("Car steering angle: %d\n", car->steering_angle);
}

int main() {
  // Initialize the car
  Car car;
  init_car(&car);

  // Set up the remote control
  int throttle = 0;
  int steering = 0;

  // Main loop
  while (1) {
    // Get input from the remote control
    printf("Enter throttle (-100 to 100): ");
    scanf("%d", &throttle);
    printf("Enter steering (-30 to 30): ");
    scanf("%d", &steering);

    // Update the car
    update_car(&car, throttle, steering);

    // Draw the car
    draw_car(&car);
  }

  return 0;
}