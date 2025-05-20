//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: introspective
/*
 * A unique C Fitness Tracker example program in an introspective style.
 */

#include <stdio.h>
#include <stdlib.h>

// Define a structure to store information about the user's fitness activities
struct FitnessActivity {
  char activity_name[50];
  int duration;
  int calories_burned;
};

// Define a function to calculate the user's total calorie burn for the day
int calculate_calories_burned(int activities, struct FitnessActivity* activity_list) {
  int total_calories = 0;
  for (int i = 0; i < activities; i++) {
    total_calories += activity_list[i].calories_burned;
  }
  return total_calories;
}

// Define a function to display the user's fitness activities
void display_activities(int activities, struct FitnessActivity* activity_list) {
  for (int i = 0; i < activities; i++) {
    printf("%s\n", activity_list[i].activity_name);
  }
}

// Define a function to display the user's total calorie burn for the day
void display_total_calories(int activities, struct FitnessActivity* activity_list) {
  int total_calories = calculate_calories_burned(activities, activity_list);
  printf("Total calories burned today: %d\n", total_calories);
}

int main() {
  // Initialize the activity list
  struct FitnessActivity activity_list[10];
  int activities = 0;

  // Prompt the user to enter their fitness activities
  printf("Enter your fitness activities (type 'done' to stop):\n");
  while (1) {
    printf("Activity name: ");
    scanf("%s", activity_list[activities].activity_name);
    if (strcmp(activity_list[activities].activity_name, "done") == 0) {
      break;
    }
    printf("Duration (in minutes): ");
    scanf("%d", &activity_list[activities].duration);
    printf("Calories burned: ");
    scanf("%d", &activity_list[activities].calories_burned);
    activities++;
  }

  // Display the user's fitness activities
  display_activities(activities, activity_list);

  // Display the user's total calorie burn for the day
  display_total_calories(activities, activity_list);

  return 0;
}