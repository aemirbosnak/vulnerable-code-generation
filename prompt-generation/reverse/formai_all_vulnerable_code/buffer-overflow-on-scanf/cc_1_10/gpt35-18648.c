//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>

int main() {
  int pushups = 0;
  int situps = 0;
  int squats = 0;
  int totalWorkoutDuration = 0;
  
  printf("Welcome to the C Fitness Tracker!\n");
  
  while(1) {
    printf("\nWhat would you like to do? Enter 'p' for pushups, 's' for situps, 'q' for squats, or 'f' to finish workout: ");
    char task;
    scanf("%c", &task);

    if(task == 'p') {
      printf("Enter the number of pushups: ");
      int numPushups;
      scanf("%d", &numPushups);
      pushups += numPushups;
      printf("Great job! You've done %d pushups so far.\n", pushups);
    } else if(task == 's') {
      printf("Enter the number of situps: ");
      int numSitups;
      scanf("%d", &numSitups);
      situps += numSitups;
      printf("Keep it up! You've done %d situps so far.\n", situps);
    } else if(task == 'q') {
      printf("Enter the number of squats: ");
      int numSquats;
      scanf("%d", &numSquats);
      squats += numSquats;
      printf("Awesome job! You've done %d squats so far.\n", squats);
    } else if(task == 'f') {
      printf("\nYour workout summary:\n");
      printf("Pushups: %d\n", pushups);
      printf("Situps: %d\n", situps);
      printf("Squats: %d\n", squats);
      totalWorkoutDuration = (pushups + situps + squats) * 10; // assuming each exercise takes 10 seconds
      printf("Total workout duration: %d seconds\n", totalWorkoutDuration);
      break;
    } else {
      printf("Invalid input. Please try again.\n");
    }
    
    // clear stdin input buffer
    while(getchar() != '\n');
  }

  return 0;
}