//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_COMMANDS 100
#define MAX_ARGS 100
#define MAX_PIPELINE_LENGTH 100

char **environ;

typedef struct {
    int argc;
    char **argv;
    char **envp;
} command_t;

void *execute_command(void *arg) {
    command_t *cmd = (command_t *) arg;

    if (cmd->argc == 0) {
        printf("No command specified.\n");
        return NULL;
    }

    pid_t pid = fork();

    if (pid == -1) {
        printf("Failed to fork.\n");
        return NULL;
    } else if (pid == 0) {
        if (execve(cmd->argv[0], cmd->argv, cmd->envp) == -1) {
            printf("Failed to execute command.\n");
            return NULL;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return NULL;
}

int main() {
    environ = malloc(sizeof(char *) * 10);
    environ[0] = strdup("PATH=/bin:/usr/bin");

    char input[1024];

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *token = strtok(input, " \n");
        command_t cmd;

        if (token == NULL)
            continue;

        cmd.argc = 0;
        cmd.argv = malloc(sizeof(char *) * MAX_ARGS);
        cmd.envp = environ;

        while (token!= NULL) {
            if (cmd.argc >= MAX_ARGS) {
                printf("Too many arguments.\n");
                break;
            }

            cmd.argv[cmd.argc++] = strdup(token);

            token = strtok(NULL, " \n");
        }

        if (cmd.argc == 0)
            continue;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, execute_command, (void *) &cmd);
        pthread_join(thread_id, NULL);
    }

    return 0;
}