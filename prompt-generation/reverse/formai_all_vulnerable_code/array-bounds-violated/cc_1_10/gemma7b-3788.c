//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

struct robot_state {
  int x;
  int y;
  char direction;
};

void send_robot_state(struct robot_state state) {
  char message[100];
  sprintf(message, "x: %d, y: %d, direction: %c", state.x, state.y, state.direction);
  send(PORT, message, strlen(message) + 1, 0);
}

void receive_robot_state(struct robot_state *state) {
  char message[100];
  int bytes_read = recv(PORT, message, 100, 0);
  if (bytes_read > 0) {
    state->x = atoi(message);
    state->y = atoi(message);
    state->direction = message[strlen(message) - 1];
  }
}

int main() {
  struct robot_state state;
  state.x = 0;
  state.y = 0;
  state.direction = 'N';

  send_robot_state(state);

  while (1) {
    receive_robot_state(&state);

    switch (state.direction) {
      case 'N':
        state.x++;
        send_robot_state(state);
        break;
      case 'S':
        state.x--;
        send_robot_state(state);
        break;
      case 'E':
        state.y++;
        send_robot_state(state);
        break;
      case 'W':
        state.y--;
        send_robot_state(state);
        break;
    }
  }

  return 0;
}