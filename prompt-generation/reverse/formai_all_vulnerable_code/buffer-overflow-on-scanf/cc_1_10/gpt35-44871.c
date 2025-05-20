//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Drone Remote Control Program!\n\n");
  
  int battery_level = 100;
  int altitude = 0;
  
  while(1) {
    printf("Choose an action:\n");
    printf("1. Increase altitude\n");
    printf("2. Decrease altitude\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Check battery level\n");
    printf("6. Exit program\n");
    
    int choice;
    scanf("%d", &choice);
    
    if(choice == 1) {
      printf("Increasing altitude...\n");
      altitude += 10;
      printf("New altitude: %d\n", altitude);
    }
    else if(choice == 2) {
      printf("Decreasing altitude...\n");
      altitude -= 10;
      printf("New altitude: %d\n", altitude);
    }
    else if(choice == 3) {
      printf("Turning left...\n");
    }
    else if(choice == 4) {
      printf("Turning right...\n");
    }
    else if(choice == 5) {
      printf("Checking battery level...\n");
      printf("Battery level: %d\n", battery_level);
    }
    else if(choice == 6) {
      printf("Exiting program...\n");
      break;
    }
    else {
      printf("Invalid choice. Please try again.\n");
    }
    
    battery_level -= 5;
    if(battery_level <= 0) {
      printf("Battery level too low. Returning to base...\n");
      exit(0);
    }
  }
  
  printf("Thank you for using the C Drone Remote Control Program!\n");
  return 0;
}