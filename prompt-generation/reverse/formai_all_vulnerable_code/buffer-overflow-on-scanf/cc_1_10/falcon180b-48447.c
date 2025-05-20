//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN 10
#define MIN_TURN 1
#define MAX_ACCEL 10
#define MIN_ACCEL 1
#define MAX_BRAKE 10
#define MIN_BRAKE 1

struct vehicle {
    int x, y;
    int speed;
    int turn;
    int accel;
    int brake;
};

void init_vehicle(struct vehicle *v) {
    v->x = rand() % WIDTH;
    v->y = rand() % HEIGHT;
    v->speed = MIN_SPEED + rand() % (MAX_SPEED - MIN_SPEED + 1);
    v->turn = MIN_TURN + rand() % (MAX_TURN - MIN_TURN + 1);
    v->accel = MIN_ACCEL + rand() % (MAX_ACCEL - MIN_ACCEL + 1);
    v->brake = MIN_BRAKE + rand() % (MAX_BRAKE - MIN_BRAKE + 1);
}

void print_vehicle(struct vehicle *v) {
    printf("Vehicle at (%d,%d) with speed %d, turn %d, accel %d, brake %d\n",
           v->x, v->y, v->speed, v->turn, v->accel, v->brake);
}

void move_vehicle(struct vehicle *v) {
    v->x += v->speed;
    v->y += v->turn;
}

void turn_vehicle(struct vehicle *v, int turn) {
    v->turn += turn;
    if (v->turn < MIN_TURN) {
        v->turn = MIN_TURN;
    } else if (v->turn > MAX_TURN) {
        v->turn = MAX_TURN;
    }
}

void accelerate_vehicle(struct vehicle *v, int accel) {
    v->speed += accel;
    if (v->speed < MIN_SPEED) {
        v->speed = MIN_SPEED;
    } else if (v->speed > MAX_SPEED) {
        v->speed = MAX_SPEED;
    }
}

void brake_vehicle(struct vehicle *v, int brake) {
    v->speed -= brake;
    if (v->speed < MIN_SPEED) {
        v->speed = MIN_SPEED;
    }
}

int main() {
    srand(time(NULL));

    struct vehicle v;
    init_vehicle(&v);
    print_vehicle(&v);

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Accelerate\n");
        printf("5. Brake\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            move_vehicle(&v);
            break;
        case 2:
            turn_vehicle(&v, -1);
            break;
        case 3:
            turn_vehicle(&v, 1);
            break;
        case 4:
            accelerate_vehicle(&v, 1);
            break;
        case 5:
            brake_vehicle(&v, 1);
            break;
        default:
            printf("Invalid choice\n");
        }

        print_vehicle(&v);
    } while (1);

    return 0;
}