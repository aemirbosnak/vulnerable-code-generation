//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
  int num_cars = 10;
  int lanes = 4;
  int car_width = 20;
  int car_length = 40;
  int road_width = lanes * car_width;
  int intersection_width = 100;
  int canvas_width = 1200;
  int canvas_height = 800;
  int cars_arrived = 0;

  srand(time(NULL)); // seed the random number generator
  int *car_positions = calloc(num_cars, sizeof(int));
  int *car_speeds = calloc(num_cars, sizeof(int));
  int *intersection_counter = calloc(lanes, sizeof(int));

  printf("Starting Traffic Flow Simulation...\n");
  sleep(1);

  while (cars_arrived < num_cars) {
    // clear the canvas for the next frame
    system("clear");

    // update car positions
    for (int i = 0; i < num_cars; i++) {
      car_positions[i] += car_speeds[i];
    }

    // generate new cars on the road
    if (rand() % 2 == 0) {
      for (int i = 0; i < lanes; i++) {
        if (intersection_counter[i] == 0) {
          car_positions[i] = 0;
          car_speeds[i] = rand() % 10 + 5;
          intersection_counter[i] = intersection_width / car_speeds[i];
          break;
        }
      }
    }

    // handle cars at intersections
    for (int i = 0; i < lanes; i++) {
      if (intersection_counter[i] > 0) {
        intersection_counter[i]--;
      } else if (car_positions[i] >= road_width + intersection_width) {
        cars_arrived++;
        car_positions[i] = -car_length;
        car_speeds[i] = 0;
      }
    }

    // draw the cars on the canvas
    for (int i = 0; i < num_cars; i++) {
      printf("Car %d: ", i+1);
      for (int j = 0; j < car_positions[i]; j++) {
        putchar('.');
      }
      for (int j = 0; j < car_length; j++) {
        putchar('#');
      }
      for (int j = car_positions[i] + car_length; j < road_width + intersection_width; j++) {
        putchar('.');
      }
      printf("\n");
    }

    // sleep for a short time to simulate frame rate
    usleep(100000);
  }

  printf("All cars arrived at their destination. Simulation complete.\n");

  free(car_positions);
  free(car_speeds);
  free(intersection_counter);

  return 0;
}