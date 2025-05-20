//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *cmd_buffer = malloc(MAX_CMD_LEN);
    char *arg_buffer = malloc(MAX_ARGS * sizeof(char *));
    struct command *cmd = NULL;

    while (1) {
        printf("$ ");
        fgets(cmd_buffer, MAX_CMD_LEN, stdin);
        cmd_buffer[strcspn(cmd_buffer, "\n")] = 0; // trim newline

        // parse command and arguments
        char *token = strtok(cmd_buffer, " ");
        cmd = malloc(sizeof(struct command));
        cmd->name = token;
        int i = 0;
        while ((token = strtok(NULL, " ")) != NULL) {
            cmd->args[i++] = token;
        }

        // execute command
        if (cmd->name[0] == '.' && cmd->name[1] == 'x') {
            // execute external command
            int status;
            pid_t pid = fork();
            if (pid == 0) {
                // child process
                execv(cmd->name, cmd->args);
                // should never reach here
                exit(1);
            } else {
                // parent process
                wait(&status);
            }
        } else {
            // execute built-in command
            if (strcmp(cmd->name, "help") == 0) {
                printf("Available commands:\n");
                printf("  help                Display this message and exit\n");
                printf("  echo <text>        Print <text> to the console\n");
                printf("  cd <directory>     Change current working directory\n");
                printf("  pwd                Print current working directory\n");
                printf("  exit <code>        Exit the program with <code>\n");
            } else if (strcmp(cmd->name, "echo") == 0) {
                int i = 0;
                while (cmd->args[i]) {
                    printf("%s ", cmd->args[i++]);
                }
                printf("\n");
            } else if (strcmp(cmd->name, "cd") == 0) {
                if (chdir(cmd->args[0]) != 0) {
                    perror("chdir");
                }
            } else if (strcmp(cmd->name, "pwd") == 0) {
                printf("%s\n", getcwd(NULL, 0));
            } else if (strcmp(cmd->name, "exit") == 0) {
                int code = atoi(cmd->args[0]);
                exit(code);
            } else {
                printf("Invalid command\n");
            }
        }

        free(cmd);
    }

    return 0;
}