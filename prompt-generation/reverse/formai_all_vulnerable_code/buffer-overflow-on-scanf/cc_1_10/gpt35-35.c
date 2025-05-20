//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void move_forward(int dist) {
    if(dist == 0) {
        return;
    }
    printf("Vehicle moved forward by 1 unit.\n");
    move_forward(dist-1);
}

void move_backward(int dist) {
    if(dist == 0) {
        return;
    }
    printf("Vehicle moved backward by 1 unit.\n");
    move_backward(dist-1);
}

void turn_left(int angle) {
    if(angle == 0) {
        return;
    }
    printf("Vehicle turned left by 1 degree.\n");
    turn_left(angle-1);
}

void turn_right(int angle) {
    if(angle == 0) {
        return;
    }
    printf("Vehicle turned right by 1 degree.\n");
    turn_right(angle-1);
}

int main() {
    int choice, dist, angle;

    printf("Welcome to Remote Control Vehicle Simulator\n");
    printf("-------------------------------------------\n");

    do {
        printf("\nChoose a command:\n");
        printf("1. Move vehicle forward\n");
        printf("2. Move vehicle backward\n");
        printf("3. Turn vehicle left\n");
        printf("4. Turn vehicle right\n");
        printf("5. Exit the program\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter distance to move forward: ");
                scanf("%d", &dist);
                move_forward(dist);
                break;
            case 2:
                printf("Enter distance to move backward: ");
                scanf("%d", &dist);
                move_backward(dist);
                break;
            case 3:
                printf("Enter angle to turn left: ");
                scanf("%d", &angle);
                turn_left(angle);
                break;
            case 4:
                printf("Enter angle to turn right: ");
                scanf("%d", &angle);
                turn_right(angle);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}