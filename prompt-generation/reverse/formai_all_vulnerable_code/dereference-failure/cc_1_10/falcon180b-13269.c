//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

struct command {
    char *name;
    void (*function)(void);
};

void move_forward(void) {
    printf("The vehicle moves forward.\n");
}

void turn_left(void) {
    printf("The vehicle turns left.\n");
}

void turn_right(void) {
    printf("The vehicle turns right.\n");
}

void stop(void) {
    printf("The vehicle stops.\n");
}

int main(int argc, char *argv[]) {
    struct command commands[MAX_COMMANDS] = {
        {"move_forward", move_forward},
        {"turn_left", turn_left},
        {"turn_right", turn_right},
        {"stop", stop}
    };

    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char input[1024];

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(token, commands[i].name) == 0) {
                commands[i].function();
                break;
            }
        }
    }

    return 0;
}