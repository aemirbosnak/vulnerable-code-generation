//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int calories_burned = 0;
  int steps_taken = 0;
  int minutes_exercised = 0;
  
  char response[50];
  
  printf("Welcome to the Surreal Fitness Tracker!\n");
  
  while (1) {
    printf("What exercise did you do today?\n");
    printf("(Enter 'run', 'yoga', 'dancing', or 'quit')\n");
    scanf("%s", response);
    
    if (strcmp(response, "run") == 0) {
      calories_burned += 500;
      steps_taken += 500;
      minutes_exercised += 30;
      printf("You ran through a field of pixelated flowers and burned 500 calories!\n");
    }
    else if (strcmp(response, "yoga") == 0) {
      calories_burned += 250;
      steps_taken += 100;
      minutes_exercised += 45;
      printf("You stretched your body into the shape of a rainbow and burned 250 calories!\n");
    }
    else if (strcmp(response, "dancing") == 0) {
      calories_burned += 350;
      steps_taken += 750;
      minutes_exercised += 60;
      printf("You danced on a beach made of liquid gold and burned 350 calories!\n");
    }
    else if (strcmp(response, "quit") == 0) {
      printf("Thank you for using the Surreal Fitness Tracker!\n");
      break;
    }
    else {
      printf("Invalid response. Please try again.\n");
    }
  }
  
  printf("You burned a total of %d calories today!\n", calories_burned);
  printf("You took a total of %d steps today!\n", steps_taken);
  printf("You exercised for a total of %d minutes today!\n", minutes_exercised);
  
  return 0;
}