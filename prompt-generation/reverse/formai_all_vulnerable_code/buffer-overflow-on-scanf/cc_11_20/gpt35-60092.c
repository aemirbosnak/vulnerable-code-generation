//FormAI DATASET v1.0 Category: Smart home light control ; Style: surprised
#include <stdio.h>
#include <stdbool.h>

int main()
{
  printf("Welcome to the Smart Home Light Control Program!\n");
  printf("-----------------------------------------------\n");

  // Initialization of the lights' status
  bool livingRoomLight = false;
  bool bedroomLight = false;
  bool kitchenLight = false;

  printf("Here are your current light statuses:\n");
  printf("------------------------------------\n");
  printf("Living Room Light: %s\n", livingRoomLight ? "On" : "Off");
  printf("Bedroom Light: %s\n", bedroomLight ? "On" : "Off");
  printf("Kitchen Light: %s\n", kitchenLight ? "On" : "Off");

  printf("\n");

  bool isRunning = true;

  while (isRunning)
  {
    printf("What would you like to do?\n");
    printf("1. Turn on/off the living room light\n");
    printf("2. Turn on/off the bedroom light\n");
    printf("3. Turn on/off the kitchen light\n");
    printf("4. Show all light statuses\n");
    printf("5. Exit the program\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        livingRoomLight = !livingRoomLight;
        printf("Living room light is now %s.\n", livingRoomLight ? "on" : "off");
        break;
      case 2:
        bedroomLight = !bedroomLight;
        printf("Bedroom light is now %s.\n", bedroomLight ? "on" : "off");
        break;
      case 3:
        kitchenLight = !kitchenLight;
        printf("Kitchen light is now %s.\n", kitchenLight ? "on" : "off");
        break;
      case 4:
        printf("Here are your current light statuses:\n");
        printf("------------------------------------\n");
        printf("Living Room Light: %s\n", livingRoomLight ? "On" : "Off");
        printf("Bedroom Light: %s\n", bedroomLight ? "On" : "Off");
        printf("Kitchen Light: %s\n", kitchenLight ? "On" : "Off");
        break;
      case 5:
        printf("Exiting the program. Goodbye!\n");
        isRunning = false;
        break;
      default:
        printf("Invalid input. Please try again.\n");
    }

    printf("\n");
  }

  return 0;
}