//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pitch;
    int roll;
    int yaw;
    int throttle;
} Remote_Control_t;

void update_pitch(Remote_Control_t* rc, int value) {
    rc->pitch = value;
}

void update_roll(Remote_Control_t* rc, int value) {
    rc->roll = value;
}

void update_yaw(Remote_Control_t* rc, int value) {
    rc->yaw = value;
}

void update_throttle(Remote_Control_t* rc, int value) {
    rc->throttle = value;
}

void print_rc_values(Remote_Control_t rc) {
    printf("Pitch: %d\n", rc.pitch);
    printf("Roll: %d\n", rc.roll);
    printf("Yaw: %d\n", rc.yaw);
    printf("Throttle: %d\n\n", rc.throttle);
}

int main() {
    Remote_Control_t rc = {0};

    printf("Welcome to C Drone Remote Control!\n\n");
    printf("Use the following commands to control the drone:\n");
    printf("\t'pitch <value>' Set the pitch (up/down) value.\n");
    printf("\t'roll <value>' Set the roll (left/right) value.\n");
    printf("\t'yaw <value>' Set the yaw (rotate) value.\n");
    printf("\t'throttle <value>' Set the throttle (up/down) value.\n");
    printf("\t'quit' Stop the program.\n\n");

    char input[50];
    char command[10];
    int value;

    while (1) {
        printf("Enter command: ");
        fgets(input, 50, stdin);
        sscanf(input, "%s %d", command, &value);

        if (strcmp(command, "quit") == 0) {
            printf("\nExiting.\n");
            break;
        }
        else if (strcmp(command, "pitch") == 0) {
            update_pitch(&rc, value);
            printf("Pitch updated to %d.\n\n", value);
        }
        else if (strcmp(command, "roll") == 0) {
            update_roll(&rc, value);
            printf("Roll updated to %d.\n\n", value);
        }
        else if (strcmp(command, "yaw") == 0) {
            update_yaw(&rc, value);
            printf("Yaw updated to %d.\n\n", value);
        }
        else if (strcmp(command, "throttle") == 0) {
            update_throttle(&rc, value);
            printf("Throttle updated to %d.\n\n", value);
        }
        else {
            printf("Unknown command.\n\n");
        }

        print_rc_values(rc);
    }

    return 0;
}