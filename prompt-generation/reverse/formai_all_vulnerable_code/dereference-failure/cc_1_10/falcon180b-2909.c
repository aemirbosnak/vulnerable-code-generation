//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 64
#define MAX_ARG_LENGTH 256

typedef struct {
    char* line;
    char** args;
    int argc;
} Command;

Command* parse_command(char* line) {
    Command* cmd = malloc(sizeof(Command));
    cmd->line = strdup(line);
    cmd->args = NULL;
    cmd->argc = 0;

    char* token = strtok(line, " ");
    while (token!= NULL) {
        if (cmd->argc >= MAX_ARG_LENGTH) {
            printf("Error: Command line too long\n");
            exit(1);
        }
        cmd->args = realloc(cmd->args, sizeof(char*) * (cmd->argc + 1));
        cmd->args[cmd->argc] = strdup(token);
        cmd->argc++;
        token = strtok(NULL, " ");
    }

    return cmd;
}

void execute_command(Command* cmd) {
    if (strcmp(cmd->args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(cmd->args[0], "echo") == 0) {
        for (int i = 1; i < cmd->argc; i++) {
            printf("%s ", cmd->args[i]);
        }
        printf("\n");
    } else {
        printf("Command not found\n");
    }
}

void run_shell(void) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        Command* cmd = parse_command(line);
        execute_command(cmd);
        free(cmd->line);
        for (int i = 0; i < cmd->argc; i++) {
            free(cmd->args[i]);
        }
        free(cmd->args);
        free(cmd);
    }
}

int main(int argc, char** argv) {
    run_shell();
    return 0;
}