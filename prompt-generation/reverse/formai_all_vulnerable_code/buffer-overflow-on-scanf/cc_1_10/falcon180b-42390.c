//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SAMPLE_RATE 10 // seconds

// Function to get current temperature
double get_temperature() {
  FILE *fp;
  char line[100];
  double temp = 0;

  fp = popen("vcgencmd measure_temp", "r");

  if (fp!= NULL) {
    fgets(line, sizeof(line), fp);
    temp = atof(line);
    pclose(fp);
  }

  return temp;
}

// Function to get average temperature over a period of time
double get_average_temperature(int num_samples) {
  int i;
  double sum = 0;

  for (i = 0; i < num_samples; i++) {
    sum += get_temperature();
    sleep(SAMPLE_RATE);
  }

  return sum / num_samples;
}

int main() {
  int num_samples;
  double avg_temp;

  printf("Enter number of samples: ");
  scanf("%d", &num_samples);

  avg_temp = get_average_temperature(num_samples);

  printf("Average temperature over %d samples: %.2f C\n", num_samples, avg_temp);

  return 0;
}