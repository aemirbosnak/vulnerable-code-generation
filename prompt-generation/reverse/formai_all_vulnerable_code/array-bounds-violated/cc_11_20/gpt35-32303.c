//FormAI DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Smart Home Light Control Program!\n");

  srand(time(NULL)); // Seed the random number generator
  
  int numLights = 5;
  int lightState[numLights]; // 0 for off, 1 for on
  for (int i = 0; i < numLights; i++) {
    lightState[i] = 0; // Initialize all lights to off
  }
  
  while (1) { // Run indefinitely
    
    printf("Options:\n");
    printf("1. Toggle lights\n");
    printf("2. Set lights to random state\n");
    printf("3. Turn all lights off\n");
    printf("4. Turn all lights on\n");
    printf("5. Exit program\n");
    
    int choice;
    printf("> ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1: {
        printf("Which light(s) would you like to toggle? (1-%d, separate by spaces)\n", numLights);
        int toggles[numLights];
        int numToggles = 0;
        int input;
        while (1) {
          scanf("%d", &input);
          if (input == 0) break; // End input when user inputs 0
          toggles[numToggles++] = input;
        }
        for (int i = 0; i < numToggles; i++) {
          int index = toggles[i] - 1; // Subtract 1 from input to get array index
          lightState[index] = 1 - lightState[index]; // Toggle the light state
        }
        printf("Lights toggled!\n");
        break;
      }
      case 2: {
        printf("Setting lights to random state...\n");
        for (int i = 0; i < numLights; i++) {
          lightState[i] = rand() % 2; // Set light state to 0 or 1 randomly
        }
        printf("Lights set to random state!\n");
        break;
      }
      case 3: {
        printf("Turning all lights off...\n");
        for (int i = 0; i < numLights; i++) {
          lightState[i] = 0;
        }
        printf("All lights turned off!\n");
        break;
      }
      case 4: {
        printf("Turning all lights on...\n");
        for (int i = 0; i < numLights; i++) {
          lightState[i] = 1;
        }
        printf("All lights turned on!\n");
        break;
      }
      case 5: {
        printf("Exiting program...\n");
        exit(0);
      }
      default: {
        printf("Invalid option!\n");
        break;
      }
    }
    printf("Current light states:");
    for (int i = 0; i < numLights; i++) {
      printf(" %d", lightState[i]);
    }
    printf("\n");
  }
}