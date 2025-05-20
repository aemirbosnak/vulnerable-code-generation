//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function prototypes
void display_menu();
void take_off();
void land();
void move_forward();
void move_backward();
void turn_left();
void turn_right();
void status_report();
void exit_program();

// Global variable to store drone status
int isFlying = 0;

int main() {
    char command[20];

    while (1) {
        display_menu();
        printf("Enter command: ");
        scanf("%s", command);

        // Command processing
        if (strcmp(command, "takeoff") == 0) {
            take_off();
        } else if (strcmp(command, "land") == 0) {
            land();
        } else if (strcmp(command, "forward") == 0) {
            move_forward();
        } else if (strcmp(command, "backward") == 0) {
            move_backward();
        } else if (strcmp(command, "left") == 0) {
            turn_left();
        } else if (strcmp(command, "right") == 0) {
            turn_right();
        } else if (strcmp(command, "status") == 0) {
            status_report();
        } else if (strcmp(command, "exit") == 0) {
            exit_program();
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n------- Drone Remote Control -------\n");
    printf("Commands:\n");
    printf("1. takeoff - Start the drone\n");
    printf("2. land - Land the drone\n");
    printf("3. forward - Move the drone forward\n");
    printf("4. backward - Move the drone backward\n");
    printf("5. left - Turn the drone left\n");
    printf("6. right - Turn the drone right\n");
    printf("7. status - Get the drone status\n");
    printf("8. exit - Exit the program\n");
    printf("-------------------------------------\n");
}

void take_off() {
    if (isFlying) {
        printf("Drone is already in the air!\n");
    } else {
        isFlying = 1;
        printf("Drone taking off...\n");
        sleep(2);
        printf("Drone is now in the air!\n");
    }
}

void land() {
    if (!isFlying) {
        printf("Drone is already on the ground!\n");
    } else {
        isFlying = 0;
        printf("Drone landing...\n");
        sleep(2);
        printf("Drone has landed safely.\n");
    }
}

void move_forward() {
    if (!isFlying) {
        printf("You need to take off first!\n");
    } else {
        printf("Drone moving forward...\n");
        sleep(1);
    }
}

void move_backward() {
    if (!isFlying) {
        printf("You need to take off first!\n");
    } else {
        printf("Drone moving backward...\n");
        sleep(1);
    }
}

void turn_left() {
    if (!isFlying) {
        printf("You need to take off first!\n");
    } else {
        printf("Drone turning left...\n");
        sleep(1);
    }
}

void turn_right() {
    if (!isFlying) {
        printf("You need to take off first!\n");
    } else {
        printf("Drone turning right...\n");
        sleep(1);
    }
}

void status_report() {
    if (isFlying) {
        printf("Drone is currently flying.\n");
    } else {
        printf("Drone is on the ground.\n");
    }
}

void exit_program() {
    printf("Exiting program...\n");
    sleep(1);
    printf("Thank you for using the Drone Remote Control System!\n");
}