//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *cmd_name;
    char *cmd_args[MAX_ARGS];
    int status;

    while (1) {
        printf("Please enter a command: ");
        scanf("%s %s", &cmd_name, &cmd_args[0]);

        // Check if the command is a valid command
        if (strcmp(cmd_name, "ls") == 0 ||
                strcmp(cmd_name, "cd") == 0 ||
                strcmp(cmd_name, "mkdir") == 0 ||
                strcmp(cmd_name, "rmdir") == 0 ||
                strcmp(cmd_name, "cp") == 0 ||
                strcmp(cmd_name, "mv") == 0 ||
                strcmp(cmd_name, "rm") == 0) {
            // Execute the command
            if (cmd_args[0] != NULL) {
                // Build the command line
                char *cmd_line = NULL;
                for (int i = 0; i < MAX_ARGS; i++) {
                    if (i > 0) {
                        cmd_line = cmd_line == NULL ? NULL : strcat(cmd_line, " ");
                    }
                    cmd_line = cmd_line == NULL ? NULL : strcat(cmd_line, cmd_args[i]);
                }

                // Execute the command
                system(cmd_line);
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}