//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector3;

typedef struct {
    char name[50];
    Vector3 position;
} Ship;

void move_ship(Ship* ship, Vector3 destination) {
    Vector3 current_position = ship->position;

    if (current_position.x == destination.x && current_position.y == destination.y && current_position.z == destination.z) {
        printf("Ship is already at destination.\n");
        return;
    }

    float dx = destination.x - current_position.x;
    float dy = destination.y - current_position.y;
    float dz = destination.z - current_position.z;

    float distance = sqrt(dx*dx + dy*dy + dz*dz);

    if (distance < 1.0) {
        ship->position.x = destination.x;
        ship->position.y = destination.y;
        ship->position.z = destination.z;

        printf("Ship moved to destination.\n");
    } else {
        printf("Ship cannot move to destination.\n");
    }
}

int main() {
    Ship ship1;
    Vector3 destination1;
    ship1.name[0] = 'A';
    ship1.name[1] = 'S';
    ship1.name[2] = 'T';
    ship1.name[3] = 0;
    destination1.x = 5;
    destination1.y = 0;
    destination1.z = 0;

    move_ship(&ship1, destination1);

    return 0;
}