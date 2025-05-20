//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RM_COUNT 5
#define ITEM_COUNT 3

typedef enum { GHOST, ITEM, EMPTY } Event;
typedef struct {
    char *name;
    Event event;
} Room;

Room house[RM_COUNT];

void init_rooms() {
    house[0] = (Room){"Entry Hall", EMPTY};    // Room 0
    house[1] = (Room){"Library", GHOST};        // Room 1
    house[2] = (Room){"Kitchen", ITEM};         // Room 2
    house[3] = (Room){"Basement", GHOST};       // Room 3
    house[4] = (Room){"Attic", ITEM};           // Room 4
}

void list_rooms() {
    printf("Rooms to explore:\n");
    for (int i = 0; i < RM_COUNT; i++) {
        printf("%d: %s\n", i, house[i].name);
    }
}

void encounter(Event ev) {
    if (ev == GHOST) {
        printf("A ghost appears! You feel a chill run down your spine...\n");
        exit(0); // Game over on ghost encounter
    } else if (ev == ITEM) {
        printf("You've found a mysterious item! What could it be?\n");
    } else {
        printf("Nothing special here, just cold shadows.\n");
    }
}

int main() {
    srand(time(NULL));
    init_rooms();
    int choice = -1;

    printf("Welcome to the Haunted House Simulator!\n");

    while (choice != 0) {
        list_rooms();
        printf("Choose a room (0 to exit): ");
        scanf("%d", &choice);

        if (choice >= 0 && choice < RM_COUNT) {
            encounter(house[choice].event);
            if (house[choice].event == ITEM) {
                house[choice].event = EMPTY; // Collect the item, room is now empty
            }
        } else if (choice != 0) {
            printf("Invalid choice, please try again.\n");
        }
    }

    printf("You have exited the haunted house. Good luck in the outside world!\n");
    return 0;
}