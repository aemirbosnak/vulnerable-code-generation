//FormAI DATASET v1.0 Category: Smart home light control ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

#define MAX_LIGHTS 5

void turnOnLight(bool lights[], int index) {
  // turn on the light at given index
  lights[index] = true;
  printf("Light %d turned on.\n", index);
}

void turnOffLight(bool lights[], int index) {
  // turn off the light at given index
  lights[index] = false;
  printf("Light %d turned off.\n", index);
}

void toggleLight(bool lights[], int index) {
  // toggle the light at given index
  lights[index] = !lights[index];
  if(lights[index]) {
    printf("Light %d turned on.\n", index);
  } else {
    printf("Light %d turned off.\n", index);
  }
}

void printMenu() {
  printf("======= Smart Home Light Control =======\n");
  printf("| 1. Turn on a light                 |\n");
  printf("| 2. Turn off a light                |\n");
  printf("| 3. Toggle a light                  |\n");
  printf("| 4. List all lights                 |\n");
  printf("| 5. Exit the program                |\n");
  printf("=======================================\n");
}

void printLights(bool lights[]) {
  printf("Current light status:\n");
  for(int i = 0; i < MAX_LIGHTS; i++) {
    if(lights[i]) {
      printf("Light %d is on.\n", i);
    } else {
      printf("Light %d is off.\n", i);
    }
  }
}

int main() {
  bool lights[MAX_LIGHTS] = {false};
  int choice = 0;
  int index = 0;

  while (true) {
    printMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the light index to turn on (0 to %d): ", MAX_LIGHTS - 1);
        scanf("%d", &index);
        turnOnLight(lights, index);
        break;

      case 2:
        printf("Enter the light index to turn off (0 to %d): ", MAX_LIGHTS - 1);
        scanf("%d", &index);
        turnOffLight(lights, index);
        break;

      case 3:
        printf("Enter the light index to toggle (0 to %d): ", MAX_LIGHTS - 1);
        scanf("%d", &index);
        toggleLight(lights, index);
        break;

      case 4:
        printLights(lights);
        break;

      case 5:
        printf("Exiting the program...\n");
        return 0;

      default:
        printf("Invalid choice. Try again.\n");
    }
  }
}