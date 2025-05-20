//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on the lights!\n");
}

void turn_off_lights(void) {
    printf("Turning off the lights!\n");
}

void lock_doors(void) {
    printf("Locking the doors!\n");
}

void unlock_doors(void) {
    printf("Unlocking the doors!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {{"turn_on_lights", turn_on_lights},
                                        {"turn_off_lights", turn_off_lights},
                                        {"lock_doors", lock_doors},
                                        {"unlock_doors", unlock_doors}};

    char *command_name = argv[1];
    int i;

    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command_name);
    return 1;
}