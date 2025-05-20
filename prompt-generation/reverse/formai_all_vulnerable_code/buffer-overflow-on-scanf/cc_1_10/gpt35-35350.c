//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int reps;
  float weight;
} Exercise;

typedef struct {
  char name[50];
  Exercise bench_press;
  Exercise squat;
  Exercise deadlift;
} Workout;

int main() {
  int num_workouts;
  printf("How many workouts would you like to track? ");
  scanf("%d", &num_workouts);

  // Allocating memory for workouts
  Workout *workouts = calloc(num_workouts, sizeof(Workout));

  // Gathering workout data
  for (int i = 0; i < num_workouts; i++) {
    printf("Enter the name of workout %d: ", i+1);
    scanf("%s", workouts[i].name);

    printf("Enter the number of reps for bench press: ");
    scanf("%d", &workouts[i].bench_press.reps);

    printf("Enter the weight for bench press: ");
    scanf("%f", &workouts[i].bench_press.weight);

    printf("Enter the number of reps for squat: ");
    scanf("%d", &workouts[i].squat.reps);

    printf("Enter the weight for squat: ");
    scanf("%f", &workouts[i].squat.weight);

    printf("Enter the number of reps for deadlift: ");
    scanf("%d", &workouts[i].deadlift.reps);

    printf("Enter the weight for deadlift: ");
    scanf("%f", &workouts[i].deadlift.weight);

    printf("\n");
  }

  // Displaying workout data
  printf("Workout Data:\n");
  for (int i = 0; i < num_workouts; i++) {
    printf("Workout %d - %s:\n", i+1, workouts[i].name);
    printf("Bench Press: %d reps x %.2f lbs\n", workouts[i].bench_press.reps, workouts[i].bench_press.weight);
    printf("Squat: %d reps x %.2f lbs\n", workouts[i].squat.reps, workouts[i].squat.weight);
    printf("Deadlift: %d reps x %.2f lbs\n", workouts[i].deadlift.reps, workouts[i].deadlift.weight);
    printf("\n");
  }

  free(workouts);
  return 0;
}