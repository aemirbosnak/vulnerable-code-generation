//FormAI DATASET v1.0 Category: Physics simulation ; Style: systematic
#include <stdio.h>

int main() {
  // declaring variables
  float initial_velocity, final_velocity, acceleration, distance, time;
  char choice;

  // user input for which variable to calculate
  printf("Which variable do you want to calculate?\n");
  printf("Options: 'a' for acceleration, 'd' for distance, 't' for time\n");
  scanf("%c", &choice);

  // switch case for different calculations
  switch(choice) {
    case 'a':
      // calculate acceleration
      printf("Enter the initial velocity: ");
      scanf("%f", &initial_velocity);
      printf("Enter the final velocity: ");
      scanf("%f", &final_velocity);
      printf("Enter the time: ");
      scanf("%f", &time);
      acceleration = (final_velocity - initial_velocity) / time;
      printf("The acceleration is: %.2f\n", acceleration);
      break;

    case 'd':
      // calculate distance
      printf("Enter the initial velocity: ");
      scanf("%f", &initial_velocity);
      printf("Enter the time: ");
      scanf("%f", &time);
      printf("Enter the acceleration: ");
      scanf("%f", &acceleration);
      distance = initial_velocity * time + 0.5 * acceleration * time * time;
      printf("The distance is: %.2f\n", distance);
      break;

    case 't':
      // calculate time
      printf("Enter the initial velocity: ");
      scanf("%f", &initial_velocity);
      printf("Enter the final velocity: ");
      scanf("%f", &final_velocity);
      printf("Enter the acceleration: ");
      scanf("%f", &acceleration);
      time = (final_velocity - initial_velocity) / acceleration;
      printf("The time is: %.2f\n", time);
      break;

    default:
      printf("Invalid choice\n");
  }
  
  return 0;
}