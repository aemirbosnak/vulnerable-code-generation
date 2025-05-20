//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100

struct vehicle {
    int speed;
    int x_pos;
    int y_pos;
};

void move_up(struct vehicle *v) {
    v->y_pos += v->speed;
}

void move_down(struct vehicle *v) {
    v->y_pos -= v->speed;
}

void move_left(struct vehicle *v) {
    v->x_pos -= v->speed;
}

void move_right(struct vehicle *v) {
    v->x_pos += v->speed;
}

int main() {
    struct vehicle car1 = {50, 0, 0};
    struct vehicle car2 = {75, 10, 10};

    while (1) {
        printf("Car 1: (%d, %d)\n", car1.x_pos, car1.y_pos);
        printf("Car 2: (%d, %d)\n", car2.x_pos, car2.y_pos);

        int input;
        printf("Enter 1 to move car 1 up, 2 to move car 1 down, 3 to move car 1 left, 4 to move car 1 right. ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                move_up(&car1);
                break;
            case 2:
                move_down(&car1);
                break;
            case 3:
                move_left(&car1);
                break;
            case 4:
                move_right(&car1);
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }

        if (car1.speed >= MAX_SPEED) {
            printf("Car 1 has reached maximum speed.\n");
            break;
        }

        car1.speed += 10;
    }

    return 0;
}