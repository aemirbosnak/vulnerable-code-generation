//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

struct DroneState {
  int altitude;
  int heading;
  int speed;
};

struct DroneCommand {
  int altitude;
  int heading;
  int speed;
};

void updateState(struct DroneState* state, struct DroneCommand* command) {
  state->altitude = command->altitude;
  state->heading = command->heading;
  state->speed = command->speed;
}

void updateCommand(struct DroneState* state, struct DroneCommand* command) {
  command->altitude = state->altitude;
  command->heading = state->heading;
  command->speed = state->speed;
}

void controlDrone(struct DroneState* state, struct DroneCommand* command) {
  printf("Drone altitude: %d\n", state->altitude);
  printf("Drone heading: %d\n", state->heading);
  printf("Drone speed: %d\n", state->speed);

  printf("Drone command: %d\n", command->altitude);
  printf("Drone command: %d\n", command->heading);
  printf("Drone command: %d\n", command->speed);

  printf("Executing command...\n");

  // execute command here
}

void initializeDrone(struct DroneState* state, struct DroneCommand* command) {
  state->altitude = 0;
  state->heading = 0;
  state->speed = 0;

  command->altitude = 0;
  command->heading = 0;
  command->speed = 0;
}

void displayDroneState(struct DroneState* state) {
  printf("Drone altitude: %d\n", state->altitude);
  printf("Drone heading: %d\n", state->heading);
  printf("Drone speed: %d\n", state->speed);
}

void displayDroneCommand(struct DroneCommand* command) {
  printf("Drone command: %d\n", command->altitude);
  printf("Drone command: %d\n", command->heading);
  printf("Drone command: %d\n", command->speed);
}

int main() {
  struct DroneState state;
  struct DroneCommand command;

  initializeDrone(&state, &command);

  while (1) {
    printf("Enter altitude command: ");
    scanf("%d", &command.altitude);

    printf("Enter heading command: ");
    scanf("%d", &command.heading);

    printf("Enter speed command: ");
    scanf("%d", &command.speed);

    updateState(&state, &command);
    updateCommand(&state, &command);

    controlDrone(&state, &command);

    displayDroneState(&state);
    displayDroneCommand(&command);
  }

  return 0;
}