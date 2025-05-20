//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
// C Drone Remote Control example program
#include <stdio.h>
#include <stdlib.h>

// Communication protocol global variables
int power_status = 0; // 0 - Off, 1 - On
int altitude = 0;
int heading = 0;
int pitch = 0;
int roll = 0;

// Function to send command to drone
void sendCommand(char *command) {
  // TODO: Implement code to send command via communication protocol
  printf("Command sent: %s\n", command);
}

int main() {

  printf("Welcome to C Drone Remote Control!\n");

  // Program loop: read user input and send command to drone
  while (1) {

    // Display menu
    printf("\nMenu:\n");
    printf("1. Power on/off\n");
    printf("2. Set altitude\n");
    printf("3. Set heading\n");
    printf("4. Set pitch\n");
    printf("5. Set roll\n");
    printf("6. Exit\n");

    // Read user input
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Process user input and send command to drone
    switch(choice) {
      case 1: { // Power on/off
        char *command;
        if (power_status == 0) {
          command = "Power on";
          power_status = 1;
        } else {
          command = "Power off";
          power_status = 0;
        }
        sendCommand(command);
        break;
      }
      case 2: { // Set altitude
        printf("Enter altitude: ");
        scanf("%d", &altitude);
        char command[100];
        sprintf(command, "Set altitude to %d", altitude);
        sendCommand(command);
        break;
      }
      case 3: { // Set heading
        printf("Enter heading: ");
        scanf("%d", &heading);
        char command[100];
        sprintf(command, "Set heading to %d", heading);
        sendCommand(command);
        break;
      }
      case 4: { // Set pitch
        printf("Enter pitch: ");
        scanf("%d", &pitch);
        char command[100];
        sprintf(command, "Set pitch to %d", pitch);
        sendCommand(command);
        break;
      }
      case 5: { // Set roll
        printf("Enter roll: ");
        scanf("%d", &roll);
        char command[100];
        sprintf(command, "Set roll to %d", roll);
        sendCommand(command);
        break;
      }
      case 6: // Exit
        printf("Exiting C Drone Remote Control!\n");
        exit(0);
      default: // Invalid choice
        printf("Invalid choice. Please enter a number from 1 to 6.\n");
    }
  }

  return 0;
}