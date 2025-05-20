//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Vehicle {
    int x;
    int y;
    int speed;
};

void move(struct Vehicle *v, char direction) {
    switch(direction) {
        case 'U':
            v->y += v->speed;
            printf("Moved vehicle up by %d units\n", v->speed);
            break;
        case 'D':
            v->y -= v->speed;
            printf("Moved vehicle down by %d units\n", v->speed);
            break;
        case 'L':
            v->x -= v->speed;
            printf("Moved vehicle left by %d units\n", v->speed);
            break;
        case 'R':
            v->x += v->speed;
            printf("Moved vehicle right by %d units\n", v->speed);
            break;
        default:
            printf("Invalid direction. Please try again.\n");
            break;
    }
}

int main() {
    struct Vehicle car1 = {0, 0, 5};
    struct Vehicle car2 = {10, 10, 3};

    printf("Welcome to the remote control vehicle simulation!\n");
    printf("You can control two cars at the same time.\n");
    printf("Use U, D, L, R to move cars up, down, left, right.\n");
    printf("Enter Q to quit.\n");

    char input1, input2;

    do {
        printf("Car 1 (x: %d, y: %d) - Enter Direction: ", car1.x, car1.y);
        scanf(" %c", &input1);
        if (input1 == 'Q') {
            break;
        }
        move(&car1, input1);

        printf("Car 2 (x: %d, y: %d) - Enter Direction: ", car2.x, car2.y);
        scanf(" %c", &input2);
        if (input2 == 'Q') {
            break;
        }
        move(&car2, input2);

    } while(1);

    printf("Goodbye!\n");

    return 0;
}