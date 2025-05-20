//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>

/*
 * This program simulates a remote control for a drone.
 */

#define MAX_SPEED 10 // Maximum speed of the drone
#define MAX_HEIGHT 100 // Maximum height of the drone

// Function declarations
void fly_up(int *height); // Increases the height of the drone
void fly_down(int *height); // Decreases the height of the drone
void move_forward(int *speed); // Increases the speed of the drone
void move_backward(int *speed); // Decreases the speed of the drone
void land(); // Lands the drone

int main()
{
    int speed = 0;
    int height = 0;
    char command;

    printf("=== Drone Remote Control ===\n");
    printf("Commands: u (up), d (down), f (forward), b (backward), l (land)\n");

    do {
        printf("Current speed: %d\n", speed);
        printf("Current height: %d\n", height);
        printf("Enter command: ");
        scanf("%c", &command);

        switch (command) {
            case 'u':
                fly_up(&height);
                break;
            case 'd':
                fly_down(&height);
                break;
            case 'f':
                move_forward(&speed);
                break;
            case 'b':
                move_backward(&speed);
                break;
            case 'l':
                land();
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        // Clear input buffer
        char c;
        while ((c = getchar()) != '\n' && c != EOF);

    } while (command != 'l');

    return 0;
}

void fly_up(int *height)
{
    if (*height < MAX_HEIGHT) {
        (*height)++;
        printf("Drone is now at height %d\n", *height);
    } else {
        printf("Drone cannot fly higher than %d\n", MAX_HEIGHT);
    }
}

void fly_down(int *height)
{
    if (*height > 0) {
        (*height)--;
        printf("Drone is now at height %d\n", *height);
    } else {
        printf("Drone cannot fly lower than 0\n");
    }
}

void move_forward(int *speed)
{
    if (*speed < MAX_SPEED) {
        (*speed)++;
        printf("Drone is now moving forward at speed %d\n", *speed);
    } else {
        printf("Drone cannot go faster than %d\n", MAX_SPEED);
    }
}

void move_backward(int *speed)
{
    if (*speed > 0) {
        (*speed)--;
        printf("Drone is now moving backward at speed %d\n", *speed);
    } else {
        printf("Drone cannot go slower than 0\n");
    }
}

void land()
{
    printf("Landing drone...\n");
    printf("Drone has landed\n");
}