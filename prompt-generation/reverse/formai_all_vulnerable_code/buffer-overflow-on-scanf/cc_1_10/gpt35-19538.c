//FormAI DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>

int main() {
  
  // Initialize variables
  int bedroom_light = 0;
  int livingroom_light = 0;
  int kitchen_light = 0;
  int bedroom_fan = 0;
  int livingroom_tv = 0;

  // Prompt user for input
  printf("Welcome to Smart Home Automation!\n");
  printf("Please type '1' to turn on, and '0' to turn off\n\n");

  // Continuous loop
  while(1) {
    printf("Bedroom Light: %d\n", bedroom_light);
    printf("Living Room Light: %d\n", livingroom_light);
    printf("Kitchen Light: %d\n", kitchen_light);
    printf("Bedroom Fan: %d\n", bedroom_fan);
    printf("Living Room TV: %d\n\n", livingroom_tv);

    printf("Enter the device to control (1-5), or '0' to exit: ");
    int choice;
    scanf("%d", &choice);

    // Exit if user chooses '0'
    if(choice == 0) {
      break;
    }

    // Control the selected device
    switch(choice) {
      case 1:
        printf("Bedroom Light: ");
        scanf("%d", &bedroom_light);
        break;

      case 2:
        printf("Living Room Light: ");
        scanf("%d", &livingroom_light);
        break;

      case 3:
        printf("Kitchen Light: ");
        scanf("%d", &kitchen_light);
        break;

      case 4:
        printf("Bedroom Fan: ");
        scanf("%d", &bedroom_fan);
        break;

      case 5:
        printf("Living Room TV: ");
        scanf("%d", &livingroom_tv);
        break;

        default:
            printf("Invalid Input\n");
            break;
    }
  }

  printf("Thank you for using Smart Home Automation!\n");
  return 0;
}