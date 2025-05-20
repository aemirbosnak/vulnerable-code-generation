//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DRONE_NAME_LEN 32
#define DRONE_COMMAND_LEN 64
#define DRONE_MAX_COMMANDS 10

typedef struct {
    char drone_name[DRONE_NAME_LEN];
    char drone_commands[DRONE_MAX_COMMANDS][DRONE_COMMAND_LEN];
    int num_commands;
} Drone;

Drone* create_drone() {
    Drone* drone = (Drone*) malloc(sizeof(Drone));
    drone->num_commands = 0;
    return drone;
}

void destroy_drone(Drone* drone) {
    free(drone);
}

void add_command(Drone* drone, char* command) {
    if (drone->num_commands >= DRONE_MAX_COMMANDS) {
        printf("Error: Maximum number of commands reached.\n");
        return;
    }

    strncpy(drone->drone_commands[drone->num_commands], command, DRONE_COMMAND_LEN);
    drone->num_commands++;
}

void print_drone_info(Drone* drone) {
    printf("Drone Name: %s\n", drone->drone_name);
    printf("Number of Commands: %d\n", drone->num_commands);

    for (int i = 0; i < drone->num_commands; i++) {
        printf("Command %d: %s\n", i + 1, drone->drone_commands[i]);
    }
}

int main() {
    Drone* drone = create_drone();

    strncpy(drone->drone_name, "My Drone", DRONE_NAME_LEN);

    add_command(drone, "Take off");
    add_command(drone, "Fly forward");
    add_command(drone, "Turn left");

    print_drone_info(drone);

    destroy_drone(drone);

    return 0;
}