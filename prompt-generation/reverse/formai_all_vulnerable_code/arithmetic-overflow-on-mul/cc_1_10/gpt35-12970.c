//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>

int main() {
  
  int calories_burned = 0;
  int total_pushups = 0;
  int total_squats = 0;
  int total_burpees = 0;
  
  printf("Welcome to Fitness Tracker! Let's start working out!\n\n");
  
  while (1) {
    
    printf("What exercise would you like to do?\n");
    printf("1. pushups\n");
    printf("2. squats\n");
    printf("3. burpees\n");
    printf("4. exit\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
      printf("How many pushups did you do?\n");
      int num_pushups;
      scanf("%d", &num_pushups);
      total_pushups += num_pushups;
      calories_burned += num_pushups*10;
      printf("You have done a total of %d pushups and burned %d calories!\n\n", total_pushups, calories_burned);
    }
    
    else if (choice == 2) {
      printf("How many squats did you do?\n");
      int num_squats;
      scanf("%d", &num_squats);
      total_squats += num_squats;
      calories_burned += num_squats*8;
      printf("You have done a total of %d squats and burned %d calories!\n\n", total_squats, calories_burned);
    }
    
    else if (choice == 3) {
      printf("How many burpees did you do?\n");
      int num_burpees;
      scanf("%d", &num_burpees);
      total_burpees += num_burpees;
      calories_burned += num_burpees*12;
      printf("You have done a total of %d burpees and burned %d calories!\n\n", total_burpees, calories_burned);
    }
    
    else if (choice == 4) {
      printf("Thanks for working out with us! You have burned a total of %d calories!\n", calories_burned);
      break;
    }
    
    else {
      printf("Invalid choice, please try again.\n\n");
    }
    
  }
  return 0;
}