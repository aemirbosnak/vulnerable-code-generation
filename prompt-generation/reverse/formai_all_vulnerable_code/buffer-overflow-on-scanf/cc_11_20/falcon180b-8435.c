//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS 5

typedef struct {
    char name[20];
    int num_lights;
    int light_status[MAX_LIGHTS];
} Room;

int main() {
    int num_rooms, num_lights, i, j;
    Room rooms[MAX_ROOMS];

    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);

    for (i = 0; i < num_rooms; i++) {
        printf("Enter the name of room %d: ", i + 1);
        scanf("%s", rooms[i].name);

        printf("Enter the number of lights in room %s: ", rooms[i].name);
        scanf("%d", &rooms[i].num_lights);

        for (j = 0; j < rooms[i].num_lights; j++) {
            printf("Enter the initial status of light %d in room %s (0 for off, 1 for on): ", j + 1, rooms[i].name);
            scanf("%d", &rooms[i].light_status[j]);
        }
    }

    printf("Smart Home Light Control\n");
    printf("=======================\n");

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Turn on/off a light\n");
        printf("2. Turn on/off all lights in a room\n");
        printf("3. Turn on/off all lights in the house\n");
        printf("4. Exit\n");

        scanf("%d", &num_lights);

        switch (num_lights) {
        case 1:
            printf("Enter the room name: ");
            scanf("%s", rooms[0].name);

            printf("Enter the light number: ");
            scanf("%d", &j);

            if (j >= 1 && j <= rooms[0].num_lights) {
                printf("Enter the new status of light %d in room %s (0 for off, 1 for on): ", j, rooms[0].name);
                scanf("%d", &rooms[0].light_status[j - 1]);
            } else {
                printf("Invalid light number.\n");
            }
            break;

        case 2:
            printf("Enter the room name: ");
            scanf("%s", rooms[0].name);

            printf("Enter the new status of all lights in room %s (0 for off, 1 for on): ", rooms[0].name);
            scanf("%d", &rooms[0].light_status[0]);

            for (j = 1; j < rooms[0].num_lights; j++) {
                rooms[0].light_status[j] = rooms[0].light_status[0];
            }
            break;

        case 3:
            for (i = 0; i < num_rooms; i++) {
                printf("Enter the new status of all lights in room %s (0 for off, 1 for on): ", rooms[i].name);
                scanf("%d", &rooms[i].light_status[0]);

                for (j = 1; j < rooms[i].num_lights; j++) {
                    rooms[i].light_status[j] = rooms[i].light_status[0];
                }
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}