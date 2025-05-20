//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)();
} command_t;

void turn_on_lights() {
    printf("Turning on the lights...\n");
}

void turn_off_lights() {
    printf("Turning off the lights...\n");
}

void lock_door() {
    printf("Locking the door...\n");
}

void unlock_door() {
    printf("Unlocking the door...\n");
}

int main() {
    command_t commands[MAX_COMMANDS] = {
        {"turn_on_lights", turn_on_lights},
        {"turn_off_lights", turn_off_lights},
        {"lock_door", lock_door},
        {"unlock_door", unlock_door}
    };

    char input[100];
    while(1) {
        printf("Enter a command: ");
        scanf("%s", input);

        for(int i=0; i<MAX_COMMANDS; i++) {
            if(strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }

        if(strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}