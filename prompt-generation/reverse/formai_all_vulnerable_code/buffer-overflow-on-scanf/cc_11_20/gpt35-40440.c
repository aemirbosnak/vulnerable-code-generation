//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
  int batteryLevel = 100; // Initialize battery level to 100%
  
  printf("Welcome to the C Drone Remote-Control Program!\n\n");
  
  printf("Current battery level: %d%%\n", batteryLevel);
  
  // Loop until battery level is 0%
  while (batteryLevel > 0) {
    printf("\n\nPlease select an option:\n");
    printf("[1] Take off\n");
    printf("[2] Land\n");
    printf("[3] Move forward\n");
    printf("[4] Move backward\n");
    printf("[5] Move left\n");
    printf("[6] Move right\n");
    printf("[7] Increase altitude\n");
    printf("[8] Decrease altitude\n");
    printf("[9] Check battery level\n");
    printf("[0] Exit program\n");
    printf("Enter option number: ");
    
    int option;
    scanf("%d", &option);
    
    switch (option) {
      case 1:
        printf("\nDrone taking off...\n");
        break;
      case 2:
        printf("\nDrone landing...\n");
        break;
      case 3:
        printf("\nDrone moving forward...\n");
        break;
      case 4:
        printf("\nDrone moving backward...\n");
        break;
      case 5:
        printf("\nDrone moving left...\n");
        break;
      case 6:
        printf("\nDrone moving right...\n");
        break;
      case 7:
        printf("\nIncreasing altitude...\n");
        break;
      case 8:
        printf("\nDecreasing altitude...\n");
        break;
      case 9:
        printf("\nCurrent battery level: %d%%\n", batteryLevel);
        break;
      case 0:
        printf("\nExiting program...\n");
        return 0;
      default:
        printf("\nInvalid option entered. Please try again.\n");
        break;
    }
    
    // Randomly decrease battery level between 0-10%
    int batteryDecrease = rand() % 11;
    batteryLevel -= batteryDecrease;
    
    if (batteryLevel <= 0) {
      printf("\nBattery level is now 0%%. Drone shutting down.\n");
      return 0;
    }
  }
  
  return 0;
}