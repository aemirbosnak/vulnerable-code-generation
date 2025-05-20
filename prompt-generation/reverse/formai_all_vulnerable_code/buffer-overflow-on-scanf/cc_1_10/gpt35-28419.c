//FormAI DATASET v1.0 Category: Smart home light control ; Style: genious
#include <stdio.h>

#define LIGHTS_ON 1
#define LIGHTS_OFF 0

int main()
{
  int livingRoomLights = LIGHTS_OFF;
  int bedroomLights = LIGHTS_OFF;
  char userInput;

  printf("Welcome to the Smart Home Light Control System!\n");

  do
  {
    printf("\nEnter 'L' for living room or 'B' for bedroom: ");
    scanf(" %c", &userInput);

    switch(userInput)
    {
      case 'L':
        if(livingRoomLights == LIGHTS_OFF)
        {
          livingRoomLights = LIGHTS_ON;
          printf("\nLiving room lights turned ON.");
        }
        else
        {
          livingRoomLights = LIGHTS_OFF;
          printf("\nLiving room lights turned OFF.");
        }
        break;

      case 'B':
        if(bedroomLights == LIGHTS_OFF)
        {
          bedroomLights = LIGHTS_ON;
          printf("\nBedroom lights turned ON.");
        }
        else
        {
          bedroomLights = LIGHTS_OFF;
          printf("\nBedroom lights turned OFF.");
        }
        break;

      default:
        printf("\nInvalid input. Please try again.");
    }

    printf("\nLiving room lights: %s", livingRoomLights == LIGHTS_ON ? "ON" : "OFF");
    printf("\nBedroom lights: %s", bedroomLights == LIGHTS_ON ? "ON" : "OFF");

    printf("\n\nEnter 'Y' to continue or any other key to exit: ");
    scanf(" %c", &userInput);

  } while(userInput == 'Y' || userInput == 'y');

  printf("\nGoodbye!");

  return 0;
}