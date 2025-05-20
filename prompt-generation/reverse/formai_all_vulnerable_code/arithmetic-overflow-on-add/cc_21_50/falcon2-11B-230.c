//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct point {
    int x, y;
};

struct pacman {
    int x, y;
    struct point *position;
    struct point *direction;
};

struct wall {
    struct point *position;
    int width, height;
};

struct pellet {
    struct point *position;
};

struct ghost {
    int x, y;
    struct point *position;
    int level;
};

int main() {
    // Code starts here
    int width, height;
    srand(time(NULL));
    printf("Enter the width of the screen: ");
    scanf("%d", &width);
    printf("Enter the height of the screen: ");
    scanf("%d", &height);

    // Create Pacman
    struct pacman pacman;
    pacman.x = (rand() % (width - 1)) + 1;
    pacman.y = (rand() % (height - 1)) + 1;
    pacman.position = malloc(sizeof(struct point));
    pacman.direction = malloc(sizeof(struct point));
    pacman.position->x = pacman.x;
    pacman.position->y = pacman.y;
    pacman.direction->x = 0;
    pacman.direction->y = 0;

    // Create Walls
    struct wall wall;
    wall.position = malloc(sizeof(struct point));
    wall.width = width / 5;
    wall.height = height / 5;
    wall.position->x = (rand() % (width - wall.width)) + 1;
    wall.position->y = (rand() % (height - wall.height)) + 1;
    wall.position->x = wall.position->x - (wall.position->x % wall.width);
    wall.position->y = wall.position->y - (wall.position->y % wall.height);

    // Create Pellet
    struct pellet pellet;
    pellet.position = malloc(sizeof(struct point));
    pellet.position->x = (rand() % (width - 1)) + 1;
    pellet.position->y = (rand() % (height - 1)) + 1;

    // Create Ghosts
    struct ghost ghost;
    ghost.x = (rand() % (width - 1)) + 1;
    ghost.y = (rand() % (height - 1)) + 1;
    ghost.position = malloc(sizeof(struct point));
    ghost.position->x = ghost.x;
    ghost.position->y = ghost.y;
    ghost.level = rand() % 4;

    // Game Loop
    while (1) {
        // Move Pacman
        if (pacman.direction->x!= 0 || pacman.direction->y!= 0) {
            pacman.x += pacman.direction->x;
            pacman.y += pacman.direction->y;
        }

        // Move Pellet
        if (pacman.x == pellet.position->x && pacman.y == pellet.position->y) {
            printf("You have eaten the pellet!\n");
        }
        pellet.position->x += 1;
        pellet.position->y += 1;

        // Move Ghosts
        if (pacman.x == ghost.position->x && pacman.y == ghost.position->y) {
            printf("You have been eaten by the ghost!\n");
            break;
        }
        ghost.x += (rand() % 2) - 1;
        ghost.y += (rand() % 2) - 1;

        // Check if Pacman collides with walls or pellets
        if (pacman.x < 0 || pacman.x >= width || pacman.y < 0 || pacman.y >= height) {
            printf("You have collided with the walls!\n");
            break;
        }
        if (pacman.x == wall.position->x && pacman.y == wall.position->y) {
            printf("You have collided with the wall!\n");
            break;
        }
        if (pacman.x == pellet.position->x && pacman.y == pellet.position->y) {
            printf("You have eaten the pellet!\n");
        }

        // Update Ghosts' levels
        if (ghost.x == pacman.x && ghost.y == pacman.y) {
            if (ghost.level == 0) {
                ghost.level = 1;
                pacman.direction->x = 0;
                pacman.direction->y = 0;
            } else if (ghost.level == 1) {
                ghost.level = 2;
                pacman.direction->x = 0;
                pacman.direction->y = 0;
            } else if (ghost.level == 2) {
                ghost.level = 3;
                pacman.direction->x = 0;
                pacman.direction->y = 0;
            } else if (ghost.level == 3) {
                ghost.level = 0;
                pacman.direction->x = 0;
                pacman.direction->y = 0;
            }
        }
    }

    // Free memory
    free(pacman.position);
    free(pacman.direction);
    free(wall.position);
    free(pellet.position);
    free(ghost.position);

    return 0;
}