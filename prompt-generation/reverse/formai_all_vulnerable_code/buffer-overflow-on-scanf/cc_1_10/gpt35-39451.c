//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>

int main() {

  // Shape shift into a drone remote control program
  printf("Welcome to your Drone Remote Control!\n\n");
  
  // Initialize variables for drone's movement
  int forward = 0, backward = 0, left = 0, right = 0, up = 0, down = 0;
  
  // Loop until user chooses to exit
  while(1) {
    
    // Prompt user to enter a command
    printf("Enter a command (f/b/l/r/u/d/exit): ");
    
    // Read user input
    char command[10];
    scanf("%s", command);
    
    // Handle user input
    if(strcmp(command, "f") == 0) {
      forward = 1;
      printf("Moving Forward\n");
    }
    else if(strcmp(command, "b") == 0) {
      backward = 1;
      printf("Moving Backward\n");
    }
    else if(strcmp(command, "l") == 0) {
      left = 1;
      printf("Moving Left\n");
    }
    else if(strcmp(command, "r") == 0) {
      right = 1;
      printf("Moving Right\n");
    }
    else if(strcmp(command, "u") == 0) {
      up = 1;
      printf("Moving Up\n");
    }
    else if(strcmp(command, "d") == 0) {
      down = 1;
      printf("Moving Down\n");
    }
    else if(strcmp(command, "exit") == 0) {
      printf("Exiting Drone Remote Control...\n");
      break;
    }
    else {
      printf("Invalid command!\n");
    }
    
  }
  
  return 0;
}