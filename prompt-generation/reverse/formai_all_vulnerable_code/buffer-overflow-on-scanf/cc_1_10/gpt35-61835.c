//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    int facing; // 0 - North, 1 - East, 2 - South, 3 - West
    position pos;
} vehicle;

void move_forward(vehicle* v) {
    switch (v->facing) {
        case 0:
            v->pos.y += 1;
            break;
        case 1:
            v->pos.x += 1;
            break;
        case 2:
            v->pos.y -= 1;
            break;
        case 3:
            v->pos.x -= 1;
            break;
    }
}

void move_backward(vehicle* v) {
    switch (v->facing) {
        case 0:
            v->pos.y -= 1;
            break;
        case 1:
            v->pos.x -= 1;
            break;
        case 2:
            v->pos.y += 1;
            break;
        case 3:
            v->pos.x += 1;
            break;
    }
}

void turn_left(vehicle* v) {
    v->facing = (v->facing + 3) % 4;
}

void turn_right(vehicle* v) {
    v->facing = (v->facing + 1) % 4;
}

int main() {
    vehicle v = {0, {0, 0}};

    while (1) {
        char input;
        printf("Enter a command (f, b, l, r)\n");
        scanf("%c", &input);

        switch (input) {
            case 'f':
                move_forward(&v);
                break;
            case 'b':
                move_backward(&v);
                break;
            case 'l':
                turn_left(&v);
                break;
            case 'r':
                turn_right(&v);
                break;
            default:
                printf("Invalid command\n");
                continue;
        }

        printf("Position: (%d, %d)\n", v.pos.x, v.pos.y);
    }

    return 0;
}