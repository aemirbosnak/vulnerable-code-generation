//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct room {
    char *description;
    int exits[4]; // up, down, left, right
};

void print_room(struct room *room) {
    printf("%s\n", room->description);
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create rooms
    struct room hallway = {"You are in a long hallway. There are doors to your left and right.", {1, 0, 0, 0}};
    struct room bedroom = {"This is a bedroom. There is a bed, a dresser, and a closet.", {0, 1, 0, 0}};
    struct room kitchen = {"You are in the kitchen. There is a stove, a refrigerator, and a table.", {0, 0, 1, 0}};
    struct room living_room = {"This is the living room. There is a couch, a TV, and a coffee table.", {0, 0, 0, 1}};

    // Set exit pointers for each room
    hallway.exits[0] = &bedroom;
    hallway.exits[1] = &kitchen;

    bedroom.exits[2] = &hallway;
    bedroom.exits[3] = &living_room;

    kitchen.exits[0] = &hallway;
    kitchen.exits[2] = &living_room;

    living_room.exits[1] = &hallway;
    living_room.exits[3] = &bedroom;

    // Start in the hallway
    struct room *current_room = &hallway;

    while(1) {
        print_room(current_room);
        printf("Which way do you want to go? ");
        char direction;
        scanf("%c", &direction);

        switch(direction) {
            case 'w':
                if(current_room->exits[0]!= NULL)
                    current_room = current_room->exits[0];
                else
                    printf("There is no exit to the west.\n");
                break;
            case 'd':
                if(current_room->exits[1]!= NULL)
                    current_room = current_room->exits[1];
                else
                    printf("There is no exit to the east.\n");
                break;
            case's':
                if(current_room->exits[2]!= NULL)
                    current_room = current_room->exits[2];
                else
                    printf("There is no exit to the north.\n");
                break;
            case 'a':
                if(current_room->exits[3]!= NULL)
                    current_room = current_room->exits[3];
                else
                    printf("There is no exit to the south.\n");
                break;
            default:
                printf("Invalid direction.\n");
        }
    }

    return 0;
}