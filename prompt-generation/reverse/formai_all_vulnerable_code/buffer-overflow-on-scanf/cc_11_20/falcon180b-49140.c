//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DIMENSIONS 10
#define MAX_DISTANCES 100

int main() {
  int num_dimensions;
  int num_distances;
  int i, j, k;
  double distances[MAX_DISTANCES];
  double dimensions[MAX_DISTANCES];
  double volume;
  double probability;
  double max_distance;
  double min_distance;
  double avg_distance;
  char *result;
  srand(time(0));

  printf("Enter the number of dimensions: ");
  scanf("%d", &num_dimensions);

  printf("Enter the number of distances: ");
  scanf("%d", &num_distances);

  printf("Enter the dimensions: ");
  for (i = 0; i < num_dimensions; i++) {
    scanf("%lf", &dimensions[i]);
  }

  printf("Enter the distances: ");
  for (i = 0; i < num_distances; i++) {
    scanf("%lf", &distances[i]);
  }

  max_distance = distances[0];
  min_distance = distances[0];
  for (i = 1; i < num_distances; i++) {
    if (distances[i] > max_distance) {
      max_distance = distances[i];
    }
    if (distances[i] < min_distance) {
      min_distance = distances[i];
    }
  }

  avg_distance = 0;
  for (i = 0; i < num_distances; i++) {
    avg_distance += distances[i];
  }
  avg_distance /= num_distances;

  volume = pow(avg_distance, num_dimensions);
  probability = (max_distance - min_distance) / volume;

  if (probability < 0.1) {
    result = "Very low";
  } else if (probability < 0.3) {
    result = "Low";
  } else if (probability < 0.6) {
    result = "Moderate";
  } else if (probability < 0.8) {
    result = "High";
  } else {
    result = "Very high";
  }

  printf("The probability of an alien invasion is %s.\n", result);

  return 0;
}