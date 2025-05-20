//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 64

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on lights...\n");
}

void turn_off_lights(void) {
    printf("Turning off lights...\n");
}

void lock_doors(void) {
    printf("Locking doors...\n");
}

void unlock_doors(void) {
    printf("Unlocking doors...\n");
}

int main(int argc, char *argv[]) {
    int num_commands = 0;
    command_t commands[MAX_COMMANDS];

    printf("Enter commands (type 'done' when finished):\n");
    while (num_commands < MAX_COMMANDS && fgets(commands[num_commands].command, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(commands[num_commands].command, "done") == 0) {
            break;
        }
        num_commands++;
    }

    printf("Commands entered:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%s\n", commands[i].command);
    }

    while (1) {
        char input[MAX_COMMAND_LENGTH];
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }

        if (strcmp(input, "done") == 0) {
            break;
        }
    }

    return 0;
}