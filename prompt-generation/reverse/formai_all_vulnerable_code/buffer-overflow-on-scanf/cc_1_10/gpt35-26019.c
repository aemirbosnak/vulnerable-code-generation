//FormAI DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lights_on = false;
bool ac_on = false;
bool door_unlocked = false;

void toggle_lights() {
  lights_on = !lights_on;
  if (lights_on) {
    printf("Turning lights on...\n");
  } else {
    printf("Turning lights off...\n");
  }
}

void toggle_ac() {
  ac_on = !ac_on;
  if (ac_on) {
    printf("Turning AC on...\n");
  } else {
    printf("Turning AC off...\n");
  }
}

void toggle_door() {
  door_unlocked = !door_unlocked;
  if (door_unlocked) {
    printf("Unlocking door...\n");
  } else {
    printf("Locking door...\n");
  }
}

int main() {
  int choice;
  printf("Welcome to Smart Home Automation!\n\n");

  while (true) {
    printf("Select an option:\n");
    printf("1. Toggle lights\n");
    printf("2. Toggle AC\n");
    printf("3. Toggle door\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        toggle_lights();
        break;
      case 2:
        toggle_ac();
        break;
      case 3:
        toggle_door();
        break;
      case 4:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}