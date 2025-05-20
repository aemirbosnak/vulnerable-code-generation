//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <string.h>

// Define initial state of all devices
int bedroom_lights = 0;
int living_room_lights = 0;
int tv = 0;
int air_conditioner = 0;
int front_door_locked = 1;
int back_door_locked = 1;

// Function to turn on/off bedroom lights
void bedroomLights(int state) {
  bedroom_lights = state;
  if (state == 1) {
    printf("Bedroom lights turned ON\n");
  } else {
    printf("Bedroom lights turned OFF\n");
  }
}

// Function to turn on/off living room lights
void livingRoomLights(int state) {
  living_room_lights = state;
  if (state == 1) {
    printf("Living room lights turned ON\n");
  } else {
    printf("Living room lights turned OFF\n");
  }
}

// Function to turn on/off TV
void tvPower(int state) {
  tv = state;
  if (state == 1) {
    printf("TV turned ON\n");
  } else {
    printf("TV turned OFF\n");
  }
}

// Function to increase/decrease temperature
void temperature(int temp) {
  air_conditioner = temp;
  printf("Temperature set to %d degrees\n", temp);
}

// Function to lock/unlock front door
void frontDoor(int state) {
  front_door_locked = state;
  if (state == 1) {
    printf("Front door locked\n");
  } else {
    printf("Front door unlocked\n");
  }
}

// Function to lock/unlock back door
void backDoor(int state) {
  back_door_locked = state;
  if (state == 1) {
    printf("Back door locked\n");
  } else {
    printf("Back door unlocked\n");
  }
}

int main() {
  printf("Welcome to Smart Home Automation System\n");

  int option;

  do {
    printf("\nPlease choose an option:\n");
    printf("1. Bedroom lights\n");
    printf("2. Living room lights\n");
    printf("3. TV power\n");
    printf("4. Temperature control\n");
    printf("5. Front door lock\n");
    printf("6. Back door lock\n");
    printf("0. Exit\n");

    scanf("%d", &option);

    switch(option) {
      case 0:
        printf("Goodbye!\n");
        break;
      case 1:
        printf("Bedroom lights - 1 for ON, 0 for OFF: ");
        int bedroom_light_state;
        scanf("%d", &bedroom_light_state);
        bedroomLights(bedroom_light_state);
        break;
      case 2:
        printf("Living room lights - 1 for ON, 0 for OFF: ");
        int living_room_light_state;
        scanf("%d", &living_room_light_state);
        livingRoomLights(living_room_light_state);
        break;
      case 3:
        printf("TV power - 1 for ON, 0 for OFF: ");
        int tv_state;
        scanf("%d", &tv_state);
        tvPower(tv_state);
        break;
      case 4:
        printf("Temperature control - Enter temperature: ");
        int ac_temp;
        scanf("%d", &ac_temp);
        temperature(ac_temp);
        break;
      case 5:
        printf("Front door lock - 1 for LOCKED, 0 for UNLOCKED: ");
        int front_door_state;
        scanf("%d", &front_door_state);
        frontDoor(front_door_state);
        break;
      case 6:
        printf("Back door lock - 1 for LOCKED, 0 for UNLOCKED: ");
        int back_door_state;
        scanf("%d", &back_door_state);
        backDoor(back_door_state);
        break;
      default:
        printf("Invalid option\n");
    }
  } while(option != 0);

  return 0;
}