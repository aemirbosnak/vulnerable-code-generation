//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Set up the fitness tracker.
  int steps[1000];
  int distance[1000];
  int calories[1000];
  int heart_rate[1000];

  // Get the user's input.
  printf("Enter your name: ");
  char name[100];
  scanf("%s", name);

  printf("Enter your age: ");
  int age;
  scanf("%d", &age);

  printf("Enter your weight: ");
  float weight;
  scanf("%f", &weight);

  printf("Enter your height: ");
  float height;
  scanf("%f", &height);

  printf("Enter your activity level: ");
  char activity_level[100];
  scanf("%s", activity_level);

  // Calculate the user's fitness metrics.
  for (int i = 0; i < 1000; i++) {
    // Generate random values for the fitness metrics.
    steps[i] = rand() % 10000;
    distance[i] = steps[i] * 0.0005;
    calories[i] = steps[i] * 0.05 * weight;
    heart_rate[i] = 120 + (steps[i] * 0.1);
  }

  // Display the user's fitness metrics.
  printf("\nFitness Tracker Results for %s\n", name);
  printf("-----------------------------------\n");
  printf("Age: %d\n", age);
  printf("Weight: %.1f kg\n", weight);
  printf("Height: %.1f cm\n", height);
  printf("Activity Level: %s\n", activity_level);
  printf("\n");
  printf("Steps: %d\n", steps[999]);
  printf("Distance: %.2f km\n", distance[999]);
  printf("Calories: %d\n", calories[999]);
  printf("Heart Rate: %d bpm\n", heart_rate[999]);

  return 0;
}