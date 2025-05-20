//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRONES 10
#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    int drone_index;
} drone_t;

command_t commands[MAX_COMMANDS];
drone_t drones[MAX_DRONES];
int num_drones = 0;
int num_commands = 0;

void register_command(char* name, void (*function)(void)) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands registered.\n");
        return;
    }

    strcpy(commands[num_commands].name, name);
    commands[num_commands].function = function;

    num_commands++;
}

void register_drone(char* name, int drone_index) {
    if (num_drones >= MAX_DRONES) {
        printf("Error: Too many drones registered.\n");
        return;
    }

    strcpy(drones[num_drones].name, name);
    drones[num_drones].drone_index = drone_index;

    num_drones++;
}

void execute_command(char* name) {
    int i;

    for (i = 0; i < num_commands; i++) {
        if (strcmp(name, commands[i].name) == 0) {
            commands[i].function();
            return;
        }
    }

    printf("Error: Command not found.\n");
}

void fly_to(int x, int y, int z) {
    printf("Flying drone to (%d, %d, %d)\n", x, y, z);
}

void take_off() {
    printf("Taking off!\n");
}

void land() {
    printf("Landing!\n");
}

int main() {
    register_command("fly_to", fly_to);
    register_command("take_off", take_off);
    register_command("land", land);

    register_drone("Drone 1", 0);
    register_drone("Drone 2", 1);

    while (1) {
        char input[MAX_COMMAND_LENGTH];
        printf("Enter command: ");
        scanf("%s", input);

        execute_command(input);
    }

    return 0;
}