//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: retro
// Welcome to the 1980s Smart Home Automation Extravaganza!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Our trusty Z80 microprocessor (a.k.a. your computer)
int main() {
  // Initialize our smart home gadgets
  int lights = 0;           // 0 = off, 1 = on
  int thermostat = 72;      // Temperature in Fahrenheit
  int burglar_alarm = 0;   // 0 = off, 1 = on
  int motion_sensor = 0;   // 0 = no motion, 1 = motion detected
  int door_lock = 0;        // 0 = unlocked, 1 = locked

  // Main loop: the brains of our smart home
  while (1) {
    // Check the time and greet the user
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    printf("Good %s, %s! It's %d:%02d.\n",
           timeinfo->tm_wday == 0 ? "Sunday" : "day",
           timeinfo->tm_wday == 0 ? "Sun" : "Mon",
           timeinfo->tm_hour, timeinfo->tm_min);

    // Check for user input
    char command;
    printf("Enter command (L=lights, T=thermostat, B=burglar alarm, M=motion sensor, D=door lock, Q=quit): ");
    scanf(" %c", &command);

    // Process the command
    switch (command) {
      case 'L':
        printf("Lights: %s\n", lights ? "On" : "Off");
        printf("Turn lights %s? (Y/N): ", lights ? "off" : "on");
        scanf(" %c", &command);
        if (command == 'Y') {
          lights = !lights;
        }
        break;
      case 'T':
        printf("Thermostat: %d°F\n", thermostat);
        printf("Adjust thermostat (U/D): ");
        scanf(" %c", &command);
        if (command == 'U') {
          thermostat++;
        } else if (command == 'D') {
          thermostat--;
        }
        break;
      case 'B':
        printf("Burglar alarm: %s\n", burglar_alarm ? "On" : "Off");
        printf("Arm/disarm alarm (A/D): ");
        scanf(" %c", &command);
        if (command == 'A') {
          burglar_alarm = 1;
        } else if (command == 'D') {
          burglar_alarm = 0;
        }
        break;
      case 'M':
        printf("Motion sensor: %s\n", motion_sensor ? "Motion detected" : "No motion");
        break;
      case 'D':
        printf("Door lock: %s\n", door_lock ? "Locked" : "Unlocked");
        printf("Lock/unlock door (L/U): ");
        scanf(" %c", &command);
        if (command == 'L') {
          door_lock = 1;
        } else if (command == 'U') {
          door_lock = 0;
        }
        break;
      case 'Q':
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid command.\n");
    }

    // Update the smart home based on the user's input
    printf("Lights: %s\n", lights ? "On" : "Off");
    printf("Thermostat: %d°F\n", thermostat);
    printf("Burglar alarm: %s\n", burglar_alarm ? "On" : "Off");
    printf("Motion sensor: %s\n", motion_sensor ? "Motion detected" : "No motion");
    printf("Door lock: %s\n", door_lock ? "Locked" : "Unlocked");

    // Wait a bit before the next loop iteration
    sleep(1);
  }

  return 0;
}