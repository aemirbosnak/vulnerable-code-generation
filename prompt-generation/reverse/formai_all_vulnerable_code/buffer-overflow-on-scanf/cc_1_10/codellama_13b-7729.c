//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate location;
    int type;
    int door;
    int treasure;
} Room;

void print_room(Room room) {
    printf("You are in room %d, %d\n", room.location.x, room.location.y);
    if (room.type == 0) {
        printf("It's a dark and spooky room.\n");
    } else if (room.type == 1) {
        printf("It's a bright and cozy room.\n");
    } else if (room.type == 2) {
        printf("It's a haunted room.\n");
    } else if (room.type == 3) {
        printf("It's a treasure room.\n");
    }
    if (room.door == 0) {
        printf("There is no door.\n");
    } else if (room.door == 1) {
        printf("There is a door to the north.\n");
    } else if (room.door == 2) {
        printf("There is a door to the south.\n");
    } else if (room.door == 3) {
        printf("There is a door to the east.\n");
    } else if (room.door == 4) {
        printf("There is a door to the west.\n");
    }
    if (room.treasure == 0) {
        printf("There is no treasure.\n");
    } else if (room.treasure == 1) {
        printf("There is a treasure chest in the corner.\n");
    }
}

void move_room(Room *room, int direction) {
    if (direction == 0) {
        room->location.x -= 1;
    } else if (direction == 1) {
        room->location.x += 1;
    } else if (direction == 2) {
        room->location.y -= 1;
    } else if (direction == 3) {
        room->location.y += 1;
    }
}

void open_door(Room *room) {
    room->door = 1;
}

void close_door(Room *room) {
    room->door = 0;
}

void get_treasure(Room *room) {
    room->treasure = 1;
}

int main() {
    srand(time(NULL));

    Room rooms[MAX_ROOMS];

    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].location.x = rand() % 10;
        rooms[i].location.y = rand() % 10;
        rooms[i].type = rand() % 4;
        rooms[i].door = rand() % 5;
        rooms[i].treasure = rand() % 2;
    }

    Room current_room = rooms[0];

    print_room(current_room);

    while (1) {
        printf("Enter a command: ");
        int command;
        scanf("%d", &command);

        if (command == 0) {
            break;
        } else if (command == 1) {
            move_room(&current_room, 0);
            print_room(current_room);
        } else if (command == 2) {
            move_room(&current_room, 1);
            print_room(current_room);
        } else if (command == 3) {
            move_room(&current_room, 2);
            print_room(current_room);
        } else if (command == 4) {
            move_room(&current_room, 3);
            print_room(current_room);
        } else if (command == 5) {
            open_door(&current_room);
            print_room(current_room);
        } else if (command == 6) {
            close_door(&current_room);
            print_room(current_room);
        } else if (command == 7) {
            get_treasure(&current_room);
            print_room(current_room);
        }
    }

    return 0;
}