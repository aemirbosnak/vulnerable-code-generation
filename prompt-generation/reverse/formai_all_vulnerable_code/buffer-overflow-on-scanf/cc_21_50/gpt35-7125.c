//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
// Cyberpunk C Drone Remote Control Program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_DISTANCE 1000
#define MAX_SPEED 100

int main() {
    int speed = 0;
    int distance = 0;
    bool isFlying = false;
    int batteryLife = 100;

    printf("-----Cyberpunk C Drone Remote Control Program-----\n\n");

    while (true) {
        // Display drone status
        printf("\n--- Drone Status ---\n");
        printf("Battery: %d%%\n", batteryLife);
        printf("Distance: %d m\n", distance);
        printf("Speed: %d m/s\n", speed);
        printf("Flying: %s\n", isFlying ? "Yes" : "No");

        if (batteryLife == 0) {
            printf("Battery is empty. Drone will land automatically.\n");
            isFlying = false;
        }

        // Input commands
        printf("\n--- Command List ---\n");
        printf("1. Take off/Land\n");
        printf("2. Increase speed\n");
        printf("3. Decrease speed\n");
        printf("4. Move forward\n");
        printf("5. Move backward\n");
        printf("6. Turn left\n");
        printf("7. Turn right\n");
        printf("8. Check battery level\n");
        printf("9. Exit program\n");
        printf("> ");

        int command;
        scanf("%d", &command);

        switch (command) {
            case 1:
                if (isFlying) {
                    printf("Landing drone...\n");
                    isFlying = false;
                } else {
                    printf("Taking off...\n");
                    isFlying = true;
                }
                break;
            case 2:
                if (speed < MAX_SPEED) {
                    speed++;
                    printf("Speed increased to %d m/s.\n", speed);
                } else {
                    printf("Maximum speed reached.\n");
                }
                break;
            case 3:
                if (speed > 0) {
                    speed--;
                    printf("Speed decreased to %d m/s.\n", speed);
                } else {
                    printf("Cannot decrease speed.\n");
                }
                break;
            case 4:
                if (isFlying) {
                    if (distance < MAX_DISTANCE) {
                        distance++;
                        printf("Drone moved forward by 1 m.\n");
                    } else {
                        printf("Maximum distance reached.\n");
                    }
                } else {
                    printf("Drone is not flying. Cannot move.\n");
                }
                break;
            case 5:
                if (isFlying) {
                    if (distance > 0) {
                        distance--;
                        printf("Drone moved backward by 1 m.\n");
                    } else {
                        printf("Cannot move backward.\n");
                    }
                } else {
                    printf("Drone is not flying. Cannot move.\n");
                }
                break;
            case 6:
                if (isFlying) {
                    printf("Drone turned left.\n");
                } else {
                    printf("Drone is not flying. Cannot turn.\n");
                }
                break;
            case 7:
                if (isFlying) {
                    printf("Drone turned right.\n");
                } else {
                    printf("Drone is not flying. Cannot turn.\n");
                }
                break;
            case 8:
                printf("Battery: %d%%\n", batteryLife);
                break;
            case 9:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid command.\n");
        }

        // Decrease battery life and sleep for 1 second
        if (isFlying) {
            batteryLife--;
        } else {
            batteryLife++;
        }
        batteryLife = batteryLife < 0 ? 0 : batteryLife;
        batteryLife = batteryLife > 100 ? 100 : batteryLife;
        usleep(1000000);
    }

    return 0;
}