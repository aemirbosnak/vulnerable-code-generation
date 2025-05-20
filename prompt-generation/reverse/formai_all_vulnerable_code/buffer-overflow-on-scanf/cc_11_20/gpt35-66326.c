//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
// Remote control vehicle simulation using C

#include <stdio.h>

int main() {
    int fuel = 100;
    int speed = 0;
    int distance = 0;

    while (fuel > 0) {
        printf("Enter a command (accelerate, brake, status, exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "accelerate") == 0) {
            int acceleration;
            printf("Enter acceleration value (0-100): ");
            scanf("%d", &acceleration);

            if (acceleration < 0 || acceleration > 100) {
                printf("Invalid acceleration value!\n");
            } else {
                speed += acceleration;
                fuel -= acceleration;
                distance += speed;
                printf("Vehicle accelerated by %d units.\n", acceleration);
            }
        } else if (strcmp(command, "brake") == 0) {
            int deceleration;
            printf("Enter deceleration value (0-50): ");
            scanf("%d", &deceleration);

            if (deceleration < 0 || deceleration > 50) {
                printf("Invalid deceleration value!\n");
            } else {
                if (speed - deceleration < 0) {
                    speed = 0;
                } else {
                    speed -= deceleration;
                }
                distance += speed;
                printf("Vehicle slowed down by %d units.\n", deceleration);
            }
        } else if (strcmp(command, "status") == 0) {
            printf("Fuel: %d\n", fuel);
            printf("Speed: %d\n", speed);
            printf("Distance: %d\n", distance);
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}