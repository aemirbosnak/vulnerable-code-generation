//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

struct command {
    char *name;
    void (*function)(void);
};

void fly_forward(void) {
    printf("Drone flying forward...\n");
}

void fly_backward(void) {
    printf("Drone flying backward...\n");
}

void fly_left(void) {
    printf("Drone flying left...\n");
}

void fly_right(void) {
    printf("Drone flying right...\n");
}

void hover(void) {
    printf("Drone hovering...\n");
}

void land(void) {
    printf("Drone landing...\n");
}

void takeoff(void) {
    printf("Drone taking off...\n");
}

int main(int argc, char **argv) {
    struct command commands[MAX_COMMANDS] = {
        {"fly_forward", fly_forward},
        {"fly_backward", fly_backward},
        {"fly_left", fly_left},
        {"fly_right", fly_right},
        {"hover", hover},
        {"land", land},
        {"takeoff", takeoff},
    };

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char input[100];
    while (1) {
        printf("> ");
        scanf("%s", input);

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].name) == 0) {
                commands[i].function();
                break;
            }
        }
    }

    return 0;
}