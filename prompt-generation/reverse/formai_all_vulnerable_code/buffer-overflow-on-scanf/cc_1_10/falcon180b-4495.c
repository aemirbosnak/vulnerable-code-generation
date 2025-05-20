//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRONES 10

typedef struct {
    char name[20];
    int x, y;
    int speed;
} Drone;

Drone drones[MAX_DRONES];

void init() {
    int i;
    for (i = 0; i < MAX_DRONES; i++) {
        drones[i].x = 0;
        drones[i].y = 0;
        drones[i].speed = 0;
    }
}

void move(int id, int dx, int dy) {
    if (id >= 0 && id < MAX_DRONES) {
        drones[id].x += dx;
        drones[id].y += dy;
    }
}

void print_drones() {
    int i;
    for (i = 0; i < MAX_DRONES; i++) {
        printf("%s: (%d, %d)\n", drones[i].name, drones[i].x, drones[i].y);
    }
}

int main() {
    init();

    int choice;
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add drone\n");
        printf("2. Move drone\n");
        printf("3. Print drones\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter drone name: ");
            scanf("%s", drones[0].name);
            break;
        case 2:
            printf("Enter drone ID: ");
            scanf("%d", &choice);
            printf("Enter dx: ");
            scanf("%d", &choice);
            printf("Enter dy: ");
            scanf("%d", &choice);
            move(choice, choice, choice);
            break;
        case 3:
            print_drones();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}