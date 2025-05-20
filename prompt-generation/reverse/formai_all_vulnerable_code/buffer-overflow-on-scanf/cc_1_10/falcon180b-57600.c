//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_OBJECTS 5

typedef struct {
    char *name;
    char *description;
} Room;

typedef struct {
    char *name;
    char *description;
    int value;
} Object;

Room rooms[NUM_ROOMS];
Object objects[NUM_OBJECTS];

void init_rooms() {
    int i;
    for (i = 0; i < NUM_ROOMS; i++) {
        rooms[i].name = malloc(20 * sizeof(char));
        rooms[i].description = malloc(100 * sizeof(char));
        sprintf(rooms[i].name, "Room %d", i + 1);
        sprintf(rooms[i].description, "You are in room %d.", i + 1);
    }
}

void init_objects() {
    int i;
    for (i = 0; i < NUM_OBJECTS; i++) {
        objects[i].name = malloc(20 * sizeof(char));
        objects[i].description = malloc(100 * sizeof(char));
        sprintf(objects[i].name, "Object %d", i + 1);
        sprintf(objects[i].description, "This is object %d.", i + 1);
    }
}

void describe_room(int room_num) {
    printf("%s\n", rooms[room_num].description);
}

int main() {
    int choice;
    int room_num;
    srand(time(NULL));

    init_rooms();
    init_objects();

    while (1) {
        printf("What do you want to do?\n");
        printf("1. Move to another room\n");
        printf("2. Search for objects\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Which room do you want to go to?\n");
            scanf("%d", &room_num);
            if (room_num >= 1 && room_num <= NUM_ROOMS) {
                describe_room(room_num - 1);
            } else {
                printf("Invalid room number.\n");
            }
        } else if (choice == 2) {
            int object_num = rand() % NUM_OBJECTS;
            printf("You found object %d!\n", object_num + 1);
            printf("%s\n", objects[object_num].description);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}