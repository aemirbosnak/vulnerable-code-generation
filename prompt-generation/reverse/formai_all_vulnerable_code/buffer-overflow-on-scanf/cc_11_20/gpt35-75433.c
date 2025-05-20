//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <string.h>

struct exercise {
  char name[50];
  int calories;
} exercises[5];

int main() {
  int total_calories = 0;
  char name[50];
  int mins, choice;
  int num_exercises = 0;

  printf("Welcome to the Fitness Tracker!\n");

  while (1) {
    printf("\n1) Add Exercise\n2) View Total Calories Burned\n3) Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
      if (num_exercises >= 5) {
        printf("\nMaximum number of exercises reached.\n");
      } else {
        printf("\nEnter exercise name: ");
        scanf("%s", exercises[num_exercises].name);
        printf("Enter number of minutes: ");
        scanf("%d", &mins);

        printf("\n1) Running\n2) Cycling\n3) Swimming\n4) Lifting Weights\n5) Other\n");
        printf("\nEnter exercise type: ");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
            exercises[num_exercises].calories = mins * 9;
            break;
          case 2:
            exercises[num_exercises].calories = mins * 6;
            break;
          case 3:
            exercises[num_exercises].calories = mins * 10;
            break;
          case 4:
            exercises[num_exercises].calories = mins * 4;
            break;
          case 5:
            printf("Enter calories burned per minute: ");
            int cals_per_min;
            scanf("%d", &cals_per_min);
            exercises[num_exercises].calories = mins * cals_per_min;
            break;
          default:
            printf("\nInvalid choice.\n");
            break;
        }

        total_calories += exercises[num_exercises].calories;
        num_exercises++;

        printf("\nExercise added successfully!\n");
      }
    } else if (choice == 2) {
      printf("\nTotal calories burned: %d\n", total_calories);
    } else if (choice == 3) {
      printf("\nThank you for using the Fitness Tracker!\n");
      break;
    } else {
      printf("\nInvalid choice.\n");
    }
  }

  return 0;
}