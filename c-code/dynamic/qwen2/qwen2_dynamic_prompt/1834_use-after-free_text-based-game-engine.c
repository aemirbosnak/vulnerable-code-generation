#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char name[256];
    int description_length;
    char *description;
} Room;

Room rooms[MAX_ROOMS];

void create_room(int index, const char *name, const char *description) {
    if (index >= MAX_ROOMS) return;
    strcpy(rooms[index].name, name);
    rooms[index].description_length = strlen(description);
    rooms[index].description = malloc(rooms[index].description_length + 1);
    strcpy(rooms[index].description, description);
}

void print_room_description(int index) {
    if (index >= MAX_ROOMS || rooms[index].description == NULL) return;
    printf("%s\n", rooms[index].description);
}

int main() {
    create_room(0, "Entrance", "You stand at the entrance of a dark cave.");
    create_room(1, "Tunnel", "You find yourself in a narrow tunnel.");

    // Free the description of room 0
    free(rooms[0].description);

    // Use-after-free vulnerability: accessing freed memory
    print_room_description(0); // This will cause undefined behavior

    return 0;
}
