//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main(){
  // Initialize variables
  int speed = 0;
  int direction = 0;
  int altitude = 0;

  // Welcome message
  printf("\n=== Welcome to the C Drone Remote Control Program ===\n");

  while(1){
    // Display menu options
    printf("\nPlease select a command:\n");
    printf("\t1. Set speed\n");
    printf("\t2. Set direction\n");
    printf("\t3. Set altitude\n");
    printf("\t4. Take off\n");
    printf("\t5. Land\n");
    printf("\t6. Exit\n");

    // Get user input
    int command;
    printf("\nEnter command number: ");
    scanf("%d", &command);

    // Process user input
    switch(command){
      case 1:
        printf("\nEnter speed (0-100): ");
        scanf("%d", &speed);
        printf("Speed set to %d\n", speed);
        break;
      case 2:
        printf("\nEnter direction (0-360): ");
        scanf("%d", &direction);
        printf("Direction set to %d\n", direction);
        break;
      case 3:
        printf("\nEnter altitude (0-1000): ");
        scanf("%d", &altitude);
        printf("Altitude set to %d\n", altitude);
        break;
      case 4:
        if(speed == 0 || altitude == 0){
          printf("Error: Speed and altitude must be set before takeoff.\n");
        }else{
          printf("Taking off at speed %d and altitude %d...\n", speed, altitude);
        }
        break;
      case 5:
        printf("Landing...\n");
        speed = 0;
        altitude = 0;
        break;
      case 6:
        printf("Exiting program...\n");
        exit(0);
        break;
      default:
        printf("Error: Invalid command.\n");
    }
  }

  return 0;
}