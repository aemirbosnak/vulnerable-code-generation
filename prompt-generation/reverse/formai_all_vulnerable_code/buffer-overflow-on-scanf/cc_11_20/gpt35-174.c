//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>

int main() {
  int living_room_lights = 0, bedroom_lights = 0, kitchen_lights = 0;
  printf("Welcome to Smart Home Light Control!");

  while (1) {
    printf("\n\n Please select the room you want to control: \n 1. Living Room \n 2. Bedroom \n 3. Kitchen \n 4. Exit \n\n");
    int selected_room;
    scanf("%d", &selected_room);

    if (selected_room == 1) {
      while (1) {
        printf("\n Living Room Light Control: \n 1. Turn On Lights \n 2. Turn Off Lights \n 3. Exit \n\n");
        int living_room_input;
        scanf("%d", &living_room_input);
        if (living_room_input == 1) {
          living_room_lights = 1;
          printf("\n Living Room Lights are now turned on.");
        } else if (living_room_input == 2) {
          living_room_lights = 0;
          printf("\n Living Room Lights are now turned off.");
        } else if (living_room_input == 3) {
          break;
        }
      } 
    } else if (selected_room == 2) {
      while (1) {
        printf("\n Bedroom Light Control: \n 1. Turn On Lights \n 2. Turn Off Lights \n 3. Exit \n\n");
        int bedroom_input;
        scanf("%d", &bedroom_input);
        if (bedroom_input == 1) {
          bedroom_lights = 1;
          printf("\n Bedroom Lights are now turned on.");
        } else if (bedroom_input == 2) {
          bedroom_lights = 0;
          printf("\n Bedroom Lights are now turned off.");
        } else if (bedroom_input == 3) {
          break;
        }
      } 
    } else if (selected_room == 3) {
      while (1) {
        printf("\n Kitchen Light Control: \n 1. Turn On Lights \n 2. Turn Off Lights \n 3. Exit \n\n");
        int kitchen_input;
        scanf("%d", &kitchen_input);
        if (kitchen_input == 1) {
          kitchen_lights = 1;
          printf("\n Kitchen Lights are now turned on.");
        } else if (kitchen_input == 2) {
          kitchen_lights = 0;
          printf("\n Kitchen Lights are now turned off.");
        } else if (kitchen_input == 3) {
          break;
        }
      } 
    } else if (selected_room == 4) {
      printf("\n Thank you for using Smart Home Light Control!");
      break;
    } else {
      printf("Invalid input, please try again.");
    }
  }

  return 0;
}