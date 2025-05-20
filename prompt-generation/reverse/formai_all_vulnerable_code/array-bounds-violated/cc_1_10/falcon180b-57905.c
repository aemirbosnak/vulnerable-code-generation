//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROOMS 10
#define MAX_ROOM_SIZE 10

typedef struct {
    char name[MAX_ROOM_SIZE];
    bool visited;
} Room;

Room rooms[ROOMS];

void generate_room_name(char* name) {
    int len = rand() % MAX_ROOM_SIZE + 1;
    for (int i = 0; i < len; i++) {
        name[i] = 'A' + rand() % 26;
    }
    name[len] = '\0';
}

void generate_rooms() {
    srand(time(NULL));
    for (int i = 0; i < ROOMS; i++) {
        generate_room_name(rooms[i].name);
        rooms[i].visited = false;
    }
}

void print_room(Room room) {
    printf("You are in the %s.\n", room.name);
}

int main() {
    generate_rooms();
    int current_room = 0;

    while (true) {
        print_room(rooms[current_room]);

        char choice;
        printf("What do you want to do? ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'n':
                if (current_room < ROOMS - 1) {
                    current_room++;
                } else {
                    printf("There's no room to the north.\n");
                }
                break;
            case's':
                if (current_room > 0) {
                    current_room--;
                } else {
                    printf("There's no room to the south.\n");
                }
                break;
            case 'e':
                if ((current_room + 1) % ROOMS == 0) {
                    printf("You've escaped the haunted house!\n");
                    return 0;
                } else {
                    printf("You can't go east from this room.\n");
                }
                break;
            case 'w':
                if ((current_room - 1) % ROOMS == ROOMS - 1) {
                    printf("You can't go west from this room.\n");
                } else {
                    current_room--;
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}