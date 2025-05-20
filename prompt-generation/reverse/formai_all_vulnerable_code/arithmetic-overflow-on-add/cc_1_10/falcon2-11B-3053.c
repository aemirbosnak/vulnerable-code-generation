//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // seed random number generator

  double x, y; // ball's position
  double vx, vy; // ball's velocity
  double ax, ay; // acceleration due to gravity and friction
  int t; // time
  int i; // counter for bouncing off the floor

  x = (double)rand() / (double)RAND_MAX * 10.0; // initial position
  y = (double)rand() / (double)RAND_MAX * 10.0;
  vx = (double)rand() / (double)RAND_MAX * 3.0; // initial velocity
  vy = (double)rand() / (double)RAND_MAX * 3.0;
  ax = -9.81; // acceleration due to gravity
  ay = 0.0; // no friction
  t = 0; // time

  while (y > -0.5 && y < 0.5) { // while ball is bouncing off the floor
    t++; // increase time
    i++; // increase counter

    vx = vx + ax * t; // update velocity due to gravity
    vy = vy + ay * t; // update velocity due to friction
    x = x + vx * t; // update position
    y = y + vy * t;

    if (y < -0.5) {
      vy = -vy; // bounce off floor
    } else if (y > 0.5) {
      vy = -vy;
    }

    if (x > 10.0) {
      x = 0.0;
      vx = 0.0;
    } else if (x < -10.0) {
      x = 0.0;
      vx = 0.0;
    }

    printf("Time %d, x %f, y %f, vx %f, vy %f\n", t, x, y, vx, vy); // print current position and velocity
  }

  printf("Time %d, x %f, y %f, vx %f, vy %f\n", t, x, y, vx, vy); // print final position and velocity
  return 0;
}