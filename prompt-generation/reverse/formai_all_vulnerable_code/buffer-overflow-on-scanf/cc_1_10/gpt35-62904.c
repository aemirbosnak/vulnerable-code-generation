//FormAI DATASET v1.0 Category: Smart home light control ; Style: active
#include <stdio.h>

int main()
{
  int bedroomLightStatus = 0;
  int livingRoomLightStatus = 0;
  int kitchenLightStatus = 0;

  while (1)
  {
    char option;

    // Presenting options to the user
    printf("\nSelect an option:\n");
    printf("1 - Turn bedroom light on/off\n");
    printf("2 - Turn living room light on/off\n");
    printf("3 - Turn kitchen light on/off\n");
    printf("4 - Exit\n");

    // Reading user's choice
    scanf(" %c", &option);

    // Processing user's choice
    switch (option)
    {
      case '1':
        bedroomLightStatus = !bedroomLightStatus;
        printf("Bedroom light turned %s\n", (bedroomLightStatus ? "on" : "off"));
        break;

      case '2':
        livingRoomLightStatus = !livingRoomLightStatus;
        printf("Living room light turned %s\n", (livingRoomLightStatus ? "on" : "off"));
        break;

      case '3':
        kitchenLightStatus = !kitchenLightStatus;
        printf("Kitchen light turned %s\n", (kitchenLightStatus ? "on" : "off"));
        break;

      case '4':
        printf("Exiting...\n");
        return 0;

      default:
        printf("Invalid option. Please try again.\n");
    }
  }

  return 0;
}