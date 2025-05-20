//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct vehicle {
    int x;
    int y;
    enum direction dir;
};

void move(struct vehicle *v, enum direction d) {
    switch (d) {
        case UP:
            v->y--;
            break;
        case DOWN:
            v->y++;
            break;
        case LEFT:
            v->x--;
            break;
        case RIGHT:
            v->x++;
            break;
    }
}

void print_vehicle(struct vehicle v) {
    printf("Vehicle at (%d, %d) facing %s\n", v.x, v.y,
        v.dir == UP? "up" :
        v.dir == DOWN? "down" :
        v.dir == LEFT? "left" : "right");
}

int main() {
    srand(time(0));

    struct vehicle v = {.x = rand() % 10,.y = rand() % 10,.dir = rand() % 4 };
    print_vehicle(v);

    int choice;
    do {
        printf("Enter your choice (0-3): ");
        scanf("%d", &choice);
        move(&v, (enum direction) choice);
        print_vehicle(v);
    } while (v.x >= 0 && v.x < 10 && v.y >= 0 && v.y < 10);

    return 0;
}