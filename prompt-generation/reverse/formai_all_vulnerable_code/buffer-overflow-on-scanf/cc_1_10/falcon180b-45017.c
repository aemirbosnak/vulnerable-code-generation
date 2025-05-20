//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)();
} command_t;

void takeoff() {
    printf("Taking off...\n");
}

void land() {
    printf("Landing...\n");
}

void forward() {
    printf("Moving forward...\n");
}

void backward() {
    printf("Moving backward...\n");
}

void left() {
    printf("Moving left...\n");
}

void right() {
    printf("Moving right...\n");
}

int main() {
    command_t commands[MAX_COMMANDS] = {{"takeoff", takeoff},
                                        {"land", land},
                                        {"forward", forward},
                                        {"backward", backward},
                                        {"left", left},
                                        {"right", right}};

    int num_commands = sizeof(commands) / sizeof(command_t);

    char input[MAX_COMMAND_LENGTH];

    while(1) {
        printf("Enter a command: ");
        scanf("%s", input);

        for(int i=0; i<num_commands; i++) {
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