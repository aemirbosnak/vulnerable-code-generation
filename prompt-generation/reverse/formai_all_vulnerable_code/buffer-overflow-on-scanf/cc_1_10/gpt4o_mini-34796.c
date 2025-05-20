//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SPACE_SIZE 10
#define MAX_SHIPS 5

typedef struct {
    char name[20];
    int x;
    int y;
} Ship;

typedef struct {
    Ship ships[MAX_SHIPS];
    int ship_count;
} Space;

void initialize_space(Space *space) {
    space->ship_count = 0;
    for (int i = 0; i < MAX_SHIPS; i++) {
        space->ships[i].x = -1; // Initialize positions to -1 (indicating no ship)
        space->ships[i].y = -1;
    }
}

void add_ship(Space *space, const char *name) {
    if (space->ship_count < MAX_SHIPS) {
        strcpy(space->ships[space->ship_count].name, name);
        space->ships[space->ship_count].x = rand() % SPACE_SIZE;
        space->ships[space->ship_count].y = rand() % SPACE_SIZE;
        space->ship_count++;
    } else {
        printf("Whoa! Can't add more ships, maximum limit reached!\n");
    }
}

void display_ships(Space *space) {
    printf("Current Ships in Space:\n");
    for (int i = 0; i < space->ship_count; i++) {
        printf("Ship Name: %s, Position: (%d, %d)\n", space->ships[i].name, space->ships[i].x, space->ships[i].y);
    }
    if (space->ship_count == 0) {
        printf("No ships found in this vast universe.\n");
    }
}

void move_ship(Space *space, const char *name) {
    for (int i = 0; i < space->ship_count; i++) {
        if (strcmp(space->ships[i].name, name) == 0) {
            space->ships[i].x = rand() % SPACE_SIZE;
            space->ships[i].y = rand() % SPACE_SIZE;
            printf("Surprise! The ship %s has been moved to new coordinates (%d, %d)!\n", name, space->ships[i].x, space->ships[i].y);
            return;
        }
    }
    printf("Oh no! Ship %s not found!\n", name);
}

void encounter_event(Space *space, int x, int y) {
    for (int i = 0; i < space->ship_count; i++) {
        if (space->ships[i].x == x && space->ships[i].y == y) {
            printf("What a twist! You encountered the ship %s at (%d, %d)!\n", space->ships[i].name, x, y);
            return;
        }
    }
    printf("Phew! No ships in sight at coordinates (%d, %d).\n", x, y);
}

int main() {
    Space space;
    char ship_name[20];
    srand(time(NULL));

    initialize_space(&space);

    printf("Welcome to the Galactic Fleet Management System!\n");

    // Add initial ships
    for (int i = 0; i < 3; i++) {
        snprintf(ship_name, sizeof(ship_name), "Ship%d", i + 1);
        add_ship(&space, ship_name);
    }

    display_ships(&space);

    // Move a ship
    move_ship(&space, "Ship1");
    
    // Check for an encounter
    int x, y;
    printf("Enter coordinates to check for an encounter (x y): ");
    scanf("%d %d", &x, &y);
    encounter_event(&space, x, y);
    
    // Add another ship
    printf("Adding a new ship to the fleet.\n");
    add_ship(&space, "MysteryShip");
    display_ships(&space);

    // Move another ship
    move_ship(&space, "Ship2");

    // Final encounter check
    printf("Enter different coordinates to check for an encounter (x y): ");
    scanf("%d %d", &x, &y);
    encounter_event(&space, x, y);

    printf("Thank you for using the Galactic Fleet Management System!\n");
    return 0;
}