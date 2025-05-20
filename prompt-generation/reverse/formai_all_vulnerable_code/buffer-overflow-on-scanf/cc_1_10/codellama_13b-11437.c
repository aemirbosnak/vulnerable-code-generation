//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_EXERCISES 10
#define MAX_REPS 100

typedef struct {
  char name[20];
  int age;
  float weight;
  float height;
} User;

typedef struct {
  char name[20];
  int calories;
} Exercise;

typedef struct {
  User user;
  Exercise exercise;
  int reps[MAX_REPS];
} Workout;

void prompt_user(User *user) {
  printf("Enter your name: ");
  scanf("%s", user->name);
  printf("Enter your age: ");
  scanf("%d", &user->age);
  printf("Enter your weight (in kg): ");
  scanf("%f", &user->weight);
  printf("Enter your height (in cm): ");
  scanf("%f", &user->height);
}

void prompt_exercise(Exercise *exercise) {
  printf("Enter the name of the exercise: ");
  scanf("%s", exercise->name);
  printf("Enter the number of calories burned: ");
  scanf("%d", &exercise->calories);
}

void prompt_workout(Workout *workout) {
  prompt_user(&workout->user);
  prompt_exercise(&workout->exercise);
  int num_reps;
  printf("Enter the number of reps: ");
  scanf("%d", &num_reps);
  for (int i = 0; i < num_reps; i++) {
    printf("Enter rep %d: ", i + 1);
    scanf("%d", &workout->reps[i]);
  }
}

void display_workout(Workout *workout) {
  printf("Name: %s\n", workout->user.name);
  printf("Age: %d\n", workout->user.age);
  printf("Weight: %f kg\n", workout->user.weight);
  printf("Height: %f cm\n", workout->user.height);
  printf("Exercise: %s\n", workout->exercise.name);
  printf("Calories burned: %d\n", workout->exercise.calories);
  printf("Reps: ");
  for (int i = 0; i < MAX_REPS; i++) {
    if (workout->reps[i] == 0) break;
    printf("%d ", workout->reps[i]);
  }
  printf("\n");
}

int main() {
  Workout workouts[MAX_USERS];
  int num_workouts;
  printf("Enter the number of workouts: ");
  scanf("%d", &num_workouts);
  for (int i = 0; i < num_workouts; i++) {
    prompt_workout(&workouts[i]);
  }
  for (int i = 0; i < num_workouts; i++) {
    display_workout(&workouts[i]);
  }
  return 0;
}