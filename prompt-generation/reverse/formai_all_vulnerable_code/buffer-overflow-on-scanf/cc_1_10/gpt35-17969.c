//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>

/* Define Constants for drone movements */
#define LEFT 'L'
#define RIGHT 'R'
#define UP 'U'
#define DOWN 'D'

/* Define Constants for drone speed and direction */
#define MIN_SPEED 0
#define MAX_SPEED 10
#define DEFAULT_SPEED 5

/* Declare Global Variables */
int x_pos = 0, y_pos = 0;
int drone_speed = DEFAULT_SPEED;

char get_user_input() {
    char input;
    printf("Enter movement command (L/R/U/D): ");
    scanf(" %c", &input);
    return input;
}

void move_drone(char direction) {
    switch(direction) {
        case LEFT:
            x_pos -= drone_speed;
            break;
        case RIGHT:
            x_pos += drone_speed;
            break;
        case UP:
            y_pos += drone_speed;
            break;
        case DOWN:
            y_pos -= drone_speed;
            break;
        default:
            printf("Invalid command!\n");
    }
}

void set_speed() {
    int speed;
    printf("Enter drone speed (0-10): ");
    scanf("%d", &speed);

    /* Check if input is within acceptable range */
    if(speed < MIN_SPEED || speed > MAX_SPEED) {
        printf("Invalid speed!\n");
    } else {
        drone_speed = speed;
        printf("Speed set to %d\n", drone_speed);
    }
}

int main() {
    char command;
    int quit = 0;

    while(!quit) {
        command = get_user_input();
        switch(command) {
            case 'Q':
                printf("Exiting program!\n");
                quit = 1;
                break;
            case 'S':
                set_speed();
                break;
            default:
                move_drone(command);
                printf("Drone position: (%d, %d)\n", x_pos, y_pos);
                break;
        }
    }

    return 0;
}