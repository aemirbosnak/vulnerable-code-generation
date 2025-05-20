//FormAI DATASET v1.0 Category: Smart home automation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to turn on/off lights
void setLight(bool state) {
  if (state == true) {
    printf("Turning on lights...\n");
  } else {
    printf("Turning off lights...\n");
  }
}

// function to adjust temperature
void setTemp(int temp) {
  printf("Setting temperature to %d degrees...\n", temp);
}

// function to open/close doors
void setDoor(bool state) {
  if (state == true) {
    printf("Opening door...\n");
  } else {
    printf("Closing door...\n");
  }
}

// main function
int main() {
  // initialize variables
  bool lights = false;
  int temperature = 70;
  bool door = false;

  // welcome message
  printf("Welcome to Smart Home Automation!\n\n");

  // loop through automation commands until user quits
  char command = ' '; // initialize command to empty char
  while (command != 'q') {
    printf("Enter a command (l = lights, t = temperature, d = door, q = quit): ");
    scanf(" %c", &command);

    // process command
    switch(command) {
      case 'l':
        // turn on/off lights
        printf("Turn lights on or off? (1 = on, 0 = off): ");
        int lightState;
        scanf("%d", &lightState);
        lights = (lightState == 1) ? true : false;
        setLight(lights);
        break;
      case 't':
        // adjust temperature
        printf("Enter temperature: ");
        scanf("%d", &temperature);
        setTemp(temperature);
        break;
      case 'd':
        // open/close door
        printf("Open or close door? (1 = open, 0 = close): ");
        int doorState;
        scanf("%d", &doorState);
        door = (doorState == 1) ? true : false;
        setDoor(door);
        break;
      case 'q':
        // quit program
        printf("Goodbye!\n");
        break;
      default:
        // invalid command
        printf("Invalid command. Please enter l, t, d, or q.\n");
        break;
    }

    // print status update
    printf("\nCurrent status:\n");
    printf("Lights: %s\n", (lights == true) ? "on" : "off");
    printf("Temperature: %d degrees\n", temperature);
    printf("Door: %s\n\n", (door == true) ? "open" : "closed");
  }

  return 0;
}