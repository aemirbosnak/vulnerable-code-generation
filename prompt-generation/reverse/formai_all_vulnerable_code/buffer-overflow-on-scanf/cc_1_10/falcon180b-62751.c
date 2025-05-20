//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_DRONES 5
#define NUM_COMMANDS 4

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
} Direction;

typedef struct {
    int x;
    int y;
    Direction direction;
} Drone;

Drone drones[NUM_DRONES];

void init() {
    for (int i = 0; i < NUM_DRONES; i++) {
        drones[i].x = rand() % 100;
        drones[i].y = rand() % 100;
        drones[i].direction = NONE;
    }
}

void move(Drone* drone, Direction dir) {
    int newX = drone->x;
    int newY = drone->y;

    switch (dir) {
        case UP:
            newY--;
            break;
        case DOWN:
            newY++;
            break;
        case LEFT:
            newX--;
            break;
        case RIGHT:
            newX++;
            break;
        default:
            break;
    }

    if (newX >= 0 && newX < 100 && newY >= 0 && newY < 100) {
        drone->x = newX;
        drone->y = newY;
    }
}

void printDrones() {
    for (int i = 0; i < NUM_DRONES; i++) {
        printf("Drone %d: (%d, %d)\n", i + 1, drones[i].x, drones[i].y);
    }
}

int main() {
    srand(time(0));
    init();

    int choice;
    while (true) {
        system("clear");
        printDrones();

        printf("\nEnter your choice:\n");
        printf("1. Move a drone\n");
        printf("2. Print drones\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the drone number: ");
                scanf("%d", &choice);
                printf("Enter the direction: ");
                scanf("%d", &choice);
                move(&drones[choice - 1], (Direction)choice);
                break;
            case 2:
                printDrones();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}