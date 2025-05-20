//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)();
} command_t;

void move_forward(void) {
    printf("Drone moving forward\n");
}

void move_backward(void) {
    printf("Drone moving backward\n");
}

void turn_left(void) {
    printf("Drone turning left\n");
}

void turn_right(void) {
    printf("Drone turning right\n");
}

void take_off(void) {
    printf("Drone taking off\n");
}

void land(void) {
    printf("Drone landing\n");
}

void emergency_stop(void) {
    printf("Emergency stop\n");
}

int main(void) {
    command_t commands[MAX_COMMANDS] = {{"forward", move_forward},
                                        {"backward", move_backward},
                                        {"left", turn_left},
                                        {"right", turn_right},
                                        {"takeoff", take_off},
                                        {"land", land},
                                        {"stop", emergency_stop}};

    int num_commands = sizeof(commands) / sizeof(command_t);

    char input[MAX_COMMAND_LENGTH];

    while(1) {
        printf("Enter command: ");
        scanf("%s", input);

        for(int i=0; i<num_commands; i++) {
            if(strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }
    }

    return 0;
}