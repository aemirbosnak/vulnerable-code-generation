//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_CMD_LEN 100

typedef struct {
    char cmd[MAX_CMD_LEN];
    char args[MAX_ARGS][MAX_CMD_LEN];
    int argc;
} command_t;

void parse_command(char* cmd, command_t* command) {
    char* token;
    token = strtok(cmd, " ");
    strcpy(command->cmd, token);
    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            strcpy(command->args[command->argc], token);
            command->argc++;
        }
    }
}

void execute_command(command_t* command) {
    if (strcmp(command->cmd, "cd") == 0) {
        if (command->argc == 1) {
            chdir(command->args[0]);
        } else {
            fprintf(stderr, "cd: too many arguments\n");
        }
    } else if (strcmp(command->cmd, "pwd") == 0) {
        char* cwd = getcwd(NULL, 0);
        printf("%s\n", cwd);
        free(cwd);
    } else if (strcmp(command->cmd, "ls") == 0) {
        if (command->argc == 0) {
            system("ls -l");
        } else {
            char* cmd = malloc(MAX_CMD_LEN);
            sprintf(cmd, "ls -l %s", command->args[0]);
            system(cmd);
            free(cmd);
        }
    } else {
        fprintf(stderr, "Unknown command: %s\n", command->cmd);
    }
}

int main(int argc, char** argv) {
    char cmd[MAX_CMD_LEN];
    command_t command;
    while (1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        parse_command(cmd, &command);
        execute_command(&command);
    }
    return 0;
}