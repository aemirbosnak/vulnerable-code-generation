//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROBOT_X 0
#define ROBOT_Y 0
#define MOVE_LEFT 1
#define MOVE_RIGHT 2
#define MOVE_FORWARD 3
#define MOVE_BACKWARD 4

void move_robot(int direction) {
    switch (direction) {
        case MOVE_LEFT:
            printf("Robot moved left.\n");
            break;
        case MOVE_RIGHT:
            printf("Robot moved right.\n");
            break;
        case MOVE_FORWARD:
            printf("Robot moved forward.\n");
            break;
        case MOVE_BACKWARD:
            printf("Robot moved backward.\n");
            break;
        default:
            printf("Invalid direction.\n");
    }
}

int main() {
    int choice;

    while (true) {
        printf("Enter your choice:\n");
        printf("1. Move left\n");
        printf("2. Move right\n");
        printf("3. Move forward\n");
        printf("4. Move backward\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_robot(MOVE_LEFT);
                break;
            case 2:
                move_robot(MOVE_RIGHT);
                break;
            case 3:
                move_robot(MOVE_FORWARD);
                break;
            case 4:
                move_robot(MOVE_BACKWARD);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}