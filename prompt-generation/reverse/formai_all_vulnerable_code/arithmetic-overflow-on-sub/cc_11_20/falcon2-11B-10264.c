//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    int vx = 0;
    int vy = 0;
    int speed = 0;
    int direction = 0;
    int turn = 0;

    printf("Welcome to the Remote Control Vehicle Simulator!\n");

    while (1) {
        printf("Enter your commands: ");
        scanf("%d %d %d %d %d %d", &x, &y, &vx, &vy, &speed, &direction);

        // Move the vehicle forward
        if (vx > 0) {
            x += vx;
        }

        // Move the vehicle backward
        if (vx < 0) {
            x -= vx;
        }

        // Move the vehicle left
        if (vy > 0) {
            y -= vy;
        }

        // Move the vehicle right
        if (vy < 0) {
            y += vy;
        }

        // Turn the vehicle left
        if (direction == 1) {
            turn -= 10;
        }

        // Turn the vehicle right
        if (direction == -1) {
            turn += 10;
        }

        // Stop the vehicle
        if (speed == 0) {
            break;
        }

        // Accelerate the vehicle
        if (speed < 100) {
            speed += 10;
        }

        // Decelerate the vehicle
        if (speed > 0) {
            speed -= 10;
        }

        // Print the vehicle's position and speed
        printf("x: %d, y: %d, vx: %d, vy: %d, speed: %d, turn: %d\n", x, y, vx, vy, speed, turn);
    }

    printf("Game over! Press any key to exit.\n");
    getchar();

    return 0;
}