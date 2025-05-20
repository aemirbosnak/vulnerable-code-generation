//Code Llama-13B DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    int x;
    int y;
    int z;
} Position;

typedef struct {
    int roll;
    int pitch;
    int yaw;
} Rotation;

typedef struct {
    Position position;
    Rotation rotation;
} DroneState;

void print_drone_state(DroneState state) {
    printf("Drone position: (%d, %d, %d)\n", state.position.x, state.position.y, state.position.z);
    printf("Drone rotation: (%d, %d, %d)\n", state.rotation.roll, state.rotation.pitch, state.rotation.yaw);
}

void move_drone(DroneState* state, int x, int y, int z) {
    state->position.x += x;
    state->position.y += y;
    state->position.z += z;
}

void rotate_drone(DroneState* state, int roll, int pitch, int yaw) {
    state->rotation.roll += roll;
    state->rotation.pitch += pitch;
    state->rotation.yaw += yaw;
}

int main() {
    DroneState state = {
        .position = { 0, 0, 0 },
        .rotation = { 0, 0, 0 }
    };

    char command[MAX_COMMAND_LENGTH];
    while (true) {
        scanf("%s", command);
        if (strcmp(command, "move") == 0) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            move_drone(&state, x, y, z);
        } else if (strcmp(command, "rotate") == 0) {
            int roll, pitch, yaw;
            scanf("%d %d %d", &roll, &pitch, &yaw);
            rotate_drone(&state, roll, pitch, yaw);
        } else if (strcmp(command, "print") == 0) {
            print_drone_state(state);
        } else if (strcmp(command, "quit") == 0) {
            break;
        }
    }

    return 0;
}