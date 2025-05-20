//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

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

void take_off(void) {
    printf("Drone taking off...\n");
}

void land(void) {
    printf("Drone landing...\n");
}

command_t commands[] = {
    {"forward", fly_forward},
    {"backward", fly_backward},
    {"left", fly_left},
    {"right", fly_right},
    {"takeoff", take_off},
    {"land", land},
    {NULL, NULL}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    command_t *c;

    for (c = commands; c->name!= NULL; c++) {
        if (strcmp(command, c->name) == 0) {
            c->function();
            break;
        }
    }

    if (c->name == NULL) {
        printf("Invalid command: %s\n", command);
    }

    return 0;
}