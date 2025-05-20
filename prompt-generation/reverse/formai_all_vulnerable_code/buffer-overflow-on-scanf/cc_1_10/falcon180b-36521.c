//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS 5

typedef struct {
    char name[20];
    int light_status[MAX_LIGHTS];
} Room;

void init_room(Room *room) {
    strcpy(room->name, "");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        room->light_status[i] = 0;
    }
}

void print_room(Room room) {
    printf("Room name: %s\n", room.name);
    printf("Light status:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%d. %s: %s\n", i+1, (i == 0)? "Main" : (i == 1)? "Reading" : (i == 2)? "Kitchen" : (i == 3)? "Bathroom" : "Bedroom", (room.light_status[i] == 1)? "On" : "Off");
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms, choice, light_num;

    printf("Welcome to Smart Home Light Control!\n");
    printf("How many rooms do you have? (1-%d): ", MAX_ROOMS);
    scanf("%d", &num_rooms);

    for (int i = 0; i < num_rooms; i++) {
        init_room(&rooms[i]);
        printf("Enter room name: ");
        scanf("%s", rooms[i].name);
    }

    while (1) {
        printf("\nChoose a room:\n");
        for (int i = 0; i < num_rooms; i++) {
            printf("%d. %s\n", i+1, rooms[i].name);
        }
        scanf("%d", &choice);

        printf("Choose a light:\n");
        for (int i = 0; i < MAX_LIGHTS; i++) {
            printf("%d. %s\n", i+1, (i == 0)? "Main" : (i == 1)? "Reading" : (i == 2)? "Kitchen" : (i == 3)? "Bathroom" : "Bedroom");
        }
        scanf("%d", &light_num);

        printf("Do you want to turn the light on or off? (1/0): ");
        int light_status;
        scanf("%d", &light_status);

        rooms[choice-1].light_status[light_num-1] = light_status;
        print_room(rooms[choice-1]);
    }

    return 0;
}