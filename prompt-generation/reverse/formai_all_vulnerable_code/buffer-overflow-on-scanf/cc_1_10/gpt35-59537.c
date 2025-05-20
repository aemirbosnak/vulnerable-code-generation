//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGLE 360
#define MIN_ANGLE 0
#define MAX_ALTITUDE 1000
#define MIN_ALTITUDE 0

typedef struct {
  int speed;
  int angle;
  int altitude;
} DroneState;

void changeSpeed(DroneState *state, int speed) {
  if (speed > MAX_SPEED) {
    speed = MAX_SPEED;
  } else if (speed < MIN_SPEED) {
    speed = MIN_SPEED;
  }
  state->speed = speed;
}

void changeAngle(DroneState *state, int angle) {
  if (angle > MAX_ANGLE) {
    angle = MAX_ANGLE;
  } else if (angle < MIN_ANGLE) {
    angle = MIN_ANGLE;
  }
  state->angle = angle;
}

void changeAltitude(DroneState *state, int altitude) {
  if (altitude > MAX_ALTITUDE) {
    altitude = MAX_ALTITUDE;
  } else if (altitude < MIN_ALTITUDE) {
    altitude = MIN_ALTITUDE;
  }
  state->altitude = altitude;
}

int main() {
  DroneState drone = {0, 0, 0};

  while (1) {
    printf("Current state: Speed=%d, Angle=%d, Altitude=%d\n", drone.speed, drone.angle, drone.altitude);

    printf("Enter speed (0-100): ");
    int speed;
    scanf("%d", &speed);
    changeSpeed(&drone, speed);

    printf("Enter angle (0-360): ");
    int angle;
    scanf("%d", &angle);
    changeAngle(&drone, angle);

    printf("Enter altitude (0-1000): ");
    int altitude;
    scanf("%d", &altitude);
    changeAltitude(&drone, altitude);
  }
  
  return 0;
}