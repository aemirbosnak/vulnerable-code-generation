//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100 // km/h
#define MAX_STEERING_ANGLE 30 // degrees

typedef struct {
  int speed; // km/h
  int steering_angle; // degrees
} CarState;

typedef struct {
  int throttle; // 0 to 100
  int steering_wheel_angle; // -100 to 100
} RemoteControlInput;

void update_car_state(CarState *car, RemoteControlInput *input) {
  // Update speed
  if (input->throttle > 0) {
    car->speed += input->throttle;
    if (car->speed > MAX_SPEED) {
      car->speed = MAX_SPEED;
    }
  } else if (input->throttle < 0) {
    car->speed -= input->throttle;
    if (car->speed < 0) {
      car->speed = 0;
    }
  }

  // Update steering angle
  if (input->steering_wheel_angle > 0) {
    car->steering_angle += input->steering_wheel_angle;
    if (car->steering_angle > MAX_STEERING_ANGLE) {
      car->steering_angle = MAX_STEERING_ANGLE;
    }
  } else if (input->steering_wheel_angle < 0) {
    car->steering_angle += input->steering_wheel_angle;
    if (car->steering_angle < -MAX_STEERING_ANGLE) {
      car->steering_angle = -MAX_STEERING_ANGLE;
    }
  }
}

void print_car_state(CarState *car) {
  printf("Speed: %d km/h\n", car->speed);
  printf("Steering angle: %d degrees\n", car->steering_angle);
}

int main() {
  // Initialize car state
  CarState car = {0, 0};

  // Initialize remote control input
  RemoteControlInput input = {0, 0};

  // Main loop
  while (1) {
    // Get remote control input
    printf("Enter throttle (0 to 100): ");
    scanf("%d", &input.throttle);
    printf("Enter steering wheel angle (-100 to 100): ");
    scanf("%d", &input.steering_wheel_angle);

    // Update car state
    update_car_state(&car, &input);

    // Print car state
    print_car_state(&car);
  }

  return 0;
}