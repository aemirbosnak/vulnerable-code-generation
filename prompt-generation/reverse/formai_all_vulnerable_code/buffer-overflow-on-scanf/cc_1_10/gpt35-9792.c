//FormAI DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  char livingRoomLight = 'off';
  char kitchenLight = 'off';
  char bedroomLight = 'off';
  char input;

  // Greet user
  printf("Welcome to the Smart Home Light Control Program!\n");

  // Display current light status
  printf("Currently, the living room light is %s.\n", livingRoomLight);
  printf("Currently, the kitchen light is %s.\n", kitchenLight);
  printf("Currently, the bedroom light is %s.\n", bedroomLight);

  // Main loop
  while (1) {
    // Prompt user for input
    printf("What would you like to do?\n");
    printf("1. Turn on living room light\n");
    printf("2. Turn off living room light\n");
    printf("3. Turn on kitchen light\n");
    printf("4. Turn off kitchen light\n");
    printf("5. Turn on bedroom light\n");
    printf("6. Turn off bedroom light\n");
    printf("7. Exit program\n");
    scanf("%c", &input);

    // Handle user input
    switch (input) {
      case '1':
        livingRoomLight = 'on';
        printf("Living room light turned on.\n");
        break;
      case '2':
        livingRoomLight = 'off';
        printf("Living room light turned off.\n");
        break;
      case '3':
        kitchenLight = 'on';
        printf("Kitchen light turned on.\n");
        break;
      case '4':
        kitchenLight = 'off';
        printf("Kitchen light turned off.\n");
        break;
      case '5':
        bedroomLight = 'on';
        printf("Bedroom light turned on.\n");
        break;
      case '6':
        bedroomLight = 'off';
        printf("Bedroom light turned off.\n");
        break;
      case '7':
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid input. Try again.\n");
    }

    // Display current light status after each change
    printf("Currently, the living room light is %s.\n", livingRoomLight);
    printf("Currently, the kitchen light is %s.\n", kitchenLight);
    printf("Currently, the bedroom light is %s.\n", bedroomLight);
  }

  return 0;
}