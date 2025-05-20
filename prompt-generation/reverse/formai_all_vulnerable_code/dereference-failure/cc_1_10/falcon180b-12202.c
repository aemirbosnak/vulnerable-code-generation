//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char *name;
    void (*function)(void);
} command_t;

void fly_forward(void) {
    printf("Drone is flying forward\n");
}

void fly_backward(void) {
    printf("Drone is flying backward\n");
}

void turn_left(void) {
    printf("Drone is turning left\n");
}

void turn_right(void) {
    printf("Drone is turning right\n");
}

void hover(void) {
    printf("Drone is hovering\n");
}

void land(void) {
    printf("Drone is landing\n");
}

int main(void) {
    command_t commands[MAX_COMMANDS] = {{"forward", fly_forward},
                                        {"backward", fly_backward},
                                        {"left", turn_left},
                                        {"right", turn_right},
                                        {"hover", hover},
                                        {"land", land}};

    int num_commands = 0;

    printf("Welcome to the drone remote control!\n");

    while (1) {
        printf("Enter a command or type 'help' for a list of commands:\n");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *token = strtok(input, " ");
        if (strcmp(token, "help") == 0) {
            printf("Available commands:\n");
            for (int i = 0; i < num_commands; i++) {
                printf("%s\n", commands[i].name);
            }
        } else {
            for (int i = 0; i < num_commands; i++) {
                if (strcmp(token, commands[i].name) == 0) {
                    commands[i].function();
                    break;
                }
            }
        }
    }

    return 0;
}