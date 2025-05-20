//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define NUM_ROOMS 5
#define NUM_LIGHTS_PER_ROOM 4

typedef struct {
    char name[20];
    int brightness;
} light_t;

typedef struct {
    light_t lights[NUM_LIGHTS_PER_ROOM];
} room_t;

typedef struct {
    room_t rooms[NUM_ROOMS];
} house_t;

void init_house(house_t* house) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_LIGHTS_PER_ROOM; j++) {
            sprintf(house->rooms[i].lights[j].name, "Room %d Light %d", i + 1, j + 1);
            house->rooms[i].lights[j].brightness = 0;
        }
    }
}

void print_room_lights(room_t* room) {
    for (int i = 0; i < NUM_LIGHTS_PER_ROOM; i++) {
        printf("%s - %d\n", room->lights[i].name, room->lights[i].brightness);
    }
}

void set_light_brightness(light_t* light, int brightness) {
    light->brightness = brightness;
}

int main() {
    house_t house;
    init_house(&house);

    int choice;
    do {
        printf("1. Turn on/off lights\n2. Set light brightness\n3. Print room lights\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number (1-5): ");
                scanf("%d", &choice);
                printf("Enter light number (1-4): ");
                scanf("%d", &choice);
                house.rooms[choice - 1].lights[choice - 1].brightness =!house.rooms[choice - 1].lights[choice - 1].brightness;
                break;
            case 2:
                printf("Enter room number (1-5): ");
                scanf("%d", &choice);
                printf("Enter light number (1-4): ");
                scanf("%d", &choice);
                printf("Enter brightness (0-100): ");
                scanf("%d", &choice);
                set_light_brightness(&house.rooms[choice - 1].lights[choice - 1], choice);
                break;
            case 3:
                printf("Enter room number (1-5): ");
                scanf("%d", &choice);
                print_room_lights(&house.rooms[choice - 1]);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}