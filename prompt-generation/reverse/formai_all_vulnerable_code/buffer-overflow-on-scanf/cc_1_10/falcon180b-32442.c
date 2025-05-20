//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SPEED 50

void move(int direction, int speed) {
    printf("Vehicle is moving %d at a speed of %d.\n", direction, speed);
}

int main() {
    int choice;

    srand(time(NULL));

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move(UP, SPEED);
                break;
            case 2:
                move(DOWN, SPEED);
                break;
            case 3:
                move(LEFT, SPEED);
                break;
            case 4:
                move(RIGHT, SPEED);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}