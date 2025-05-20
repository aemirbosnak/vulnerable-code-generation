//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    char direction;
} Vehicle;

void displayMenu() {
    printf("Remote Control Vehicle Simulation\n");
    printf("1. Move Forward\n");
    printf("2. Move Backward\n");
    printf("3. Turn Left\n");
    printf("4. Turn Right\n");
    printf("5. Display Position\n");
    printf("6. Exit Simulation\n");
}

void moveForward(Vehicle *v) {
    switch (v->direction) {
        case 'N':
            v->y += 1;
            break;
        case 'E':
            v->x += 1;
            break;
        case 'S':
            v->y -= 1;
            break;
        case 'W':
            v->x -= 1;
            break;
        default:
            printf("Invalid direction!\n");
    }
}

void moveBackward(Vehicle *v) {
    switch (v->direction) {
        case 'N':
            v->y -= 1;
            break;
        case 'E':
            v->x -= 1;
            break;
        case 'S':
            v->y += 1;
            break;
        case 'W':
            v->x += 1;
            break;
        default:
            printf("Invalid direction!\n");
    }
}

void turnLeft(Vehicle *v) {
    switch (v->direction) {
        case 'N':
            v->direction = 'W';
            break;
        case 'E':
            v->direction = 'N';
            break;
        case 'S':
            v->direction = 'E';
            break;
        case 'W':
            v->direction = 'S';
            break;
    }
}

void turnRight(Vehicle *v) {
    switch (v->direction) {
        case 'N':
            v->direction = 'E';
            break;
        case 'E':
            v->direction = 'S';
            break;
        case 'S':
            v->direction = 'W';
            break;
        case 'W':
            v->direction = 'N';
            break;
    }
}

void displayPosition(Vehicle v) {
    printf("Current Position: (%d, %d) Facing %c\n", v.x, v.y, v.direction);
}

int main() {
    Vehicle rcVehicle = {0, 0, 'N'};  // Initial position (0,0) facing North
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveForward(&rcVehicle);
                break;
            case 2:
                moveBackward(&rcVehicle);
                break;
            case 3:
                turnLeft(&rcVehicle);
                break;
            case 4:
                turnRight(&rcVehicle);
                break;
            case 5:
                displayPosition(rcVehicle);
                break;
            case 6:
                printf("Exiting simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
        printf("\n");
    }

    return 0;
}