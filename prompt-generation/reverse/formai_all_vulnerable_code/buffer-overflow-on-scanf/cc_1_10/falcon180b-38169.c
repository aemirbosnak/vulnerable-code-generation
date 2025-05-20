//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  // Initialize variables
  double temperature = 0;
  double temperature_diff = 0;
  double temperature_diff_prev = 0;
  double temperature_diff_avg = 0;
  double temperature_diff_avg_prev = 0;
  int count = 0;
  time_t start_time, end_time;
  double elapsed_time;
  char c;

  // Get start time
  time(&start_time);

  // Loop until user presses 'q' to quit
  while (1) {
    // Get temperature
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &temperature);

    // Calculate temperature difference from previous reading
    temperature_diff = temperature - temperature_diff_prev;

    // Update temperature difference average
    temperature_diff_avg = ((temperature_diff_avg * count) + temperature_diff) / (count + 1);

    // Update temperature difference average from previous reading
    temperature_diff_avg_prev = temperature_diff_avg;

    // Update count
    count++;

    // Calculate elapsed time
    time(&end_time);
    elapsed_time = difftime(end_time, start_time);

    // Print results
    printf("Temperature: %.2lf Celsius\n", temperature);
    printf("Temperature difference from previous reading: %.2lf Celsius\n", temperature_diff);
    printf("Temperature difference average: %.2lf Celsius\n", temperature_diff_avg);
    printf("Elapsed time: %ld seconds\n", elapsed_time);

    // Check if user wants to quit
    printf("Press 'q' to quit or any other key to continue: ");
    scanf(" %c", &c);
    if (c == 'q') {
      break;
    }
  }

  // Print final results
  printf("Final results:\n");
  printf("Temperature difference average: %.2lf Celsius\n", temperature_diff_avg_prev);
  printf("Elapsed time: %ld seconds\n", elapsed_time);

  return 0;
}