//FormAI DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>

typedef enum {
  OFF,
  ON
} state_t;

typedef struct {
  state_t state;
} light_t;

typedef struct {
  state_t state;
  int temp;
} thermostat_t;

int main() {
  light_t living_room_light = { .state = OFF };
  thermostat_t living_room_thermostat = { .state = OFF, .temp = 70 };

  while (1) {
    printf("Living Room Light is currently %s\n", living_room_light.state == ON ? "on" : "off");
    printf("Living Room Thermostat is currently %s and set to %d degrees\n", living_room_thermostat.state == ON ? "on" : "off", living_room_thermostat.temp);

    char action;
    printf("Enter a character to take an action: l for light, t for thermostat, and q to quit\n");
    scanf(" %c", &action);

    if (action == 'l') {
      if (living_room_light.state == ON) {
        living_room_light.state = OFF;
      } else {
        living_room_light.state = ON;
      }
    } else if (action == 't') {
      if (living_room_thermostat.state == ON) {
        living_room_thermostat.state = OFF;
      } else {
        living_room_thermostat.state = ON;
      }

      printf("Enter a desired temperature in degrees Fahrenheit to set the thermostat to: ");
      scanf("%d", &living_room_thermostat.temp);
    } else if (action == 'q') {
      break;
    }
  }

  return 0;
}