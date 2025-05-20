//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int x;
    int y;
} Point;

Point drone_position;

void initialize() {
    srand(time(NULL));
    drone_position.x = rand() % 100;
    drone_position.y = rand() % 100;
    printf("Drone initialized at position (%d, %d)\n", drone_position.x, drone_position.y);
}

void move_drone(int dx, int dy) {
    drone_position.x += dx;
    drone_position.y += dy;
    printf("Drone moved to position (%d, %d)\n", drone_position.x, drone_position.y);
}

void fly_drone(int target_x, int target_y) {
    int dx = target_x - drone_position.x;
    int dy = target_y - drone_position.y;
    int distance = sqrt(dx * dx + dy * dy);

    if (distance <= 10) {
        printf("Drone reached target at position (%d, %d)\n", target_x, target_y);
        return;
    }

    if (dx == 0 && dy == 0) {
        printf("Cannot fly to the same position!\n");
        return;
    }

    if (dx > 0) {
        move_drone(1, 0);
    } else if (dx < 0) {
        move_drone(-1, 0);
    } else if (dy > 0) {
        move_drone(0, 1);
    } else if (dy < 0) {
        move_drone(0, -1);
    }

    fly_drone(target_x, target_y);
}

int main() {
    initialize();
    int target_x, target_y;

    printf("Enter target position (x, y): ");
    scanf("%d %d", &target_x, &target_y);

    fly_drone(target_x, target_y);

    return 0;
}