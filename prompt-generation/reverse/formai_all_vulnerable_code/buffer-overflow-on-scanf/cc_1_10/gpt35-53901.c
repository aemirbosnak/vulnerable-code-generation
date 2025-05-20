//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to hold the data for a workout
typedef struct Workout {
  char name[MAX_SIZE];
  int duration;
  int calories;
} Workout;

// Global variables
Workout workouts[MAX_SIZE];
int num_workouts = 0;

// Function declarations
void add_workout();
void view_workouts(bool detailed);
int get_total_calories();
int get_longest_workout_duration();
float get_average_workout_duration();
void search_workouts(char search_query[]);

int main() {
  int option;

  do {
    printf("\n=== C Fitness Tracker ===\n");
    printf("1. Add workout\n");
    printf("2. View workouts\n");
    printf("3. Get total calories burned\n");
    printf("4. Get longest workout duration\n");
    printf("5. Get average workout duration\n");
    printf("6. Search workouts by name\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        add_workout();
        break;
      case 2:
        view_workouts(true);
        break;
      case 3:
        printf("Total calories burned: %d\n", get_total_calories());
        break;
      case 4:
        printf("Longest workout duration: %d minutes\n", get_longest_workout_duration());
        break;
      case 5:
        printf("Average workout duration: %.2f minutes\n", get_average_workout_duration());
        break;
      case 6:
        {
          char search_query[MAX_SIZE];
          printf("Enter search query: ");
          scanf("%s", search_query);
          search_workouts(search_query);
          break;
        }
      case 0:
        printf("Thank you for using C Fitness Tracker!\n");
        break;
      default:
        printf("Invalid option. Please try again.\n");
        break;
    }

  } while (option != 0);

  return 0;
}

// Function to add a new workout
void add_workout() {
  printf("Enter workout name: ");
  scanf("%s", workouts[num_workouts].name);
  printf("Enter workout duration (in minutes): ");
  scanf("%d", &workouts[num_workouts].duration);
  printf("Enter calories burned: ");
  scanf("%d", &workouts[num_workouts].calories);
  num_workouts++;
  printf("Workout added!\n");
}

// Function to view all workouts
void view_workouts(bool detailed) {
  printf("\nWorkout List: \n");

  if (num_workouts == 0) {
    printf("No workouts found!\n");
    return;
  }

  for (int i = 0; i < num_workouts; i++) {
    printf("%d. %s\n", i+1, workouts[i].name);
    if (detailed) {
      printf("\tDuration: %d minutes\n", workouts[i].duration);
      printf("\tCalories burned: %d\n", workouts[i].calories);
    }
  }
}

// Function to get total calories burned
int get_total_calories() {
  int total_calories = 0;
  for (int i = 0; i < num_workouts; i++) {
    total_calories += workouts[i].calories;
  }
  return total_calories;
}

// Function to get longest workout duration
int get_longest_workout_duration() {
  int max_duration = 0;
  for (int i = 0; i < num_workouts; i++) {
    if (workouts[i].duration > max_duration) {
      max_duration = workouts[i].duration;
    }
  }
  return max_duration;
}

// Function to get average workout duration
float get_average_workout_duration() {
  int total_duration = 0;
  for (int i = 0; i < num_workouts; i++) {
    total_duration += workouts[i].duration;
  }
  return (float) total_duration / num_workouts;
}

// Function to search workouts by name
void search_workouts(char search_query[]) {
  printf("\nSearch results for '%s':\n", search_query);
  bool found = false;

  for (int i = 0; i < num_workouts; i++) {
    if (strstr(workouts[i].name, search_query) != NULL) {
      printf("%d. %s\n", i+1, workouts[i].name);
      printf("\tDuration: %d minutes\n", workouts[i].duration);
      printf("\tCalories burned: %d\n", workouts[i].calories);
      found = true;
    }
  }

  if (!found) {
    printf("No results found!\n");
  }
}