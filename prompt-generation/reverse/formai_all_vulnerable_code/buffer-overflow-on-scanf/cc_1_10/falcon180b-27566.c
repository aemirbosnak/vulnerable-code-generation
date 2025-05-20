//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 1
#define MAX_TURN 100
#define MIN_TURN 1

struct vehicle {
    int speed;
    int turn;
    int x, y;
};

void drive(struct vehicle* v, int dx, int dy) {
    v->x += dx * v->speed / 100;
    v->y += dy * v->turn / 100;
}

void turn(struct vehicle* v, int angle) {
    v->turn = (v->turn + angle + 360) % 360;
}

void move(struct vehicle* v, int dir) {
    drive(v, dir == 0? 1 : 0, dir == 1? 1 : 0);
}

void stop(struct vehicle* v) {
    v->speed = 0;
    v->turn = 0;
}

int main() {
    srand(time(NULL));
    struct vehicle v = {.speed = rand() % MAX_SPEED + MIN_SPEED,.turn = rand() % MAX_TURN + MIN_TURN,.x = 0,.y = 0 };
    printf("Vehicle started at (%d, %d)\n", v.x, v.y);

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move(&v, 0);
                break;
            case 2:
                turn(&v, -90);
                break;
            case 3:
                turn(&v, 90);
                break;
            case 4:
                stop(&v);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Current position: (%d, %d)\n", v.x, v.y);
    } while (choice!= 4);

    return 0;
}