//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main() {
  float distance, speed, time;
  int choice;

  printf("Welcome to the Ultimate Unit Converter!\n");
  printf("Please select an option:\n");
  printf("1. Convert distance\n");
  printf("2. Convert speed\n");
  printf("3. Convert time\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the distance you want to convert: ");
      scanf("%f", &distance);
      printf("Please select the target unit:\n");
      printf("1. Miles\n");
      printf("2. Kilometers\n");
      printf("3. Yards\n");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          distance *= 1.613;
          printf("The converted distance is: %.2f miles.\n", distance);
          break;
        case 2:
          distance *= 1.613;
          printf("The converted distance is: %.2f kilometers.\n", distance);
          break;
        case 3:
          distance *= 0.9144;
          printf("The converted distance is: %.2f yards.\n", distance);
          break;
        default:
          printf("Invalid input.\n");
      }
      break;
    case 2:
      printf("Enter the speed you want to convert: ");
      scanf("%f", &speed);
      printf("Please select the target unit:\n");
      printf("1. Miles per hour\n");
      printf("2. Kilometers per hour\n");
      printf("3. Knots\n");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          speed *= 1.613;
          printf("The converted speed is: %.2f miles per hour.\n", speed);
          break;
        case 2:
          speed *= 1.613;
          printf("The converted speed is: %.2f kilometers per hour.\n", speed);
          break;
        case 3:
          speed *= 0.5144;
          printf("The converted speed is: %.2f knots.\n", speed);
          break;
        default:
          printf("Invalid input.\n");
      }
      break;
    case 3:
      printf("Enter the time you want to convert: ");
      scanf("%f", &time);
      printf("Please select the target unit:\n");
      printf("1. Seconds\n");
      printf("2. Minutes\n");
      printf("3. Hours\n");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          time *= 1;
          printf("The converted time is: %.2f seconds.\n", time);
          break;
        case 2:
          time *= 60;
          printf("The converted time is: %.2f minutes.\n", time);
          break;
        case 3:
          time *= 3600;
          printf("The converted time is: %.2f hours.\n", time);
          break;
        default:
          printf("Invalid input.\n");
      }
      break;
    default:
      printf("Invalid input.\n");
  }

  return 0;
}