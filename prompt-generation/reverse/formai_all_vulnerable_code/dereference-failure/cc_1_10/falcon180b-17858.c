//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>

#define MAX_COMMANDS 50
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on the lights...\n");
}

void play_music(void) {
    printf("Playing romantic music...\n");
}

void set_mood_lighting(void) {
    printf("Setting mood lighting...\n");
}

void cook_dinner(void) {
    printf("Cooking a romantic dinner...\n");
}

int main(int argc, char **argv) {
    int i;
    char input[MAX_COMMAND_LENGTH];
    command_t commands[MAX_COMMANDS] = {{"turn on lights", turn_on_lights},
                                        {"play music", play_music},
                                        {"set mood lighting", set_mood_lighting},
                                        {"cook dinner", cook_dinner}};

    printf("Welcome to the Smart Home Automation System\n");

    while(1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Convert input to lowercase
        for(i=0; i<strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Search for command in list of commands
        int found = 0;
        for(i=0; i<MAX_COMMANDS; i++) {
            if(strcmp(input, commands[i].command) == 0) {
                commands[i].function();
                found = 1;
                break;
            }
        }

        if(!found) {
            printf("Invalid command\n");
        }
    }

    return 0;
}