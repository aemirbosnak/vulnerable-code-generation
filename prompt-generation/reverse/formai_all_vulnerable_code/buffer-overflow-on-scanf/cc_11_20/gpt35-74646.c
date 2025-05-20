//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
// Smart Home Automation Program
#include <stdio.h>

int main() {
  // Variables for different devices
  int light = 0;
  int fan = 0;
  int ac = 0;
  int door = 0;
  
  // User input for device control
  int input = 0;

  printf("Welcome to Smart Home Automation!\n");

  // Main program loop
  while(1) {
    printf("Select device to control: \n1. Light\n2. Fan\n3. AC\n4. Door\n5. Quit\n");
    scanf("%d", &input);

    if(input == 1) {
      // Light control
      printf("Light control: \n1. On\n2. Off\n");
      scanf("%d", &light);
      
      switch(light) {
        case 1:
          printf("Turning light on.\n");
          break;
        case 2:
          printf("Turning light off.\n");
          break;
        default:
          printf("Invalid input. Please try again.\n");
      }

    } else if(input == 2) {
      // Fan control
      printf("Fan control: \n1. On\n2. Off\n");
      scanf("%d", &fan);
      
      switch(fan) {
        case 1:
          printf("Turning fan on.\n");
          break;
        case 2:
          printf("Turning fan off.\n");
          break;
        default:
          printf("Invalid input. Please try again.\n");
      }

    } else if(input == 3) {
      // AC control
      printf("AC control: \n1. On\n2. Off\n");
      scanf("%d", &ac);
      
      switch(ac) {
        case 1:
          printf("Turning AC on.\n");
          break;
        case 2:
          printf("Turning AC off.\n");
          break;
        default:
          printf("Invalid input. Please try again.\n");
      }

    } else if(input == 4) {
      // Door control
      printf("Door control: \n1. Open\n2. Close\n");
      scanf("%d", &door);
      
      switch(door) {
        case 1:
          printf("Opening door.\n");
          break;
        case 2:
          printf("Closing door.\n");
          break;
        default:
          printf("Invalid input. Please try again.\n");
      }

    } else if(input == 5) {
      // Quit program
      printf("Exiting Smart Home Automation.\n");
      break;
    } else {
      // Invalid input
      printf("Invalid input. Please try again.\n");
    }
  }
  
  return 0;
}