//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>

// Define the Boolean variables
bool button_pressed[10] = {false}; // 10 buttons
bool elevator_call[10] = {false}; // 10 call switches
bool elevator_door_open = false;
bool elevator_moving = false;
bool floor_sensor[10] = {false}; // 10 floor sensors
bool desired_floor = 0;

// Define the Boolean functions
bool button_pressed_logic(int floor) {
  return button_pressed[floor];
}

bool elevator_call_logic(int floor) {
  return elevator_call[floor] && !floor_sensor[floor] && !elevator_door_open;
}

bool floor_sensor_logic(int floor) {
  return floor_sensor[floor] || elevator_moving && (floor == desired_floor);
}

bool elevator_logic(void) {
  int i;

  elevator_door_open = false;

  // Find the desired floor
  for (i = 0; i < 10; i++) {
    if (elevator_call_logic(i)) {
      desired_floor = i;
      break;
    }
  }

  // Move to the desired floor
  if (desired_floor != -1 && !elevator_moving) {
    elevator_moving = true;

    for (i = 0; i < 10; i++) {
      if (i == desired_floor) {
        floor_sensor[i] = true;
      } else {
        floor_sensor[i] = false;
      }
    }
  }

  // Open the door when arrived at the floor
  if (floor_sensor_logic(desired_floor)) {
    elevator_door_open = true;
  }

  return true;
}

int main(void) {
  int button_press, floor;

  while (1) {
    button_press = scanf("%d", &floor);

    if (button_press != EOF) {
      button_pressed[floor] = true;
    }

    elevator_logic();

    printf("Desired floor: %d\n", desired_floor);
    printf("Elevator door open: %d\n", elevator_door_open);
    printf("Elevator moving: %d\n", elevator_moving);
    printf("Floor sensors:\n");

    for (int i = 0; i < 10; i++) {
      printf("  Floor %d: %d\n", i, floor_sensor[i]);
    }

    printf("\n");
  }

  return 0;
}