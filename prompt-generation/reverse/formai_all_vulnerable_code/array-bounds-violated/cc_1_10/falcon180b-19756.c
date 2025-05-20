//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define DOORS 4

typedef struct {
    char name[20];
    int description[3];
    int connected_rooms[3];
} Room;

Room rooms[ROOMS] = {
    {"Entrance", {0, 1, 2}, {0, 1, 3}},
    {"Living Room", {1, 2, 3}, {1, 0, 4}},
    {"Kitchen", {2, 3, 0}, {2, 4, 1}},
    {"Bedroom", {3, 0, 1}, {3, 1, 4}},
    {"Bathroom", {4, 1, 2}, {4, 0, 3}}
};

void print_room(int room_number) {
    printf("You are in the %s.\n", rooms[room_number].name);
    printf("The room is ");
    switch (rooms[room_number].description[0]) {
        case 0:
            printf("dark and creepy.\n");
            break;
        case 1:
            printf("well-lit and cozy.\n");
            break;
        case 2:
            printf("spacious and empty.\n");
            break;
        case 3:
            printf("small and cramped.\n");
            break;
    }
    printf("There are doors leading to the ");
    for (int i = 0; i < DOORS; i++) {
        int door_room = rooms[room_number].connected_rooms[i];
        if (door_room!= -1) {
            printf("%s ", rooms[door_room].name);
        }
    }
    printf(".\n");
}

int main() {
    srand(time(NULL));
    int current_room = 0;

    while (1) {
        print_room(current_room);
        printf("Which door do you want to go through? (0-%d)\n", DOORS - 1);
        int door_choice;
        scanf("%d", &door_choice);

        if (door_choice < 0 || door_choice >= DOORS) {
            printf("Invalid choice, staying in the same room.\n");
        } else {
            int next_room = rooms[current_room].connected_rooms[door_choice];
            if (next_room == -1) {
                printf("That door is locked, staying in the same room.\n");
            } else {
                current_room = next_room;
            }
        }
    }

    return 0;
}