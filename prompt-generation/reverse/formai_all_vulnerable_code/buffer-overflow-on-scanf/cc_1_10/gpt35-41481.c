//FormAI DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  int temp = 70; // Set initial temperature to 70 degrees Fahrenheit
  int lights = 0; // Lights are initially turned off
  int time = 0; // Set initial time to 12:00am
  
  printf("Welcome to your smart home automation system!\n");
  printf("The current temperature is %dF.\n", temp);
  
  while (1) { // Loop indefinitely
    
    printf("What would you like to do? Enter '1' to adjust temperature, '2' to turn lights on/off, and '3' to check the time.\n");
    int option;
    scanf("%d", &option);
    
    switch(option) {
      case 1: // Adjust temperature
        printf("Enter the desired temperature in Fahrenheit:\n");
        scanf("%d", &temp);
        printf("The temperature has been set to %dF.\n", temp);
        break;
      case 2: // Turn lights on/off
        if (lights == 0) {
          printf("The lights are currently off. Enter '1' to turn them on.\n");
          scanf("%d", &lights);
          printf("The lights have been turned on.\n");
        } else {
          printf("The lights are currently on. Enter '0' to turn them off.\n");
          scanf("%d", &lights);
          printf("The lights have been turned off.\n");
        }
        break;
      case 3: // Check time
        if (time == 0) {
          printf("The current time is 12:00am.\n");
          time++;
        } else if (time < 12) {
          printf("The current time is %d:00am.\n", time);
          time++;
        } else if (time == 12) {
          printf("The current time is 12:00pm.\n");
          time++;
        } else if (time < 24) {
          printf("The current time is %d:00pm.\n", time-12);
          time++;
        } else {
          printf("The day has ended. Goodnight!\n");
          exit(0); // Exit the program
        }
        break;
      default:
        printf("Invalid input. Please enter '1', '2', or '3'.\n");
        break;
    }
    
    printf("\n"); // Add blank line for readability
  }
  
  return 0;
}