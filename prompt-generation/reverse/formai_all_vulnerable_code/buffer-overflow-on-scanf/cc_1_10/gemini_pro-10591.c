//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SPEED 10.0
#define MAX_ANG_VEL 1.0
#define DT 0.1

typedef struct {
  double x, y, theta;
  double v, w;
} Car;

void init_car(Car *car) {
  car->x = 0.0;
  car->y = 0.0;
  car->theta = 0.0;
  car->v = 0.0;
  car->w = 0.0;
}

void update_car(Car *car) {
  car->x += car->v * DT * cos(car->theta);
  car->y += car->v * DT * sin(car->theta);
  car->theta += car->w * DT;
}

void set_speed(Car *car, double speed) {
  car->v = speed;
}

void set_ang_vel(Car *car, double ang_vel) {
  car->w = ang_vel;
}

void print_car(Car *car) {
  printf("x: %.2f, y: %.2f, theta: %.2f, v: %.2f, w: %.2f\n",
         car->x, car->y, car->theta, car->v, car->w);
}

int main() {
  Car car;
  init_car(&car);

  while (1) {
    char command[100];
    printf("> ");
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "forward") == 0) {
      set_speed(&car, MAX_SPEED);
    } else if (strcmp(command, "backward") == 0) {
      set_speed(&car, -MAX_SPEED);
    } else if (strcmp(command, "left") == 0) {
      set_ang_vel(&car, MAX_ANG_VEL);
    } else if (strcmp(command, "right") == 0) {
      set_ang_vel(&car, -MAX_ANG_VEL);
    } else if (strcmp(command, "stop") == 0) {
      set_speed(&car, 0.0);
      set_ang_vel(&car, 0.0);
    } else if (strcmp(command, "print") == 0) {
      print_car(&car);
    } else {
      printf("Invalid command.\n");
    }

    update_car(&car);
  }

  return 0;
}