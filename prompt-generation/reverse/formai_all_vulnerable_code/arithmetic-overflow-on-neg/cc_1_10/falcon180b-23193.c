//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector3;

Vector3 drone_position;
Vector3 drone_velocity;

void init_drone() {
    drone_position.x = 0;
    drone_position.y = 0;
    drone_position.z = 0;
    drone_velocity.x = 0;
    drone_velocity.y = 0;
    drone_velocity.z = 0;
}

void move_drone(int direction, int speed) {
    switch(direction) {
        case 1: // forward
            drone_velocity.z = speed;
            break;
        case 2: // backward
            drone_velocity.z = -speed;
            break;
        case 3: // left
            drone_velocity.y = speed;
            break;
        case 4: // right
            drone_velocity.y = -speed;
            break;
        case 5: // up
            drone_velocity.x = speed;
            break;
        case 6: // down
            drone_velocity.x = -speed;
            break;
        default:
            break;
    }
}

void update_drone_position() {
    drone_position.x += drone_velocity.x;
    drone_position.y += drone_velocity.y;
    drone_position.z += drone_velocity.z;
}

int main() {
    init_drone();

    int choice;
    while(1) {
        printf("Choose a direction (1-6): ");
        scanf("%d", &choice);
        printf("Choose a speed (1-10): ");
        scanf("%d", &drone_velocity.z);
        move_drone(choice, drone_velocity.z);
        update_drone_position();
        printf("Drone position: (%d, %d, %d)\n", drone_position.x, drone_position.y, drone_position.z);
    }

    return 0;
}