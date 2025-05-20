//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int hr, min, sec, steps, reps, sets;
  float weight, distance;

  printf("Enter the current hour:");
  scanf("%d", &hr);

  printf("Enter the current minute:");
  scanf("%d", &min);

  printf("Enter the current second:");
  scanf("%d", &sec);

  printf("Enter the number of steps taken:");
  scanf("%d", &steps);

  printf("Enter the number of repetitions:");
  scanf("%d", &reps);

  printf("Enter the number of sets:");
  scanf("%d", &sets);

  printf("Enter your weight:");
  scanf("%f", &weight);

  printf("Enter the distance traveled:");
  scanf("%f", &distance);

  // Calculate the total time spent exercising
  int totalTime = hr * 60 + min + sec;

  // Calculate the total number of repetitions
  int totalReps = reps * sets;

  // Calculate the total distance traveled
  float totalDistance = distance * 1.613;

  // Display the results
  printf("Your current time is: %d:%d:%d", hr, min, sec);
  printf("\n");
  printf("You have taken %d steps.", steps);
  printf("\n");
  printf("You have completed a total of %d repetitions.", totalReps);
  printf("\n");
  printf("You have completed a total of %d sets.", sets);
  printf("\n");
  printf("Your total time spent exercising is: %d minutes.", totalTime);
  printf("\n");
  printf("Your total distance traveled is: %.2f miles.", totalDistance);
  printf("\n");
  printf("Your total weight loss is: %.2f pounds.", weight * totalReps * totalDistance);

  return 0;
}