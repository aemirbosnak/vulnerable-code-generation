//FormAI DATASET v1.0 Category: Smart home light control ; Style: brave
#include <stdio.h>
#include <stdbool.h>

int main(void) {
  // initialize variables
  int masterSwitch = 0;
  int livingRoomLight = 0;
  int kitchenLight = 0;
  int bedroomLight = 0;

  printf("Welcome to the Smart Home Light Control System!\n");

  // loop indefinitely until user exits program
  while (true) {
    printf("\n---Menu---\n");
    printf("1. Master Switch\n");
    printf("2. Living Room Light\n");
    printf("3. Kitchen Light\n");
    printf("4. Bedroom Light\n");
    printf("5. Exit\n");

    int choice = 0;
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);

    // handle user choice
    switch (choice) {
      case 1:
        printf("\nToggle master switch (0 = Off, 1 = On): ");
        scanf("%d", &masterSwitch);
        break;
      case 2:
        if (masterSwitch == 0) {
          printf("\nCannot control living room light as master switch is off.\n");
        } else {
          printf("\nToggle living room light (0 = Off, 1 = On): ");
          scanf("%d", &livingRoomLight);
        }
        break;
      case 3:
        if (masterSwitch == 0) {
          printf("\nCannot control kitchen light as master switch is off.\n");
        } else {
          printf("\nToggle kitchen light (0 = Off, 1 = On): ");
          scanf("%d", &kitchenLight);
        }
        break;
      case 4:
        if (masterSwitch == 0) {
          printf("\nCannot control bedroom light as master switch is off.\n");
        } else {
          printf("\nToggle bedroom light (0 = Off, 1 = On): ");
          scanf("%d", &bedroomLight);
        }
        break;
      case 5:
        printf("\nExiting program...\n");
        return 0;
      default:
        printf("\nInvalid choice. Please enter a valid choice (1-5).\n");
    }

    // display current light status
    printf("\n---Light Status---\n");
    printf("Master Switch: %d\n", masterSwitch);
    printf("Living Room Light: %d\n", livingRoomLight);
    printf("Kitchen Light: %d\n", kitchenLight);
    printf("Bedroom Light: %d\n", bedroomLight);
  }
}