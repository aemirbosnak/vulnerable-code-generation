//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
  int power = 0;
  int altitude = 0;
  int pitch = 0;
  int roll = 0;
  int yaw = 0;

  while(1) {
    printf("Welcome to the C Drone Remote Control!\n");
    printf("Enter a command:\n");
    printf("1. Power\n");
    printf("2. Altitude\n");
    printf("3. Pitch\n");
    printf("4. Roll\n");
    printf("5. Yaw\n");
    printf("6. Quit\n");

    int command = 0;
    scanf("%d", &command);

    switch(command) {
      case 1:
        printf("Power: ");
        scanf("%d", &power);
        printf("Power set to %d\n", power);
        break;
      case 2:
        printf("Altitude: ");
        scanf("%d", &altitude);
        printf("Altitude set to %d\n", altitude);
        break;
      case 3:
        printf("Pitch: ");
        scanf("%d", &pitch);
        printf("Pitch set to %d\n", pitch);
        break;
      case 4:
        printf("Roll: ");
        scanf("%d", &roll);
        printf("Roll set to %d\n", roll);
        break;
      case 5:
        printf("Yaw: ");
        scanf("%d", &yaw);
        printf("Yaw set to %d\n", yaw);
        break;
      case 6:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid command\n");
        break;
    }

    printf("========================================\n");
  }

  return 0;
}