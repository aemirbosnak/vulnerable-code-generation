//FormAI DATASET v1.0 Category: Smart home light control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

struct Light {
  int id;
  bool on;
};

int main() {
  struct Light lights[MAX_LIGHTS];
  int num_lights = 0;

  while (true) {
    // Print menu
    printf("Smart Home Light Control\n");
    printf("------------------------\n");
    printf("1. Add Light\n");
    printf("2. Toggle Light\n");
    printf("3. List Lights\n");
    printf("4. Exit\n");

    // Get user input
    int choice;
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    // Handle user input
    switch (choice) {
      case 1:
        // Add new light
        if (num_lights == MAX_LIGHTS) {
          printf("Error: Maximum number of lights reached.\n");
        } else {
          struct Light new_light;
          new_light.id = num_lights;
          new_light.on = false; // Default to off
          lights[num_lights] = new_light;
          num_lights++;
          printf("New light added!\n");
        }
        break;

      case 2:
        // Toggle light
        printf("Enter light ID to toggle (0-%d): ", num_lights-1);
        int id;
        scanf("%d", &id);
        if (id < 0 || id >= num_lights) {
          printf("Error: Invalid light ID.\n");
        } else {
          lights[id].on = !lights[id].on;
          printf("Light %d toggled %s.\n", id, lights[id].on ? "on" : "off");
        }
        break;

      case 3:
        // List lights
        printf("Current Lights:\n");
        printf("----------------\n");
        for (int i = 0; i < num_lights; i++) {
          printf("Light %d: %s\n", lights[i].id, lights[i].on ? "on" : "off");
        }
        break;

      case 4:
        // Exit
        printf("Exiting program.\n");
        exit(0);

      default:
        printf("Error: Invalid choice.\n");
    }

    // Wait for user to read output
    printf("Press enter to continue.\n");
    getchar();
    getchar();
    printf("\n");
  }

  return 0; // Just to be safe
}