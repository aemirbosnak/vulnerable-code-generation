//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS 5
#define MAX_COMMANDS 10

typedef struct {
    char *name;
    int num_lights;
    int lights[MAX_LIGHTS];
} Room;

typedef struct {
    char *name;
    char *command;
} Command;

int num_rooms = 0;
int num_commands = 0;

Room rooms[MAX_ROOMS];
Command commands[MAX_COMMANDS];

void add_room(char *name, int num_lights) {
    num_rooms++;
    rooms[num_rooms - 1].name = strdup(name);
    rooms[num_rooms - 1].num_lights = num_lights;
}

void add_light(char *room_name, int light_num, int light_id) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
            rooms[i].lights[light_num] = light_id;
            break;
        }
    }
}

void add_command(char *name, char *command) {
    num_commands++;
    commands[num_commands - 1].name = strdup(name);
    commands[num_commands - 1].command = strdup(command);
}

int main() {
    add_room("Living Room", 3);
    add_light("Living Room", 0, 1);
    add_light("Living Room", 1, 2);
    add_light("Living Room", 2, 3);

    add_room("Bedroom", 2);
    add_light("Bedroom", 0, 4);
    add_light("Bedroom", 1, 5);

    add_command("Turn on Living Room", "turn on Living Room");
    add_command("Turn off Living Room", "turn off Living Room");
    add_command("Turn on Bedroom", "turn on Bedroom");
    add_command("Turn off Bedroom", "turn off Bedroom");

    int i;
    for (i = 0; i < num_commands; i++) {
        printf("%s - %s\n", commands[i].name, commands[i].command);
    }

    return 0;
}