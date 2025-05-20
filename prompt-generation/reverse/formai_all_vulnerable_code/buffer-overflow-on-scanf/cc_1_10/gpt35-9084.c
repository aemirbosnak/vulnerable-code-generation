//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool isWorkoutComplete(int reps, int sets, int duration);

void main() {
  int reps = 10;
  int sets = 3;
  int duration = 60;

  printf("Welcome to the Surrealist Fitness Tracker!\n");
  printf("Today's workout consists of:\n");
  printf("%d sets of %d reps of mind-bending exercises\n", sets, reps);
  printf("You will be working out for %d minutes\n", duration);

  bool workoutComplete = false;

  while (!workoutComplete) {
    printf("Please start your workout - we are tracking your progress!\n");

    for (int set_num = 1; set_num <= sets; set_num++) {
      for (int rep_num = 1; rep_num <= reps; rep_num++) {
        printf("Set %d, Rep %d: Please choose a surrealist exercise: \n", set_num, rep_num);
        printf("1. Reimagine gravity and levitate for 10 seconds\n");
        printf("2. Contemplate the infinite void and perform 10 burpees\n");
        printf("3. Imagine you are a tree and hold a plank for 30 seconds\n");
        printf("4. Visualize a desert mirage and do 10 jumping jacks\n");

        int exerciseChoice;
        scanf("%d", &exerciseChoice);

        switch (exerciseChoice) {
          case 1:
            printf("You have reimagined gravity and levitated for 10 seconds!\n");
            break;
          case 2:
            printf("You have contemplated the infinite void and performed 10 burpees!\n");
            break;
          case 3:
            printf("You have imagined you are a tree and held a plank for 30 seconds!\n");
            break;
          case 4:
            printf("You have visualized a desert mirage and completed 10 jumping jacks!\n");
            break;
          default:
            printf("Invalid exercise choice - please choose again\n");
            rep_num--; // repeat this rep
            break;
        }
      }
      printf("Set %d complete!\n", set_num);
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Congratulations! You have completed your workout on %d-%02d-%02d at %02d:%02d:%02d\n",
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    workoutComplete = isWorkoutComplete(reps, sets, duration);
    if (!workoutComplete) {
      printf("Sorry, your workout was not complete - please start again\n");
    }
  }

  printf("Thank you for using the Surrealist Fitness Tracker! Goodbye!\n");
}

bool isWorkoutComplete(int reps, int sets, int duration) {
  srand(time(NULL)); // use current time as seed for random generator
  int timeSpent = rand() % 20 + duration - 10; // randomly add or subtract up to 10 minutes

  printf("Your workout lasted %d minutes\n", timeSpent);

  if (timeSpent < duration) {
    printf("You did not complete your workout - you worked out for less than the planned duration of %d minutes\n", duration);
    return false;
  }

  int repsCompleted = rand() % 5 + (reps * sets) - 5;
  printf("You completed %d reps (out of %d)\n", repsCompleted, reps * sets);

  if (repsCompleted < (reps * sets) * 0.7) {
    printf("You did not complete your workout - you completed less than 70 percent of the planned reps\n");
    return false;
  }

  printf("Congratulations! You have completed your workout successfully!\n");
  return true;
}