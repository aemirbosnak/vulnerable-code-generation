//FormAI DATASET v1.0 Category: Smart home automation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to turn lights on or off
void switchLight(bool switchLight, int lightNumber) {
  if (switchLight) {
    printf("Turning on light %d\n", lightNumber);
  } else {
    printf("Turning off light %d\n", lightNumber);
  }
}

// function to control the TV
void controlTV(bool controlTV, int volume, int channel) {
  if (controlTV) {
    printf("Turning on TV, volume: %d, channel: %d\n", volume, channel);
  } else {
    printf("Turning off TV\n");
  }
}

// function to set thermostat temperature
void setTemperature(int temperature) {
  printf("Setting thermostat temperature to %d degrees\n", temperature);
}

// function to lock or unlock the front door
void lockDoor(bool lockDoor) {
  if (lockDoor) {
    printf("Locking front door\n");
  } else {
    printf("Unlocking front door\n");
  }
}

int main() {
  
  // set the initial state of the house
  bool lightsOn = false;
  int currentTemperature = 72;
  bool TVOn = false;
  int TVVolume = 50;
  int TVChannel = 1;
  bool doorLocked = true;

  // welcome message
  printf("Welcome to your Smart Home!\n\n");
  printf("To turn on the lights, enter 1\n");
  printf("To turn off the lights, enter 2\n");
  printf("To turn on the TV, enter 3\n");
  printf("To turn off the TV, enter 4\n");
  printf("To set the temperature, enter 5\n");
  printf("To lock the front door, enter 6\n");
  printf("To unlock the front door, enter 7\n");

  // loop to accept user input
  int choice;
  while (true) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        switchLight(true, 1);
        lightsOn = true;
        break;
      case 2:
        switchLight(false, 1);
        lightsOn = false;
        break;
      case 3:
        controlTV(true, TVVolume, TVChannel);
        TVOn = true;
        break;
      case 4:
        controlTV(false, 0, 0);
        TVOn = false;
        break;
      case 5:
        printf("Enter the new temperature: ");
        scanf("%d", &currentTemperature);
        setTemperature(currentTemperature);
        break;
      case 6:
        lockDoor(true);
        doorLocked = true;
        break;
      case 7:
        lockDoor(false);
        doorLocked = false;
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }

    // display the current state of the house
    printf("\nCurrent state:\n");
    printf("Lights: %s\n", lightsOn ? "On" : "Off");
    printf("Temperature: %d degrees\n", currentTemperature);
    printf("TV: %s, volume: %d, channel: %d\n", TVOn ? "On" : "Off", TVVolume, TVChannel);
    printf("Front door: %s\n", doorLocked ? "Locked" : "Unlocked");
  }

  return 0;
}