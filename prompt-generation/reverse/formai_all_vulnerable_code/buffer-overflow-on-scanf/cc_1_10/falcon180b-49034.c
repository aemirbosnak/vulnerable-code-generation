//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD,
    TURN_LEFT,
    TURN_RIGHT,
    TAKE_OFF,
    LAND
};

struct command {
    char name[MAX_COMMAND_LENGTH];
    int (*function)(void);
};

void fly_up(void) {
    printf("Flying up...\n");
}

void fly_down(void) {
    printf("Flying down...\n");
}

void fly_left(void) {
    printf("Flying left...\n");
}

void fly_right(void) {
    printf("Flying right...\n");
}

void fly_forward(void) {
    printf("Flying forward...\n");
}

void fly_backward(void) {
    printf("Flying backward...\n");
}

void turn_left(void) {
    printf("Turning left...\n");
}

void turn_right(void) {
    printf("Turning right...\n");
}

void take_off(void) {
    printf("Taking off...\n");
}

void land(void) {
    printf("Landing...\n");
}

int main() {
    struct command commands[MAX_COMMANDS] = {{"fly_up", fly_up},
                                              {"fly_down", fly_down},
                                              {"fly_left", fly_left},
                                              {"fly_right", fly_right},
                                              {"fly_forward", fly_forward},
                                              {"fly_backward", fly_backward},
                                              {"turn_left", turn_left},
                                              {"turn_right", turn_right},
                                              {"take_off", take_off},
                                              {"land", land}};

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);
        input[strcspn(input, "\r\n")] = '\0';

        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].name) == 0) {
                (*commands[i].function)();
                break;
            }
        }
    }

    return 0;
}