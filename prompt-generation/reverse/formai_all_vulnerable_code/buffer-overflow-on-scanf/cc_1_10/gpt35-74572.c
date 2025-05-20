//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>

// A structure to hold the drone's current position
typedef struct {
    int x;
    int y;
    int z;
} Position;

// Function to move the drone up by a specified distance
void moveUp(Position* pos, int distance) {
    pos->z += distance;
    printf("Drone moves up by %d meters\n", distance);
}

// Function to move the drone down by a specified distance
void moveDown(Position* pos, int distance) {
    pos->z -= distance;
    printf("Drone moves down by %d meters\n", distance);
}

// Function to move the drone forward by a specified distance
void moveForward(Position* pos, int distance) {
    pos->y += distance;
    printf("Drone moves forward by %d meters\n", distance);
}

// Function to move the drone backward by a specified distance
void moveBackward(Position* pos, int distance) {
    pos->y -= distance;
    printf("Drone moves backward by %d meters\n", distance);
}

// Function to move the drone left by a specified distance
void moveLeft(Position* pos, int distance) {
    pos->x -= distance;
    printf("Drone moves left by %d meters\n", distance);
}

// Function to move the drone right by a specified distance
void moveRight(Position* pos, int distance) {
    pos->x += distance;
    printf("Drone moves right by %d meters\n", distance);
}

int main() {
    // Variable to hold the drone's current position
    Position pos = {0, 0, 0};

    // Menu to allow the user to control the drone
    int choice;
    do {
        printf("\nCurrent Position: x=%d, y=%d, z=%d\n", pos.x, pos.y, pos.z);
        printf("1. Move Up\n");
        printf("2. Move Down\n");
        printf("3. Move Forward\n");
        printf("4. Move Backward\n");
        printf("5. Move Left\n");
        printf("6. Move Right\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int distance;
        switch (choice) {
            case 1:
                printf("Enter distance to move up: ");
                scanf("%d", &distance);
                moveUp(&pos, distance);
                break;
            case 2:
                printf("Enter distance to move down: ");
                scanf("%d", &distance);
                moveDown(&pos, distance);
                break;
            case 3:
                printf("Enter distance to move forward: ");
                scanf("%d", &distance);
                moveForward(&pos, distance);
                break;
            case 4:
                printf("Enter distance to move backward: ");
                scanf("%d", &distance);
                moveBackward(&pos, distance);
                break;
            case 5:
                printf("Enter distance to move left: ");
                scanf("%d", &distance);
                moveLeft(&pos, distance);
                break;
            case 6:
                printf("Enter distance to move right: ");
                scanf("%d", &distance);
                moveRight(&pos, distance);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 7);

    return 0;
}