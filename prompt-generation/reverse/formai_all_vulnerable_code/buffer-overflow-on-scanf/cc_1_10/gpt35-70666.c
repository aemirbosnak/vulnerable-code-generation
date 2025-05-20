//FormAI DATASET v1.0 Category: Smart home automation ; Style: Claude Shannon
/* Smart Home Automation Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define Devices */
#define LIGHTS 0
#define LOCKS 1
#define THERMOSTAT 2

/* Define Actions */
#define TURN_ON 0
#define TURN_OFF 1
#define LOCK 0
#define UNLOCK 1
#define SET_TEMPERATURE 0
#define GET_TEMPERATURE 1

/* Define Rooms */
#define BEDROOM 0
#define LIVING_ROOM 1
#define KITCHEN 2

/* Define States */
#define ON 1
#define OFF 0
#define LOCKED 1
#define UNLOCKED 0

/* Initialize Devices and States */
int lights = OFF;
int locks = UNLOCKED;
int thermostat = 68;

/* Function to Turn On/Off Lights */
void turn_lights(int action) {
  if (action == TURN_ON) {
    lights = ON;
    printf("Lights Turned On\n");
  } else {
    lights = OFF;
    printf("Lights Turned Off\n");
  }
}

/* Function to Lock/Unlock Doors */
void lock_doors(int action) {
  if (action == LOCK) {
    locks = LOCKED;
    printf("Doors Locked\n");
  } else {
    locks = UNLOCKED;
    printf("Doors Unlocked\n");
  }
}

/* Function to Set/Get Thermostat Temperature */
void set_temperature(int action, int temperature) {
  if (action == SET_TEMPERATURE) {
    thermostat = temperature;
    printf("Thermostat Set to %d degrees\n", temperature);
  } else {
    printf("Current Temperature is %d degrees\n", thermostat);
  }
}

/* Main Function */
int main() {
  int room;
  int device;
  int action;
  int temperature;

  /* Welcome Message */
  printf("Welcome to Smart Home Automation\n");

  /* User Input Loop */
  while (1) {
    /* Room Selection */
    printf("Select a Room (0 - Bedroom, 1 - Living Room, 2 - Kitchen): ");
    scanf("%d", &room);

    /* Device Selection */
    printf("Select a Device (0 - Lights, 1 - Locks, 2 - Thermostat): ");
    scanf("%d", &device);

    /* Action Selection */
    printf("Select an Action (Lights - 0: Turn On, 1: Turn Off; Locks - 0: Lock, 1: Unlock; Thermostat - 0: Set Temperature, 1: Get Temperature): ");
    scanf("%d", &action);

    /* Check Device and Perform Action */
    switch (device) {
      case LIGHTS:
        turn_lights(action);
        break;
      case LOCKS:
        lock_doors(action);
        break;
      case THERMOSTAT:
        if (action == SET_TEMPERATURE) {
          printf("Enter the Temperature (in Degrees Fahrenheit): ");
          scanf("%d", &temperature);
          set_temperature(action, temperature);
        } else {
          set_temperature(action, 0);
        }
        break;
      default:
        printf("Invalid Device Selection\n");
    }

    /* Continue or Exit Loop */
    char continue_choice[10];
    printf("Do you want to continue (yes/no)?: ");
    scanf("%s", continue_choice);
    if (strcmp(continue_choice, "no") == 0) {
      break;
    }
  }

  /* Goodbye Message */
  printf("Thank you for using Smart Home Automation\n");

  return 0;
}