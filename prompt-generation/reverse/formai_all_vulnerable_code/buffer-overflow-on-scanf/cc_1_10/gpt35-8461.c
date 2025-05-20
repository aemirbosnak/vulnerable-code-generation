//FormAI DATASET v1.0 Category: Smart home automation ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool lightsOn = false;
  bool doorsLocked = true;
  bool temperatureSet = false;
  int temperature = 73;
  
  printf("Welcome to Smart Home Automation\n");
  
  while (true) {
    printf("Please enter a command (lights, doors, temperature, exit): ");
    char command[10];
    scanf("%s", command);
    
    if (strcmp(command, "lights") == 0) {
      if (lightsOn) {
        printf("Turning off lights...\n");
        lightsOn = false;
      } else {
        printf("Turning on lights...\n");
        lightsOn = true;
      }
    } else if (strcmp(command, "doors") == 0) {
      if (doorsLocked) {
        printf("Unlocking doors...\n");
        doorsLocked = false;
      } else {
        printf("Locking doors...\n");
        doorsLocked = true;
      }
    } else if (strcmp(command, "temperature") == 0) {
      if (temperatureSet) {
        printf("The current temperature is %d degrees Fahrenheit\n", temperature);
      } else {
        printf("Please set a temperature: ");
        scanf("%d", &temperature);
        temperatureSet = true;
      }
    } else if (strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      break;
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }
  
  return 0;
}