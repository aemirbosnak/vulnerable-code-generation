//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int current_x, current_y;
int drone_battery = 100;
char command;

void move_drone(int x, int y) {
    current_x = x;
    current_y = y;
    printf("Drone has moved to location (%d, %d)\n", current_x, current_y);
}

void rotate_left() {
    printf("Drone has rotated to the left\n");
}

void rotate_right() {
    printf("Drone has rotated to the right\n");
}

void hover() {
    printf("Drone is hovering\n");
}

void land() {
    printf("Drone is landing\n");
}

int main() {
    srand(time(NULL)); // seed random number generator
    current_x = rand() % 101; // set initial x coordinate to random value between 0 and 100
    current_y = rand() % 101; // set initial y coordinate to random value between 0 and 100

    printf("Welcome to C Drone Remote Control!\n");
    printf("Your current drone location is (%d, %d)\n", current_x, current_y);

    while (drone_battery > 0) {
        printf("Enter a command (m, l, r, h, or q): "); // m = move, l = rotate left, r = rotate right, h = hover, q = quit
        scanf(" %c", &command);

        switch (command) {
            case 'm': {
                int x, y;
                printf("Enter new location (x, y): ");
                scanf("%d %d", &x, &y);
                move_drone(x, y);
                drone_battery -= 10;
                printf("Battery level: %d\n", drone_battery);
                break;
            }
            case 'l': {
                rotate_left();
                drone_battery -= 5;
                printf("Battery level: %d\n", drone_battery);
                break;
            }
            case 'r': {
                rotate_right();
                drone_battery -= 5;
                printf("Battery level: %d\n", drone_battery);
                break;
            }
            case 'h': {
                hover();
                drone_battery -= 2;
                printf("Battery level: %d\n", drone_battery);
                break;
            }
            case 'q': {
                land();
                printf("Thanks for using C Drone Remote Control!\n");
                return 0;
            }
            default: {
                printf("Invalid command\n");
                break;
            }
        }

        if (drone_battery <= 0) {
            printf("Drone battery is dead, returning to base...\n");
            land();
            printf("Thanks for using C Drone Remote Control!\n");
            return 0;
        }
    }
    return 0;
}