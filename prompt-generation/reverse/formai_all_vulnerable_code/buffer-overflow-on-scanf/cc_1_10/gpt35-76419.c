//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>

/* Constants */
#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGLE 180
#define MIN_ANGLE 0

/* Global variables */
int speed = 0;
int angle = 90;
int battery_level = 100;

/* Functions */
void print_status() {
    printf("Speed: %d\n", speed);
    printf("Angle: %d\n", angle);
    printf("Battery: %d%%\n", battery_level);
}

void set_speed(int new_speed) {
    if (new_speed >= MIN_SPEED && new_speed <= MAX_SPEED) {
        speed = new_speed;
    }
}

void set_angle(int new_angle) {
    if (new_angle >= MIN_ANGLE && new_angle <= MAX_ANGLE) {
        angle = new_angle;
    }
}

void move_forward() {
    printf("Moving forward with speed %d and angle %d\n", speed, angle);
    battery_level -= 2;
}

void move_backward() {
    printf("Moving backward with speed %d and angle %d\n", speed, angle);
    battery_level -= 2;
}

void turn_left() {
    printf("Turning left with angle %d\n", angle);
    battery_level--;
}

void turn_right() {
    printf("Turning right with angle %d\n", angle);
    battery_level--;
}

void recharge_battery() {
    printf("Recharging battery\n");
    battery_level = 100;
}

/* Main function */
int main() {
    char input;
    printf("Welcome to the remote control vehicle simulation program!\n");

    while (1) {
        /* Print status and prompt for input */
        print_status();
        printf("Enter command (f = forward, b = backward, l = left, r = right, s = speed, a = angle, c = charge, q = quit): ");
        scanf(" %c", &input);

        /* Parse input and execute command */
        switch (input) {
            case 'f':
                move_forward();
                break;
            case 'b':
                move_backward();
                break;
            case 'l':
                turn_left();
                break;
            case 'r':
                turn_right();
                break;
            case 's':
                printf("Enter new speed (between %d and %d): ", MIN_SPEED, MAX_SPEED);
                scanf("%d", &speed);
                set_speed(speed);
                break;
            case 'a':
                printf("Enter new angle (between %d and %d): ", MIN_ANGLE, MAX_ANGLE);
                scanf("%d", &angle);
                set_angle(angle);
                break;
            case 'c':
                recharge_battery();
                break;
            case 'q':
                printf("Exiting remote control vehicle simulation program.\n");
                return 0;
            default:
                printf("Unknown command '%c'.\n", input);
        }
    }

    return 0;
}