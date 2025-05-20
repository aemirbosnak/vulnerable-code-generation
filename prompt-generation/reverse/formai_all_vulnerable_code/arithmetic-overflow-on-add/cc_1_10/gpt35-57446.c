//FormAI DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  This program generates a series of random numbers within a given range
  and calculates the average, maximum and minimum values of the series.
*/

int main() {
  // Initialize variables and retrieve user input
  int max_range, min_range, num_elements;
  printf("Enter the maximum range: ");
  scanf("%d", &max_range);
  printf("Enter the minimum range: ");
  scanf("%d", &min_range);
  printf("Enter the number of elements in the series: ");
  scanf("%d", &num_elements);

  // Generate the series of random numbers
  int series[num_elements];
  srand(time(NULL));
  for (int i = 0; i < num_elements; i++) {
    series[i] = (rand() % (max_range - min_range + 1)) + min_range;
  }

  // Calculate the average, maximum and minimum values of the series
  int sum = series[0], max = series[0], min = series[0];
  for (int i = 1; i < num_elements; i++) {
    sum += series[i];
    if (series[i] > max) {
      max = series[i];
    }
    if (series[i] < min) {
      min = series[i];
    }
  }
  float avg = (float)sum / num_elements;

  // Display the results
  printf("The series of random numbers is:\n");
  for (int i = 0; i < num_elements; i++) {
    printf("%d ", series[i]);
  }
  printf("\n\nThe average value of the series is: %.2f\n", avg);
  printf("The maximum value of the series is: %d\n", max);
  printf("The minimum value of the series is: %d\n", min);

  return 0;
}