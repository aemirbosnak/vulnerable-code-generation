//FormAI DATASET v1.0 Category: Robot movement control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define some constants */
#define MAX_COMMAND_LENGTH 20
#define MAX_INPUT_LENGTH 100

/* Declare functions */
void move_forward();
void move_backward();
void turn_left();
void turn_right();

/* Define global variables */
int x = 0;
int y = 0;
int facing = 0;

int main() {
    /* Greet the user */
    printf("Hello! I am your robot. Let's move together!\n");

    /* Loop to accept user commands */
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        /* Print current status */
        printf("Current position: (%d, %d) facing ", x, y);
        if (facing == 0) {
            printf("north\n");
        } else if (facing == 1) {
            printf("east\n");
        } else if (facing == 2) {
            printf("south\n");
        } else {
            printf("west\n");
        }

        /* Accept user input */
        printf("What do you want me to do? ");
        char input[MAX_INPUT_LENGTH];
        fgets(input, MAX_INPUT_LENGTH, stdin);
        sscanf(input, "%s", command);

        /* Determine which action to take */
        if (strcmp(command, "forward") == 0) {
            move_forward();
        } else if (strcmp(command, "backward") == 0) {
            move_backward();
        } else if (strcmp(command, "left") == 0) {
            turn_left();
        } else if (strcmp(command, "right") == 0) {
            turn_right();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Sorry, I didn't understand that.\n");
        }
    }

    /* Say goodbye */
    printf("Goodbye! Thank you for moving with me.\n");

    /* Return success */
    return 0;
}

void move_forward() {
    /* Determine new position */
    if (facing == 0) {
        y++;
    } else if (facing == 1) {
        x++;
    } else if (facing == 2) {
        y--;
    } else {
        x--;
    }

    /* Print new position */
    printf("Moving forward to (%d, %d)\n", x, y);
}

void move_backward() {
    /* Determine new position */
    if (facing == 0) {
        y--;
    } else if (facing == 1) {
        x--;
    } else if (facing == 2) {
        y++;
    } else {
        x++;
    }

    /* Print new position */
    printf("Moving backward to (%d, %d)\n", x, y);
}

void turn_left() {
    /* Determine new facing */
    facing--;
    if (facing < 0) {
        facing += 4;
    }

    /* Print new facing */
    printf("Turning left, now facing ");
    if (facing == 0) {
        printf("north\n");
    } else if (facing == 1) {
        printf("east\n");
    } else if (facing == 2) {
        printf("south\n");
    } else {
        printf("west\n");
    }
}

void turn_right() {
    /* Determine new facing */
    facing++;
    if (facing >= 4) {
        facing -= 4;
    }

    /* Print new facing */
    printf("Turning right, now facing ");
    if (facing == 0) {
        printf("north\n");
    } else if (facing == 1) {
        printf("east\n");
    } else if (facing == 2) {
        printf("south\n");
    } else {
        printf("west\n");
    }
}