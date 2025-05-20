//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct {
    char *name;
    char *description;
    int items[MAX_ITEMS];
} Room;

typedef struct {
    char *name;
    char *description;
} Item;

int main() {
    srand(time(NULL));

    Room rooms[MAX_ROOMS];
    Item items[MAX_ITEMS];

    int num_rooms = 0;
    int num_items = 0;

    Room *current_room = &rooms[0];
    current_room->name = "Starting Room";
    current_room->description = "You are in the starting room. There is a door to the east.";

    Room *east_room = &rooms[1];
    east_room->name = "East Room";
    east_room->description = "You are in the east room. There is a door to the west.";

    current_room->items[0] = 1; // Key
    east_room->items[0] = 2; // Locked Chest

    num_rooms = 2;
    num_items = 2;

    int player_x = 0;
    int player_y = 0;

    while (1) {
        system("clear");

        printf("Room: %s\n", current_room->name);
        printf("Description: %s\n", current_room->description);

        if (current_room->items[0] == 1) {
            printf("You see a key on the ground.\n");
        }

        if (current_room->items[1] == 2) {
            printf("You see a locked chest in the corner.\n");
        }

        printf("What do you want to do? ");
        char action[100];
        scanf("%s", action);

        if (strcmp(action, "go east") == 0) {
            if (player_x < num_rooms - 1) {
                player_x++;
                current_room = &rooms[player_x];
            }
        } else if (strcmp(action, "go west") == 0) {
            if (player_x > 0) {
                player_x--;
                current_room = &rooms[player_x];
            }
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}