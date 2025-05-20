//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_OPTIONS 5
#define MAX_ROOMS 10

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

typedef struct {
    int room_id;
    char name[50];
    char description[100];
    int connections[MAX_OPTIONS];
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;
int current_room = 0;

void load_rooms() {
    // Load rooms from file
    FILE* file = fopen("rooms.txt", "r");
    if (file == NULL) {
        printf("Could not open file: rooms.txt\n");
        exit(1);
    }

    char line[255];
    while (fgets(line, sizeof(line), file)) {
        // Process each line as a room
        Room new_room;
        sscanf(line, "%d,%[^,],%[^,],%d,%d,%d,%d\n", &new_room.room_id, new_room.name, new_room.description, &new_room.connections[NORTH], &new_room.connections[EAST], &new_room.connections[SOUTH], &new_room.connections[WEST]);
        rooms[num_rooms++] = new_room;
    }
    fclose(file);
}

void print_room() {
    printf("\n%s\n", rooms[current_room].name);
    printf("%s\n\n", rooms[current_room].description);
    printf("Available options:\n");
    int num_options = 0;
    for (int i = 0; i < MAX_OPTIONS; i++) {
        if (rooms[current_room].connections[i] != -1) {
            printf("%d. Move %s\n", ++num_options, (i==0)?"North":(i==1)?"East":(i==2)?"South":"West");
        }
    }
    printf("\n");
}

int main() {
    load_rooms();

    printf("Welcome to the Adventure Game!\n\n");

    while (1) {
        print_room();
        printf("> ");

        // Read player input
        char input[50];
        fgets(input, sizeof(input), stdin);

        // Process player command
        if (strcmp(input, "quit\n") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else if (strncmp(input, "move", strlen("move")) == 0) {
            char* direction = input + strlen("move");
            if (strncmp(direction, "north", strlen("north")) == 0) {
                if (rooms[current_room].connections[NORTH] != -1) {
                    current_room = rooms[current_room].connections[NORTH];
                } else {
                    printf("You cannot go that way.\n");
                }
            } else if (strncmp(direction, "east", strlen("east")) == 0) {
                if (rooms[current_room].connections[EAST] != -1) {
                    current_room = rooms[current_room].connections[EAST];
                } else {
                    printf("You cannot go that way.\n");
                }
            } else if (strncmp(direction, "south", strlen("south")) == 0) {
                if (rooms[current_room].connections[SOUTH] != -1) {
                    current_room = rooms[current_room].connections[SOUTH];
                } else {
                    printf("You cannot go that way.\n");
                }
            } else if (strncmp(direction, "west", strlen("west")) == 0) {
                if (rooms[current_room].connections[WEST] != -1) {
                    current_room = rooms[current_room].connections[WEST];
                } else {
                    printf("You cannot go that way.\n");
                }
            } else {
                printf("Invalid direction.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}