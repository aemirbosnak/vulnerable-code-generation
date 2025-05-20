//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Global variable */
int current_light = 0; /* 0 = Red, 1 = Green */
int change_interval = 10; /* Time interval between light changes */

/* Function to get the current time */
void get_current_time(char* timestamp) {
  time_t current_time = time(NULL);
  struct tm* time_info = localtime(&current_time);
  strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", time_info);
}

/* Function to wait for a certain amount of time */
void wait(int seconds) {
  int milli_seconds = 1000 * seconds;
  clock_t start_time = clock();

  while (clock() < start_time + milli_seconds);
}

/* Main function */
int main() {
  while (1) {
    /* Get the current time */
    char timestamp[20];
    get_current_time(timestamp);

    /* Determine the current light color */
    char light_color[10];
    if (current_light == 0) {
      sprintf(light_color, "Red");
    } else {
      sprintf(light_color, "Green");
    }

    /* Inform the user about the current light color */
    printf("[%s] Current light color: %s\n", timestamp, light_color);

    /* Wait for the light to change */
    wait(change_interval);

    /* Change the light */
    if (current_light == 0) {
      current_light = 1;
    } else {
      current_light = 0;
    }
  }

  return 0;
}