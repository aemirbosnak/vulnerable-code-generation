//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int is_lit;
} Room;

void display_rooms(Room rooms[], int room_count) {
    printf("\nThe Grand Castle Room Status:\n");
    for (int i = 0; i < room_count; i++) {
        printf("%d. The room of %s is %s.\n", i + 1, rooms[i].name, rooms[i].is_lit ? "lit" : "dark");
    }
}

void toggle_light(Room* room) {
    room->is_lit = !room->is_lit;
}

int main() {
    Room castle_rooms[MAX_ROOMS] = {
        {"The Great Hall", 0},
        {"The Royal Chamber", 0},
        {"The Armory", 0},
        {"The Kitchen", 0},
        {"The Library", 0},
        {"The Courtyard", 0},
        {"The Ball Room", 0},
        {"The Dungeon", 0},
        {"The Chapel", 0},
        {"The Tower", 0}
    };

    int room_count = 10;
    int choice;
    char command[10];

    printf("Welcome to the Enchanted Castle Light Control!\n");
    printf("By thy command, we shall illuminate the abode.\n");

    do {
        display_rooms(castle_rooms, room_count);

        printf("\nWouldst thou like to 'light', 'darken', or 'exit' a room? (type 'exit' to leave): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        printf("Which room dost thou wish to command? (1-%d): ", room_count);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > room_count) {
            printf("Alas! That be not a valid room.\n");
            continue;
        }

        if (strcmp(command, "light") == 0) {
            toggle_light(&castle_rooms[choice - 1]);
            printf("Thou hast illuminated the %s! \n", castle_rooms[choice - 1].name);
        } else if (strcmp(command, "darken") == 0) {
            toggle_light(&castle_rooms[choice - 1]);
            printf("Thou hast darkened the %s! \n", castle_rooms[choice - 1].name);
        } else {
            printf("Alas! 'Light' or 'Darken' be the proper commands.\n");
        }

    } while (1);

    printf("Farewell, noble lord or lady! May the lights guide your way!\n");
    
    return 0;
}