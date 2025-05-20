//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: inquisitive
// This is a Smart Home Light Control program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS_PER_ROOM 10
#define MAX_COMMANDS_PER_LINE 10

typedef struct {
    char name[20];
    int lights[MAX_LIGHTS_PER_ROOM];
} Room;

Room rooms[MAX_ROOMS];

int num_rooms = 0;

void add_room(char *name)
{
    rooms[num_rooms].name[0] = '\0';
    strcat(rooms[num_rooms].name, name);
    num_rooms++;
}

void add_light(char *room_name, int light_num)
{
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (strcmp(room_name, rooms[i].name) == 0) {
            if (light_num >= 0 && light_num < MAX_LIGHTS_PER_ROOM) {
                rooms[i].lights[light_num] = 1;
            } else {
                printf("Invalid light number\n");
            }
            return;
        }
    }
    printf("Room not found\n");
}

void process_command(char *command)
{
    int i, j, num_lights = 0;
    char *token = strtok(command, " ");
    while (token!= NULL) {
        if (num_lights >= MAX_LIGHTS_PER_ROOM) {
            printf("Too many lights specified\n");
            return;
        }
        if (isdigit(token[0])) {
            int light_num = atoi(token);
            if (light_num < 0 || light_num >= MAX_LIGHTS_PER_ROOM) {
                printf("Invalid light number\n");
                return;
            }
            rooms[num_rooms - 1].lights[light_num] = 1;
            num_lights++;
        } else {
            printf("Invalid command\n");
            return;
        }
        token = strtok(NULL, " ");
    }
    if (num_lights == 0) {
        printf("No lights specified\n");
    }
}

int main()
{
    char command[100];
    while (1) {
        printf("Enter command (room name lights): ");
        fgets(command, sizeof(command), stdin);
        process_command(command);
    }
    return 0;
}