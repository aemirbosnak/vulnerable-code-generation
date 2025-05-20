//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 100

// Struct to hold command and frequency
typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int frequency;
} Command;

// Function to compare two commands based on frequency
int compare_commands(const void *a, const void *b) {
    const Command *command_a = a;
    const Command *command_b = b;

    return command_b->frequency - command_a->frequency;
}

// Function to print the top n commands
void print_top_commands(Command *commands, int n) {
    qsort(commands, n, sizeof(Command), compare_commands);

    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", commands[i].command, commands[i].frequency);
    }
}

int main() {
    // Initialize command list
    Command commands[MAX_COMMANDS];
    memset(commands, 0, sizeof(commands));

    // Read commands from file
    FILE *file = fopen("commands.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    while (fscanf(file, "%s", command)!= EOF) {
        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (commands[i].frequency == 0) {
                strcpy(commands[i].command, command);
                commands[i].frequency = 1;
                break;
            } else if (strcmp(commands[i].command, command) == 0) {
                commands[i].frequency++;
                break;
            }
        }
    }

    fclose(file);

    // Sort commands by frequency
    qsort(commands, MAX_COMMANDS, sizeof(Command), compare_commands);

    // Print top n commands
    int n;
    printf("Enter the number of top commands to print: ");
    scanf("%d", &n);

    print_top_commands(commands, n);

    return 0;
}