//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS 5

typedef struct {
    char name[30];
    int light_status[MAX_LIGHTS];
} Room;

void init_room(Room *room) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        room->light_status[i] = 0;
    }
}

void print_room(Room *room) {
    printf("Room: %s\n", room->name);
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d: %s\n", i + 1, room->light_status[i]? "On" : "Off");
    }
}

void toggle_light(Room *room, int light_num) {
    room->light_status[light_num - 1] =!room->light_status[light_num - 1];
}

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;

    printf("Enter number of rooms: ");
    scanf("%d", &num_rooms);

    for (int i = 0; i < num_rooms; i++) {
        printf("Enter room name: ");
        scanf("%s", rooms[i].name);
        init_room(&rooms[i]);
    }

    int choice;
    do {
        printf("\n1. Turn on/off light\n2. View room status\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter room name: ");
            char room_name[30];
            scanf("%s", room_name);

            for (int i = 0; i < num_rooms; i++) {
                if (strcmp(room_name, rooms[i].name) == 0) {
                    printf("Enter light number: ");
                    int light_num;
                    scanf("%d", &light_num);

                    toggle_light(&rooms[i], light_num);
                    printf("Light %d status changed.\n", light_num);
                    break;
                }
            }
        } else if (choice == 2) {
            printf("Enter room name: ");
            char room_name[30];
            scanf("%s", room_name);

            for (int i = 0; i < num_rooms; i++) {
                if (strcmp(room_name, rooms[i].name) == 0) {
                    print_room(&rooms[i]);
                    break;
                }
            }
        }

    } while (choice!= 3);

    return 0;
}