#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char name[20];
    int description;
} Room;

Room* rooms[MAX_ROOMS];
int room_count = 0;

void create_room(const char* name) {
    if (room_count >= MAX_ROOMS) {
        printf("Too many rooms!\n");
        return;
    }
    rooms[room_count] = malloc(sizeof(Room));
    strcpy(rooms[room_count]->name, name);
    rooms[room_count]->description = rand();
    room_count++;
}

void print_room(int index) {
    if (index < 0 || index >= room_count) {
        printf("Invalid room index!\n");
        return;
    }
    printf("Room: %s\nDescription: %d\n", rooms[index]->name, rooms[index]->description);
}

void delete_room(int index) {
    if (index < 0 || index >= room_count) {
        printf("Invalid room index!\n");
        return;
    }
    free(rooms[index]);
    rooms[index] = NULL; // Use after free vulnerability
}

int main() {
    srand(time(NULL));

    create_room("Entrance");
    create_room("Hall");
    create_room("Treasure Room");

    print_room(0);
    print_room(1);

    delete_room(1); // Delete room 1

    // Use after free vulnerability
    print_room(1); // This should crash due to dereferencing a freed pointer

    return 0;
}
