//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    bool status;
} light;

void turn_on_light(light* light) {
    printf("Turning on %s...\n", light->name);
    light->status = true;
}

void turn_off_light(light* light) {
    printf("Turning off %s...\n", light->name);
    light->status = false;
}

void toggle_light(light* light) {
    if (light->status) {
        turn_off_light(light);
    } else {
        turn_on_light(light);
    }
}

int main() {
    light living_room = {"Living Room", false};
    light kitchen = {"Kitchen", false};
    light bedroom = {"Bedroom", false};

    printf("Welcome to the Smart Home!\n");
    printf("Living Room: %s\n", living_room.name);
    printf("Kitchen: %s\n", kitchen.name);
    printf("Bedroom: %s\n", bedroom.name);

    int choice;
    char room_name[50];

    while (true) {
        printf("\nWhat room do you want to control?\n");
        printf("1. Living Room\n2. Kitchen\n3. Bedroom\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(room_name, living_room.name);
                break;
            case 2:
                strcpy(room_name, kitchen.name);
                break;
            case 3:
                strcpy(room_name, bedroom.name);
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        printf("\nWhat do you want to do with the %s lights?\n", room_name);
        printf("1. Turn on\n2. Turn off\n3. Toggle\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                turn_on_light(&living_room);
                turn_on_light(&kitchen);
                turn_on_light(&bedroom);
                printf("\nAll lights turned on.\n");
                break;
            case 2:
                turn_off_light(&living_room);
                turn_off_light(&kitchen);
                turn_off_light(&bedroom);
                printf("\nAll lights turned off.\n");
                break;
            case 3:
                toggle_light(&living_room);
                toggle_light(&kitchen);
                toggle_light(&bedroom);
                printf("\nAll lights toggled.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}