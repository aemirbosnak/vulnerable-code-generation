//Falcon-180B DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENV_VARIABLES 10

char **build_env(char *envp[]) {
    char **new_envp = malloc(sizeof(char *) * (MAX_ENV_VARIABLES + 1));
    int i = 0;
    for (; envp[i]!= NULL; i++) {
        new_envp[i] = strdup(envp[i]);
    }
    new_envp[i] = NULL;
    return new_envp;
}

int main(int argc, char **argv, char **envp) {
    pid_t pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS];
    int num_args = 0;
    char **new_envp = build_env(envp);

    if (argc < 2) {
        printf("Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);
    num_args = argc - 2;

    for (int i = 0; i < num_args; i++) {
        args[i] = argv[i + 2];
    }

    args[num_args] = NULL;

    switch (pid = fork()) {
        case -1:
            perror("fork");
            return 1;
        case 0:
            execve(command, args, new_envp);
            perror("execve");
            exit(1);
        default:
            waitpid(pid, &status, 0);
            break;
    }

    return 0;
}