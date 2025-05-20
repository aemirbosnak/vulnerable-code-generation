//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SAMPLES 1000

struct temperature_sample {
  time_t timestamp;
  double temperature;
};

int main() {
  int i;
  double min_temp = 100.0;
  double max_temp = -100.0;
  double avg_temp = 0.0;
  FILE *file;
  struct temperature_sample samples[MAX_SAMPLES];

  file = fopen("temperature.log", "r");

  if (file == NULL) {
    puts("Temperature log file not found. Exiting...");
    return 1;
  }

  i = 0;
  while (fscanf(file, "%ld %lf\n", &samples[i].timestamp, &samples[i].temperature)!= EOF) {
    i++;
    if (i >= MAX_SAMPLES) {
      break;
    }
  }

  fclose(file);

  puts("Temperature log file read successfully.");

  for (i = 0; i < MAX_SAMPLES; i++) {
    if (samples[i].temperature < min_temp) {
      min_temp = samples[i].temperature;
    }
    if (samples[i].temperature > max_temp) {
      max_temp = samples[i].temperature;
    }
    avg_temp += samples[i].temperature;
  }

  avg_temp /= i;
  printf("Minimum temperature: %.2lf\n", min_temp);
  printf("Maximum temperature: %.2lf\n", max_temp);
  printf("Average temperature: %.2lf\n", avg_temp);

  return 0;
}