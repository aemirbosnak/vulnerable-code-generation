//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: interoperable
#include <stdbool.h> /* Boolean values */
#include <stdio.h>  /* IO Functions */
#include <stdlib.h> /* EXIT Codes */
#include <string.h> /* String functions */
#include <time.h>   /* Time functions */

/**
 * @brief Function to simulate the traffic light controller.
 * @param[in] cycle_time Cycle time in seconds
 * @param[in] green_time Green time in seconds
 * @param[in] yellow_time Yellow time in seconds
 */
void traffic_light_controller(int cycle_time, int green_time, int yellow_time) {
  int red_time = cycle_time - green_time - yellow_time;

  printf("Cycle Time: %d\n", cycle_time);
  printf("Green Time: %d\n", green_time);
  printf("Yellow Time: %d\n", yellow_time);
  printf("Red Time: %d\n", red_time);

  time_t start_time = time(NULL);
  bool is_green = true;

  while (true) {
    time_t current_time = time(NULL);

    if (current_time >= start_time + cycle_time) {
      start_time = current_time;
      is_green = !is_green;
    }

    if (is_green) {
      printf("Green Light On\n");
    } else {
      if (current_time >= start_time + red_time) {
        printf("Yellow Light On\n");
      } else {
        printf("Red Light On\n");
      }
    }

    sleep(1);
  }
}

/**
 * @brief Main function.
 */
int main() {
  int cycle_time, green_time, yellow_time;

  printf("Enter Cycle Time in seconds: ");
  scanf("%d", &cycle_time);

  printf("Enter Green Time in seconds: ");
  scanf("%d", &green_time);

  printf("Enter Yellow Time in seconds: ");
  scanf("%d", &yellow_time);

  traffic_light_controller(cycle_time, green_time, yellow_time);

  return 0;
}