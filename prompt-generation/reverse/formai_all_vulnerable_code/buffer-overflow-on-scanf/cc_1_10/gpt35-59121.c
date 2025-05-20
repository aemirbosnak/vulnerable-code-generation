//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// define the commands for the drone
#define TURN_LEFT 'l'
#define TURN_RIGHT 'r'
#define UP 'u'
#define DOWN 'd'
#define FORWARD 'f'
#define BACKWARD 'b'
#define LAND 't'
#define QUIT 'q'

// define the range of the drone movements
#define MAX_HEIGHT 100
#define MIN_HEIGHT 0
#define MAX_ANGLE 180
#define MIN_ANGLE 0

// function prototypes
void print_menu(void);
char get_user_command(void);
void perform_action(char command, int *height, int *angle);

int main(void) {
    char command;
    int height = 0;
    int angle = 0;
    printf("Welcome to the Drone Remote Control Program!\n");
    print_menu();
    while ((command = get_user_command()) != QUIT) {
        perform_action(command, &height, &angle);
    }
    printf("Thank you for using the Drone Remote Control Program!\n");
    return 0;
}

void print_menu(void) {
    printf("\nAvailable commands:\n");
    printf("l: Turn left\n");
    printf("r: Turn right\n");
    printf("u: Move up\n");
    printf("d: Move down\n");
    printf("f: Move forward\n");
    printf("b: Move backward\n");
    printf("t: Land the drone\n");
    printf("q: Quit\n");
}

char get_user_command(void) {
    char command;
    printf("\nEnter command: ");
    scanf(" %c", &command);
    return command;
}

void perform_action(char command, int *height, int *angle) {
    int value;
    switch (command) {
        case TURN_LEFT:
            value = (*angle - 10) % MAX_ANGLE;
            if (value < 0) {
                *angle = MAX_ANGLE - 10;
            } else {
                *angle = value;
            }
            printf("Turning left. Current angle: %d\n", *angle);
            break;
        case TURN_RIGHT:
            *angle = (*angle + 10) % MAX_ANGLE;
            printf("Turning right. Current angle: %d\n", *angle);
            break;
        case UP:
            value = *height + 10;
            if (value > MAX_HEIGHT) {
                *height = MAX_HEIGHT;
            } else {
                *height = value;
            }
            printf("Moving up. Current height: %d\n", *height);
            break;
        case DOWN:
            value = *height - 10;
            if (value < MIN_HEIGHT) {
                *height = MIN_HEIGHT;
            } else {
                *height = value;
            }
            printf("Moving down. Current height: %d\n", *height);
            break;
        case FORWARD:
            printf("Moving forward.\n");
            break;
        case BACKWARD:
            printf("Moving backward.\n");
            break;
        case LAND:
            printf("Landing the drone.\n");
            break;
        default:
            printf("Invalid command!\n");
            break;
    }
}