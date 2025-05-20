//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>

int main() {
  // Initialize variables
  int lights = 0, temperature = 68, humidity = 40, door_locked = 1, alarm_activated = 0;

  // Display initial state
  printf("Smart Home Automation System\n");
  printf("Lights: %d\n", lights);
  printf("Temperature: %d\n", temperature);
  printf("Humidity: %d\n", humidity);
  printf("Door Locked: %d\n", door_locked);
  printf("Alarm Activated: %d\n", alarm_activated);

  // Wait for user input
  char input;
  while (1) {
    printf("\nEnter command: ");
    scanf(" %c", &input);

    if (input == 'l') {
      // Toggle lights
      lights = !lights;
      printf("Lights: %d\n", lights);
    } else if (input == 't') {
      // Adjust temperature
      int new_temp;
      printf("Enter new temperature: ");
      scanf("%d", &new_temp);
      temperature = new_temp;
      printf("Temperature: %d\n", temperature);
    } else if (input == 'h') {
      // Adjust humidity
      int new_humidity;
      printf("Enter new humidity: ");
      scanf("%d", &new_humidity);
      humidity = new_humidity;
      printf("Humidity: %d\n", humidity);
    } else if (input == 'd') {
      // Toggle door lock
      door_locked = !door_locked;
      printf("Door Locked: %d\n", door_locked);
    } else if (input == 'a') {
      // Toggle alarm
      alarm_activated = !alarm_activated;
      printf("Alarm Activated: %d\n", alarm_activated);
    } else if (input == 'q') {
      // Quit program
      break;
    } else {
      // Invalid command
      printf("Invalid command\n");
    }
  }

  return 0;
}