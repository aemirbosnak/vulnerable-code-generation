//Falcon-180B DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10
#define MAX_ENV_VARS 10

typedef struct {
    char *name;
    char *value;
} env_var_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char *args[MAX_ARGS];
    int num_args = 0;

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            args[num_args++] = argv[i];
        }
    }

    pid_t pid = fork();

    if (pid == -1) {
        printf("Failed to fork process.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < num_args; i++) {
            printf("%s ", args[i]);
        }
        printf("\n");

        execlp(command, command, NULL);
        printf("Failed to execute command.\n");
        return 1;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Command exited with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command was terminated by signal %d.\n", WTERMSIG(status));
        } else {
            printf("Command terminated abnormally.\n");
        }

        return 0;
    }
}