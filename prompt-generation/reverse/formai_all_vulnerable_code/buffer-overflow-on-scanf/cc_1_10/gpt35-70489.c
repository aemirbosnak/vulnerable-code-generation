//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: high level of detail
#include <stdio.h>

int main() {
  // initialize variables
  int pitch = 0;
  int roll = 0;
  int altitude = 0;
  
  // print welcome message
  printf("Welcome to the C Drone Remote Control!\n");
  
  // print menu options
  printf("Please select an option:\n");
  printf("1. Change pitch\n");
  printf("2. Change roll\n");
  printf("3. Change altitude\n");
  
  // get user input for option selection
  int option = 0;
  scanf("%d", &option);
  
  // execute selected option
  switch(option) {
    case 1:
      printf("Enter new pitch (-90 to 90 degrees): ");
      scanf("%d", &pitch);
      printf("Pitch set to %d degrees.\n", pitch);
      break;
    case 2:
      printf("Enter new roll (-90 to 90 degrees): ");
      scanf("%d", &roll);
      printf("Roll set to %d degrees.\n", roll);
      break;
    case 3:
      printf("Enter new altitude (0 to 100 meters): ");
      scanf("%d", &altitude);
      printf("Altitude set to %d meters.\n", altitude);
      break;
    default:
      printf("Invalid option.\n");
      break;
  }
  
  // print updated drone status
  printf("\nCurrent Drone Status:\n");
  printf("Pitch: %d degrees\n", pitch);
  printf("Roll: %d degrees\n", roll);
  printf("Altitude: %d meters\n", altitude);
  
  return 0;
}