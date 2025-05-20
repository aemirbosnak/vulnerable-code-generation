//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

int main() {
  double angle, temp, max_temp, min_temp, avg_temp;
  int count = 0;
  time_t start_time, end_time;
  struct tm *start_tm, *end_tm;
  char *time_str;

  printf("Welcome to the Temperature Monitor!\n");
  printf("Please enter the temperature in degrees Celsius: ");

  while (scanf("%lf", &temp) == 1) {
    if (temp >= -273.15 && temp <= 1000) {
      if (count == 0) {
        start_time = time(NULL);
        start_tm = localtime(&start_time);
        time_str = asctime(start_tm);
        printf("Starting temperature monitoring at %s...\n", time_str);
      }
      count++;

      if (temp > max_temp) {
        max_temp = temp;
      }
      if (temp < min_temp) {
        min_temp = temp;
      }
      avg_temp += temp;
    } else {
      printf("Invalid temperature entered. Please enter a temperature between -273.15 and 1000 degrees Celsius.\n");
    }
  }

  end_time = time(NULL);
  end_tm = localtime(&end_time);
  time_str = asctime(end_tm);

  avg_temp /= count;

  printf("Temperature monitoring completed at %s.\n", time_str);
  printf("Maximum temperature: %.2lf degrees Celsius\n", max_temp);
  printf("Minimum temperature: %.2lf degrees Celsius\n", min_temp);
  printf("Average temperature: %.2lf degrees Celsius\n", avg_temp);

  return 0;
}