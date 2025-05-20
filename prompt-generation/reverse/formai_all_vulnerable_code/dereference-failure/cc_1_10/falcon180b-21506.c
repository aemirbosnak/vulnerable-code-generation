//Falcon-180B DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

int main(int argc, char *argv[]) {

    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;
    int i = 0;
    int status;

    if (argc < 2) {
        printf("Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);

    while ((i < argc - 1) && (num_arguments < MAX_ARGUMENTS - 1)) {
        arguments[num_arguments] = argv[++i];
        num_arguments++;
    }

    arguments[num_arguments] = NULL;

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(command, arguments);
        perror("execvp");
        return 1;
    } else {
        waitpid(pid, &status, WUNTRACED);
        if (WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command killed by signal %d\n", WTERMSIG(status));
        } else {
            printf("Command stopped by signal %d\n", WSTOPSIG(status));
        }
        return 0;
    }
}