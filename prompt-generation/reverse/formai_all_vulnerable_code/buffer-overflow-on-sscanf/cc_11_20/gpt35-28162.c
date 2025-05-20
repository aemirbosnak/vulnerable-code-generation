//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10
#define MAX_COMMAND_LENGTH 50

int main() {
  char droneIDs[MAX_DRONES][10] = {"drone1", "drone2", "drone3", "drone4", "drone5", "drone6", "drone7", "drone8", "drone9", "drone10"};
  int droneBattery[MAX_DRONES] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
  int droneX[MAX_DRONES];
  int droneY[MAX_DRONES];
  int numDrones = 3;
  int i, j;
  
  for (i = 0; i < numDrones; i++) {
    droneX[i] = rand()%100;
    droneY[i] = rand()%50;
  }
  
  printf("Welcome to the C Drone Remote Control Program\n\n");
  printf("Available drones: ");
  for (i = 0; i < numDrones; i++) {
    printf("%s ", droneIDs[i]);
  }
  printf("\n");
  
  char command[MAX_COMMAND_LENGTH];
  char droneID[10];
  int commandType;
  int droneIndex;
  int xPos, yPos;
  int batteryUsage;
  
  while(1) {
    printf("\nEnter command (takeoff, land, move, charge, status, exit): ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    sscanf(command, "%s", droneID);
    
    droneIndex = -1;
    for (i = 0; i < numDrones; i++) {
      if (strcmp(droneID, droneIDs[i]) == 0) {
        droneIndex = i;
        break;
      }
    }
    if (droneIndex == -1) {
      printf("Invalid drone ID\n");
      continue;
    }
    
    sscanf(command, "%*s %d", &commandType);
    switch(commandType) {
      case 1: // Takeoff
        if (droneBattery[droneIndex] < 20) {
          printf("%s battery is too low to takeoff\n", droneIDs[droneIndex]);
        } else {
          printf("%s is taking off...\n", droneIDs[droneIndex]);
          droneBattery[droneIndex] -= 20;
        }
        break;
        
      case 2: // Land
        if (droneBattery[droneIndex] < 10) {
          printf("%s battery is too low to land\n", droneIDs[droneIndex]);
        } else {
          printf("%s is landing...\n", droneIDs[droneIndex]);
          droneBattery[droneIndex] -= 10;
        }
        break;
        
      case 3: // Move
        if (droneBattery[droneIndex] < 5) {
          printf("%s battery is too low to move\n", droneIDs[droneIndex]);
        } else {
          sscanf(command, "%*s %*d %d %d", &xPos, &yPos);
          printf("%s is moving to position (%d, %d)\n", droneIDs[droneIndex], xPos, yPos);
          droneX[droneIndex] = xPos;
          droneY[droneIndex] = yPos;
          droneBattery[droneIndex] -= 5;
        }
        break;
        
      case 4: // Charge
        printf("%s is charging...\n", droneIDs[droneIndex]);
        droneBattery[droneIndex] = 100;
        break;
        
      case 5: // Status
        printf("Drone status:\n");
        for (i = 0; i < numDrones; i++) {
          printf("%s (%d, %d) battery=%d%%\n", droneIDs[i], droneX[i], droneY[i], droneBattery[i]);
        }
        break;
        
      case 6: // Exit
        printf("Exiting program\n");
        return 0;
        
      default:
        printf("Invalid command\n");
        break;
    }
  }
}