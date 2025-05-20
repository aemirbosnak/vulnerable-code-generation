//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void main() {
  int x = 0;
  printf("Welcome to the C Drone Remote Control program!\n\n");

  // connect to drone
  printf("Connecting to drone...\n");
  while (x < 10) {
    printf("Connecting...\n");
    x++;
  }
  printf("Connection established!\n\n");

  // main menu
  printf("Main Menu:\n");
  printf("1. Take off\n");
  printf("2. Land\n");
  printf("3. Move up\n");
  printf("4. Move down\n");
  printf("5. Move left\n");
  printf("6. Move right\n");
  printf("7. Rotate clockwise\n");
  printf("8. Rotate counterclockwise\n");
  printf("9. Exit\n\n");

  // user input
  int choice = 0;
  while (choice != 9) {
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Drone is taking off...\n\n");
        break;
      case 2:
        printf("Drone is landing...\n\n");
        break;
      case 3:
        printf("Drone is moving up...\n\n");
        break;
      case 4:
        printf("Drone is moving down...\n\n");
        break;
      case 5:
        printf("Drone is moving left...\n\n");
        break;
      case 6:
        printf("Drone is moving right...\n\n");
        break;
      case 7:
        printf("Drone is rotating clockwise...\n\n");
        break;
      case 8:
        printf("Drone is rotating counterclockwise...\n\n");
        break;
      case 9:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice, please enter a number from 1 to 9.\n\n");
        break;
    }
  }

  // disconnect from drone
  printf("Disconnecting from drone...\n");
  while (x > 0) {
    printf("Disconnecting...\n");
    x--;
  }
  printf("Disconnected from drone!\n");
}