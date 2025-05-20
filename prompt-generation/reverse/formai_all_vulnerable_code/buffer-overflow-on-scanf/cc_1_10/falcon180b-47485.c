//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define NUM_ITEMS 10

typedef struct {
    char *name;
    int is_haunted;
} Room;

typedef struct {
    char *name;
    int is_haunted;
} Item;

Room rooms[NUM_ROOMS] = {
    {"Living Room", 1},
    {"Kitchen", 0},
    {"Bathroom", 0},
    {"Bedroom", 1},
    {"Attic", 1}
};

Item items[NUM_ITEMS] = {
    {"Couch", 0},
    {"TV", 0},
    {"Fridge", 0},
    {"Sink", 0},
    {"Toilet", 0},
    {"Bed", 1},
    {"Dresser", 0},
    {"Closet", 1},
    {"Chair", 0},
    {"Box", 1}
};

void describe_room(Room *room) {
    if (room->is_haunted) {
        printf("This room is haunted!\n");
    } else {
        printf("This room is not haunted.\n");
    }
}

void describe_item(Item *item) {
    if (item->is_haunted) {
        printf("This item is haunted!\n");
    } else {
        printf("This item is not haunted.\n");
    }
}

int main() {
    srand(time(NULL));

    int player_x = 0;
    int player_y = 0;

    printf("Welcome to the Haunted House!\n");

    while (1) {
        system("clear");

        printf("You are in the %s.\n", rooms[player_x + player_y * NUM_ROOMS].name);

        for (int i = 0; i < NUM_ITEMS; i++) {
            if (items[i].is_haunted) {
                describe_item(&items[i]);
            }
        }

        int choice;
        printf("What would you like to do?\n");
        printf("1. Move to a different room.\n");
        printf("2. Interact with an item.\n");
        printf("3. Quit.\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Which room would you like to go to?\n");
            printf("0. Living Room\n");
            printf("1. Kitchen\n");
            printf("2. Bathroom\n");
            printf("3. Bedroom\n");
            printf("4. Attic\n");
            scanf("%d", &choice);

            player_x = choice % NUM_ROOMS;
            player_y = choice / NUM_ROOMS;

            break;

        case 2:
            printf("Which item would you like to interact with?\n");
            for (int i = 0; i < NUM_ITEMS; i++) {
                describe_item(&items[i]);
            }

            scanf("%d", &choice);

            if (items[choice].is_haunted) {
                printf("You feel a chill run down your spine as you touch the haunted %s.\n", items[choice].name);
            } else {
                printf("Nothing happens as you touch the non-haunted %s.\n", items[choice].name);
            }

            break;

        case 3:
            printf("Thanks for playing!\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}