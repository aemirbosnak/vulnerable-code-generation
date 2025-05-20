//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pwd.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_HISTORY 10

void print_prompt() {
    printf("simple_shell> ");
}

void execute_command(char *command) {
    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return;
    }
    
    if (pid == 0) {
        // Child process
        char *args[3];
        args[0] = "/bin/sh"; // Use shell to execute command
        args[1] = "-c";     // Pass command
        args[2] = command;  // Command to execute
        args[3] = NULL;

        execvp(args[0], args);
        // If execvp fails
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

void add_to_history(char *history[], char *command, int *index) {
    free(history[*index]);  // Free previous command at this index
    history[*index] = strdup(command); // Store new command in history
    *index = (*index + 1) % MAX_HISTORY; // Circular buffer
}

void print_history(char *history[], int index) {
    printf("Command History:\n");
    for (int i = 0; i < MAX_HISTORY; i++) {
        int cmd_index = (index + i) % MAX_HISTORY;
        if (history[cmd_index] != NULL) {
            printf("%d: %s\n", cmd_index + 1, history[cmd_index]);
        }
    }
}

int main() {
    char *history[MAX_HISTORY] = {NULL};
    int history_index = 0;
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        print_prompt();
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("Error reading command");
            continue;
        }

        // Remove newline character
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "history") == 0) {
            print_history(history, history_index);
            continue;
        } else if (strcmp(command, "") == 0) {
            continue; // Skip empty command
        }

        add_to_history(history, command, &history_index);
        execute_command(command);
    }

    // Cleanup history
    for (int i = 0; i < MAX_HISTORY; i++) {
        free(history[i]);
    }

    return 0;
}