//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int calories = 0;
  int steps = 0;
  float distance = 0;
  float pace = 0;
  int time = 0;
  float calories_per_step = 0.04;

  printf("Welcome to your Fitness Tracker!\n");

  while (1) {

    int option = 0;

    printf("\nWhat would you like to do?\n");
    printf("1. Track calories burned\n");
    printf("2. Track steps taken\n");
    printf("3. Track distance traveled\n");
    printf("4. Track pace\n");
    printf("5. Track exercise time\n");
    printf("6. Exit\n");
    printf("Enter option number: ");
    scanf("%d", &option);

    if (option == 6) {
      printf("\nThank you for using your Fitness Tracker! Keep up the good work!\n");
      break;
    }

    switch (option) {
      case 1:
        printf("\nEnter the number of calories burned: ");
        scanf("%d", &calories);
        break;
      case 2:
        printf("\nEnter the number of steps taken: ");
        scanf("%d", &steps);
        calories = steps * calories_per_step;
        break;
      case 3:
        printf("\nEnter the distance traveled (in km): ");
        scanf("%f", &distance);
        break;
      case 4:
        printf("\nEnter your pace (in minutes per km): ");
        scanf("%f", &pace);
        break;
      case 5:
        printf("\nEnter the exercise time (in minutes): ");
        scanf("%d", &time);
        calories = time * 10;
        break;
      default:
        printf("\nInvalid option\n");
        continue;
    }

    printf("\nYour current stats:\n");
    printf("Calories burned: %d\n", calories);
    printf("Steps taken: %d\n", steps);
    printf("Distance traveled: %.2f km\n", distance);
    printf("Pace: %.2f minutes per km\n", pace);
    printf("Exercise time: %d minutes\n", time);
  }

  return 0;
}