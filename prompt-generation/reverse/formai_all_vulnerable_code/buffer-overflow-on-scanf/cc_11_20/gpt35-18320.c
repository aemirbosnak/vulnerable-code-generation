//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>

int main() {
  // Initialize the remote control
  int throttle = 0;
  int pitch = 0;
  int yaw = 0;
  int roll = 0;
  int armed = 0;
  
  printf("Welcome to the C Drone Remote Control Program!\n");
  
  // Keep the remote control running until we decide to stop it
  while(1) {
    
    // Get the user input
    char input[100];
    printf("\nEnter a command (throttle, pitch, yaw, roll, arm, disarm, quit): ");
    fgets(input, 100, stdin);
    
    // Parse and execute the command
    if(strcmp(input, "throttle\n") == 0) {
      printf("Enter a value for throttle (0-100): ");
      scanf("%d", &throttle);
      getchar(); // clear the newline character from the buffer
      printf("Setting throttle to %d\n", throttle);
    } else if(strcmp(input, "pitch\n") == 0) {
      printf("Enter a value for pitch (-100 to 100): ");
      scanf("%d", &pitch);
      getchar(); // clear the newline character from the buffer
      printf("Setting pitch to %d\n", pitch);
    } else if(strcmp(input, "yaw\n") == 0) {
      printf("Enter a value for yaw (-100 to 100): ");
      scanf("%d", &yaw);
      getchar(); // clear the newline character from the buffer
      printf("Setting yaw to %d\n", yaw);
    } else if(strcmp(input, "roll\n") == 0) {
      printf("Enter a value for roll (-100 to 100): ");
      scanf("%d", &roll);
      getchar(); // clear the newline character from the buffer
      printf("Setting roll to %d\n", roll);
    } else if(strcmp(input, "arm\n") == 0) {
      if(!armed) {
        printf("Arming the drone...\n");
        armed = 1; // set the ARMED flag
      } else {
        printf("The drone is already armed!\n");
      }
    } else if(strcmp(input, "disarm\n") == 0) {
      if(armed) {
        printf("Disarming the drone...\n");
        armed = 0; // clear the ARMED flag
      } else {
        printf("The drone is already disarmed!\n");
      }
    } else if(strcmp(input, "quit\n") == 0) {
      printf("Exiting...\n");
      break; // exit the program
    } else {
      printf("Invalid command!\n");
    }
    
    // Print the current status of the drone
    printf("\nCurrent status:\n");
    printf("  Throttle: %d\n", throttle);
    printf("  Pitch: %d\n", pitch);
    printf("  Yaw: %d\n", yaw);
    printf("  Roll: %d\n", roll);
    if(armed) {
      printf("  ARMED\n");
    } else {
      printf("  DISARMED\n");
    }
  }
  
  return 0;
}