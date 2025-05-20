//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>

struct drone {
  int altitude;
  int speed;
  char direction;
};

struct remote {
  int batteryLife;
  int signalStrength;
  struct drone linkedDrone;
};

int main() {
  struct drone mavicPro = {0, 0, 'N'};
  struct remote controller = {100, 90, mavicPro};

  printf("=== Welcome to the Mavic Pro Remote Control App ===\n\n");

  while (1) {
    printf("\n\nCurrent drone status:\n");
    printf("Altitude: %d\n", controller.linkedDrone.altitude);
    printf("Speed: %d\n", controller.linkedDrone.speed);
    printf("Direction: %c\n", controller.linkedDrone.direction);

    printf("\nWhat would you like to do?\n");
    printf("1. Change altitude\n");
    printf("2. Change speed\n");
    printf("3. Change direction\n");
    printf("4. Exit\n");

    int userInput;
    scanf("%d", &userInput);

    switch (userInput) {
      case 1:
        printf("Enter new altitude: ");
        int newAltitude;
        scanf("%d", &newAltitude);

        controller.linkedDrone.altitude = newAltitude;
        printf("New altitude set to %d\n", newAltitude);

        break;

      case 2:
        printf("Enter new speed: ");
        int newSpeed;
        scanf("%d", &newSpeed);

        controller.linkedDrone.speed = newSpeed;
        printf("New speed set to %d\n", newSpeed);

        break;

      case 3:
        printf("Enter new direction: ");
        char newDir;
        scanf(" %c", &newDir);

        controller.linkedDrone.direction = newDir;
        printf("New direction set to %c\n", newDir);

        break;

      case 4:
        printf("Thank you for using the Mavic Pro Remote Control App.\n");
        return 0;

      default:
        printf("Invalid input. Please try again.\n");
        break;
    }

    // simulate battery usage and signal loss
    controller.batteryLife--;
    controller.signalStrength--;

    if (controller.batteryLife == 0 || controller.signalStrength == 0) {
      printf("Connection lost. Returning drone to origin.\n");
      controller.linkedDrone.altitude = 0;
      controller.linkedDrone.speed = 0;
      controller.linkedDrone.direction = 'N';

      controller.batteryLife = 100;
      controller.signalStrength = 90;
    }
  }

  return 0;
}