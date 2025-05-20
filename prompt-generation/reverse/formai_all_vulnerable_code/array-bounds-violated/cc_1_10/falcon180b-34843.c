//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_ITEMS 10
#define NUM_GHOSTS 5

struct room {
    char name[50];
    int has_item;
    int has_ghost;
};

struct item {
    char name[50];
    int value;
};

struct ghost {
    char name[50];
    int strength;
};

void generate_rooms(struct room rooms[]) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].has_item = rand() % 2;
        rooms[i].has_ghost = rand() % 2;
    }
}

void generate_items(struct item items[]) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        items[i].value = rand() % 100;
    }
}

void generate_ghosts(struct ghost ghosts[]) {
    for (int i = 0; i < NUM_GHOSTS; i++) {
        ghosts[i].strength = rand() % 100;
    }
}

void print_room(struct room room) {
    if (room.has_item) {
        printf("There is an item here.\n");
    }
    if (room.has_ghost) {
        printf("There is a ghost here.\n");
    }
}

void print_item(struct item item) {
    printf("You found a %s worth %d points.\n", item.name, item.value);
}

void fight_ghost(struct ghost ghost) {
    int player_strength = rand() % 100;
    if (player_strength > ghost.strength) {
        printf("You defeated the ghost and gained 50 points.\n");
    } else {
        printf("The ghost defeated you and you lost 50 points.\n");
    }
}

int main() {
    srand(time(NULL));

    struct room rooms[NUM_ROOMS];
    generate_rooms(rooms);

    struct item items[NUM_ITEMS];
    generate_items(items);

    struct ghost ghosts[NUM_GHOSTS];
    generate_ghosts(ghosts);

    int player_score = 0;

    for (int i = 0; i < NUM_ROOMS; i++) {
        print_room(rooms[i]);
        if (rooms[i].has_item) {
            player_score += items[i].value;
            printf("You found a %s worth %d points.\n", items[i].name, items[i].value);
        }
        if (rooms[i].has_ghost) {
            fight_ghost(ghosts[i]);
        }
    }

    printf("Your final score is %d points.\n", player_score);

    return 0;
}