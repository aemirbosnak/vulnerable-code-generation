//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>

/* Function to turn on/off light bulb */
void light_bulb(int state) {
  if(state)
    printf("Light bulb turned ON\n");
  else
    printf("Light bulb turned OFF\n");
}

/* Function to adjust thermostat */
void thermostat(int temperature) {
  printf("Thermostat set to: %d degrees\n", temperature);
}

/* Function to lock/unlock door */
void door_lock(int state) {
  if(state)
    printf("Door locked\n");
  else
    printf("Door unlocked\n");
}

/* Main program */
int main() {
  int light = 0, temperature = 25, door = 1, option;

  printf("***Welcome to Smart Home Automation System***\n");

  while(1) {
    printf("\nPlease select an option:\n");
    printf("1. Turn on/off light bulb\n");
    printf("2. Adjust thermostat\n");
    printf("3. Lock/unlock door\n");
    printf("4. Exit program\n");

    scanf("%d", &option);

    switch(option) {
      case 1:
        light = !light;
        light_bulb(light);
        break;
      case 2:
        printf("Enter desired temperature: ");
        scanf("%d", &temperature);
        thermostat(temperature);
        break;
      case 3:
        door = !door;
        door_lock(door);
        break;
      case 4:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid option, please try again\n");
    }
  }

  return 0;
}