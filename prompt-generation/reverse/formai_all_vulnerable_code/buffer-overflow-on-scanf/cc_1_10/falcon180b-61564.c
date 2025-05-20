//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_SIZE 100
#define MAX_COMMAND_HISTORY 10

struct command_t {
    char text[MAX_COMMAND_SIZE];
    bool executed;
};

int command_history_index = 0;
struct command_t command_history[MAX_COMMAND_HISTORY];

void execute_command(char* command) {
    printf("Executing command: %s\n", command);
    // Add your code here to execute the command
}

void add_to_command_history(char* command) {
    if (command_history_index >= MAX_COMMAND_HISTORY) {
        command_history_index = 0;
    }
    strcpy(command_history[command_history_index].text, command);
    command_history[command_history_index].executed = false;
    command_history_index++;
}

void print_command_history() {
    printf("Command history:\n");
    for (int i = 0; i < MAX_COMMAND_HISTORY; i++) {
        if (command_history[i].executed) {
            printf("%d. %s (Executed)\n", i+1, command_history[i].text);
        } else {
            printf("%d. %s\n", i+1, command_history[i].text);
        }
    }
}

int main() {
    char input[MAX_COMMAND_SIZE];

    while(true) {
        printf("Enter command: ");
        scanf("%s", input);

        add_to_command_history(input);

        if (strcmp(input, "history") == 0) {
            print_command_history();
        } else if (strcmp(input, "execute") == 0) {
            int index;
            printf("Enter index of command to execute: ");
            scanf("%d", &index);

            if (index >= 0 && index < MAX_COMMAND_HISTORY) {
                execute_command(command_history[index].text);
                command_history[index].executed = true;
            } else {
                printf("Invalid index.\n");
            }
        } else {
            execute_command(input);
        }
    }

    return 0;
}