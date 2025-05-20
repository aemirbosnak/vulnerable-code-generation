//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
/*
 * Fitness Tracker
 *
 * A simple program that tracks the user's fitness goals and progress.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_GOALS 5
#define MAX_LENGTH 256

typedef struct {
  char name[MAX_LENGTH];
  int steps;
  int calories;
  int distance;
} Goal;

void print_goal(Goal goal) {
  printf("Name: %s\n", goal.name);
  printf("Steps: %d\n", goal.steps);
  printf("Calories: %d\n", goal.calories);
  printf("Distance: %d\n", goal.distance);
}

int main() {
  Goal goals[MAX_GOALS];
  int num_goals = 0;

  while (1) {
    char command[MAX_LENGTH];
    printf("Enter a command: ");
    fgets(command, MAX_LENGTH, stdin);
    command[strlen(command) - 1] = '\0';

    if (strcmp(command, "add") == 0) {
      Goal goal;
      printf("Enter the goal name: ");
      fgets(goal.name, MAX_LENGTH, stdin);
      goal.name[strlen(goal.name) - 1] = '\0';
      printf("Enter the goal steps: ");
      scanf("%d", &goal.steps);
      printf("Enter the goal calories: ");
      scanf("%d", &goal.calories);
      printf("Enter the goal distance: ");
      scanf("%d", &goal.distance);
      goals[num_goals++] = goal;
    } else if (strcmp(command, "print") == 0) {
      for (int i = 0; i < num_goals; i++) {
        print_goal(goals[i]);
      }
    } else if (strcmp(command, "exit") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}