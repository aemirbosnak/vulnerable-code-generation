#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct {
    char name[256];
    int description;
} Room;

Room rooms[MAX_ROOMS];

void load_rooms() {
    FILE *file = fopen("rooms.dat", "rb");
    if (!file) {
        printf("Failed to open rooms file.\n");
        return;
    }

    fread(rooms, sizeof(Room), MAX_ROOMS, file);
    fclose(file);
}

void print_room(int index) {
    if (index >= 0 && index < MAX_ROOMS) {
        printf("Room: %s\nDescription: %d\n", rooms[index].name, rooms[index].description);
    } else {
        printf("Invalid room index.\n");
    }
}

int main() {
    load_rooms();

    int choice;
    while (1) {
        printf("Choose a room (0-%d): ", MAX_ROOMS - 1);
        scanf("%d", &choice);

        if (choice == -1) {
            break;
        }

        print_room(choice);
    }

    return 0;
}
