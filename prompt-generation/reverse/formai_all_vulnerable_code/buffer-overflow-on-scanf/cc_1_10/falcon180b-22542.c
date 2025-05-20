//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)();
} command_t;

void fly_forward();
void fly_backward();
void fly_left();
void fly_right();
void take_off();
void land();

command_t commands[MAX_COMMANDS] = {
    {"forward", fly_forward},
    {"backward", fly_backward},
    {"left", fly_left},
    {"right", fly_right},
    {"takeoff", take_off},
    {"land", land},
};

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);
        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }
    }
    return 0;
}

void fly_forward() {
    printf("Drone is flying forward.\n");
}

void fly_backward() {
    printf("Drone is flying backward.\n");
}

void fly_left() {
    printf("Drone is flying left.\n");
}

void fly_right() {
    printf("Drone is flying right.\n");
}

void take_off() {
    printf("Drone is taking off.\n");
}

void land() {
    printf("Drone is landing.\n");
}