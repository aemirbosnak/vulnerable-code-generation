//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS_PER_ROOM 5

typedef struct {
    char name[50];
    int num_lights;
    int lights[MAX_LIGHTS_PER_ROOM];
} Room;

int main() {
    int num_rooms;
    scanf("%d", &num_rooms);

    Room rooms[MAX_ROOMS];
    for (int i = 0; i < num_rooms; i++) {
        scanf("%s", rooms[i].name);
        scanf("%d", &rooms[i].num_lights);

        for (int j = 0; j < rooms[i].num_lights; j++) {
            scanf("%d", &rooms[i].lights[j]);
        }
    }

    char command[100];
    while (1) {
        printf("Enter command (on/off/room/exit): ");
        scanf("%s", command);

        if (strcmp(command, "on") == 0) {
            int room_idx, light_idx;
            scanf("%d %d", &room_idx, &light_idx);

            Room *room = &rooms[room_idx];
            if (light_idx >= 0 && light_idx < room->num_lights) {
                printf("Turning on light %d in room %s\n", light_idx, room->name);
            } else {
                printf("Invalid light index\n");
            }
        } else if (strcmp(command, "off") == 0) {
            int room_idx, light_idx;
            scanf("%d %d", &room_idx, &light_idx);

            Room *room = &rooms[room_idx];
            if (light_idx >= 0 && light_idx < room->num_lights) {
                printf("Turning off light %d in room %s\n", light_idx, room->name);
            } else {
                printf("Invalid light index\n");
            }
        } else if (strcmp(command, "room") == 0) {
            int room_idx;
            scanf("%d", &room_idx);

            Room *room = &rooms[room_idx];
            printf("Room %s has %d lights:\n", room->name, room->num_lights);
            for (int j = 0; j < room->num_lights; j++) {
                printf("%d ", room->lights[j]);
            }
            printf("\n");
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}